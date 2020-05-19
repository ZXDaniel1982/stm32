#line 1 "Core\\Src\\eeprom.c"
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"
 
 
 





 






 







 




  
 








#line 47 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"


  



    typedef unsigned int size_t;    









 
 

 



    typedef struct __va_list __va_list;






   




 




typedef struct __fpos_t_struct {
    unsigned __int64 __pos;
    



 
    struct {
        unsigned int __state1, __state2;
    } __mbstate;
} fpos_t;
   


 


   

 

typedef struct __FILE FILE;
   






 

#line 136 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"


extern FILE __stdin, __stdout, __stderr;
extern FILE *__aeabi_stdin, *__aeabi_stdout, *__aeabi_stderr;

#line 166 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"
    

    

    





     



   


 


   


 

   



 

   


 




   


 





    


 






extern __declspec(__nothrow) int remove(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int rename(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) FILE *tmpfile(void);
   




 
extern __declspec(__nothrow) char *tmpnam(char *  );
   











 

extern __declspec(__nothrow) int fclose(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) int fflush(FILE *  );
   







 
extern __declspec(__nothrow) FILE *fopen(const char * __restrict  ,
                           const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   








































 
extern __declspec(__nothrow) FILE *freopen(const char * __restrict  ,
                    const char * __restrict  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(2,3)));
   








 
extern __declspec(__nothrow) void setbuf(FILE * __restrict  ,
                    char * __restrict  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) int setvbuf(FILE * __restrict  ,
                   char * __restrict  ,
                   int  , size_t  ) __attribute__((__nonnull__(1)));
   















 
#pragma __printf_args
extern __declspec(__nothrow) int fprintf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   


















 
#pragma __printf_args
extern __declspec(__nothrow) int _fprintf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   




 
#pragma __printf_args
extern __declspec(__nothrow) int _printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






 
#pragma __printf_args
extern __declspec(__nothrow) int _sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int __ARM_snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));


#pragma __printf_args
extern __declspec(__nothrow) int snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   















 

#pragma __printf_args
extern __declspec(__nothrow) int _snprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int fscanf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






























 
#pragma __scanf_args
extern __declspec(__nothrow) int _fscanf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   






 
#pragma __scanf_args
extern __declspec(__nothrow) int _scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int sscanf(const char * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   








 
#pragma __scanf_args
extern __declspec(__nothrow) int _sscanf(const char * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

 
extern __declspec(__nothrow) int vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int _vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int _vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int _vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int __ARM_vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int _vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int vfprintf(FILE * __restrict  ,
                    const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int vsprintf(char * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int __ARM_vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));

extern __declspec(__nothrow) int vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   







 

extern __declspec(__nothrow) int _vsprintf(char * __restrict  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vfprintf(FILE * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vsnprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int asprintf(char **  , const char * __restrict  , ...) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) int vasprintf(char **  , const char * __restrict  , __va_list  ) __attribute__((__nonnull__(2)));

#pragma __printf_args
extern __declspec(__nothrow) int __ARM_asprintf(char **  , const char * __restrict  , ...) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) int __ARM_vasprintf(char **  , const char * __restrict  , __va_list  ) __attribute__((__nonnull__(2)));
   








 

extern __declspec(__nothrow) int fgetc(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) char *fgets(char * __restrict  , int  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   










 
extern __declspec(__nothrow) int fputc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   







 
extern __declspec(__nothrow) int fputs(const char * __restrict  , FILE * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int getc(FILE *  ) __attribute__((__nonnull__(1)));
   







 




    extern __declspec(__nothrow) int (getchar)(void);

   





 
extern __declspec(__nothrow) char *gets(char *  ) __attribute__((__nonnull__(1)));
   









 
extern __declspec(__nothrow) int putc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   





 




    extern __declspec(__nothrow) int (putchar)(int  );

   



 
extern __declspec(__nothrow) int puts(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int ungetc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   






















 

extern __declspec(__nothrow) size_t fread(void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   











 

extern __declspec(__nothrow) size_t __fread_bytes_avail(void * __restrict  ,
                    size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   











 

extern __declspec(__nothrow) size_t fwrite(const void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   







 

extern __declspec(__nothrow) int fgetpos(FILE * __restrict  , fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) int fseek(FILE *  , long int  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) int fsetpos(FILE * __restrict  , const fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   










 
extern __declspec(__nothrow) long int ftell(FILE *  ) __attribute__((__nonnull__(1)));
   











 
extern __declspec(__nothrow) void rewind(FILE *  ) __attribute__((__nonnull__(1)));
   





 

extern __declspec(__nothrow) void clearerr(FILE *  ) __attribute__((__nonnull__(1)));
   




 

extern __declspec(__nothrow) int feof(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) int ferror(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) void perror(const char *  );
   









 

extern __declspec(__nothrow) int _fisatty(FILE *   ) __attribute__((__nonnull__(1)));
    
 

extern __declspec(__nothrow) void __use_no_semihosting_swi(void);
extern __declspec(__nothrow) void __use_no_semihosting(void);
    





 











#line 1021 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"



 

#line 2 "Core\\Src\\eeprom.c"
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"
 






 

 
 
 





 





#line 34 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"




  typedef signed int ptrdiff_t;



  



    typedef unsigned int size_t;    
#line 57 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



   



      typedef unsigned short wchar_t;  
#line 82 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



    




   




  typedef long double max_align_t;









#line 114 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



 

#line 3 "Core\\Src\\eeprom.c"
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
 
 
 
 




 








 












#line 38 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"


  



    typedef unsigned int size_t;    
#line 54 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"




extern __declspec(__nothrow) void *memcpy(void * __restrict  ,
                    const void * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) void *memmove(void *  ,
                    const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   







 
extern __declspec(__nothrow) char *strcpy(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncpy(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 

extern __declspec(__nothrow) char *strcat(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncat(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 






 

extern __declspec(__nothrow) int memcmp(const void *  , const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strcmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int strncmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcasecmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strncasecmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcoll(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   







 

extern __declspec(__nothrow) size_t strxfrm(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   













 


#line 193 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) void *memchr(const void *  , int  , size_t  ) __attribute__((__nonnull__(1)));

   





 

#line 209 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   




 

extern __declspec(__nothrow) size_t strcspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 

#line 232 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strpbrk(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   




 

#line 247 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strrchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   





 

extern __declspec(__nothrow) size_t strspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   



 

#line 270 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strstr(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   





 

extern __declspec(__nothrow) char *strtok(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) char *_strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

extern __declspec(__nothrow) char *strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

   

































 

extern __declspec(__nothrow) void *memset(void *  , int  , size_t  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) char *strerror(int  );
   





 
extern __declspec(__nothrow) size_t strlen(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) size_t strlcpy(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   
















 

extern __declspec(__nothrow) size_t strlcat(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






















 

extern __declspec(__nothrow) void _membitcpybl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpybb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
    














































 







#line 502 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"



 

#line 4 "Core\\Src\\eeprom.c"

#line 1 ".\\Core\\Inc\\stm32f1xx.h"













































 



 



 
    






  


 



 






 

#line 96 ".\\Core\\Inc\\stm32f1xx.h"



 
  





 
   




 
#line 121 ".\\Core\\Inc\\stm32f1xx.h"



 



 

#line 1 ".\\Core\\Inc\\stm32f103xe.h"











































 




 



 
    









 


 







 



 




 

  
typedef enum
{
 
  NonMaskableInt_IRQn         = -14,     
  HardFault_IRQn              = -13,     
  MemoryManagement_IRQn       = -12,     
  BusFault_IRQn               = -11,     
  UsageFault_IRQn             = -10,     
  SVCall_IRQn                 = -5,      
  DebugMonitor_IRQn           = -4,      
  PendSV_IRQn                 = -2,      
  SysTick_IRQn                = -1,      

 
  WWDG_IRQn                   = 0,       
  PVD_IRQn                    = 1,       
  TAMPER_IRQn                 = 2,       
  RTC_IRQn                    = 3,       
  FLASH_IRQn                  = 4,       
  RCC_IRQn                    = 5,       
  EXTI0_IRQn                  = 6,       
  EXTI1_IRQn                  = 7,       
  EXTI2_IRQn                  = 8,       
  EXTI3_IRQn                  = 9,       
  EXTI4_IRQn                  = 10,      
  DMA1_Channel1_IRQn          = 11,      
  DMA1_Channel2_IRQn          = 12,      
  DMA1_Channel3_IRQn          = 13,      
  DMA1_Channel4_IRQn          = 14,      
  DMA1_Channel5_IRQn          = 15,      
  DMA1_Channel6_IRQn          = 16,      
  DMA1_Channel7_IRQn          = 17,      
  ADC1_2_IRQn                 = 18,      
  USB_HP_CAN1_TX_IRQn         = 19,      
  USB_LP_CAN1_RX0_IRQn        = 20,      
  CAN1_RX1_IRQn               = 21,      
  CAN1_SCE_IRQn               = 22,      
  EXTI9_5_IRQn                = 23,      
  TIM1_BRK_IRQn               = 24,      
  TIM1_UP_IRQn                = 25,      
  TIM1_TRG_COM_IRQn           = 26,      
  TIM1_CC_IRQn                = 27,      
  TIM2_IRQn                   = 28,      
  TIM3_IRQn                   = 29,      
  TIM4_IRQn                   = 30,      
  I2C1_EV_IRQn                = 31,      
  I2C1_ER_IRQn                = 32,      
  I2C2_EV_IRQn                = 33,      
  I2C2_ER_IRQn                = 34,      
  SPI1_IRQn                   = 35,      
  SPI2_IRQn                   = 36,      
  USART1_IRQn                 = 37,      
  USART2_IRQn                 = 38,      
  USART3_IRQn                 = 39,      
  EXTI15_10_IRQn              = 40,      
  RTC_Alarm_IRQn              = 41,      
  USBWakeUp_IRQn              = 42,      
  TIM8_BRK_IRQn               = 43,      
  TIM8_UP_IRQn                = 44,      
  TIM8_TRG_COM_IRQn           = 45,      
  TIM8_CC_IRQn                = 46,      
  ADC3_IRQn                   = 47,      
  FSMC_IRQn                   = 48,      
  SDIO_IRQn                   = 49,      
  TIM5_IRQn                   = 50,      
  SPI3_IRQn                   = 51,      
  UART4_IRQn                  = 52,      
  UART5_IRQn                  = 53,      
  TIM6_IRQn                   = 54,      
  TIM7_IRQn                   = 55,      
  DMA2_Channel1_IRQn          = 56,      
  DMA2_Channel2_IRQn          = 57,      
  DMA2_Channel3_IRQn          = 58,      
  DMA2_Channel4_5_IRQn        = 59,      
} IRQn_Type;



 

#line 1 ".\\Core\\Inc\\core_cm3.h"
 




 

























 











#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
 
 





 









     
#line 27 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
     











#line 46 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"





 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     




typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;


     
typedef   signed     long long intmax_t;
typedef unsigned     long long uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     






     






     






     

     


     


     


     

     
#line 216 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     



     






     
    
 



#line 241 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     







     










     











#line 305 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"






 
#line 45 ".\\Core\\Inc\\core_cm3.h"

















 




 



 

 













#line 120 ".\\Core\\Inc\\core_cm3.h"



 







#line 162 ".\\Core\\Inc\\core_cm3.h"

#line 1 ".\\Core\\Inc\\core_cmInstr.h"
 




 

























 












 



 

 
#line 1 ".\\Core\\Inc\\cmsis_armcc.h"
 




 

























 










 



 

 
 





 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}






 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}






 
static __inline uint32_t __get_IPSR(void)
{
  register uint32_t __regIPSR          __asm("ipsr");
  return(__regIPSR);
}






 
static __inline uint32_t __get_APSR(void)
{
  register uint32_t __regAPSR          __asm("apsr");
  return(__regAPSR);
}






 
static __inline uint32_t __get_xPSR(void)
{
  register uint32_t __regXPSR          __asm("xpsr");
  return(__regXPSR);
}






 
static __inline uint32_t __get_PSP(void)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  return(__regProcessStackPointer);
}






 
static __inline void __set_PSP(uint32_t topOfProcStack)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  __regProcessStackPointer = topOfProcStack;
}






 
static __inline uint32_t __get_MSP(void)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  return(__regMainStackPointer);
}






 
static __inline void __set_MSP(uint32_t topOfMainStack)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  __regMainStackPointer = topOfMainStack;
}






 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}






 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}








 







 







 
static __inline uint32_t  __get_BASEPRI(void)
{
  register uint32_t __regBasePri         __asm("basepri");
  return(__regBasePri);
}






 
static __inline void __set_BASEPRI(uint32_t basePri)
{
  register uint32_t __regBasePri         __asm("basepri");
  __regBasePri = (basePri & 0xFFU);
}







 
static __inline void __set_BASEPRI_MAX(uint32_t basePri)
{
  register uint32_t __regBasePriMax      __asm("basepri_max");
  __regBasePriMax = (basePri & 0xFFU);
}






 
static __inline uint32_t __get_FAULTMASK(void)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  return(__regFaultMask);
}






 
static __inline void __set_FAULTMASK(uint32_t faultMask)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  __regFaultMask = (faultMask & (uint32_t)1);
}




#line 297 ".\\Core\\Inc\\cmsis_armcc.h"



 


 



 




 






 







 






 








 










 










 











 








 

__attribute__((section(".rev16_text"))) static __inline __asm uint32_t __REV16(uint32_t value)
{
  rev16 r0, r0
  bx lr
}







 

__attribute__((section(".revsh_text"))) static __inline __asm int32_t __REVSH(int32_t value)
{
  revsh r0, r0
  bx lr
}









 









 








 
#line 455 ".\\Core\\Inc\\cmsis_armcc.h"







 










 












 












 














 














 














 










 









 









 









 

__attribute__((section(".rrx_text"))) static __inline __asm uint32_t __RRX(uint32_t value)
{
  rrx r0, r0
  bx lr
}








 








 








 








 








 








 




   


 



 

#line 731 ".\\Core\\Inc\\cmsis_armcc.h"
 


#line 54 ".\\Core\\Inc\\core_cmInstr.h"

 
#line 84 ".\\Core\\Inc\\core_cmInstr.h"

   

#line 164 ".\\Core\\Inc\\core_cm3.h"
#line 1 ".\\Core\\Inc\\core_cmFunc.h"
 




 

























 












 



 

 
#line 54 ".\\Core\\Inc\\core_cmFunc.h"

 
#line 84 ".\\Core\\Inc\\core_cmFunc.h"

 

#line 165 ".\\Core\\Inc\\core_cm3.h"
















 
#line 203 ".\\Core\\Inc\\core_cm3.h"

 






 
#line 219 ".\\Core\\Inc\\core_cm3.h"

 




 












 



 






 



 
typedef union
{
  struct
  {
    uint32_t _reserved0:27;               
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} APSR_Type;

 


















 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:23;               
  } b;                                    
  uint32_t w;                             
} IPSR_Type;

 






 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:15;               
    uint32_t T:1;                         
    uint32_t IT:2;                        
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} xPSR_Type;

 



























 
typedef union
{
  struct
  {
    uint32_t nPRIV:1;                     
    uint32_t SPSEL:1;                     
    uint32_t _reserved1:30;               
  } b;                                    
  uint32_t w;                             
} CONTROL_Type;

 






 







 



 
typedef struct
{
  volatile uint32_t ISER[8U];                
        uint32_t RESERVED0[24U];
  volatile uint32_t ICER[8U];                
        uint32_t RSERVED1[24U];
  volatile uint32_t ISPR[8U];                
        uint32_t RESERVED2[24U];
  volatile uint32_t ICPR[8U];                
        uint32_t RESERVED3[24U];
  volatile uint32_t IABR[8U];                
        uint32_t RESERVED4[56U];
  volatile uint8_t  IP[240U];                
        uint32_t RESERVED5[644U];
  volatile  uint32_t STIR;                    
}  NVIC_Type;

 



 







 



 
typedef struct
{
  volatile const  uint32_t CPUID;                   
  volatile uint32_t ICSR;                    
  volatile uint32_t VTOR;                    
  volatile uint32_t AIRCR;                   
  volatile uint32_t SCR;                     
  volatile uint32_t CCR;                     
  volatile uint8_t  SHP[12U];                
  volatile uint32_t SHCSR;                   
  volatile uint32_t CFSR;                    
  volatile uint32_t HFSR;                    
  volatile uint32_t DFSR;                    
  volatile uint32_t MMFAR;                   
  volatile uint32_t BFAR;                    
  volatile uint32_t AFSR;                    
  volatile const  uint32_t PFR[2U];                 
  volatile const  uint32_t DFR;                     
  volatile const  uint32_t ADR;                     
  volatile const  uint32_t MMFR[4U];                
  volatile const  uint32_t ISAR[5U];                
        uint32_t RESERVED0[5U];
  volatile uint32_t CPACR;                   
} SCB_Type;

 















 






























 




#line 500 ".\\Core\\Inc\\core_cm3.h"

 





















 









 


















 










































 









 









 















 







 



 
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile const  uint32_t ICTR;                    

  volatile uint32_t ACTLR;                   



} SCnSCB_Type;

 



 










 







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t LOAD;                    
  volatile uint32_t VAL;                     
  volatile const  uint32_t CALIB;                   
} SysTick_Type;

 












 



 



 









 







 



 
typedef struct
{
  volatile  union
  {
    volatile  uint8_t    u8;                  
    volatile  uint16_t   u16;                 
    volatile  uint32_t   u32;                 
  }  PORT [32U];                          
        uint32_t RESERVED0[864U];
  volatile uint32_t TER;                     
        uint32_t RESERVED1[15U];
  volatile uint32_t TPR;                     
        uint32_t RESERVED2[15U];
  volatile uint32_t TCR;                     
        uint32_t RESERVED3[29U];
  volatile  uint32_t IWR;                     
  volatile const  uint32_t IRR;                     
  volatile uint32_t IMCR;                    
        uint32_t RESERVED4[43U];
  volatile  uint32_t LAR;                     
  volatile const  uint32_t LSR;                     
        uint32_t RESERVED5[6U];
  volatile const  uint32_t PID4;                    
  volatile const  uint32_t PID5;                    
  volatile const  uint32_t PID6;                    
  volatile const  uint32_t PID7;                    
  volatile const  uint32_t PID0;                    
  volatile const  uint32_t PID1;                    
  volatile const  uint32_t PID2;                    
  volatile const  uint32_t PID3;                    
  volatile const  uint32_t CID0;                    
  volatile const  uint32_t CID1;                    
  volatile const  uint32_t CID2;                    
  volatile const  uint32_t CID3;                    
} ITM_Type;

 



 



























 



 



 



 









   







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t CYCCNT;                  
  volatile uint32_t CPICNT;                  
  volatile uint32_t EXCCNT;                  
  volatile uint32_t SLEEPCNT;                
  volatile uint32_t LSUCNT;                  
  volatile uint32_t FOLDCNT;                 
  volatile const  uint32_t PCSR;                    
  volatile uint32_t COMP0;                   
  volatile uint32_t MASK0;                   
  volatile uint32_t FUNCTION0;               
        uint32_t RESERVED0[1U];
  volatile uint32_t COMP1;                   
  volatile uint32_t MASK1;                   
  volatile uint32_t FUNCTION1;               
        uint32_t RESERVED1[1U];
  volatile uint32_t COMP2;                   
  volatile uint32_t MASK2;                   
  volatile uint32_t FUNCTION2;               
        uint32_t RESERVED2[1U];
  volatile uint32_t COMP3;                   
  volatile uint32_t MASK3;                   
  volatile uint32_t FUNCTION3;               
} DWT_Type;

 






















































 



 



 



 



 



 



 



























   







 



 
typedef struct
{
  volatile uint32_t SSPSR;                   
  volatile uint32_t CSPSR;                   
        uint32_t RESERVED0[2U];
  volatile uint32_t ACPR;                    
        uint32_t RESERVED1[55U];
  volatile uint32_t SPPR;                    
        uint32_t RESERVED2[131U];
  volatile const  uint32_t FFSR;                    
  volatile uint32_t FFCR;                    
  volatile const  uint32_t FSCR;                    
        uint32_t RESERVED3[759U];
  volatile const  uint32_t TRIGGER;                 
  volatile const  uint32_t FIFO0;                   
  volatile const  uint32_t ITATBCTR2;               
        uint32_t RESERVED4[1U];
  volatile const  uint32_t ITATBCTR0;               
  volatile const  uint32_t FIFO1;                   
  volatile uint32_t ITCTRL;                  
        uint32_t RESERVED5[39U];
  volatile uint32_t CLAIMSET;                
  volatile uint32_t CLAIMCLR;                
        uint32_t RESERVED7[8U];
  volatile const  uint32_t DEVID;                   
  volatile const  uint32_t DEVTYPE;                 
} TPI_Type;

 



 



 












 






 



 





















 



 





















 



 



 


















 






   


#line 1223 ".\\Core\\Inc\\core_cm3.h"







 



 
typedef struct
{
  volatile uint32_t DHCSR;                   
  volatile  uint32_t DCRSR;                   
  volatile uint32_t DCRDR;                   
  volatile uint32_t DEMCR;                   
} CoreDebug_Type;

 




































 






 







































 







 






 







 


 







 

 
#line 1372 ".\\Core\\Inc\\core_cm3.h"

#line 1381 ".\\Core\\Inc\\core_cm3.h"






 










 


 



 





 









 
static __inline void NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);              

  reg_value  =  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR;                                                    
  reg_value &= ~((uint32_t)((0xFFFFUL << 16U) | (7UL << 8U)));  
  reg_value  =  (reg_value                                   |
                ((uint32_t)0x5FAUL << 16U) |
                (PriorityGroupTmp << 8U)                      );               
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR =  reg_value;
}






 
static __inline uint32_t NVIC_GetPriorityGrouping(void)
{
  return ((uint32_t)((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) >> 8U));
}






 
static __inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}






 
static __inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}








 
static __inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
}






 
static __inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}






 
static __inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}








 
static __inline uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
  return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IABR[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
}








 
static __inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) < 0)
  {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] = (uint8_t)((priority << (8U - 4U)) & (uint32_t)0xFFUL);
  }
  else
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)(int32_t)IRQn)]               = (uint8_t)((priority << (8U - 4U)) & (uint32_t)0xFFUL);
  }
}










 
static __inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) < 0)
  {
    return(((uint32_t)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] >> (8U - 4U)));
  }
  else
  {
    return(((uint32_t)((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)(int32_t)IRQn)]               >> (8U - 4U)));
  }
}












 
static __inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);    
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4U)) ? (uint32_t)(4U) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(4U)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4U));

  return (
           ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
           ((SubPriority     & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL)))
         );
}












 
static __inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* const pPreemptPriority, uint32_t* const pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);    
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4U)) ? (uint32_t)(4U) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(4U)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4U));

  *pPreemptPriority = (Priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
  *pSubPriority     = (Priority                   ) & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL);
}





 
static __inline void NVIC_SystemReset(void)
{
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                          
 
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR  = (uint32_t)((0x5FAUL << 16U)    |
                           (((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) |
                            (1UL << 2U)    );          
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                           

  for(;;)                                                            
  {
    __nop();
  }
}

 



 





 













 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > (0xFFFFFFUL ))
  {
    return (1UL);                                                    
  }

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD  = (uint32_t)(ticks - 1UL);                          
  NVIC_SetPriority (SysTick_IRQn, (1UL << 4U) - 1UL);  
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL   = 0UL;                                              
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL  = (1UL << 2U) |
                   (1UL << 1U)   |
                   (1UL );                          
  return (0UL);                                                      
}



 



 





 

extern volatile int32_t ITM_RxBuffer;                     










 
static __inline uint32_t ITM_SendChar (uint32_t ch)
{
  if (((((ITM_Type *) (0xE0000000UL) )->TCR & (1UL )) != 0UL) &&       
      ((((ITM_Type *) (0xE0000000UL) )->TER & 1UL               ) != 0UL)   )      
  {
    while (((ITM_Type *) (0xE0000000UL) )->PORT[0U].u32 == 0UL)
    {
      __nop();
    }
    ((ITM_Type *) (0xE0000000UL) )->PORT[0U].u8 = (uint8_t)ch;
  }
  return (ch);
}







 
static __inline int32_t ITM_ReceiveChar (void)
{
  int32_t ch = -1;                            

  if (ITM_RxBuffer != 0x5AA55AA5U)
  {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = 0x5AA55AA5U;        
  }

  return (ch);
}







 
static __inline int32_t ITM_CheckChar (void)
{

  if (ITM_RxBuffer == 0x5AA55AA5U)
  {
    return (0);                               
  }
  else
  {
    return (1);                               
  }
}

 










#line 168 ".\\Core\\Inc\\stm32f103xe.h"
#line 1 ".\\Core\\Inc\\system_stm32f1xx.h"



































 



 



   
  


 









 



 




 

extern uint32_t SystemCoreClock;           
extern const uint8_t  AHBPrescTable[16U];   
extern const uint8_t  APBPrescTable[8U];    



 



 



 



 



 



 
  
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);


 









 
  


   
 
#line 169 ".\\Core\\Inc\\stm32f103xe.h"
#line 170 ".\\Core\\Inc\\stm32f103xe.h"



    



 

typedef struct
{
  volatile uint32_t SR;
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMPR1;
  volatile uint32_t SMPR2;
  volatile uint32_t JOFR1;
  volatile uint32_t JOFR2;
  volatile uint32_t JOFR3;
  volatile uint32_t JOFR4;
  volatile uint32_t HTR;
  volatile uint32_t LTR;
  volatile uint32_t SQR1;
  volatile uint32_t SQR2;
  volatile uint32_t SQR3;
  volatile uint32_t JSQR;
  volatile uint32_t JDR1;
  volatile uint32_t JDR2;
  volatile uint32_t JDR3;
  volatile uint32_t JDR4;
  volatile uint32_t DR;
} ADC_TypeDef;

typedef struct
{
  volatile uint32_t SR;                
  volatile uint32_t CR1;               
  volatile uint32_t CR2;               
  uint32_t  RESERVED[16];
  volatile uint32_t DR;                
} ADC_Common_TypeDef;



 

typedef struct
{
  uint32_t  RESERVED0;
  volatile uint32_t DR1;
  volatile uint32_t DR2;
  volatile uint32_t DR3;
  volatile uint32_t DR4;
  volatile uint32_t DR5;
  volatile uint32_t DR6;
  volatile uint32_t DR7;
  volatile uint32_t DR8;
  volatile uint32_t DR9;
  volatile uint32_t DR10;
  volatile uint32_t RTCCR;
  volatile uint32_t CR;
  volatile uint32_t CSR;
  uint32_t  RESERVED13[2];
  volatile uint32_t DR11;
  volatile uint32_t DR12;
  volatile uint32_t DR13;
  volatile uint32_t DR14;
  volatile uint32_t DR15;
  volatile uint32_t DR16;
  volatile uint32_t DR17;
  volatile uint32_t DR18;
  volatile uint32_t DR19;
  volatile uint32_t DR20;
  volatile uint32_t DR21;
  volatile uint32_t DR22;
  volatile uint32_t DR23;
  volatile uint32_t DR24;
  volatile uint32_t DR25;
  volatile uint32_t DR26;
  volatile uint32_t DR27;
  volatile uint32_t DR28;
  volatile uint32_t DR29;
  volatile uint32_t DR30;
  volatile uint32_t DR31;
  volatile uint32_t DR32;
  volatile uint32_t DR33;
  volatile uint32_t DR34;
  volatile uint32_t DR35;
  volatile uint32_t DR36;
  volatile uint32_t DR37;
  volatile uint32_t DR38;
  volatile uint32_t DR39;
  volatile uint32_t DR40;
  volatile uint32_t DR41;
  volatile uint32_t DR42;
} BKP_TypeDef;
  


 

typedef struct
{
  volatile uint32_t TIR;
  volatile uint32_t TDTR;
  volatile uint32_t TDLR;
  volatile uint32_t TDHR;
} CAN_TxMailBox_TypeDef;



 
  
typedef struct
{
  volatile uint32_t RIR;
  volatile uint32_t RDTR;
  volatile uint32_t RDLR;
  volatile uint32_t RDHR;
} CAN_FIFOMailBox_TypeDef;



 
  
typedef struct
{
  volatile uint32_t FR1;
  volatile uint32_t FR2;
} CAN_FilterRegister_TypeDef;



 
  
typedef struct
{
  volatile uint32_t MCR;
  volatile uint32_t MSR;
  volatile uint32_t TSR;
  volatile uint32_t RF0R;
  volatile uint32_t RF1R;
  volatile uint32_t IER;
  volatile uint32_t ESR;
  volatile uint32_t BTR;
  uint32_t  RESERVED0[88];
  CAN_TxMailBox_TypeDef sTxMailBox[3];
  CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
  uint32_t  RESERVED1[12];
  volatile uint32_t FMR;
  volatile uint32_t FM1R;
  uint32_t  RESERVED2;
  volatile uint32_t FS1R;
  uint32_t  RESERVED3;
  volatile uint32_t FFA1R;
  uint32_t  RESERVED4;
  volatile uint32_t FA1R;
  uint32_t  RESERVED5[8];
  CAN_FilterRegister_TypeDef sFilterRegister[14];
} CAN_TypeDef;



 

typedef struct
{
  volatile uint32_t DR;            
  volatile uint8_t  IDR;           
  uint8_t       RESERVED0;     
  uint16_t      RESERVED1;       
  volatile uint32_t CR;             
} CRC_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SWTRIGR;
  volatile uint32_t DHR12R1;
  volatile uint32_t DHR12L1;
  volatile uint32_t DHR8R1;
  volatile uint32_t DHR12R2;
  volatile uint32_t DHR12L2;
  volatile uint32_t DHR8R2;
  volatile uint32_t DHR12RD;
  volatile uint32_t DHR12LD;
  volatile uint32_t DHR8RD;
  volatile uint32_t DOR1;
  volatile uint32_t DOR2;
} DAC_TypeDef;



 

typedef struct
{
  volatile uint32_t IDCODE;
  volatile uint32_t CR;
}DBGMCU_TypeDef;



 

typedef struct
{
  volatile uint32_t CCR;
  volatile uint32_t CNDTR;
  volatile uint32_t CPAR;
  volatile uint32_t CMAR;
} DMA_Channel_TypeDef;

typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t IFCR;
} DMA_TypeDef;





 

typedef struct
{
  volatile uint32_t IMR;
  volatile uint32_t EMR;
  volatile uint32_t RTSR;
  volatile uint32_t FTSR;
  volatile uint32_t SWIER;
  volatile uint32_t PR;
} EXTI_TypeDef;



 

typedef struct
{
  volatile uint32_t ACR;
  volatile uint32_t KEYR;
  volatile uint32_t OPTKEYR;
  volatile uint32_t SR;
  volatile uint32_t CR;
  volatile uint32_t AR;
  volatile uint32_t RESERVED;
  volatile uint32_t OBR;
  volatile uint32_t WRPR;
} FLASH_TypeDef;



 
  
typedef struct
{
  volatile uint16_t RDP;
  volatile uint16_t USER;
  volatile uint16_t Data0;
  volatile uint16_t Data1;
  volatile uint16_t WRP0;
  volatile uint16_t WRP1;
  volatile uint16_t WRP2;
  volatile uint16_t WRP3;
} OB_TypeDef;



 

typedef struct
{
  volatile uint32_t BTCR[8];   
} FSMC_Bank1_TypeDef; 



 
  
typedef struct
{
  volatile uint32_t BWTR[7];
} FSMC_Bank1E_TypeDef;



 
  
typedef struct
{
  volatile uint32_t PCR2;        
  volatile uint32_t SR2;         
  volatile uint32_t PMEM2;       
  volatile uint32_t PATT2;       
  uint32_t      RESERVED0;   
  volatile uint32_t ECCR2;       
  uint32_t      RESERVED1;   
  uint32_t      RESERVED2;   
  volatile uint32_t PCR3;        
  volatile uint32_t SR3;         
  volatile uint32_t PMEM3;       
  volatile uint32_t PATT3;       
  uint32_t      RESERVED3;   
  volatile uint32_t ECCR3;       
} FSMC_Bank2_3_TypeDef;  



 
  
typedef struct
{
  volatile uint32_t PCR4;
  volatile uint32_t SR4;
  volatile uint32_t PMEM4;
  volatile uint32_t PATT4;
  volatile uint32_t PIO4; 
} FSMC_Bank4_TypeDef; 



 

typedef struct
{
  volatile uint32_t CRL;
  volatile uint32_t CRH;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t BRR;
  volatile uint32_t LCKR;
} GPIO_TypeDef;



 

typedef struct
{
  volatile uint32_t EVCR;
  volatile uint32_t MAPR;
  volatile uint32_t EXTICR[4];
  uint32_t RESERVED0;
  volatile uint32_t MAPR2;  
} AFIO_TypeDef;


 

typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t OAR1;
  volatile uint32_t OAR2;
  volatile uint32_t DR;
  volatile uint32_t SR1;
  volatile uint32_t SR2;
  volatile uint32_t CCR;
  volatile uint32_t TRISE;
} I2C_TypeDef;



 

typedef struct
{
  volatile uint32_t KR;            
  volatile uint32_t PR;            
  volatile uint32_t RLR;           
  volatile uint32_t SR;            
} IWDG_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CSR;
} PWR_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFGR;
  volatile uint32_t CIR;
  volatile uint32_t APB2RSTR;
  volatile uint32_t APB1RSTR;
  volatile uint32_t AHBENR;
  volatile uint32_t APB2ENR;
  volatile uint32_t APB1ENR;
  volatile uint32_t BDCR;
  volatile uint32_t CSR;


} RCC_TypeDef;



 

typedef struct
{
  volatile uint32_t CRH;
  volatile uint32_t CRL;
  volatile uint32_t PRLH;
  volatile uint32_t PRLL;
  volatile uint32_t DIVH;
  volatile uint32_t DIVL;
  volatile uint32_t CNTH;
  volatile uint32_t CNTL;
  volatile uint32_t ALRH;
  volatile uint32_t ALRL;
} RTC_TypeDef;



 

typedef struct
{
  volatile uint32_t POWER;
  volatile uint32_t CLKCR;
  volatile uint32_t ARG;
  volatile uint32_t CMD;
  volatile const uint32_t RESPCMD;
  volatile const uint32_t RESP1;
  volatile const uint32_t RESP2;
  volatile const uint32_t RESP3;
  volatile const uint32_t RESP4;
  volatile uint32_t DTIMER;
  volatile uint32_t DLEN;
  volatile uint32_t DCTRL;
  volatile const uint32_t DCOUNT;
  volatile const uint32_t STA;
  volatile uint32_t ICR;
  volatile uint32_t MASK;
  uint32_t  RESERVED0[2];
  volatile const uint32_t FIFOCNT;
  uint32_t  RESERVED1[13];
  volatile uint32_t FIFO;
} SDIO_TypeDef;



 

typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SR;
  volatile uint32_t DR;
  volatile uint32_t CRCPR;
  volatile uint32_t RXCRCR;
  volatile uint32_t TXCRCR;
  volatile uint32_t I2SCFGR;
  volatile uint32_t I2SPR;
} SPI_TypeDef;



 
typedef struct
{
  volatile uint32_t CR1;              
  volatile uint32_t CR2;              
  volatile uint32_t SMCR;             
  volatile uint32_t DIER;             
  volatile uint32_t SR;               
  volatile uint32_t EGR;              
  volatile uint32_t CCMR1;            
  volatile uint32_t CCMR2;            
  volatile uint32_t CCER;             
  volatile uint32_t CNT;              
  volatile uint32_t PSC;              
  volatile uint32_t ARR;              
  volatile uint32_t RCR;              
  volatile uint32_t CCR1;             
  volatile uint32_t CCR2;             
  volatile uint32_t CCR3;             
  volatile uint32_t CCR4;             
  volatile uint32_t BDTR;             
  volatile uint32_t DCR;              
  volatile uint32_t DMAR;             
  volatile uint32_t OR;               
}TIM_TypeDef;




 
 
typedef struct
{
  volatile uint32_t SR;          
  volatile uint32_t DR;          
  volatile uint32_t BRR;         
  volatile uint32_t CR1;         
  volatile uint32_t CR2;         
  volatile uint32_t CR3;         
  volatile uint32_t GTPR;        
} USART_TypeDef;



 
  
typedef struct
{
  volatile uint16_t EP0R;                   
  volatile uint16_t RESERVED0;                  
  volatile uint16_t EP1R;                  
  volatile uint16_t RESERVED1;                    
  volatile uint16_t EP2R;                  
  volatile uint16_t RESERVED2;                    
  volatile uint16_t EP3R;                   
  volatile uint16_t RESERVED3;                    
  volatile uint16_t EP4R;                  
  volatile uint16_t RESERVED4;                    
  volatile uint16_t EP5R;                  
  volatile uint16_t RESERVED5;                    
  volatile uint16_t EP6R;                  
  volatile uint16_t RESERVED6;                    
  volatile uint16_t EP7R;                  
  volatile uint16_t RESERVED7[17];              
  volatile uint16_t CNTR;                  
  volatile uint16_t RESERVED8;                    
  volatile uint16_t ISTR;                  
  volatile uint16_t RESERVED9;                    
  volatile uint16_t FNR;                   
  volatile uint16_t RESERVEDA;                    
  volatile uint16_t DADDR;                 
  volatile uint16_t RESERVEDB;                    
  volatile uint16_t BTABLE;                
  volatile uint16_t RESERVEDC;                    
} USB_TypeDef;




 

typedef struct
{
  volatile uint32_t CR;    
  volatile uint32_t CFR;   
  volatile uint32_t SR;    
} WWDG_TypeDef;



 
  


 













 




#line 796 ".\\Core\\Inc\\stm32f103xe.h"



#line 815 ".\\Core\\Inc\\stm32f103xe.h"
























 






 
  


   

#line 916 ".\\Core\\Inc\\stm32f103xe.h"




 



 
  
  

 
    
 
 
 

 
 
 
 
 

 




 




 




 
 
 
 
 

 
#line 977 ".\\Core\\Inc\\stm32f103xe.h"

#line 984 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 994 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 1004 ".\\Core\\Inc\\stm32f103xe.h"






 
#line 1023 ".\\Core\\Inc\\stm32f103xe.h"

 
 
 
 
 

 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 






 
#line 1255 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 1263 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 1280 ".\\Core\\Inc\\stm32f103xe.h"

 
 
 
 
 

 
#line 1318 ".\\Core\\Inc\\stm32f103xe.h"


 
 










 










 
#line 1351 ".\\Core\\Inc\\stm32f103xe.h"

#line 1361 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 1369 ".\\Core\\Inc\\stm32f103xe.h"







 
#line 1383 ".\\Core\\Inc\\stm32f103xe.h"







 



















 
#line 1418 ".\\Core\\Inc\\stm32f103xe.h"




#line 1468 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 1476 ".\\Core\\Inc\\stm32f103xe.h"







  
#line 1493 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 1546 ".\\Core\\Inc\\stm32f103xe.h"


 
#line 1567 ".\\Core\\Inc\\stm32f103xe.h"





#line 1581 ".\\Core\\Inc\\stm32f103xe.h"






#line 1599 ".\\Core\\Inc\\stm32f103xe.h"



 
#line 1618 ".\\Core\\Inc\\stm32f103xe.h"





#line 1629 ".\\Core\\Inc\\stm32f103xe.h"

#line 1642 ".\\Core\\Inc\\stm32f103xe.h"





#line 1665 ".\\Core\\Inc\\stm32f103xe.h"








 
#line 1686 ".\\Core\\Inc\\stm32f103xe.h"





#line 1697 ".\\Core\\Inc\\stm32f103xe.h"


 
#line 1718 ".\\Core\\Inc\\stm32f103xe.h"





#line 1732 ".\\Core\\Inc\\stm32f103xe.h"






#line 1750 ".\\Core\\Inc\\stm32f103xe.h"



 
#line 1769 ".\\Core\\Inc\\stm32f103xe.h"





#line 1780 ".\\Core\\Inc\\stm32f103xe.h"

#line 1793 ".\\Core\\Inc\\stm32f103xe.h"





#line 1816 ".\\Core\\Inc\\stm32f103xe.h"








 
#line 1834 ".\\Core\\Inc\\stm32f103xe.h"







 





#line 1853 ".\\Core\\Inc\\stm32f103xe.h"

   
#line 1882 ".\\Core\\Inc\\stm32f103xe.h"


 
 
 
 
 
 

 








































































































 








































































































 
#line 2150 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2200 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2250 ".\\Core\\Inc\\stm32f103xe.h"

#line 2299 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2349 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2402 ".\\Core\\Inc\\stm32f103xe.h"

 

 
#line 2413 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2461 ".\\Core\\Inc\\stm32f103xe.h"

#line 2468 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2483 ".\\Core\\Inc\\stm32f103xe.h"





 
#line 2501 ".\\Core\\Inc\\stm32f103xe.h"







 
#line 2516 ".\\Core\\Inc\\stm32f103xe.h"







 
#line 2531 ".\\Core\\Inc\\stm32f103xe.h"







 
#line 2549 ".\\Core\\Inc\\stm32f103xe.h"







 
#line 2564 ".\\Core\\Inc\\stm32f103xe.h"











 
#line 2583 ".\\Core\\Inc\\stm32f103xe.h"

#line 2602 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2610 ".\\Core\\Inc\\stm32f103xe.h"

#line 2621 ".\\Core\\Inc\\stm32f103xe.h"


 
#line 2636 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2657 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2678 ".\\Core\\Inc\\stm32f103xe.h"

   
#line 2699 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2720 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2734 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2755 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2776 ".\\Core\\Inc\\stm32f103xe.h"

   
#line 2797 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2818 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2832 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2853 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2874 ".\\Core\\Inc\\stm32f103xe.h"

   
#line 2895 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2916 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2930 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2951 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 2972 ".\\Core\\Inc\\stm32f103xe.h"

   
#line 2993 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 3014 ".\\Core\\Inc\\stm32f103xe.h"

 






 
 
 
 
 

 
#line 3086 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 3108 ".\\Core\\Inc\\stm32f103xe.h"
 
 
#line 3167 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 3188 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 3247 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 3268 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 3327 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 3348 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 3407 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 3428 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 3487 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 3508 ".\\Core\\Inc\\stm32f103xe.h"

 
 
 
 
 

 
#line 3600 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 3686 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 3712 ".\\Core\\Inc\\stm32f103xe.h"























 




 




 




 
 
 
 
 



 


 
#line 3777 ".\\Core\\Inc\\stm32f103xe.h"

 



 
#line 3791 ".\\Core\\Inc\\stm32f103xe.h"

#line 3816 ".\\Core\\Inc\\stm32f103xe.h"

#line 3823 ".\\Core\\Inc\\stm32f103xe.h"

#line 3831 ".\\Core\\Inc\\stm32f103xe.h"

#line 3838 ".\\Core\\Inc\\stm32f103xe.h"

 



 
#line 3862 ".\\Core\\Inc\\stm32f103xe.h"

#line 3869 ".\\Core\\Inc\\stm32f103xe.h"





#line 3880 ".\\Core\\Inc\\stm32f103xe.h"

#line 3893 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 3901 ".\\Core\\Inc\\stm32f103xe.h"

#line 3908 ".\\Core\\Inc\\stm32f103xe.h"

#line 3915 ".\\Core\\Inc\\stm32f103xe.h"

#line 3922 ".\\Core\\Inc\\stm32f103xe.h"

#line 3929 ".\\Core\\Inc\\stm32f103xe.h"

#line 3936 ".\\Core\\Inc\\stm32f103xe.h"

#line 3943 ".\\Core\\Inc\\stm32f103xe.h"

#line 3950 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 3958 ".\\Core\\Inc\\stm32f103xe.h"

#line 3965 ".\\Core\\Inc\\stm32f103xe.h"

#line 3972 ".\\Core\\Inc\\stm32f103xe.h"

#line 3979 ".\\Core\\Inc\\stm32f103xe.h"

#line 3986 ".\\Core\\Inc\\stm32f103xe.h"

#line 3993 ".\\Core\\Inc\\stm32f103xe.h"

#line 4000 ".\\Core\\Inc\\stm32f103xe.h"

#line 4007 ".\\Core\\Inc\\stm32f103xe.h"

#line 4014 ".\\Core\\Inc\\stm32f103xe.h"

#line 4021 ".\\Core\\Inc\\stm32f103xe.h"

 




 




 




 




 




 




 
#line 4061 ".\\Core\\Inc\\stm32f103xe.h"

#line 4070 ".\\Core\\Inc\\stm32f103xe.h"

#line 4079 ".\\Core\\Inc\\stm32f103xe.h"

#line 4088 ".\\Core\\Inc\\stm32f103xe.h"

#line 4096 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 4106 ".\\Core\\Inc\\stm32f103xe.h"

#line 4115 ".\\Core\\Inc\\stm32f103xe.h"

#line 4124 ".\\Core\\Inc\\stm32f103xe.h"

#line 4133 ".\\Core\\Inc\\stm32f103xe.h"

#line 4142 ".\\Core\\Inc\\stm32f103xe.h"

#line 4151 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 4161 ".\\Core\\Inc\\stm32f103xe.h"

#line 4170 ".\\Core\\Inc\\stm32f103xe.h"

#line 4179 ".\\Core\\Inc\\stm32f103xe.h"

#line 4188 ".\\Core\\Inc\\stm32f103xe.h"

#line 4197 ".\\Core\\Inc\\stm32f103xe.h"

#line 4206 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 4216 ".\\Core\\Inc\\stm32f103xe.h"

#line 4225 ".\\Core\\Inc\\stm32f103xe.h"

#line 4234 ".\\Core\\Inc\\stm32f103xe.h"

#line 4243 ".\\Core\\Inc\\stm32f103xe.h"







 




 




 




 




 
#line 4277 ".\\Core\\Inc\\stm32f103xe.h"
 
 
 
 
 

 
#line 4293 ".\\Core\\Inc\\stm32f103xe.h"

#line 4300 ".\\Core\\Inc\\stm32f103xe.h"







#line 4314 ".\\Core\\Inc\\stm32f103xe.h"

#line 4327 ".\\Core\\Inc\\stm32f103xe.h"

#line 4334 ".\\Core\\Inc\\stm32f103xe.h"







#line 4348 ".\\Core\\Inc\\stm32f103xe.h"






 
#line 4361 ".\\Core\\Inc\\stm32f103xe.h"

 




 




 




 




 




 




 
#line 4399 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 4407 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 4415 ".\\Core\\Inc\\stm32f103xe.h"

 




 






 
 
 
 
 
 
#line 4449 ".\\Core\\Inc\\stm32f103xe.h"

















 
#line 4476 ".\\Core\\Inc\\stm32f103xe.h"

#line 4483 ".\\Core\\Inc\\stm32f103xe.h"

#line 4508 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 4516 ".\\Core\\Inc\\stm32f103xe.h"

#line 4523 ".\\Core\\Inc\\stm32f103xe.h"





#line 4535 ".\\Core\\Inc\\stm32f103xe.h"







#line 4548 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 4595 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 4633 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 4659 ".\\Core\\Inc\\stm32f103xe.h"

 






#line 4673 ".\\Core\\Inc\\stm32f103xe.h"

#line 4680 ".\\Core\\Inc\\stm32f103xe.h"











#line 4697 ".\\Core\\Inc\\stm32f103xe.h"

#line 4704 ".\\Core\\Inc\\stm32f103xe.h"





 







#line 4724 ".\\Core\\Inc\\stm32f103xe.h"







#line 4738 ".\\Core\\Inc\\stm32f103xe.h"

 






#line 4752 ".\\Core\\Inc\\stm32f103xe.h"

#line 4759 ".\\Core\\Inc\\stm32f103xe.h"











#line 4776 ".\\Core\\Inc\\stm32f103xe.h"

#line 4783 ".\\Core\\Inc\\stm32f103xe.h"





 







#line 4803 ".\\Core\\Inc\\stm32f103xe.h"







#line 4817 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 4861 ".\\Core\\Inc\\stm32f103xe.h"

 




 




 




 




 




 




 




 




 
#line 4914 ".\\Core\\Inc\\stm32f103xe.h"







#line 4939 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 4949 ".\\Core\\Inc\\stm32f103xe.h"

#line 4958 ".\\Core\\Inc\\stm32f103xe.h"

 




 
 
 
 
 

 
#line 4980 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 5000 ".\\Core\\Inc\\stm32f103xe.h"

 




 




 




 




 




 




 




 




 
 
 
 
 

 




 
#line 5059 ".\\Core\\Inc\\stm32f103xe.h"

 




 
#line 5072 ".\\Core\\Inc\\stm32f103xe.h"

 
 
 
 
 

 
#line 5090 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 5099 ".\\Core\\Inc\\stm32f103xe.h"





 
#line 5115 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 5124 ".\\Core\\Inc\\stm32f103xe.h"







 







 




 
 
 
 
 

 
#line 5157 ".\\Core\\Inc\\stm32f103xe.h"













#line 5200 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 5209 ".\\Core\\Inc\\stm32f103xe.h"

#line 5217 ".\\Core\\Inc\\stm32f103xe.h"

#line 5229 ".\\Core\\Inc\\stm32f103xe.h"

#line 5237 ".\\Core\\Inc\\stm32f103xe.h"

#line 5245 ".\\Core\\Inc\\stm32f103xe.h"

#line 5253 ".\\Core\\Inc\\stm32f103xe.h"







 
#line 5268 ".\\Core\\Inc\\stm32f103xe.h"

#line 5276 ".\\Core\\Inc\\stm32f103xe.h"

#line 5288 ".\\Core\\Inc\\stm32f103xe.h"

#line 5296 ".\\Core\\Inc\\stm32f103xe.h"







 
#line 5313 ".\\Core\\Inc\\stm32f103xe.h"











#line 5331 ".\\Core\\Inc\\stm32f103xe.h"

#line 5339 ".\\Core\\Inc\\stm32f103xe.h"

#line 5346 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 5369 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 5382 ".\\Core\\Inc\\stm32f103xe.h"

#line 5394 ".\\Core\\Inc\\stm32f103xe.h"

#line 5406 ".\\Core\\Inc\\stm32f103xe.h"

#line 5418 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 5431 ".\\Core\\Inc\\stm32f103xe.h"

#line 5443 ".\\Core\\Inc\\stm32f103xe.h"

#line 5455 ".\\Core\\Inc\\stm32f103xe.h"

#line 5467 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 5480 ".\\Core\\Inc\\stm32f103xe.h"

#line 5492 ".\\Core\\Inc\\stm32f103xe.h"

#line 5504 ".\\Core\\Inc\\stm32f103xe.h"

#line 5516 ".\\Core\\Inc\\stm32f103xe.h"

 




 




 
 
 
 
 

 






 
#line 5553 ".\\Core\\Inc\\stm32f103xe.h"







#line 5566 ".\\Core\\Inc\\stm32f103xe.h"

 




 










#line 5604 ".\\Core\\Inc\\stm32f103xe.h"

 




 




 




 




 




 




 




 




 
#line 5658 ".\\Core\\Inc\\stm32f103xe.h"

#line 5666 ".\\Core\\Inc\\stm32f103xe.h"

#line 5679 ".\\Core\\Inc\\stm32f103xe.h"

 




 
#line 5758 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 5799 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 5873 ".\\Core\\Inc\\stm32f103xe.h"

 




 




 
 
 
 
 

 
#line 5899 ".\\Core\\Inc\\stm32f103xe.h"

  
#line 5931 ".\\Core\\Inc\\stm32f103xe.h"

 

                                                                            
#line 5943 ".\\Core\\Inc\\stm32f103xe.h"


                                                                                
#line 5953 ".\\Core\\Inc\\stm32f103xe.h"
                                                                                
#line 5961 ".\\Core\\Inc\\stm32f103xe.h"

 










#line 5982 ".\\Core\\Inc\\stm32f103xe.h"
                                                                           
















#line 6005 ".\\Core\\Inc\\stm32f103xe.h"

 



                                                                          






#line 6026 ".\\Core\\Inc\\stm32f103xe.h"










                                                                           






#line 6049 ".\\Core\\Inc\\stm32f103xe.h"

 










#line 6070 ".\\Core\\Inc\\stm32f103xe.h"

















#line 6093 ".\\Core\\Inc\\stm32f103xe.h"

 










#line 6114 ".\\Core\\Inc\\stm32f103xe.h"

















#line 6137 ".\\Core\\Inc\\stm32f103xe.h"

 










#line 6158 ".\\Core\\Inc\\stm32f103xe.h"

















#line 6181 ".\\Core\\Inc\\stm32f103xe.h"

 










#line 6202 ".\\Core\\Inc\\stm32f103xe.h"

















#line 6225 ".\\Core\\Inc\\stm32f103xe.h"

 










#line 6246 ".\\Core\\Inc\\stm32f103xe.h"

















#line 6269 ".\\Core\\Inc\\stm32f103xe.h"

 










#line 6290 ".\\Core\\Inc\\stm32f103xe.h"

















#line 6313 ".\\Core\\Inc\\stm32f103xe.h"

 
 
#line 6355 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 6387 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 6404 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 6430 ".\\Core\\Inc\\stm32f103xe.h"





     




 
 




 




 




 




 




 




 




 




 

 




 




 




 




 




 




 




 




 

 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 

 




 




 




 




 




 




 




 




 

 




#line 6630 ".\\Core\\Inc\\stm32f103xe.h"





 




#line 6648 ".\\Core\\Inc\\stm32f103xe.h"





 




#line 6666 ".\\Core\\Inc\\stm32f103xe.h"





 




#line 6684 ".\\Core\\Inc\\stm32f103xe.h"





 




#line 6702 ".\\Core\\Inc\\stm32f103xe.h"





 




#line 6720 ".\\Core\\Inc\\stm32f103xe.h"





 




#line 6738 ".\\Core\\Inc\\stm32f103xe.h"





 




#line 6756 ".\\Core\\Inc\\stm32f103xe.h"





 

 


#line 6772 ".\\Core\\Inc\\stm32f103xe.h"



 


#line 6784 ".\\Core\\Inc\\stm32f103xe.h"



 


#line 6796 ".\\Core\\Inc\\stm32f103xe.h"



 


#line 6808 ".\\Core\\Inc\\stm32f103xe.h"



 


#line 6820 ".\\Core\\Inc\\stm32f103xe.h"



 


#line 6832 ".\\Core\\Inc\\stm32f103xe.h"



 


#line 6844 ".\\Core\\Inc\\stm32f103xe.h"



 


#line 6856 ".\\Core\\Inc\\stm32f103xe.h"



 


#line 6868 ".\\Core\\Inc\\stm32f103xe.h"



 


#line 6880 ".\\Core\\Inc\\stm32f103xe.h"



 


#line 6892 ".\\Core\\Inc\\stm32f103xe.h"



 


#line 6904 ".\\Core\\Inc\\stm32f103xe.h"



 


#line 6916 ".\\Core\\Inc\\stm32f103xe.h"



 


#line 6928 ".\\Core\\Inc\\stm32f103xe.h"



 


#line 6940 ".\\Core\\Inc\\stm32f103xe.h"



 


#line 6952 ".\\Core\\Inc\\stm32f103xe.h"



 
 
 
 
 

 
 
#line 6993 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7022 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7072 ".\\Core\\Inc\\stm32f103xe.h"

#line 7085 ".\\Core\\Inc\\stm32f103xe.h"

#line 7098 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7112 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7126 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7170 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7181 ".\\Core\\Inc\\stm32f103xe.h"

#line 7188 ".\\Core\\Inc\\stm32f103xe.h"

#line 7195 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7224 ".\\Core\\Inc\\stm32f103xe.h"

 
 
#line 7242 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7253 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7267 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7281 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7298 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7309 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7323 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7337 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7354 ".\\Core\\Inc\\stm32f103xe.h"

   
#line 7365 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7379 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7393 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7407 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7418 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7432 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7446 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7460 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7471 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7485 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7499 ".\\Core\\Inc\\stm32f103xe.h"

 
 
#line 7508 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7555 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7602 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7649 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7696 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7794 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7892 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 7990 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 8088 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 8186 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 8284 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 8382 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 8480 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 8578 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 8676 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 8774 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 8872 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 8970 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 9068 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 9166 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 9264 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 9362 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 9460 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 9558 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 9656 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 9754 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 9852 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 9950 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 10048 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 10146 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 10244 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 10342 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 10440 ".\\Core\\Inc\\stm32f103xe.h"

 
 
 
 
 


 

 
#line 10460 ".\\Core\\Inc\\stm32f103xe.h"

#line 10467 ".\\Core\\Inc\\stm32f103xe.h"

#line 10498 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 10518 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 10544 ".\\Core\\Inc\\stm32f103xe.h"

 




 




 




 




 






























#line 10602 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 10613 ".\\Core\\Inc\\stm32f103xe.h"

 
 
 
 
 

 
#line 10663 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 10674 ".\\Core\\Inc\\stm32f103xe.h"

#line 10690 ".\\Core\\Inc\\stm32f103xe.h"

 



#line 10725 ".\\Core\\Inc\\stm32f103xe.h"





 
#line 10737 ".\\Core\\Inc\\stm32f103xe.h"

 




 
#line 10786 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 10812 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 10823 ".\\Core\\Inc\\stm32f103xe.h"

 




 
 
 
 
 

 
#line 10866 ".\\Core\\Inc\\stm32f103xe.h"

 




 
#line 10879 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 10923 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 10946 ".\\Core\\Inc\\stm32f103xe.h"











 
#line 10991 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 11004 ".\\Core\\Inc\\stm32f103xe.h"





 
 
 
 
 

 




#line 11039 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 11053 ".\\Core\\Inc\\stm32f103xe.h"







#line 11099 ".\\Core\\Inc\\stm32f103xe.h"

 
 
 
 
 
 
#line 11112 ".\\Core\\Inc\\stm32f103xe.h"

#line 11122 ".\\Core\\Inc\\stm32f103xe.h"

 




#line 11137 ".\\Core\\Inc\\stm32f103xe.h"

 







 
#line 11159 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 11191 ".\\Core\\Inc\\stm32f103xe.h"

 




 
#line 11204 ".\\Core\\Inc\\stm32f103xe.h"

#line 11223 ".\\Core\\Inc\\stm32f103xe.h"

 




 

 
#line 11238 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 11246 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 11254 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 11262 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 11270 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 11278 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 11286 ".\\Core\\Inc\\stm32f103xe.h"

 
#line 11294 ".\\Core\\Inc\\stm32f103xe.h"





 



  



 

 



                                       







     


 


 


 
#line 11343 ".\\Core\\Inc\\stm32f103xe.h"
  
 
#line 11352 ".\\Core\\Inc\\stm32f103xe.h"

 


 


 



 


 



 


 


 




 
 
#line 11392 ".\\Core\\Inc\\stm32f103xe.h"





#line 11404 ".\\Core\\Inc\\stm32f103xe.h"

#line 11412 ".\\Core\\Inc\\stm32f103xe.h"

#line 11420 ".\\Core\\Inc\\stm32f103xe.h"

#line 11428 ".\\Core\\Inc\\stm32f103xe.h"

#line 11436 ".\\Core\\Inc\\stm32f103xe.h"

#line 11444 ".\\Core\\Inc\\stm32f103xe.h"

#line 11452 ".\\Core\\Inc\\stm32f103xe.h"

#line 11460 ".\\Core\\Inc\\stm32f103xe.h"

#line 11468 ".\\Core\\Inc\\stm32f103xe.h"

#line 11476 ".\\Core\\Inc\\stm32f103xe.h"

#line 11484 ".\\Core\\Inc\\stm32f103xe.h"

#line 11494 ".\\Core\\Inc\\stm32f103xe.h"

#line 11502 ".\\Core\\Inc\\stm32f103xe.h"



#line 11512 ".\\Core\\Inc\\stm32f103xe.h"





#line 11553 ".\\Core\\Inc\\stm32f103xe.h"

#line 11564 ".\\Core\\Inc\\stm32f103xe.h"

#line 11572 ".\\Core\\Inc\\stm32f103xe.h"





#line 11584 ".\\Core\\Inc\\stm32f103xe.h"

#line 11594 ".\\Core\\Inc\\stm32f103xe.h"
    
#line 11602 ".\\Core\\Inc\\stm32f103xe.h"
    




#line 11613 ".\\Core\\Inc\\stm32f103xe.h"

#line 11620 ".\\Core\\Inc\\stm32f103xe.h"



 


                                            




 






 






 






                                     




 




 






 






 





 


 


 











  
 
 
 
 
  
 
 

 
#line 11734 ".\\Core\\Inc\\stm32f103xe.h"


 
#line 11761 ".\\Core\\Inc\\stm32f103xe.h"



 



 





  

  
  
  
   
#line 152 ".\\Core\\Inc\\stm32f1xx.h"
#line 161 ".\\Core\\Inc\\stm32f1xx.h"



 



   
typedef enum 
{
  RESET = 0, 
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum 
{
  DISABLE = 0, 
  ENABLE = !DISABLE
} FunctionalState;


typedef enum 
{
  ERROR = 0, 
  SUCCESS = !ERROR
} ErrorStatus;



 




 



















 













 



 
  



 
#line 6 "Core\\Src\\eeprom.c"
#line 7 "Core\\Src\\eeprom.c"
#line 1 ".\\Core\\Inc\\common.h"
 






    
#line 10 ".\\Core\\Inc\\common.h"
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdbool.h"
 






 





#line 25 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdbool.h"



#line 11 ".\\Core\\Inc\\common.h"
#line 12 ".\\Core\\Inc\\common.h"
	
#line 14 ".\\Core\\Inc\\common.h"





    
#line 30 ".\\Core\\Inc\\common.h"
    



typedef  void (*pFunction)(void);






typedef  void (*commandfunc)(uint8_t *command);

typedef struct
{
    GPIO_TypeDef *port;
    uint32_t pin;
    uint32_t clear;
    uint32_t set;
} GPIO_PINS_t;

typedef enum {
    STM32_FALSE = 0,
    STM32_SUCCESS
} BootState_t;

typedef struct
{
    uint16_t header;
    uint8_t confSrc[(10)];
    uint8_t statSrc[(10)];
    uint32_t version;
    uint16_t tail; 
} Bootargs_t;

typedef struct
{
    uint16_t header;
    uint16_t version;
    uint32_t size;
    uint16_t tail; 
} Imageargs_t;

typedef struct 
{
    uint8_t name[10];
    commandfunc func;
} cmdType_t;

void Error_Handle(void);


void delay(uint32_t val);
    

void GPIO_Init(void);


void USART_Init(void);
void USART_SendData(uint8_t *data, uint16_t len);
void uartprintf(const char* fmt, ...);


void FLASH_Lock(void);
void FLASH_Unlock(void);
void FLASH_Erase(uint32_t Add);
_Bool FLASH_WaitForFinish(void);
_Bool FLASH_Program(uint8_t *dest, uint8_t *src, uint32_t len);
void USART_RxProcess(uint8_t val);


void SPI_Init(void);
uint8_t SPI_Transmit(uint8_t *data, uint16_t size);
uint8_t SPI_TransmitReceive(uint8_t *txData, uint8_t *rxData, uint16_t size);


void EEPROM_Init(void);
void EEPROM_Read(uint32_t addr, uint8_t *buf, uint16_t len);
void EEPROM_Write(uint32_t addr, uint8_t * buf, uint16_t len);
void EEProm_SectorErrase(uint32_t addr);


void BootargsInit(void);
BootState_t autoboot(void);
void GetBootargFromDefault(void);
BootState_t GetBootargFromEEP(void);
void bootm(uint8_t *command);
void execute_command(uint8_t *command);
void AppJump(void);


void delay(uint32_t val);
    






 
#line 8 "Core\\Src\\eeprom.c"







 

 

 


static void wip(void);
static void wsr(void);
static void wen(void);
static void wdis(void);
static uint8_t rdsr(void);
static uint16_t SPI_Flash_ReadID(void);
static void EEPRom_SendByte(uint8_t byte);

 
 
 
static void EEPRom_SendByte(uint8_t byte)
{
    uint8_t val = byte;
    SPI_Transmit(&val, 1);
}

static uint16_t SPI_Flash_ReadID(void)
{
    uint8_t Temp = 0;
    uint8_t Ret = 0;
    uint16_t id = 0;
    (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | (0))));

    
    Temp = 0xAB;
    SPI_TransmitReceive(&Temp, &Ret, 1);

    Temp = 0x00;
    SPI_TransmitReceive(&Temp, &Ret, 1);

    Temp = 0x00;
    SPI_TransmitReceive(&Temp, &Ret, 1);

    Temp = 0x00;
    SPI_TransmitReceive(&Temp, &Ret, 1);

    
    Temp = 0xFF;
    SPI_TransmitReceive(&Temp, &Ret, 1);
    id = ((uint16_t) Ret) << 8;

    Temp = 0xFF;
    SPI_TransmitReceive(&Temp, &Ret, 1);
    id += (uint16_t) Ret;

    (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | ((0x1U << (4U))))));

    return id;
}

static uint8_t rdsr(void)
{
    uint8_t busy;

    (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | (0))));
    EEPRom_SendByte(0x05);
    SPI_TransmitReceive(&busy, &busy, 1);
    (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | ((0x1U << (4U))))));
    return (busy);
}

static void wip(void)
{
    uint8_t a = 1;
    while ((a & 0x01) == 1) a = rdsr();
}

static void wsr(void)
{
    (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | (0))));
    EEPRom_SendByte(0x50);
    (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | ((0x1U << (4U))))));

    (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | (0))));
    EEPRom_SendByte(0x01);
    EEPRom_SendByte(0x00);
    (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | ((0x1U << (4U))))));

    wip();
}

static void wen(void)
{
    (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | (0))));
    EEPRom_SendByte(0x06);
    (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | ((0x1U << (4U))))));
}

static void wdis(void)
{
    (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | (0))));
    EEPRom_SendByte(0x04);
    (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | ((0x1U << (4U))))));

    wip();
}

void EEProm_SectorErrase(uint32_t addr)
{
    wsr();
    wen();

    (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | (0))));
    EEPRom_SendByte(0x20);
    EEPRom_SendByte((uint8_t) ((addr & 0xffffff) >> 16)); 
    EEPRom_SendByte((uint8_t) ((addr & 0xffff) >> 8));    
    EEPRom_SendByte((uint8_t) (addr & 0xff)); 
    (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | ((0x1U << (4U))))));

    wip();
}

void EEPROM_Write(uint32_t addr, uint8_t * buf, uint16_t len)
{
    uint16_t i = 0, a2;

    wsr();
    wen();
    (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | (0))));
    EEPRom_SendByte(0xad);
    EEPRom_SendByte((uint8_t) ((addr & 0xffffff) >> 16));
    EEPRom_SendByte((uint8_t) ((addr & 0xffff) >> 8));
    EEPRom_SendByte((uint8_t) (addr & 0xff));
    EEPRom_SendByte(buf[0]);
    EEPRom_SendByte(buf[1]);
    (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | ((0x1U << (4U))))));

    i = 2;
    while (i < len) {
        a2 = 120;
        while (a2 > 0) a2--;

        (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | (0))));
        EEPRom_SendByte(0xad);
        EEPRom_SendByte(buf[i]);
        i++;
        EEPRom_SendByte(buf[i]);
        i++;
        (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | ((0x1U << (4U))))));
    }

    a2 = 100;
    while (a2 > 0) a2--;

    wdis();
    (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | (0))));
    wip();
}

void EEPROM_Read(uint32_t addr, uint8_t *buf, uint16_t len)
{
    uint16_t i = 0;

    (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | (0))));
    EEPRom_SendByte(0x0b);
    EEPRom_SendByte((uint8_t) ((addr & 0xffffff) >> 16));
    EEPRom_SendByte((uint8_t) ((addr & 0xffff) >> 8));
    EEPRom_SendByte((uint8_t) (addr & 0xff));
    EEPRom_SendByte(0);

    while (i < len) {
        SPI_TransmitReceive(&(buf[i]), &(buf[i]), 1);
        i++;
    }
    (((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR)) = ((((((((GPIO_TypeDef *)((0x40000000U + 0x00010000U) + 0x00000800U))->ODR))) & (~((0x1U << (4U))))) | ((0x1U << (4U))))));
}

 
 
 

void EEPROM_Init()
{
    uint8_t i;
    for (i=0;i<5;++i) {
        if (0xbf41 == SPI_Flash_ReadID()) {
            uartprintf("\r\n\r\nEEPROM initaion success\r\n");
            return;
        }
    }
    uartprintf("\r\n\r\nEEPROM initaion failed\r\n");
}
