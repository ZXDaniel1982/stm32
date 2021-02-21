#ifndef __SPC_H
#define __SPC_H

#ifdef __cplusplus
extern "C" {
#endif

#define PAGE_INDEX(PAGE_OPT) \
  PAGE_OPT(Actual) \
  PAGE_OPT(Program)

#define PAGE_ENUM(TYPE) TYPE,
#define PAGE_INIT_DECLARE(TYPE) void Page_Init_##TYPE(void);
#define PAGE_INIT(TYPE) Page_Init_##TYPE();
#define PAGE_REG(TYPE)

typedef enum PageEnum {
  PAGE_INDEX(PAGE_ENUM)
} PageEnum_t; 

PAGE_INDEX(PAGE_INIT_DECLARE)

#ifdef __cplusplus
}
#endif

#endif /* __SPC_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

