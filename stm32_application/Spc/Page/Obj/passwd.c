#include "spc.h"
#include "spctimer.h"

#define MAX_HEATERNAME_LEN (15)

static const uint8_t kMapPasswdCharactor[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

static uint8_t PasswordGetCharactor(uint8_t charator)
{
    for (uint8_t i=0;i<NUM_ROWS(kMapPasswdCharactor);i++) {
        if (charator == kMapPasswdCharactor[i]) {
            return i;
        }
    }
    return 0;
}

typedef void (*PasswdFunc)(KeyEnum_t, Logger, PageEntity_t *);
typedef struct {
    SpcPasswdConfig_Enum_t status;
    PasswdFunc func;
} PasswordFunction;

static void OldPasswordRequireUpdate(KeyEnum_t key, Logger logger, PageEntity_t *page);
static void PasswordUpdate(KeyEnum_t key, Logger logger, PageEntity_t *page);
static const PasswordFunction PasswdUpdateFunctions[] = {
    {EnterOldPasswd,                    OldPasswordRequireUpdate},
    {EnterOldPasswdBusy,                PasswordUpdate},
    {EnterNewPasswdBusy,                PasswordUpdate},
    {EnterNewPasswdAgainBusy,           PasswordUpdate}
};

static void OldPasswordRequireConfig(KeyEnum_t key, Logger logger, PageEntity_t *page);
static void OldPasswordChangeConfig(KeyEnum_t key, Logger logger, PageEntity_t *page);
static void NewPasswordChangeConfig(KeyEnum_t key, Logger logger, PageEntity_t *page);
static void NewPasswordChangeAgainConfig(KeyEnum_t key, Logger logger, PageEntity_t *page);
static const PasswordFunction PasswdConfigFunctions[] = {
    {EnterOldPasswd,                    OldPasswordRequireConfig},
    {EnterOldPasswdBusy,                OldPasswordChangeConfig},
    {EnterNewPasswdBusy,                NewPasswordChangeConfig},
    {EnterNewPasswdAgainBusy,           NewPasswordChangeAgainConfig}
};

static void ExecutePasswdUpdateFunction (KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    SpcPasswdConfig_t *password = (SpcPasswdConfig_t *) (page->data);
    for (uint8_t i=0;i<NUM_ROWS(PasswdUpdateFunctions);i++) {
        if (password->status == PasswdUpdateFunctions[i].status) {
            PasswdFunc func = PasswdUpdateFunctions[i].func;
            func(key, logger, page);
            return;
        }
    }
}

static void ExecutePasswdSwitchFunction (KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    SpcPasswdConfig_t *password = (SpcPasswdConfig_t *) (page->data);
    for (uint8_t i=0;i<NUM_ROWS(PasswdConfigFunctions);i++) {
        if (password->status == PasswdConfigFunctions[i].status) {
            PasswdFunc func = PasswdConfigFunctions[i].func;
            func(key, logger, page);
            return;
        }
    }
}

static SpcStringConfig_t *GetPasswordType(SpcPasswdConfig_t *password)
{
    switch (password->status) {
    case EnterOldPasswdBusy:
        return &(password->oldPasswdInput);
    case EnterNewPasswdBusy:
        return &(password->newPasswd);
    case EnterNewPasswdAgainBusy:
        return &(password->newPasswdAgain);
    default :
        return NULL;
    }
}

static void PasswordStringOpt(SpcStringConfig_t *in, KeyEnum_t key)
{
    if (key == Up) {
        if (in->value[in->index] == '\0') {
            in->value[in->index] = '0';
        } else {
            uint8_t charator = PasswordGetCharactor(in->value[in->index]);
            uint8_t charatorNum = NUM_ROWS(kMapPasswdCharactor);
            charator = (charator + charatorNum + 1) % charatorNum;
            if ((in->index == 0) && (charator == 0)) charator++;
            in->value[in->index] = kMapPasswdCharactor[charator];
        }
    } else if (key == Down) {
        if (in->value[in->index] == '\0') {
            in->value[in->index] = 'Z';
        } else {
            uint8_t charator = PasswordGetCharactor(in->value[in->index]);
            uint8_t charatorNum = NUM_ROWS(kMapPasswdCharactor);
            charator = (charator + charatorNum - 1) % charatorNum;
            if ((in->index == 0) && (charator == 0)) charator = charatorNum - 1;
            in->value[in->index] = kMapPasswdCharactor[charator];
        }
    } else if (key == Left) {
        if (in->index > 0) in->index--;
    } else if (key == Right) {
        if (in->index < 10) {
            if (in->value[in->index] != '\0') {
                in->index++;
                if (in->value[in->index] == '\0') 
                    in->value[in->index] = '0';
            }
        }
    }
}

// Password string update functions
// Up and Down keys
//=================  Start =============================//
static void OldPasswordRequireUpdate(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;
    SpcPasswdConfig_t *password = (SpcPasswdConfig_t *) (page->data);

    if (key == Up) {
        password->changePasswd = 1;
        strncpy((char *)(page->info.Content), "Yes", MAX_INFO_LEN);
    } else {
        password->changePasswd = 0;
        strncpy((char *)(page->info.Content), "No", MAX_INFO_LEN);
    }
}

static void PasswordUpdate(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;
    SpcPasswdConfig_t *password = (SpcPasswdConfig_t *) (page->data);
    SpcStringConfig_t *passwordSingle = GetPasswordType(password);
    PasswordStringOpt(passwordSingle, key);
    memset((char *)(page->info.Content), 0, MAX_INFO_LEN);
    memset((char *)(page->info.Content), '*', strlen((char *)(passwordSingle->value)));
    page->info.Content[passwordSingle->index] = passwordSingle->value[passwordSingle->index];
}

static void Page_Update_Password(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);

    ExecutePasswdUpdateFunction(key, logger, page);
    page->publisher(&(page->info));
}
//=================  End =============================//

// Password string config functions
// Enter keys
//=================  Start =============================//
static void OldPasswordRequireConfig(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;
    SpcPasswdConfig_t *password = (SpcPasswdConfig_t *) (page->data);

    if (password->changePasswd) {
        strncpy((char *)(page->info.Title), "Enter Old Psw", MAX_INFO_LEN);
        memset((char *)(page->info.Content), 0, MAX_INFO_LEN);
        password->status = EnterOldPasswdBusy;
    }
}

static void OldPasswordChangeConfig(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;
    SpcPasswdConfig_t *password = (SpcPasswdConfig_t *) (page->data);
    SpcStringConfig_t *oldPasswd = &(password->oldPasswd);
    SpcStringConfig_t *oldPasswdInput = &(password->oldPasswdInput);

    if (strncmp((char *)(oldPasswd->value), (char *)(oldPasswdInput->value), MAX_INFO_LEN) == 0) {
        strncpy((char *)(page->info.Title), "Enter New Psw", MAX_INFO_LEN);
        memset((char *)(page->info.Content), 0, MAX_INFO_LEN);
        password->status = EnterNewPasswdBusy;
    } else {
        SpcTimer_StopTimer(Flash);
        SpcTimer_StartTimer(Restore, 40, false);

        strncpy((char *)(page->info.Title), "Invalid Password", MAX_INFO_LEN);
        memset((char *)(page->info.Content), 0, MAX_INFO_LEN);
        password->status = EnterOldPasswd;
    }
}

static void NewPasswordChangeConfig(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;
    SpcPasswdConfig_t *password = (SpcPasswdConfig_t *) (page->data);

    strncpy((char *)(page->info.Title), "Enter Again", MAX_INFO_LEN);
    memset((char *)(page->info.Content), 0, MAX_INFO_LEN);
    password->status = EnterNewPasswdAgainBusy;
}

static void NewPasswordChangeAgainConfig(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;
    SpcPasswdConfig_t *password = (SpcPasswdConfig_t *) (page->data);
    SpcStringConfig_t *newPasswd = &(password->newPasswd);
    SpcStringConfig_t *newPasswdAgain = &(password->newPasswdAgain);
        
    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);
    
    if (strncmp((char *)(newPasswd->value), (char *)(newPasswdAgain->value), MAX_INFO_LEN) == 0) {
        strncpy((char *)(page->info.Title), "Operate success", MAX_INFO_LEN);
        memset((char *)(page->info.Content), 0, MAX_INFO_LEN);
        password->status = EnterOldPasswd;

        SpcData_SetPassword(newPasswd->value);
    } else {
        strncpy((char *)(page->info.Title), "Not match", MAX_INFO_LEN);
        memset((char *)(page->info.Content), 0, MAX_INFO_LEN);
        password->status = EnterOldPasswd;
    }
}

static void Page_Config_Password(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    ExecutePasswdSwitchFunction(key, logger, page);
    page->publisher(&(page->info));
}
//=================  End =============================//

static void Page_Reset_Password(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(SpcPasswdConfig_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    strncpy((char *)(page->info.Title), "Change Password", MAX_INFO_LEN);

    SpcPasswdConfig_t *password = (SpcPasswdConfig_t *) (page->data);
    SpcStringConfig_t *oldPasswd = &(password->oldPasswd);
    SpcData_GetPassword(oldPasswd->value);
    OldPasswordRequireUpdate(password->changePasswd, logger, page);
    page->publisher(&(page->info));
}

static void Page_Flash_Password(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcPasswdConfig_t *password = (SpcPasswdConfig_t *) (page->data);

    static bool flash = false;
    if (flash) {
        if (password->status == EnterOldPasswd) {
            memset((char *)(page->info.Content), 0, MAX_INFO_LEN);
        } else {
            SpcStringConfig_t *passwordSingle = GetPasswordType(password);
            memset((char *)(page->info.Content), 0, MAX_INFO_LEN);
            memset((char *)(page->info.Content), '*', strlen((char *)(passwordSingle->value)));
            page->info.Content[passwordSingle->index] = '-';
        }
    } else {
        if (password->status == EnterOldPasswd) {
            if (password->changePasswd) {
                strncpy((char *)(page->info.Content), "Yes", MAX_INFO_LEN);
            } else {
                strncpy((char *)(page->info.Content), "No", MAX_INFO_LEN);
            }
        } else {
            SpcStringConfig_t *passwordSingle = GetPasswordType(password);
            memset((char *)(page->info.Content), 0, MAX_INFO_LEN);
            memset((char *)(page->info.Content), '*', strlen((char *)(passwordSingle->value)));
            page->info.Content[passwordSingle->index] = passwordSingle->value[passwordSingle->index];
        }
    }

    flash = !flash;
    page->publisher(&(page->info));
}

void Page_Init_Password(Logger logger, PageEntity_t *page)
{
    //logger("\r\nPassword\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "Change Password", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (SpcPasswdConfig_t *) malloc(sizeof(SpcPasswdConfig_t));
    memset(page->data, 0, sizeof(SpcPasswdConfig_t));
    SpcPasswdConfig_t *password = (SpcPasswdConfig_t *) (page->data);
    SpcStringConfig_t *oldPasswd = &(password->oldPasswd);
    if (SpcData_GetPassword(oldPasswd->value)) {
        OldPasswordRequireUpdate(password->changePasswd, logger, page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read name", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

static uint8_t PasswordPageLock(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return 0;

    SpcPasswdConfig_t *password = (SpcPasswdConfig_t *) (page->data);
    return (password->status == EnterOldPasswd) ? 0 : 1;
}

PageEntity_t *Page_Func_Password(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        {
            if (PasswordPageLock(logger, page)) {
                Page_Update_Password(key, logger, page);
                return NULL;
            } else {
                return Page_CreatePage(TempUnits, logger, page->publisher);
            }
        }
    case Left:
        {
            if (PasswordPageLock(logger, page)) {
                Page_Update_Password(key, logger, page);
                return NULL;
            } else {
                return Page_CreatePage(PasswdEn, logger, page->publisher);
            }
        }
    case Up:
    case Down:
        Page_Update_Password(key, logger, page);
        return NULL;
    case Enter:
        Page_Config_Password(key, logger, page);
        return NULL;
    case Reset:
    case Restore:
        Page_Reset_Password(logger, page);
        return NULL;
    case Flash:
        Page_Flash_Password(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

