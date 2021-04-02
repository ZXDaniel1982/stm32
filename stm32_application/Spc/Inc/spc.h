#ifndef __SPC_H
#define __SPC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "key.h"

typedef int (*Logger)(const char* fmt, ...);

#define PAGE_INDEX(PAGE_OPT, type) \
  PAGE_OPT(Default, type) \
  PAGE_OPT(Actual, type) \
  PAGE_OPT(Program, type)

#define OBJ_ENUM(TYPE, type) TYPE,
#define PAGE_INIT_DECLARE(TYPE, type) void Page_Init_##TYPE(Logger, PageEntity_t *);
#define PAGE_FUNC_DECLARE(TYPE, type) PageEntity_t *Page_Func_##TYPE(KeyEnum_t, Logger, PageEntity_t *);
#define PAGE_INIT(TYPE, type) { \
    if (TYPE == type) { \
        return Page_Init_##TYPE; \
    } \
}
#define PAGE_FUNC(TYPE, type) { \
    if (TYPE == type) { \
        return Page_Func_##TYPE; \
    } \
}

#define MAX_INFO_LEN (16)
typedef struct {
  uint8_t Title[MAX_INFO_LEN];
  uint8_t Content[MAX_INFO_LEN];
} PageInfo_t;

typedef void (*Publisher)(PageInfo_t *);

typedef enum PageEnum {
	PAGE_INDEX(OBJ_ENUM, NULL)
} PageEnum_t;

typedef struct PageEntity {
	PageEnum_t type;
  PageInfo_t info;
  Publisher publisher;
	struct PageEntity *(*func) (KeyEnum_t, Logger, struct PageEntity *);
} PageEntity_t;

typedef void (*PageInit) (Logger, PageEntity_t *);
typedef PageEntity_t *(*PageFunc) (KeyEnum_t, Logger, PageEntity_t *);

PAGE_INDEX(PAGE_INIT_DECLARE, NULL)
PAGE_INDEX(PAGE_FUNC_DECLARE, NULL)

static inline PageInit GetPageInit(PageEnum_t type) {
	PAGE_INDEX(PAGE_INIT, type)
    return NULL;
} 
static inline PageFunc GetPageFunc(PageEnum_t type) {
	PAGE_INDEX(PAGE_FUNC, type)
    return NULL;
}

PageEntity_t *Page_CreatePage(PageEnum_t, Logger, Publisher);

#ifdef __cplusplus
}
#endif

#endif							/* __SPC_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
