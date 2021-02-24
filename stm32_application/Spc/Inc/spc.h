#ifndef __SPC_H
#define __SPC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef int (*Logger)(const char* fmt, ...);

#define ToString(x) #x

#define PAGE_INDEX(PAGE_OPT, type) \
  PAGE_OPT(Default, type) \
  PAGE_OPT(Actual, type) \
  PAGE_OPT(Program, type)

#define KEY_INDEX(KEY_OPT, key) \
  KEY_OPT(Def, key) \
  KEY_OPT(Act, key) \
  KEY_OPT(Prog, key) \
  KEY_OPT(Up, key) \
  KEY_OPT(Down, key) \
  KEY_OPT(Left, key) \
  KEY_OPT(Right, key)

#define OBJ_ENUM(TYPE, type) TYPE,
#define PAGE_INIT_DECLARE(TYPE, type) void Page_Init_##TYPE(Logger);
#define PAGE_FUNC_DECLARE(TYPE, type) PageEntity_t *Page_Func_##TYPE(KeyEnum_t, Logger);
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
#define KEY_GET_TYPE(TYPE, key) { \
    if (strncmp(ToString(TYPE), key, sizeof(ToString(TYPE))) == 0) { \
        return TYPE; \
    } \
}

typedef enum KeyEnum {
    KEY_INDEX(OBJ_ENUM, NULL)
} KeyEnum_t;

typedef void (*PageInit) (Logger);

typedef enum PageEnum {
	PAGE_INDEX(OBJ_ENUM, NULL)
} PageEnum_t;

typedef struct PageEntity {
	PageEnum_t type;
	struct PageEntity *(*func) (KeyEnum_t, Logger);
} PageEntity_t;

typedef PageEntity_t *(*PageFunc) (KeyEnum_t, Logger);

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
static inline KeyEnum_t GetKeyType(char *key) {
    KEY_INDEX(KEY_GET_TYPE, key);
}

PageEntity_t *Page_CreatePage(PageEnum_t, Logger);

#ifdef __cplusplus
}
#endif

#endif							/* __SPC_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
