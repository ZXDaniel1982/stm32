#include "common.h"

static const char versionfn[] = "../.version";

static uint32_t GetFileSize(char *filename)
{
    if (filename == NULL)
        return 0;

    struct stat st;
    stat(filename, &st);
    return (uint32_t)st.st_size;
}

static uint16_t IncrementVersion()
{
    char buf[10] = {0};
    uint16_t version = 0;
    if( access( versionfn, F_OK ) != -1 ) {
        FILE *file = fopen(versionfn, "r+");
        if (file == NULL) {
            printf("Fail to open file (%s)\n", versionfn);
            return 0;
        }
        fread(buf, 10, 1, file);
        version = atol(buf);
        version++;

        memset(buf, 0, 10);
        snprintf(buf, 10, "%d", version);
        fseek(file, 0, SEEK_SET);
        fwrite(buf, strlen(buf)+1, 1, file);
        fclose(file);
    } else {
        version = 1;
        FILE *file = fopen(versionfn, "w+");
        if (file == NULL) {
            printf("Fail to open file (%s)\n", versionfn);
            return 0;
        }
        memset(buf, 0, 10);
        snprintf(buf, 10, "%d", version);
        rewind(file);
        fwrite(buf, strlen(buf)+1, 1, file);
        fclose(file);
    }
    return version;
}

uint16_t GetVersion()
{
    char buf[10] = {0};
    uint16_t version = 0;

    if( access( versionfn, F_OK ) != -1 ) {
        FILE *file = fopen(versionfn, "r+");
        if (file == NULL) {
            printf("Fail to open file (%s)\n", versionfn);
            return 0;
        }
        fread(buf, 10, 1, file);
        version = atol(buf);
        fclose(file);
    }
    return version;
}

void GetImageArgs(Imageargs_t *iargs, char *filename)
{
    memset(iargs, 0, sizeof(Imageargs_t));
    iargs->header = IMAGEARGS_HEADER;
    iargs->tail = IMAGEARGS_TAIL;
    iargs->version = IncrementVersion();
    iargs->size = GetFileSize(filename);
}
