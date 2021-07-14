#include "spc.h"

void Spc_Init_Page(Logger logger,
                   PageEntity_t *page,
                   const uint8_t* title,
                   const uint8_t* content)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), (char *)title, MAX_INFO_LEN);
    strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
    page->publisher(&(page->info));
}
