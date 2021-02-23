#ifndef __SPC_H
#define __SPC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>

#define ToString(x) #x

#define PAGE_INDEX(PAGE_OPT, type) \
  PAGE_OPT(Default, type) \
  PAGE_OPT(Actual, type) \
  PAGE_OPT(Program, type)

#define PAGE_ENUM(TYPE, type) TYPE,
#define PAGE_INIT_DECLARE(TYPE, type) void Page_Init_##TYPE(void);
#define PAGE_FUNC_DECLARE(TYPE, type) PageEntity_t *Page_Func_##TYPE(void);
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
#define PAGE_GET_TYPE(TYPE, key) { \
    if (strncmp(ToString(TYPE), key, sizeof(ToString(TYPE))) == 0) { \
        return TYPE; \
    } \
}

typedef void (*PageInit) (void);

typedef enum PageEnum {
		PAGE_INDEX(PAGE_ENUM, NULL)
} PageEnum_t;

typedef struct PageEntity {
		PageEnum_t type;
		struct PageEntity *(*func) (void);
} PageEntity_t;

typedef PageEntity_t *(*PageFunc) (void);

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
static inline PageEnum_t GetPageType(char *key)
{
    PAGE_INDEX(PAGE_GET_TYPE, key);
}

PageEntity_t *Page_CreatePage(PageEnum_t type);

#ifdef __cplusplus
}
#endif

#endif							/* __SPC_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
