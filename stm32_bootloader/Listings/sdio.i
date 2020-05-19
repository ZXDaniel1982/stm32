#line 1 "Core\\Src\\sdio.c"
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



 




 



















 













 



 
  



 
#line 2 "Core\\Src\\sdio.c"
#line 3 "Core\\Src\\sdio.c"
#line 1 ".\\Core\\Inc\\common.h"
 






    
#line 10 ".\\Core\\Inc\\common.h"
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdbool.h"
 






 





#line 25 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdbool.h"



#line 11 ".\\Core\\Inc\\common.h"
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"
 






 

 
 
 





 





#line 34 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"




  typedef signed int ptrdiff_t;



  



    typedef unsigned int size_t;    
#line 57 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



   



      typedef unsigned short wchar_t;  
#line 82 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



    




   




  typedef long double max_align_t;









#line 114 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



 

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
    






 
#line 4 "Core\\Src\\sdio.c"
#line 1 ".\\Core\\Inc\\stm32_sdio.h"




















 

 







 
#line 33 ".\\Core\\Inc\\stm32_sdio.h"



 



 



 

typedef struct
{
  uint32_t SDIO_ClockEdge;            
 

  uint32_t SDIO_ClockBypass;          

 

  uint32_t SDIO_ClockPowerSave;       

 

  uint32_t SDIO_BusWide;              
 

  uint32_t SDIO_HardwareFlowControl;  
 

  uint8_t SDIO_ClockDiv;              
 
                                           
} SDIO_InitTypeDef;

typedef struct
{
  uint32_t SDIO_Argument;  


 

  uint32_t SDIO_CmdIndex;   

  uint32_t SDIO_Response;  
 

  uint32_t SDIO_Wait;      
 

  uint32_t SDIO_CPSM;      

 
} SDIO_CmdInitTypeDef;

typedef struct
{
  uint32_t SDIO_DataTimeOut;     

  uint32_t SDIO_DataLength;      
 
  uint32_t SDIO_DataBlockSize;  
 
 
  uint32_t SDIO_TransferDir;    

 
 
  uint32_t SDIO_TransferMode;   
 
 
  uint32_t SDIO_DPSM;           

 
} SDIO_DataInitTypeDef;



  



 



 







 



 







  



 







 



 









 



 







 



 






  




 

#line 222 ".\\Core\\Inc\\stm32_sdio.h"


  



 




 



 

#line 245 ".\\Core\\Inc\\stm32_sdio.h"


 



 








 



 






  



 

#line 283 ".\\Core\\Inc\\stm32_sdio.h"


 



 




 



 

#line 330 ".\\Core\\Inc\\stm32_sdio.h"


 



 







 



 







 



 






 



 

#line 421 ".\\Core\\Inc\\stm32_sdio.h"



#line 448 ".\\Core\\Inc\\stm32_sdio.h"





 



 







 



 



 



 



 

void SDIO_DeInit(void);
void SDIO_Init(SDIO_InitTypeDef* SDIO_InitStruct);
void SDIO_StructInit(SDIO_InitTypeDef* SDIO_InitStruct);
void SDIO_ClockCmd(FunctionalState NewState);
void SDIO_SetPowerState(uint32_t SDIO_PowerState);
uint32_t SDIO_GetPowerState(void);
void SDIO_ITConfig(uint32_t SDIO_IT, FunctionalState NewState);
void SDIO_DMACmd(FunctionalState NewState);
void SDIO_SendCommand(SDIO_CmdInitTypeDef *SDIO_CmdInitStruct);
void SDIO_CmdStructInit(SDIO_CmdInitTypeDef* SDIO_CmdInitStruct);
uint8_t SDIO_GetCommandResponse(void);
uint32_t SDIO_GetResponse(uint32_t SDIO_RESP);
void SDIO_DataConfig(SDIO_DataInitTypeDef* SDIO_DataInitStruct);
void SDIO_DataStructInit(SDIO_DataInitTypeDef* SDIO_DataInitStruct);
uint32_t SDIO_GetDataCounter(void);
uint32_t SDIO_ReadData(void);
void SDIO_WriteData(uint32_t Data);
uint32_t SDIO_GetFIFOCount(void);
void SDIO_StartSDIOReadWait(FunctionalState NewState);
void SDIO_StopSDIOReadWait(FunctionalState NewState);
void SDIO_SetSDIOReadWaitMode(uint32_t SDIO_ReadWaitMode);
void SDIO_SetSDIOOperation(FunctionalState NewState);
void SDIO_SendSDIOSuspendCmd(FunctionalState NewState);
void SDIO_CommandCompletionCmd(FunctionalState NewState);
void SDIO_CEATAITCmd(FunctionalState NewState);
void SDIO_SendCEATACmd(FunctionalState NewState);
FlagStatus SDIO_GetFlagStatus(uint32_t SDIO_FLAG);
void SDIO_ClearFlag(uint32_t SDIO_FLAG);
ITStatus SDIO_GetITStatus(uint32_t SDIO_IT);
void SDIO_ClearITPendingBit(uint32_t SDIO_IT);








 



 



 

 
#line 5 "Core\\Src\\sdio.c"
#line 1 ".\\Core\\Inc\\sdio.h"




















  

 







 


 
  


  



 
  


   



  
typedef enum
{


    
  SD_CMD_CRC_FAIL                    = (1),  
  SD_DATA_CRC_FAIL                   = (2),  
  SD_CMD_RSP_TIMEOUT                 = (3),  
  SD_DATA_TIMEOUT                    = (4),  
  SD_TX_UNDERRUN                     = (5),  
  SD_RX_OVERRUN                      = (6),  
  SD_START_BIT_ERR                   = (7),  
  SD_CMD_OUT_OF_RANGE                = (8),  
  SD_ADDR_MISALIGNED                 = (9),  
  SD_BLOCK_LEN_ERR                   = (10),  
  SD_ERASE_SEQ_ERR                   = (11),  
  SD_BAD_ERASE_PARAM                 = (12),  
  SD_WRITE_PROT_VIOLATION            = (13),  
  SD_LOCK_UNLOCK_FAILED              = (14),  
  SD_COM_CRC_FAILED                  = (15),  
  SD_ILLEGAL_CMD                     = (16),  
  SD_CARD_ECC_FAILED                 = (17),  
  SD_CC_ERROR                        = (18),  
  SD_GENERAL_UNKNOWN_ERROR           = (19),  
  SD_STREAM_READ_UNDERRUN            = (20),  
  SD_STREAM_WRITE_OVERRUN            = (21),  
  SD_CID_CSD_OVERWRITE               = (22),  
  SD_WP_ERASE_SKIP                   = (23),  
  SD_CARD_ECC_DISABLED               = (24),  
  SD_ERASE_RESET                     = (25),  
  SD_AKE_SEQ_ERROR                   = (26),  
  SD_INVALID_VOLTRANGE               = (27),
  SD_ADDR_OUT_OF_RANGE               = (28),
  SD_SWITCH_ERROR                    = (29),
  SD_SDIO_DISABLED                   = (30),
  SD_SDIO_FUNCTION_BUSY              = (31),
  SD_SDIO_FUNCTION_FAILED            = (32),
  SD_SDIO_UNKNOWN_FUNCTION           = (33),



  
  SD_INTERNAL_ERROR, 
  SD_NOT_CONFIGURED,
  SD_REQUEST_PENDING, 
  SD_REQUEST_NOT_APPLICABLE, 
  SD_INVALID_PARAMETER,  
  SD_UNSUPPORTED_FEATURE,  
  SD_UNSUPPORTED_HW,  
  SD_ERROR,  
  SD_OK  
} SD_Error;



    
typedef enum
{
  SD_TRANSFER_OK  = 0,
  SD_TRANSFER_BUSY = 1,
  SD_TRANSFER_ERROR
} SDTransferState;



    
typedef enum
{
  SD_CARD_READY                  = ((uint32_t)0x00000001),
  SD_CARD_IDENTIFICATION         = ((uint32_t)0x00000002),
  SD_CARD_STANDBY                = ((uint32_t)0x00000003),
  SD_CARD_TRANSFER               = ((uint32_t)0x00000004),
  SD_CARD_SENDING                = ((uint32_t)0x00000005),
  SD_CARD_RECEIVING              = ((uint32_t)0x00000006),
  SD_CARD_PROGRAMMING            = ((uint32_t)0x00000007),
  SD_CARD_DISCONNECTED           = ((uint32_t)0x00000008),
  SD_CARD_ERROR                  = ((uint32_t)0x000000FF)
}SDCardState;




  
typedef struct
{
  volatile uint8_t  CSDStruct;             
  volatile uint8_t  SysSpecVersion;        
  volatile uint8_t  Reserved1;             
  volatile uint8_t  TAAC;                  
  volatile uint8_t  NSAC;                  
  volatile uint8_t  MaxBusClkFrec;         
  volatile uint16_t CardComdClasses;       
  volatile uint8_t  RdBlockLen;            
  volatile uint8_t  PartBlockRead;         
  volatile uint8_t  WrBlockMisalign;       
  volatile uint8_t  RdBlockMisalign;       
  volatile uint8_t  DSRImpl;               
  volatile uint8_t  Reserved2;             
  volatile uint32_t DeviceSize;            
  volatile uint8_t  MaxRdCurrentVDDMin;    
  volatile uint8_t  MaxRdCurrentVDDMax;    
  volatile uint8_t  MaxWrCurrentVDDMin;    
  volatile uint8_t  MaxWrCurrentVDDMax;    
  volatile uint8_t  DeviceSizeMul;         
  volatile uint8_t  EraseGrSize;           
  volatile uint8_t  EraseGrMul;            
  volatile uint8_t  WrProtectGrSize;       
  volatile uint8_t  WrProtectGrEnable;     
  volatile uint8_t  ManDeflECC;            
  volatile uint8_t  WrSpeedFact;           
  volatile uint8_t  MaxWrBlockLen;         
  volatile uint8_t  WriteBlockPaPartial;   
  volatile uint8_t  Reserved3;             
  volatile uint8_t  ContentProtectAppli;   
  volatile uint8_t  FileFormatGrouop;      
  volatile uint8_t  CopyFlag;              
  volatile uint8_t  PermWrProtect;         
  volatile uint8_t  TempWrProtect;         
  volatile uint8_t  FileFormat;            
  volatile uint8_t  ECC;                   
  volatile uint8_t  CSD_CRC;               
  volatile uint8_t  Reserved4;             
} SD_CSD;



 
typedef struct
{
  volatile uint8_t  ManufacturerID;        
  volatile uint16_t OEM_AppliID;           
  volatile uint32_t ProdName1;             
  volatile uint8_t  ProdName2;             
  volatile uint8_t  ProdRev;               
  volatile uint32_t ProdSN;                
  volatile uint8_t  Reserved1;             
  volatile uint16_t ManufactDate;          
  volatile uint8_t  CID_CRC;               
  volatile uint8_t  Reserved2;             
} SD_CID;



 
typedef struct
{
  SD_CSD SD_csd;
  SD_CID SD_cid;
  uint32_t CardCapacity;   
  uint32_t CardBlockSize;  
  uint16_t RCA;
  uint8_t CardType;
} SD_CardInfo;



 
  


  



 
#line 251 ".\\Core\\Inc\\sdio.h"




#line 262 ".\\Core\\Inc\\sdio.h"




 
#line 275 ".\\Core\\Inc\\sdio.h"




 
#line 291 ".\\Core\\Inc\\sdio.h"
  






 





 
#line 313 ".\\Core\\Inc\\sdio.h"



  
  


  


  
void SDIOEx_Init(void);



  
void SD_DeInit(void);
SDTransferState SD_GetStatus(void);
SDCardState SD_GetState(void);
uint8_t SD_Detect(void);
SD_Error SD_PowerON(void);
SD_Error SD_PowerOFF(void);
SD_Error SD_InitializeCards(void);
SD_Error SD_GetCardInfo(SD_CardInfo *cardinfo);
SD_Error SD_EnableWideBusOperation(uint32_t WideMode);
SD_Error SD_SetDeviceMode(uint32_t Mode);
SD_Error SD_SelectDeselect(uint32_t addr);
SD_Error SD_ReadBlock(uint32_t *readbuff, uint32_t ReadAddr, uint16_t BlockSize);
SD_Error SD_WriteBlock(uint32_t *writebuff, uint32_t WriteAddr, uint16_t BlockSize);
SDTransferState SD_GetTransferState(void);
SD_Error SD_StopTransfer(void);
SD_Error SD_Erase(uint32_t startaddr, uint32_t endaddr);
SD_Error SD_SendStatus(uint32_t *pcardstatus);
SD_Error SD_SendSDStatus(uint32_t *psdstatus);
SD_Error SD_ProcessIRQSrc(void);








 



 



 



  



  

 
#line 6 "Core\\Src\\sdio.c"






 
#line 33 "Core\\Src\\sdio.c"



 
















#line 59 "Core\\Src\\sdio.c"






 







 







 



 





static uint32_t CardType =  ((uint32_t)0x00000000);
static uint32_t CSD_Tab[4], CID_Tab[4], RCA = 0;
static uint32_t DeviceMode = ((uint32_t)0x00000002);
static uint32_t TotalNumberOfBytes = 0, StopCondition = 0;
uint32_t *SrcBuffer, *DestBuffer;
volatile SD_Error TransferError = SD_OK;
volatile uint32_t TransferEnd = 0;
volatile uint32_t NumberOfBytes = 0;
SD_CardInfo SDCardInfo;
SDIO_InitTypeDef SDIO_InitStructure;
SDIO_CmdInitTypeDef SDIO_CmdInitStructure;
SDIO_DataInitTypeDef SDIO_DataInitStructure;   


  




 
static SD_Error CmdError(void);
static SD_Error CmdResp1Error(uint8_t cmd);
static SD_Error CmdResp7Error(void);
static SD_Error CmdResp3Error(void);
static SD_Error CmdResp2Error(void);
static SD_Error CmdResp6Error(uint8_t cmd, uint16_t *prca);
static SD_Error SDEnWideBus(FunctionalState NewState);
static SD_Error IsCardProgramming(uint8_t *pstatus);
static SD_Error FindSCR(uint16_t rca, uint32_t *pscr);
static uint8_t convert_from_bytes_to_power_of_two(uint16_t NumberOfBytes);
  


  

void SD_LowLevel_DeInit(void)
{

}






 
void SD_LowLevel_Init(void)
{

}





 



   





 
void SD_DeInit(void)
{ 
  SD_LowLevel_DeInit();
}








 
SDTransferState SD_GetStatus(void)
{
  SDCardState cardstate =  SD_CARD_TRANSFER;

  cardstate = SD_GetState();
  
  if (cardstate == SD_CARD_TRANSFER)
  {
    return(SD_TRANSFER_OK);
  }
  else if(cardstate == SD_CARD_ERROR)
  {
    return (SD_TRANSFER_ERROR);
  }
  else
  {
    return(SD_TRANSFER_BUSY);
  }
}





 
SDCardState SD_GetState(void)
{
  uint32_t resp1 = 0;
  
  if(SD_Detect()== ((uint8_t)0x01))
  {
    if (SD_SendStatus(&resp1) != SD_OK)
    {
      return SD_CARD_ERROR;
    }
    else
    {
      return (SDCardState)((resp1 >> 9) & 0x0F);
    }
  }
  else
  {
    return SD_CARD_ERROR;
  }
}





 
uint8_t SD_Detect(void)
{
  volatile uint8_t status = ((uint8_t)0x01);

  return status;
}






 
SD_Error SD_PowerON(void)
{
  SD_Error errorstatus = SD_OK;
  uint32_t response = 0, count = 0, validvoltage = 0;
  uint32_t SDType = ((uint32_t)0x00000000);

   
   
   
     
  SDIO_InitStructure.SDIO_ClockDiv = ((uint8_t)0xB2);
  SDIO_InitStructure.SDIO_ClockEdge = ((uint32_t)0x00000000);
  SDIO_InitStructure.SDIO_ClockBypass = ((uint32_t)0x00000000);
  SDIO_InitStructure.SDIO_ClockPowerSave = ((uint32_t)0x00000000);
  SDIO_InitStructure.SDIO_BusWide = ((uint32_t)0x00000000);
  SDIO_InitStructure.SDIO_HardwareFlowControl = ((uint32_t)0x00000000);
  SDIO_Init(&SDIO_InitStructure);

   
  SDIO_SetPowerState(((uint32_t)0x00000003));

   
  SDIO_ClockCmd(ENABLE);

   
   
  SDIO_CmdInitStructure.SDIO_Argument = 0x0;
  SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)0);
  SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000000);
  SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
  SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
  SDIO_SendCommand(&SDIO_CmdInitStructure);

  errorstatus = CmdError();

  if (errorstatus != SD_OK)
  {
     
    return(errorstatus);
  }

   
   
  

 
   
  SDIO_CmdInitStructure.SDIO_Argument = ((uint32_t)0x000001AA);
  SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint32_t)0x00000008);
  SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
  SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
  SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
  SDIO_SendCommand(&SDIO_CmdInitStructure);

  errorstatus = CmdResp7Error();

  if (errorstatus == SD_OK)
  {
    CardType = ((uint32_t)0x00000001);  
    SDType = ((uint32_t)0x40000000);
  }
  else
  {
     
    SDIO_CmdInitStructure.SDIO_Argument = 0x00;
    SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)55);
    SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
    SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
    SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
    SDIO_SendCommand(&SDIO_CmdInitStructure);
    errorstatus = CmdResp1Error(((uint8_t)55));
  }
   
  SDIO_CmdInitStructure.SDIO_Argument = 0x00;
  SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)55);
  SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
  SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
  SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
  SDIO_SendCommand(&SDIO_CmdInitStructure);
  errorstatus = CmdResp1Error(((uint8_t)55));

   
  
 
  if (errorstatus == SD_OK)
  {
     
     
    while ((!validvoltage) && (count < ((uint32_t)0x0000FFFF)))
    {

       
      SDIO_CmdInitStructure.SDIO_Argument = 0x00;
      SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)55);
      SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
      SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
      SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
      SDIO_SendCommand(&SDIO_CmdInitStructure);

      errorstatus = CmdResp1Error(((uint8_t)55));

      if (errorstatus != SD_OK)
      {
        return(errorstatus);
      }
      SDIO_CmdInitStructure.SDIO_Argument = ((uint32_t)0x80100000) | SDType;
      SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)41);
      SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
      SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
      SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
      SDIO_SendCommand(&SDIO_CmdInitStructure);

      errorstatus = CmdResp3Error();
      if (errorstatus != SD_OK)
      {
        return(errorstatus);
      }

      response = SDIO_GetResponse(((uint32_t)0x00000000));
      validvoltage = (((response >> 31) == 1) ? 1 : 0);
      count++;
    }
    if (count >= ((uint32_t)0x0000FFFF))
    {
      errorstatus = SD_INVALID_VOLTRANGE;
      return(errorstatus);
    }

    if (response &= ((uint32_t)0x40000000))
    {
      CardType = ((uint32_t)0x00000002);
      
    }

  } 

  return(errorstatus);
}





 
SD_Error SD_PowerOFF(void)
{
  SD_Error errorstatus = SD_OK;

   
  SDIO_SetPowerState(((uint32_t)0x00000000));

  return(errorstatus);
}






 
SD_Error SD_InitializeCards(void)
{
  SD_Error errorstatus = SD_OK;
  uint16_t rca = 0x01;

  if (SDIO_GetPowerState() == ((uint32_t)0x00000000))
  {
    errorstatus = SD_REQUEST_NOT_APPLICABLE;
    return(errorstatus);
  }

  if (((uint32_t)0x00000004) != CardType)
  {
     
    SDIO_CmdInitStructure.SDIO_Argument = 0x0;
    SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)2);
    SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x000000C0);
    SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
    SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
    SDIO_SendCommand(&SDIO_CmdInitStructure);

    errorstatus = CmdResp2Error();

    if (SD_OK != errorstatus)
    {
      return(errorstatus);
    }

    CID_Tab[0] = SDIO_GetResponse(((uint32_t)0x00000000));
    CID_Tab[1] = SDIO_GetResponse(((uint32_t)0x00000004));
    CID_Tab[2] = SDIO_GetResponse(((uint32_t)0x00000008));
    CID_Tab[3] = SDIO_GetResponse(((uint32_t)0x0000000C));
  }
  if ((((uint32_t)0x00000000) == CardType) ||  (((uint32_t)0x00000001) == CardType) ||  (((uint32_t)0x00000006) == CardType)
      ||  (((uint32_t)0x00000002) == CardType))
  {
     
     
    SDIO_CmdInitStructure.SDIO_Argument = 0x00;
    SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)3);
    SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
    SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
    SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
    SDIO_SendCommand(&SDIO_CmdInitStructure);

    errorstatus = CmdResp6Error(((uint8_t)3), &rca);

    if (SD_OK != errorstatus)
    {
      return(errorstatus);
    }
  }

  if (((uint32_t)0x00000004) != CardType)
  {
    RCA = rca;

     
    SDIO_CmdInitStructure.SDIO_Argument = (uint32_t)(rca << 16);
    SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)9);
    SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x000000C0);
    SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
    SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
    SDIO_SendCommand(&SDIO_CmdInitStructure);

    errorstatus = CmdResp2Error();

    if (SD_OK != errorstatus)
    {
      return(errorstatus);
    }

    CSD_Tab[0] = SDIO_GetResponse(((uint32_t)0x00000000));
    CSD_Tab[1] = SDIO_GetResponse(((uint32_t)0x00000004));
    CSD_Tab[2] = SDIO_GetResponse(((uint32_t)0x00000008));
    CSD_Tab[3] = SDIO_GetResponse(((uint32_t)0x0000000C));
  }

  errorstatus = SD_OK;  

  return(errorstatus);
}






 
SD_Error SD_GetCardInfo(SD_CardInfo *cardinfo)
{
  SD_Error errorstatus = SD_OK;
  uint8_t tmp = 0;

  cardinfo->CardType = (uint8_t)CardType;
  cardinfo->RCA = (uint16_t)RCA;

   
  tmp = (uint8_t)((CSD_Tab[0] & 0xFF000000) >> 24);
  cardinfo->SD_csd.CSDStruct = (tmp & 0xC0) >> 6;
  cardinfo->SD_csd.SysSpecVersion = (tmp & 0x3C) >> 2;
  cardinfo->SD_csd.Reserved1 = tmp & 0x03;

   
  tmp = (uint8_t)((CSD_Tab[0] & 0x00FF0000) >> 16);
  cardinfo->SD_csd.TAAC = tmp;

   
  tmp = (uint8_t)((CSD_Tab[0] & 0x0000FF00) >> 8);
  cardinfo->SD_csd.NSAC = tmp;

   
  tmp = (uint8_t)(CSD_Tab[0] & 0x000000FF);
  cardinfo->SD_csd.MaxBusClkFrec = tmp;

   
  tmp = (uint8_t)((CSD_Tab[1] & 0xFF000000) >> 24);
  cardinfo->SD_csd.CardComdClasses = tmp << 4;

   
  tmp = (uint8_t)((CSD_Tab[1] & 0x00FF0000) >> 16);
  cardinfo->SD_csd.CardComdClasses |= (tmp & 0xF0) >> 4;
  cardinfo->SD_csd.RdBlockLen = tmp & 0x0F;

   
  tmp = (uint8_t)((CSD_Tab[1] & 0x0000FF00) >> 8);
  cardinfo->SD_csd.PartBlockRead = (tmp & 0x80) >> 7;
  cardinfo->SD_csd.WrBlockMisalign = (tmp & 0x40) >> 6;
  cardinfo->SD_csd.RdBlockMisalign = (tmp & 0x20) >> 5;
  cardinfo->SD_csd.DSRImpl = (tmp & 0x10) >> 4;
  cardinfo->SD_csd.Reserved2 = 0;  

  if ((CardType == ((uint32_t)0x00000000)) || (CardType == ((uint32_t)0x00000001)))
  {
    cardinfo->SD_csd.DeviceSize = (tmp & 0x03) << 10;

     
    tmp = (uint8_t)(CSD_Tab[1] & 0x000000FF);
    cardinfo->SD_csd.DeviceSize |= (tmp) << 2;

     
    tmp = (uint8_t)((CSD_Tab[2] & 0xFF000000) >> 24);
    cardinfo->SD_csd.DeviceSize |= (tmp & 0xC0) >> 6;

    cardinfo->SD_csd.MaxRdCurrentVDDMin = (tmp & 0x38) >> 3;
    cardinfo->SD_csd.MaxRdCurrentVDDMax = (tmp & 0x07);

     
    tmp = (uint8_t)((CSD_Tab[2] & 0x00FF0000) >> 16);
    cardinfo->SD_csd.MaxWrCurrentVDDMin = (tmp & 0xE0) >> 5;
    cardinfo->SD_csd.MaxWrCurrentVDDMax = (tmp & 0x1C) >> 2;
    cardinfo->SD_csd.DeviceSizeMul = (tmp & 0x03) << 1;
     
    tmp = (uint8_t)((CSD_Tab[2] & 0x0000FF00) >> 8);
    cardinfo->SD_csd.DeviceSizeMul |= (tmp & 0x80) >> 7;
    
    cardinfo->CardCapacity = (cardinfo->SD_csd.DeviceSize + 1) ;
    cardinfo->CardCapacity *= (1 << (cardinfo->SD_csd.DeviceSizeMul + 2));
    cardinfo->CardBlockSize = 1 << (cardinfo->SD_csd.RdBlockLen);
    cardinfo->CardCapacity *= cardinfo->CardBlockSize;
  }
  else if (CardType == ((uint32_t)0x00000002))
  {
     
    tmp = (uint8_t)(CSD_Tab[1] & 0x000000FF);
    cardinfo->SD_csd.DeviceSize = (tmp & 0x3F) << 16;

     
    tmp = (uint8_t)((CSD_Tab[2] & 0xFF000000) >> 24);

    cardinfo->SD_csd.DeviceSize |= (tmp << 8);

     
    tmp = (uint8_t)((CSD_Tab[2] & 0x00FF0000) >> 16);

    cardinfo->SD_csd.DeviceSize |= (tmp);

     
    tmp = (uint8_t)((CSD_Tab[2] & 0x0000FF00) >> 8);
    
    cardinfo->CardCapacity = (cardinfo->SD_csd.DeviceSize + 1) * 512 * 1024;
    cardinfo->CardBlockSize = 512;    
  }


  cardinfo->SD_csd.EraseGrSize = (tmp & 0x40) >> 6;
  cardinfo->SD_csd.EraseGrMul = (tmp & 0x3F) << 1;

   
  tmp = (uint8_t)(CSD_Tab[2] & 0x000000FF);
  cardinfo->SD_csd.EraseGrMul |= (tmp & 0x80) >> 7;
  cardinfo->SD_csd.WrProtectGrSize = (tmp & 0x7F);

   
  tmp = (uint8_t)((CSD_Tab[3] & 0xFF000000) >> 24);
  cardinfo->SD_csd.WrProtectGrEnable = (tmp & 0x80) >> 7;
  cardinfo->SD_csd.ManDeflECC = (tmp & 0x60) >> 5;
  cardinfo->SD_csd.WrSpeedFact = (tmp & 0x1C) >> 2;
  cardinfo->SD_csd.MaxWrBlockLen = (tmp & 0x03) << 2;

   
  tmp = (uint8_t)((CSD_Tab[3] & 0x00FF0000) >> 16);
  cardinfo->SD_csd.MaxWrBlockLen |= (tmp & 0xC0) >> 6;
  cardinfo->SD_csd.WriteBlockPaPartial = (tmp & 0x20) >> 5;
  cardinfo->SD_csd.Reserved3 = 0;
  cardinfo->SD_csd.ContentProtectAppli = (tmp & 0x01);

   
  tmp = (uint8_t)((CSD_Tab[3] & 0x0000FF00) >> 8);
  cardinfo->SD_csd.FileFormatGrouop = (tmp & 0x80) >> 7;
  cardinfo->SD_csd.CopyFlag = (tmp & 0x40) >> 6;
  cardinfo->SD_csd.PermWrProtect = (tmp & 0x20) >> 5;
  cardinfo->SD_csd.TempWrProtect = (tmp & 0x10) >> 4;
  cardinfo->SD_csd.FileFormat = (tmp & 0x0C) >> 2;
  cardinfo->SD_csd.ECC = (tmp & 0x03);

   
  tmp = (uint8_t)(CSD_Tab[3] & 0x000000FF);
  cardinfo->SD_csd.CSD_CRC = (tmp & 0xFE) >> 1;
  cardinfo->SD_csd.Reserved4 = 1;


   
  tmp = (uint8_t)((CID_Tab[0] & 0xFF000000) >> 24);
  cardinfo->SD_cid.ManufacturerID = tmp;

   
  tmp = (uint8_t)((CID_Tab[0] & 0x00FF0000) >> 16);
  cardinfo->SD_cid.OEM_AppliID = tmp << 8;

   
  tmp = (uint8_t)((CID_Tab[0] & 0x000000FF00) >> 8);
  cardinfo->SD_cid.OEM_AppliID |= tmp;

   
  tmp = (uint8_t)(CID_Tab[0] & 0x000000FF);
  cardinfo->SD_cid.ProdName1 = tmp << 24;

   
  tmp = (uint8_t)((CID_Tab[1] & 0xFF000000) >> 24);
  cardinfo->SD_cid.ProdName1 |= tmp << 16;

   
  tmp = (uint8_t)((CID_Tab[1] & 0x00FF0000) >> 16);
  cardinfo->SD_cid.ProdName1 |= tmp << 8;

   
  tmp = (uint8_t)((CID_Tab[1] & 0x0000FF00) >> 8);
  cardinfo->SD_cid.ProdName1 |= tmp;

   
  tmp = (uint8_t)(CID_Tab[1] & 0x000000FF);
  cardinfo->SD_cid.ProdName2 = tmp;

   
  tmp = (uint8_t)((CID_Tab[2] & 0xFF000000) >> 24);
  cardinfo->SD_cid.ProdRev = tmp;

   
  tmp = (uint8_t)((CID_Tab[2] & 0x00FF0000) >> 16);
  cardinfo->SD_cid.ProdSN = tmp << 24;

   
  tmp = (uint8_t)((CID_Tab[2] & 0x0000FF00) >> 8);
  cardinfo->SD_cid.ProdSN |= tmp << 16;

   
  tmp = (uint8_t)(CID_Tab[2] & 0x000000FF);
  cardinfo->SD_cid.ProdSN |= tmp << 8;

   
  tmp = (uint8_t)((CID_Tab[3] & 0xFF000000) >> 24);
  cardinfo->SD_cid.ProdSN |= tmp;

   
  tmp = (uint8_t)((CID_Tab[3] & 0x00FF0000) >> 16);
  cardinfo->SD_cid.Reserved1 |= (tmp & 0xF0) >> 4;
  cardinfo->SD_cid.ManufactDate = (tmp & 0x0F) << 8;

   
  tmp = (uint8_t)((CID_Tab[3] & 0x0000FF00) >> 8);
  cardinfo->SD_cid.ManufactDate |= tmp;

   
  tmp = (uint8_t)(CID_Tab[3] & 0x000000FF);
  cardinfo->SD_cid.CID_CRC = (tmp & 0xFE) >> 1;
  cardinfo->SD_cid.Reserved2 = 1;
  
  return(errorstatus);
}










 
SD_Error SD_EnableWideBusOperation(uint32_t WideMode)
{
  SD_Error errorstatus = SD_OK;

   
  if (((uint32_t)0x00000003) == CardType)
  {
    errorstatus = SD_UNSUPPORTED_FEATURE;
    return(errorstatus);
  }
  else if ((((uint32_t)0x00000000) == CardType) || (((uint32_t)0x00000001) == CardType) || (((uint32_t)0x00000002) == CardType))
  {
    if (((uint32_t)0x00001000) == WideMode)
    {
      errorstatus = SD_UNSUPPORTED_FEATURE;
      return(errorstatus);
    }
    else if (((uint32_t)0x00000800) == WideMode)
    {
      errorstatus = SDEnWideBus(ENABLE);

      if (SD_OK == errorstatus)
      {
         
        SDIO_InitStructure.SDIO_ClockDiv = ((uint8_t)0x1); 
        SDIO_InitStructure.SDIO_ClockEdge = ((uint32_t)0x00000000);
        SDIO_InitStructure.SDIO_ClockBypass = ((uint32_t)0x00000000);
        SDIO_InitStructure.SDIO_ClockPowerSave = ((uint32_t)0x00000000);
        SDIO_InitStructure.SDIO_BusWide = ((uint32_t)0x00000800);
        SDIO_InitStructure.SDIO_HardwareFlowControl = ((uint32_t)0x00000000);
        SDIO_Init(&SDIO_InitStructure);
      }
    }
    else
    {
      errorstatus = SDEnWideBus(DISABLE);

      if (SD_OK == errorstatus)
      {
         
        SDIO_InitStructure.SDIO_ClockDiv = ((uint8_t)0x1); 
        SDIO_InitStructure.SDIO_ClockEdge = ((uint32_t)0x00000000);
        SDIO_InitStructure.SDIO_ClockBypass = ((uint32_t)0x00000000);
        SDIO_InitStructure.SDIO_ClockPowerSave = ((uint32_t)0x00000000);
        SDIO_InitStructure.SDIO_BusWide = ((uint32_t)0x00000000);
        SDIO_InitStructure.SDIO_HardwareFlowControl = ((uint32_t)0x00000000);
        SDIO_Init(&SDIO_InitStructure);
      }
    }
  }

  return(errorstatus);
}





 
SD_Error SD_SelectDeselect(uint32_t addr)
{
  SD_Error errorstatus = SD_OK;

   
  SDIO_CmdInitStructure.SDIO_Argument =  addr;
  SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)7);
  SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
  SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
  SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
  SDIO_SendCommand(&SDIO_CmdInitStructure);

  errorstatus = CmdResp1Error(((uint8_t)7));

  return(errorstatus);
}







 
SD_Error SD_ReadBlock(uint32_t *readbuff, uint32_t ReadAddr, uint16_t BlockSize)
{
  SD_Error errorstatus = SD_OK;
  uint32_t count = 0, *tempbuff = (uint32_t *)readbuff;
  uint8_t power = 0;

  if (0 == readbuff)
  {
    errorstatus = SD_INVALID_PARAMETER;
    return(errorstatus);
  }

  TransferError = SD_OK;
  TransferEnd = 0;
  TotalNumberOfBytes = 0;

   
  SDIO_DataInitStructure.SDIO_DataTimeOut = ((uint32_t)0x000FFFFF);
  SDIO_DataInitStructure.SDIO_DataLength = 0;
  SDIO_DataInitStructure.SDIO_DataBlockSize = ((uint32_t)0x00000000);
  SDIO_DataInitStructure.SDIO_TransferDir = ((uint32_t)0x00000000);
  SDIO_DataInitStructure.SDIO_TransferMode = ((uint32_t)0x00000000);
  SDIO_DataInitStructure.SDIO_DPSM = ((uint32_t)0x00000000);
  SDIO_DataConfig(&SDIO_DataInitStructure);
  SDIO_DMACmd(DISABLE);

  if (SDIO_GetResponse(((uint32_t)0x00000000)) & ((uint32_t)0x02000000))
  {
    errorstatus = SD_LOCK_UNLOCK_FAILED;
    return(errorstatus);
  }
  
  if (CardType == ((uint32_t)0x00000002))
  {
    BlockSize = 512;
    ReadAddr /= 512;
  }
  if ((BlockSize > 0) && (BlockSize <= 2048) && ((BlockSize & (BlockSize - 1)) == 0))
  {
    power = convert_from_bytes_to_power_of_two(BlockSize);

     
    SDIO_CmdInitStructure.SDIO_Argument = (uint32_t) BlockSize;
    SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)16);
    SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
    SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
    SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
    SDIO_SendCommand(&SDIO_CmdInitStructure);

    errorstatus = CmdResp1Error(((uint8_t)16));

    if (SD_OK != errorstatus)
    {
      return(errorstatus);
    }
  }
  else
  {
    errorstatus = SD_INVALID_PARAMETER;
    return(errorstatus);
  }

  SDIO_DataInitStructure.SDIO_DataTimeOut = ((uint32_t)0x000FFFFF);
  SDIO_DataInitStructure.SDIO_DataLength = BlockSize;
  SDIO_DataInitStructure.SDIO_DataBlockSize = (uint32_t) power << 4;
  SDIO_DataInitStructure.SDIO_TransferDir = ((uint32_t)0x00000002);
  SDIO_DataInitStructure.SDIO_TransferMode = ((uint32_t)0x00000000);
  SDIO_DataInitStructure.SDIO_DPSM = ((uint32_t)0x00000001);
  SDIO_DataConfig(&SDIO_DataInitStructure);

  TotalNumberOfBytes = BlockSize;
  StopCondition = 0;
  DestBuffer = (uint32_t *)readbuff;

   
  SDIO_CmdInitStructure.SDIO_Argument = (uint32_t)ReadAddr;
  SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)17);
  SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
  SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
  SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
  SDIO_SendCommand(&SDIO_CmdInitStructure);

  errorstatus = CmdResp1Error(((uint8_t)17));

  if (errorstatus != SD_OK)
  {
    return(errorstatus);
  }
   
     
    while (!(((SDIO_TypeDef *)(0x40000000U + 0x00018000U))->STA &(((uint32_t)0x00000020) | ((uint32_t)0x00000002) | ((uint32_t)0x00000008) | ((uint32_t)0x00000400) | ((uint32_t)0x00000200))))
    {
      if (SDIO_GetFlagStatus(((uint32_t)0x00008000)) != RESET)
      {
        for (count = 0; count < 8; count++)
        {
          *(tempbuff + count) = SDIO_ReadData();
        }
        tempbuff += 8;
      }
    }

    if (SDIO_GetFlagStatus(((uint32_t)0x00000008)) != RESET)
    {
      SDIO_ClearFlag(((uint32_t)0x00000008));
      errorstatus = SD_DATA_TIMEOUT;
      return(errorstatus);
    }
    else if (SDIO_GetFlagStatus(((uint32_t)0x00000002)) != RESET)
    {
      SDIO_ClearFlag(((uint32_t)0x00000002));
      errorstatus = SD_DATA_CRC_FAIL;
      return(errorstatus);
    }
    else if (SDIO_GetFlagStatus(((uint32_t)0x00000020)) != RESET)
    {
      SDIO_ClearFlag(((uint32_t)0x00000020));
      errorstatus = SD_RX_OVERRUN;
      return(errorstatus);
    }
    else if (SDIO_GetFlagStatus(((uint32_t)0x00000200)) != RESET)
    {
      SDIO_ClearFlag(((uint32_t)0x00000200));
      errorstatus = SD_START_BIT_ERR;
      return(errorstatus);
    }
    while (SDIO_GetFlagStatus(((uint32_t)0x00200000)) != RESET)
    {
      *tempbuff = SDIO_ReadData();
      tempbuff++;
    }

     
    SDIO_ClearFlag(((uint32_t)0x000005FF));

  return(errorstatus);
}







 
SD_Error SD_WriteBlock(uint32_t *writebuff, uint32_t WriteAddr, uint16_t BlockSize)
{
  SD_Error errorstatus = SD_OK;
  uint8_t  power = 0, cardstate = 0;
  uint32_t timeout = 0, bytestransferred = 0;
  uint32_t cardstatus = 0, count = 0, restwords = 0;
  uint32_t *tempbuff = (uint32_t *)writebuff;

  if (writebuff == 0)
  {
    errorstatus = SD_INVALID_PARAMETER;
    return(errorstatus);
  }

  TransferError = SD_OK;
  TransferEnd = 0;
  TotalNumberOfBytes = 0;

  SDIO_DataInitStructure.SDIO_DataTimeOut = ((uint32_t)0x000FFFFF);
  SDIO_DataInitStructure.SDIO_DataLength = 0;
  SDIO_DataInitStructure.SDIO_DataBlockSize = ((uint32_t)0x00000000);
  SDIO_DataInitStructure.SDIO_TransferDir = ((uint32_t)0x00000000);
  SDIO_DataInitStructure.SDIO_TransferMode = ((uint32_t)0x00000000);
  SDIO_DataInitStructure.SDIO_DPSM = ((uint32_t)0x00000000);
  SDIO_DataConfig(&SDIO_DataInitStructure);
  SDIO_DMACmd(DISABLE);

  if (SDIO_GetResponse(((uint32_t)0x00000000)) & ((uint32_t)0x02000000))
  {
    errorstatus = SD_LOCK_UNLOCK_FAILED;
    return(errorstatus);
  }

  if (CardType == ((uint32_t)0x00000002))
  {
    BlockSize = 512;
    WriteAddr /= 512;
  }
  
   
  if ((BlockSize > 0) && (BlockSize <= 2048) && ((BlockSize & (BlockSize - 1)) == 0))
  {
    power = convert_from_bytes_to_power_of_two(BlockSize);

    SDIO_CmdInitStructure.SDIO_Argument = (uint32_t) BlockSize;
    SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)16);
    SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
    SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
    SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
    SDIO_SendCommand(&SDIO_CmdInitStructure);

    errorstatus = CmdResp1Error(((uint8_t)16));

    if (errorstatus != SD_OK)
    {
      return(errorstatus);
    }
  }
  else
  {
    errorstatus = SD_INVALID_PARAMETER;
    return(errorstatus);
  }

   
  SDIO_CmdInitStructure.SDIO_Argument = (uint32_t) (RCA << 16);
  SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)13);
  SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
  SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
  SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
  SDIO_SendCommand(&SDIO_CmdInitStructure);

  errorstatus = CmdResp1Error(((uint8_t)13));

  if (errorstatus != SD_OK)
  {
    return(errorstatus);
  }

  cardstatus = SDIO_GetResponse(((uint32_t)0x00000000));

  timeout = ((uint32_t)0x000FFFFF);

  while (((cardstatus & 0x00000100) == 0) && (timeout > 0))
  {
    timeout--;
    SDIO_CmdInitStructure.SDIO_Argument = (uint32_t) (RCA << 16);
    SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)13);
    SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
    SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
    SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
    SDIO_SendCommand(&SDIO_CmdInitStructure);

    errorstatus = CmdResp1Error(((uint8_t)13));

    if (errorstatus != SD_OK)
    {
      return(errorstatus);
    }
    cardstatus = SDIO_GetResponse(((uint32_t)0x00000000));
  }

  if (timeout == 0)
  {
    return(SD_ERROR);
  }

   
  SDIO_CmdInitStructure.SDIO_Argument = WriteAddr;
  SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)24);
  SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
  SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
  SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
  SDIO_SendCommand(&SDIO_CmdInitStructure);

  errorstatus = CmdResp1Error(((uint8_t)24));

  if (errorstatus != SD_OK)
  {
    return(errorstatus);
  }

  TotalNumberOfBytes = BlockSize;
  StopCondition = 0;
  SrcBuffer = (uint32_t *)writebuff;

  SDIO_DataInitStructure.SDIO_DataTimeOut = ((uint32_t)0x000FFFFF);
  SDIO_DataInitStructure.SDIO_DataLength = BlockSize;
  SDIO_DataInitStructure.SDIO_DataBlockSize = (uint32_t) power << 4;
  SDIO_DataInitStructure.SDIO_TransferDir = ((uint32_t)0x00000000);
  SDIO_DataInitStructure.SDIO_TransferMode = ((uint32_t)0x00000000);
  SDIO_DataInitStructure.SDIO_DPSM = ((uint32_t)0x00000001);
  SDIO_DataConfig(&SDIO_DataInitStructure);

   
    while (!(((SDIO_TypeDef *)(0x40000000U + 0x00018000U))->STA & (((uint32_t)0x00000400) | ((uint32_t)0x00000010) | ((uint32_t)0x00000002) | ((uint32_t)0x00000008) | ((uint32_t)0x00000200))))
    {
      if (SDIO_GetFlagStatus(((uint32_t)0x00004000)) != RESET)
      {
        if ((TotalNumberOfBytes - bytestransferred) < 32)
        {
          restwords = ((TotalNumberOfBytes - bytestransferred) % 4 == 0) ? ((TotalNumberOfBytes - bytestransferred) / 4) : (( TotalNumberOfBytes -  bytestransferred) / 4 + 1);

          for (count = 0; count < restwords; count++, tempbuff++, bytestransferred += 4)
          {
            SDIO_WriteData(*tempbuff);
          }
        }
        else
        {
          for (count = 0; count < 8; count++)
          {
            SDIO_WriteData(*(tempbuff + count));
          }
          tempbuff += 8;
          bytestransferred += 32;
        }
      }
    }
    if (SDIO_GetFlagStatus(((uint32_t)0x00000008)) != RESET)
    {
      SDIO_ClearFlag(((uint32_t)0x00000008));
      errorstatus = SD_DATA_TIMEOUT;
      return(errorstatus);
    }
    else if (SDIO_GetFlagStatus(((uint32_t)0x00000002)) != RESET)
    {
      SDIO_ClearFlag(((uint32_t)0x00000002));
      errorstatus = SD_DATA_CRC_FAIL;
      return(errorstatus);
    }
    else if (SDIO_GetFlagStatus(((uint32_t)0x00000010)) != RESET)
    {
      SDIO_ClearFlag(((uint32_t)0x00000010));
      errorstatus = SD_TX_UNDERRUN;
      return(errorstatus);
    }
    else if (SDIO_GetFlagStatus(((uint32_t)0x00000200)) != RESET)
    {
      SDIO_ClearFlag(((uint32_t)0x00000200));
      errorstatus = SD_START_BIT_ERR;
      return(errorstatus);
    }

   
  SDIO_ClearFlag(((uint32_t)0x000005FF));

   
  errorstatus = IsCardProgramming(&cardstate);

  while ((errorstatus == SD_OK) && ((cardstate == SD_CARD_PROGRAMMING) || (cardstate == SD_CARD_RECEIVING)))
  {
    errorstatus = IsCardProgramming(&cardstate);
  }

  return(errorstatus);
}








 
SDTransferState SD_GetTransferState(void)
{
  if (((SDIO_TypeDef *)(0x40000000U + 0x00018000U))->STA & (((uint32_t)0x00001000) | ((uint32_t)0x00002000)))
  {
    return(SD_TRANSFER_BUSY);
  }
  else
  {
    return(SD_TRANSFER_OK);
  }
}





 
SD_Error SD_StopTransfer(void)
{
  SD_Error errorstatus = SD_OK;

   
  SDIO_CmdInitStructure.SDIO_Argument = 0x0;
  SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)12);
  SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
  SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
  SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
  SDIO_SendCommand(&SDIO_CmdInitStructure);

  errorstatus = CmdResp1Error(((uint8_t)12));

  return(errorstatus);
}






 
SD_Error SD_Erase(uint32_t startaddr, uint32_t endaddr)
{
  SD_Error errorstatus = SD_OK;
  uint32_t delay = 0;
  volatile uint32_t maxdelay = 0;
  uint8_t cardstate = 0;

   
  if (((CSD_Tab[1] >> 20) & ((uint32_t)0x00000020)) == 0)
  {
    errorstatus = SD_REQUEST_NOT_APPLICABLE;
    return(errorstatus);
  }

  maxdelay = 120000 / ((((SDIO_TypeDef *)(0x40000000U + 0x00018000U))->CLKCR & 0xFF) + 2);

  if (SDIO_GetResponse(((uint32_t)0x00000000)) & ((uint32_t)0x02000000))
  {
    errorstatus = SD_LOCK_UNLOCK_FAILED;
    return(errorstatus);
  }

  if (CardType == ((uint32_t)0x00000002))
  {
    startaddr /= 512;
    endaddr /= 512;
  }
  
   
  if ((((uint32_t)0x00000000) == CardType) || (((uint32_t)0x00000001) == CardType) || (((uint32_t)0x00000002) == CardType))
  {
     
    SDIO_CmdInitStructure.SDIO_Argument = startaddr;
    SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)32);
    SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
    SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
    SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
    SDIO_SendCommand(&SDIO_CmdInitStructure);

    errorstatus = CmdResp1Error(((uint8_t)32));
    if (errorstatus != SD_OK)
    {
      return(errorstatus);
    }

     
    SDIO_CmdInitStructure.SDIO_Argument = endaddr;
    SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)33);
    SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
    SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
    SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
    SDIO_SendCommand(&SDIO_CmdInitStructure);

    errorstatus = CmdResp1Error(((uint8_t)33));
    if (errorstatus != SD_OK)
    {
      return(errorstatus);
    }
  }

   
  SDIO_CmdInitStructure.SDIO_Argument = 0;
  SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)38);
  SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
  SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
  SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
  SDIO_SendCommand(&SDIO_CmdInitStructure);

  errorstatus = CmdResp1Error(((uint8_t)38));

  if (errorstatus != SD_OK)
  {
    return(errorstatus);
  }

  for (delay = 0; delay < maxdelay; delay++)
  {}

   
  errorstatus = IsCardProgramming(&cardstate);

  while ((errorstatus == SD_OK) && ((SD_CARD_PROGRAMMING == cardstate) || (SD_CARD_RECEIVING == cardstate)))
  {
    errorstatus = IsCardProgramming(&cardstate);
  }

  return(errorstatus);
}






 
SD_Error SD_SendStatus(uint32_t *pcardstatus)
{
  SD_Error errorstatus = SD_OK;

  if (pcardstatus == 0)
  {
    errorstatus = SD_INVALID_PARAMETER;
    return(errorstatus);
  }

  SDIO_CmdInitStructure.SDIO_Argument = (uint32_t) RCA << 16;
  SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)13);
  SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
  SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
  SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
  SDIO_SendCommand(&SDIO_CmdInitStructure);


  errorstatus = CmdResp1Error(((uint8_t)13));

  if (errorstatus != SD_OK)
  {
    return(errorstatus);
  }

  *pcardstatus = SDIO_GetResponse(((uint32_t)0x00000000));

  return(errorstatus);
}






 
SD_Error SD_SendSDStatus(uint32_t *psdstatus)
{
  SD_Error errorstatus = SD_OK;
  uint32_t count = 0;

  if (SDIO_GetResponse(((uint32_t)0x00000000)) & ((uint32_t)0x02000000))
  {
    errorstatus = SD_LOCK_UNLOCK_FAILED;
    return(errorstatus);
  }

   
  SDIO_CmdInitStructure.SDIO_Argument = 64;
  SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)16);
  SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
  SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
  SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
  SDIO_SendCommand(&SDIO_CmdInitStructure);

  errorstatus = CmdResp1Error(((uint8_t)16));

  if (errorstatus != SD_OK)
  {
    return(errorstatus);
  }

   
  SDIO_CmdInitStructure.SDIO_Argument = (uint32_t) RCA << 16;
  SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)55);
  SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
  SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
  SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
  SDIO_SendCommand(&SDIO_CmdInitStructure);
  errorstatus = CmdResp1Error(((uint8_t)55));

  if (errorstatus != SD_OK)
  {
    return(errorstatus);
  }

  SDIO_DataInitStructure.SDIO_DataTimeOut = ((uint32_t)0x000FFFFF);
  SDIO_DataInitStructure.SDIO_DataLength = 64;
  SDIO_DataInitStructure.SDIO_DataBlockSize = ((uint32_t)0x00000060);
  SDIO_DataInitStructure.SDIO_TransferDir = ((uint32_t)0x00000002);
  SDIO_DataInitStructure.SDIO_TransferMode = ((uint32_t)0x00000000);
  SDIO_DataInitStructure.SDIO_DPSM = ((uint32_t)0x00000001);
  SDIO_DataConfig(&SDIO_DataInitStructure);

   
  SDIO_CmdInitStructure.SDIO_Argument = 0;
  SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)13);
  SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
  SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
  SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
  SDIO_SendCommand(&SDIO_CmdInitStructure);
  errorstatus = CmdResp1Error(((uint8_t)13));

  if (errorstatus != SD_OK)
  {
    return(errorstatus);
  }

  while (!(((SDIO_TypeDef *)(0x40000000U + 0x00018000U))->STA &(((uint32_t)0x00000020) | ((uint32_t)0x00000002) | ((uint32_t)0x00000008) | ((uint32_t)0x00000400) | ((uint32_t)0x00000200))))
  {
    if (SDIO_GetFlagStatus(((uint32_t)0x00008000)) != RESET)
    {
      for (count = 0; count < 8; count++)
      {
        *(psdstatus + count) = SDIO_ReadData();
      }
      psdstatus += 8;
    }
  }

  if (SDIO_GetFlagStatus(((uint32_t)0x00000008)) != RESET)
  {
    SDIO_ClearFlag(((uint32_t)0x00000008));
    errorstatus = SD_DATA_TIMEOUT;
    return(errorstatus);
  }
  else if (SDIO_GetFlagStatus(((uint32_t)0x00000002)) != RESET)
  {
    SDIO_ClearFlag(((uint32_t)0x00000002));
    errorstatus = SD_DATA_CRC_FAIL;
    return(errorstatus);
  }
  else if (SDIO_GetFlagStatus(((uint32_t)0x00000020)) != RESET)
  {
    SDIO_ClearFlag(((uint32_t)0x00000020));
    errorstatus = SD_RX_OVERRUN;
    return(errorstatus);
  }
  else if (SDIO_GetFlagStatus(((uint32_t)0x00000200)) != RESET)
  {
    SDIO_ClearFlag(((uint32_t)0x00000200));
    errorstatus = SD_START_BIT_ERR;
    return(errorstatus);
  }

  while (SDIO_GetFlagStatus(((uint32_t)0x00200000)) != RESET)
  {
    *psdstatus = SDIO_ReadData();
    psdstatus++;
  }

   
  SDIO_ClearFlag(((uint32_t)0x000005FF));
  psdstatus -= 16;
  for (count = 0; count < 16; count++)
  {
    psdstatus[count] = ((psdstatus[count] & ((uint32_t)0x000000FF)) << 24) |((psdstatus[count] & ((uint32_t)0x0000FF00)) << 8) |
                       ((psdstatus[count] & ((uint32_t)0x00FF0000)) >> 8) |((psdstatus[count] & ((uint32_t)0xFF000000)) >> 24);
  }
  return(errorstatus);
}





 
SD_Error SD_ProcessIRQSrc(void)
{
  uint32_t count = 0, restwords = 0;

  if (DeviceMode == ((uint32_t)0x00000001))
  {
    if (SDIO_GetITStatus(((uint32_t)0x00008000)) != RESET)
    {
      for (count = 0; count < ((uint32_t)0x00000008); count++)
      {
        *(DestBuffer + count) = SDIO_ReadData();
      }
      DestBuffer += ((uint32_t)0x00000008);
      NumberOfBytes += ((uint32_t)0x00000020);
    }
    else if (SDIO_GetITStatus(((uint32_t)0x00004000)) != RESET)
    {
      if ((TotalNumberOfBytes - NumberOfBytes) < ((uint32_t)0x00000020))
      {
        restwords = ((TotalNumberOfBytes - NumberOfBytes) %  4 == 0) ?
                    ((TotalNumberOfBytes - NumberOfBytes) / 4) :
                    ((TotalNumberOfBytes - NumberOfBytes) / 4 + 1);

        for (count = 0; count < restwords;  count++, SrcBuffer++, NumberOfBytes += 4)
        {
          SDIO_WriteData(*SrcBuffer);
        }
      }
      else
      {
        for (count = 0; count < ((uint32_t)0x00000008); count++)
        {
          SDIO_WriteData(*(SrcBuffer + count));
        }

        SrcBuffer += ((uint32_t)0x00000008);
        NumberOfBytes += ((uint32_t)0x00000020);
      }
    }
  }

  if (SDIO_GetITStatus(((uint32_t)0x00000100)) != RESET)
  {
    if (DeviceMode != ((uint32_t)0x00000000))
    {
      while ((SDIO_GetFlagStatus(((uint32_t)0x00200000)) != RESET)  &&  (NumberOfBytes < TotalNumberOfBytes))
      {
        *DestBuffer = SDIO_ReadData();
        DestBuffer++;
        NumberOfBytes += 4;
      }
    }

    if (StopCondition == 1)
    {
      TransferError = SD_StopTransfer();
    }
    else
    {
      TransferError = SD_OK;
    }
    SDIO_ClearITPendingBit(((uint32_t)0x00000100));
    SDIO_ITConfig(((uint32_t)0x00000002) | ((uint32_t)0x00000008) | ((uint32_t)0x00000100) |
                  ((uint32_t)0x00004000) | ((uint32_t)0x00008000) | ((uint32_t)0x00000010) |
                  ((uint32_t)0x00000020) | ((uint32_t)0x00000200), DISABLE);
    TransferEnd = 1;
    NumberOfBytes = 0;
    return(TransferError);
  }

  if (SDIO_GetITStatus(((uint32_t)0x00000002)) != RESET)
  {
    SDIO_ClearITPendingBit(((uint32_t)0x00000002));
    SDIO_ITConfig(((uint32_t)0x00000002) | ((uint32_t)0x00000008) | ((uint32_t)0x00000100) |
                  ((uint32_t)0x00004000) | ((uint32_t)0x00008000) | ((uint32_t)0x00000010) |
                  ((uint32_t)0x00000020) | ((uint32_t)0x00000200), DISABLE);
    NumberOfBytes = 0;
    TransferError = SD_DATA_CRC_FAIL;
    return(SD_DATA_CRC_FAIL);
  }

  if (SDIO_GetITStatus(((uint32_t)0x00000008)) != RESET)
  {
    SDIO_ClearITPendingBit(((uint32_t)0x00000008));
    SDIO_ITConfig(((uint32_t)0x00000002) | ((uint32_t)0x00000008) | ((uint32_t)0x00000100) |
                  ((uint32_t)0x00004000) | ((uint32_t)0x00008000) | ((uint32_t)0x00000010) |
                  ((uint32_t)0x00000020) | ((uint32_t)0x00000200), DISABLE);
    NumberOfBytes = 0;
    TransferError = SD_DATA_TIMEOUT;
    return(SD_DATA_TIMEOUT);
  }

  if (SDIO_GetITStatus(((uint32_t)0x00000020)) != RESET)
  {
    SDIO_ClearITPendingBit(((uint32_t)0x00000020));
    SDIO_ITConfig(((uint32_t)0x00000002) | ((uint32_t)0x00000008) | ((uint32_t)0x00000100) |
                  ((uint32_t)0x00004000) | ((uint32_t)0x00008000) | ((uint32_t)0x00000010) |
                  ((uint32_t)0x00000020) | ((uint32_t)0x00000200), DISABLE);
    NumberOfBytes = 0;
    TransferError = SD_RX_OVERRUN;
    return(SD_RX_OVERRUN);
  }

  if (SDIO_GetITStatus(((uint32_t)0x00000010)) != RESET)
  {
    SDIO_ClearITPendingBit(((uint32_t)0x00000010));
    SDIO_ITConfig(((uint32_t)0x00000002) | ((uint32_t)0x00000008) | ((uint32_t)0x00000100) |
                  ((uint32_t)0x00004000) | ((uint32_t)0x00008000) | ((uint32_t)0x00000010) |
                  ((uint32_t)0x00000020) | ((uint32_t)0x00000200), DISABLE);
    NumberOfBytes = 0;
    TransferError = SD_TX_UNDERRUN;
    return(SD_TX_UNDERRUN);
  }

  if (SDIO_GetITStatus(((uint32_t)0x00000200)) != RESET)
  {
    SDIO_ClearITPendingBit(((uint32_t)0x00000200));
    SDIO_ITConfig(((uint32_t)0x00000002) | ((uint32_t)0x00000008) | ((uint32_t)0x00000100) |
                  ((uint32_t)0x00004000) | ((uint32_t)0x00008000) | ((uint32_t)0x00000010) |
                  ((uint32_t)0x00000020) | ((uint32_t)0x00000200), DISABLE);
    NumberOfBytes = 0;
    TransferError = SD_START_BIT_ERR;
    return(SD_START_BIT_ERR);
  }

  return(SD_OK);
}





 
static SD_Error CmdError(void)
{
  SD_Error errorstatus = SD_OK;
  uint32_t timeout;

  timeout = ((uint32_t)0x00010000);  

  while ((timeout > 0) && (SDIO_GetFlagStatus(((uint32_t)0x00000080)) == RESET))
  {
    timeout--;
  }

  if (timeout == 0)
  {
    errorstatus = SD_CMD_RSP_TIMEOUT;
    return(errorstatus);
  }

   
  SDIO_ClearFlag(((uint32_t)0x000005FF));

  return(errorstatus);
}





 
static SD_Error CmdResp7Error(void)
{
  SD_Error errorstatus = SD_OK;
  uint32_t status;
  uint32_t timeout = ((uint32_t)0x00010000);

  status = ((SDIO_TypeDef *)(0x40000000U + 0x00018000U))->STA;

  while (!(status & (((uint32_t)0x00000001) | ((uint32_t)0x00000040) | ((uint32_t)0x00000004))) && (timeout > 0))
  {
    timeout--;
    status = ((SDIO_TypeDef *)(0x40000000U + 0x00018000U))->STA;
  }

  if ((timeout == 0) || (status & ((uint32_t)0x00000004)))
  {
     
    errorstatus = SD_CMD_RSP_TIMEOUT;
    SDIO_ClearFlag(((uint32_t)0x00000004));
    return(errorstatus);
  }

  if (status & ((uint32_t)0x00000040))
  {
     
    errorstatus = SD_OK;
    SDIO_ClearFlag(((uint32_t)0x00000040));
    return(errorstatus);
  }
  return(errorstatus);
}





 
static SD_Error CmdResp1Error(uint8_t cmd)
{
  SD_Error errorstatus = SD_OK;
  uint32_t status;
  uint32_t response_r1;

  status = ((SDIO_TypeDef *)(0x40000000U + 0x00018000U))->STA;

  while (!(status & (((uint32_t)0x00000001) | ((uint32_t)0x00000040) | ((uint32_t)0x00000004))))
  {
    status = ((SDIO_TypeDef *)(0x40000000U + 0x00018000U))->STA;
  }

  if (status & ((uint32_t)0x00000004))
  {
    errorstatus = SD_CMD_RSP_TIMEOUT;
    SDIO_ClearFlag(((uint32_t)0x00000004));
    return(errorstatus);
  }
  else if (status & ((uint32_t)0x00000001))
  {
    errorstatus = SD_CMD_CRC_FAIL;
    SDIO_ClearFlag(((uint32_t)0x00000001));
    return(errorstatus);
  }

   
  if (SDIO_GetCommandResponse() != cmd)
  {
    errorstatus = SD_ILLEGAL_CMD;
    return(errorstatus);
  }

   
  SDIO_ClearFlag(((uint32_t)0x000005FF));

   
  response_r1 = SDIO_GetResponse(((uint32_t)0x00000000));

  if ((response_r1 & ((uint32_t)0xFDFFE008)) == ((uint32_t)0x00000000))
  {
    return(errorstatus);
  }

  if (response_r1 & ((uint32_t)0x80000000))
  {
    return(SD_ADDR_OUT_OF_RANGE);
  }

  if (response_r1 & ((uint32_t)0x40000000))
  {
    return(SD_ADDR_MISALIGNED);
  }

  if (response_r1 & ((uint32_t)0x20000000))
  {
    return(SD_BLOCK_LEN_ERR);
  }

  if (response_r1 & ((uint32_t)0x10000000))
  {
    return(SD_ERASE_SEQ_ERR);
  }

  if (response_r1 & ((uint32_t)0x08000000))
  {
    return(SD_BAD_ERASE_PARAM);
  }

  if (response_r1 & ((uint32_t)0x04000000))
  {
    return(SD_WRITE_PROT_VIOLATION);
  }

  if (response_r1 & ((uint32_t)0x01000000))
  {
    return(SD_LOCK_UNLOCK_FAILED);
  }

  if (response_r1 & ((uint32_t)0x00800000))
  {
    return(SD_COM_CRC_FAILED);
  }

  if (response_r1 & ((uint32_t)0x00400000))
  {
    return(SD_ILLEGAL_CMD);
  }

  if (response_r1 & ((uint32_t)0x00200000))
  {
    return(SD_CARD_ECC_FAILED);
  }

  if (response_r1 & ((uint32_t)0x00100000))
  {
    return(SD_CC_ERROR);
  }

  if (response_r1 & ((uint32_t)0x00080000))
  {
    return(SD_GENERAL_UNKNOWN_ERROR);
  }

  if (response_r1 & ((uint32_t)0x00040000))
  {
    return(SD_STREAM_READ_UNDERRUN);
  }

  if (response_r1 & ((uint32_t)0x00020000))
  {
    return(SD_STREAM_WRITE_OVERRUN);
  }

  if (response_r1 & ((uint32_t)0x00010000))
  {
    return(SD_CID_CSD_OVERWRITE);
  }

  if (response_r1 & ((uint32_t)0x00008000))
  {
    return(SD_WP_ERASE_SKIP);
  }

  if (response_r1 & ((uint32_t)0x00004000))
  {
    return(SD_CARD_ECC_DISABLED);
  }

  if (response_r1 & ((uint32_t)0x00002000))
  {
    return(SD_ERASE_RESET);
  }

  if (response_r1 & ((uint32_t)0x00000008))
  {
    return(SD_AKE_SEQ_ERROR);
  }
  return(errorstatus);
}





 
static SD_Error CmdResp3Error(void)
{
  SD_Error errorstatus = SD_OK;
  uint32_t status;

  status = ((SDIO_TypeDef *)(0x40000000U + 0x00018000U))->STA;

  while (!(status & (((uint32_t)0x00000001) | ((uint32_t)0x00000040) | ((uint32_t)0x00000004))))
  {
    status = ((SDIO_TypeDef *)(0x40000000U + 0x00018000U))->STA;
  }

  if (status & ((uint32_t)0x00000004))
  {
    errorstatus = SD_CMD_RSP_TIMEOUT;
    SDIO_ClearFlag(((uint32_t)0x00000004));
    return(errorstatus);
  }
   
  SDIO_ClearFlag(((uint32_t)0x000005FF));
  return(errorstatus);
}





 
static SD_Error CmdResp2Error(void)
{
  SD_Error errorstatus = SD_OK;
  uint32_t status;

  status = ((SDIO_TypeDef *)(0x40000000U + 0x00018000U))->STA;

  while (!(status & (((uint32_t)0x00000001) | ((uint32_t)0x00000004) | ((uint32_t)0x00000040))))
  {
    status = ((SDIO_TypeDef *)(0x40000000U + 0x00018000U))->STA;
  }

  if (status & ((uint32_t)0x00000004))
  {
    errorstatus = SD_CMD_RSP_TIMEOUT;
    SDIO_ClearFlag(((uint32_t)0x00000004));
    return(errorstatus);
  }
  else if (status & ((uint32_t)0x00000001))
  {
    errorstatus = SD_CMD_CRC_FAIL;
    SDIO_ClearFlag(((uint32_t)0x00000001));
    return(errorstatus);
  }

   
  SDIO_ClearFlag(((uint32_t)0x000005FF));

  return(errorstatus);
}







 
static SD_Error CmdResp6Error(uint8_t cmd, uint16_t *prca)
{
  SD_Error errorstatus = SD_OK;
  uint32_t status;
  uint32_t response_r1;

  status = ((SDIO_TypeDef *)(0x40000000U + 0x00018000U))->STA;

  while (!(status & (((uint32_t)0x00000001) | ((uint32_t)0x00000004) | ((uint32_t)0x00000040))))
  {
    status = ((SDIO_TypeDef *)(0x40000000U + 0x00018000U))->STA;
  }

  if (status & ((uint32_t)0x00000004))
  {
    errorstatus = SD_CMD_RSP_TIMEOUT;
    SDIO_ClearFlag(((uint32_t)0x00000004));
    return(errorstatus);
  }
  else if (status & ((uint32_t)0x00000001))
  {
    errorstatus = SD_CMD_CRC_FAIL;
    SDIO_ClearFlag(((uint32_t)0x00000001));
    return(errorstatus);
  }

   
  if (SDIO_GetCommandResponse() != cmd)
  {
    errorstatus = SD_ILLEGAL_CMD;
    return(errorstatus);
  }

   
  SDIO_ClearFlag(((uint32_t)0x000005FF));

   
  response_r1 = SDIO_GetResponse(((uint32_t)0x00000000));

  if (((uint32_t)0x00000000) == (response_r1 & (((uint32_t)0x00002000) | ((uint32_t)0x00004000) | ((uint32_t)0x00008000))))
  {
    *prca = (uint16_t) (response_r1 >> 16);
    return(errorstatus);
  }

  if (response_r1 & ((uint32_t)0x00002000))
  {
    return(SD_GENERAL_UNKNOWN_ERROR);
  }

  if (response_r1 & ((uint32_t)0x00004000))
  {
    return(SD_ILLEGAL_CMD);
  }

  if (response_r1 & ((uint32_t)0x00008000))
  {
    return(SD_COM_CRC_FAILED);
  }

  return(errorstatus);
}






 
static SD_Error SDEnWideBus(FunctionalState NewState)
{
  SD_Error errorstatus = SD_OK;

  uint32_t scr[2] = {0, 0};

  if (SDIO_GetResponse(((uint32_t)0x00000000)) & ((uint32_t)0x02000000))
  {
    errorstatus = SD_LOCK_UNLOCK_FAILED;
    return(errorstatus);
  }

   
  errorstatus = FindSCR(RCA, scr);

  if (errorstatus != SD_OK)
  {
    return(errorstatus);
  }

   
  if (NewState == ENABLE)
  {
     
    if ((scr[1] & ((uint32_t)0x00040000)) != ((uint32_t)0x00000000))
    {
       
      SDIO_CmdInitStructure.SDIO_Argument = (uint32_t) RCA << 16;
      SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)55);
      SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
      SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
      SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
      SDIO_SendCommand(&SDIO_CmdInitStructure);

      errorstatus = CmdResp1Error(((uint8_t)55));

      if (errorstatus != SD_OK)
      {
        return(errorstatus);
      }

       
      SDIO_CmdInitStructure.SDIO_Argument = 0x2;
      SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)6);
      SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
      SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
      SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
      SDIO_SendCommand(&SDIO_CmdInitStructure);

      errorstatus = CmdResp1Error(((uint8_t)6));

      if (errorstatus != SD_OK)
      {
        return(errorstatus);
      }
      return(errorstatus);
    }
    else
    {
      errorstatus = SD_REQUEST_NOT_APPLICABLE;
      return(errorstatus);
    }
  }    
  else
  {
     
    if ((scr[1] & ((uint32_t)0x00010000)) != ((uint32_t)0x00000000))
    {
       
      SDIO_CmdInitStructure.SDIO_Argument = (uint32_t) RCA << 16;
      SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)55);
      SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
      SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
      SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
      SDIO_SendCommand(&SDIO_CmdInitStructure);


      errorstatus = CmdResp1Error(((uint8_t)55));

      if (errorstatus != SD_OK)
      {
        return(errorstatus);
      }

       
      SDIO_CmdInitStructure.SDIO_Argument = 0x00;
      SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)6);
      SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
      SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
      SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
      SDIO_SendCommand(&SDIO_CmdInitStructure);

      errorstatus = CmdResp1Error(((uint8_t)6));

      if (errorstatus != SD_OK)
      {
        return(errorstatus);
      }

      return(errorstatus);
    }
    else
    {
      errorstatus = SD_REQUEST_NOT_APPLICABLE;
      return(errorstatus);
    }
  }
}





 
static SD_Error IsCardProgramming(uint8_t *pstatus)
{
  SD_Error errorstatus = SD_OK;
  volatile uint32_t respR1 = 0, status = 0;

  SDIO_CmdInitStructure.SDIO_Argument = (uint32_t) RCA << 16;
  SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)13);
  SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
  SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
  SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
  SDIO_SendCommand(&SDIO_CmdInitStructure);

  status = ((SDIO_TypeDef *)(0x40000000U + 0x00018000U))->STA;
  while (!(status & (((uint32_t)0x00000001) | ((uint32_t)0x00000040) | ((uint32_t)0x00000004))))
  {
    status = ((SDIO_TypeDef *)(0x40000000U + 0x00018000U))->STA;
  }

  if (status & ((uint32_t)0x00000004))
  {
    errorstatus = SD_CMD_RSP_TIMEOUT;
    SDIO_ClearFlag(((uint32_t)0x00000004));
    return(errorstatus);
  }
  else if (status & ((uint32_t)0x00000001))
  {
    errorstatus = SD_CMD_CRC_FAIL;
    SDIO_ClearFlag(((uint32_t)0x00000001));
    return(errorstatus);
  }

  status = (uint32_t)SDIO_GetCommandResponse();

   
  if (status != ((uint8_t)13))
  {
    errorstatus = SD_ILLEGAL_CMD;
    return(errorstatus);
  }

   
  SDIO_ClearFlag(((uint32_t)0x000005FF));


   
  respR1 = SDIO_GetResponse(((uint32_t)0x00000000));

   
  *pstatus = (uint8_t) ((respR1 >> 9) & 0x0000000F);

  if ((respR1 & ((uint32_t)0xFDFFE008)) == ((uint32_t)0x00000000))
  {
    return(errorstatus);
  }

  if (respR1 & ((uint32_t)0x80000000))
  {
    return(SD_ADDR_OUT_OF_RANGE);
  }

  if (respR1 & ((uint32_t)0x40000000))
  {
    return(SD_ADDR_MISALIGNED);
  }

  if (respR1 & ((uint32_t)0x20000000))
  {
    return(SD_BLOCK_LEN_ERR);
  }

  if (respR1 & ((uint32_t)0x10000000))
  {
    return(SD_ERASE_SEQ_ERR);
  }

  if (respR1 & ((uint32_t)0x08000000))
  {
    return(SD_BAD_ERASE_PARAM);
  }

  if (respR1 & ((uint32_t)0x04000000))
  {
    return(SD_WRITE_PROT_VIOLATION);
  }

  if (respR1 & ((uint32_t)0x01000000))
  {
    return(SD_LOCK_UNLOCK_FAILED);
  }

  if (respR1 & ((uint32_t)0x00800000))
  {
    return(SD_COM_CRC_FAILED);
  }

  if (respR1 & ((uint32_t)0x00400000))
  {
    return(SD_ILLEGAL_CMD);
  }

  if (respR1 & ((uint32_t)0x00200000))
  {
    return(SD_CARD_ECC_FAILED);
  }

  if (respR1 & ((uint32_t)0x00100000))
  {
    return(SD_CC_ERROR);
  }

  if (respR1 & ((uint32_t)0x00080000))
  {
    return(SD_GENERAL_UNKNOWN_ERROR);
  }

  if (respR1 & ((uint32_t)0x00040000))
  {
    return(SD_STREAM_READ_UNDERRUN);
  }

  if (respR1 & ((uint32_t)0x00020000))
  {
    return(SD_STREAM_WRITE_OVERRUN);
  }

  if (respR1 & ((uint32_t)0x00010000))
  {
    return(SD_CID_CSD_OVERWRITE);
  }

  if (respR1 & ((uint32_t)0x00008000))
  {
    return(SD_WP_ERASE_SKIP);
  }

  if (respR1 & ((uint32_t)0x00004000))
  {
    return(SD_CARD_ECC_DISABLED);
  }

  if (respR1 & ((uint32_t)0x00002000))
  {
    return(SD_ERASE_RESET);
  }

  if (respR1 & ((uint32_t)0x00000008))
  {
    return(SD_AKE_SEQ_ERROR);
  }

  return(errorstatus);
}






 
static SD_Error FindSCR(uint16_t rca, uint32_t *pscr)
{
  uint32_t index = 0;
  SD_Error errorstatus = SD_OK;
  uint32_t tempscr[2] = {0, 0};

   
   
  SDIO_CmdInitStructure.SDIO_Argument = (uint32_t)8;
  SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)16);
  SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
  SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
  SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
  SDIO_SendCommand(&SDIO_CmdInitStructure);

  errorstatus = CmdResp1Error(((uint8_t)16));

  if (errorstatus != SD_OK)
  {
    return(errorstatus);
  }

   
  SDIO_CmdInitStructure.SDIO_Argument = (uint32_t) RCA << 16;
  SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)55);
  SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
  SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
  SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
  SDIO_SendCommand(&SDIO_CmdInitStructure);

  errorstatus = CmdResp1Error(((uint8_t)55));

  if (errorstatus != SD_OK)
  {
    return(errorstatus);
  }
  SDIO_DataInitStructure.SDIO_DataTimeOut = ((uint32_t)0x000FFFFF);
  SDIO_DataInitStructure.SDIO_DataLength = 8;
  SDIO_DataInitStructure.SDIO_DataBlockSize = ((uint32_t)0x00000030);
  SDIO_DataInitStructure.SDIO_TransferDir = ((uint32_t)0x00000002);
  SDIO_DataInitStructure.SDIO_TransferMode = ((uint32_t)0x00000000);
  SDIO_DataInitStructure.SDIO_DPSM = ((uint32_t)0x00000001);
  SDIO_DataConfig(&SDIO_DataInitStructure);


   
  SDIO_CmdInitStructure.SDIO_Argument = 0x0;
  SDIO_CmdInitStructure.SDIO_CmdIndex = ((uint8_t)51);
  SDIO_CmdInitStructure.SDIO_Response = ((uint32_t)0x00000040);
  SDIO_CmdInitStructure.SDIO_Wait = ((uint32_t)0x00000000);
  SDIO_CmdInitStructure.SDIO_CPSM = ((uint32_t)0x00000400);
  SDIO_SendCommand(&SDIO_CmdInitStructure);

  errorstatus = CmdResp1Error(((uint8_t)51));

  if (errorstatus != SD_OK)
  {
    return(errorstatus);
  }

  while (!(((SDIO_TypeDef *)(0x40000000U + 0x00018000U))->STA & (((uint32_t)0x00000020) | ((uint32_t)0x00000002) | ((uint32_t)0x00000008) | ((uint32_t)0x00000400) | ((uint32_t)0x00000200))))
  {
    if (SDIO_GetFlagStatus(((uint32_t)0x00200000)) != RESET)
    {
      *(tempscr + index) = SDIO_ReadData();
      index++;
    }
  }

  if (SDIO_GetFlagStatus(((uint32_t)0x00000008)) != RESET)
  {
    SDIO_ClearFlag(((uint32_t)0x00000008));
    errorstatus = SD_DATA_TIMEOUT;
    return(errorstatus);
  }
  else if (SDIO_GetFlagStatus(((uint32_t)0x00000002)) != RESET)
  {
    SDIO_ClearFlag(((uint32_t)0x00000002));
    errorstatus = SD_DATA_CRC_FAIL;
    return(errorstatus);
  }
  else if (SDIO_GetFlagStatus(((uint32_t)0x00000020)) != RESET)
  {
    SDIO_ClearFlag(((uint32_t)0x00000020));
    errorstatus = SD_RX_OVERRUN;
    return(errorstatus);
  }
  else if (SDIO_GetFlagStatus(((uint32_t)0x00000200)) != RESET)
  {
    SDIO_ClearFlag(((uint32_t)0x00000200));
    errorstatus = SD_START_BIT_ERR;
    return(errorstatus);
  }

   
  SDIO_ClearFlag(((uint32_t)0x000005FF));

  *(pscr + 1) = ((tempscr[0] & ((uint32_t)0x000000FF)) << 24) | ((tempscr[0] & ((uint32_t)0x0000FF00)) << 8) | ((tempscr[0] & ((uint32_t)0x00FF0000)) >> 8) | ((tempscr[0] & ((uint32_t)0xFF000000)) >> 24);

  *(pscr) = ((tempscr[1] & ((uint32_t)0x000000FF)) << 24) | ((tempscr[1] & ((uint32_t)0x0000FF00)) << 8) | ((tempscr[1] & ((uint32_t)0x00FF0000)) >> 8) | ((tempscr[1] & ((uint32_t)0xFF000000)) >> 24);

  return(errorstatus);
}





 
static uint8_t convert_from_bytes_to_power_of_two(uint16_t NumberOfBytes)
{
  uint8_t count = 0;

  while (NumberOfBytes != 1)
  {
    NumberOfBytes >>= 1;
    count++;
  }
  return(count);
}

void SDIOEx_Init()
{
    SD_Error errorstatus = SD_OK;

    SDIO_DeInit();
    errorstatus = SD_PowerON();

    if (errorstatus != SD_OK) {
         
        return;
    }

    errorstatus = SD_InitializeCards();

    if (errorstatus != SD_OK) {
         
        return;
    }

     
     
    SDIO_InitStructure.SDIO_ClockDiv = ((uint8_t)0x1); 
    SDIO_InitStructure.SDIO_ClockEdge = ((uint32_t)0x00000000);
    SDIO_InitStructure.SDIO_ClockBypass = ((uint32_t)0x00000000);
    SDIO_InitStructure.SDIO_ClockPowerSave = ((uint32_t)0x00000000);
    SDIO_InitStructure.SDIO_BusWide = ((uint32_t)0x00000000);
    SDIO_InitStructure.SDIO_HardwareFlowControl = ((uint32_t)0x00000000);
    SDIO_Init(&SDIO_InitStructure);
  
    if (errorstatus == SD_OK) {
         
        errorstatus = SD_GetCardInfo(&SDCardInfo);
    }

    if (errorstatus == SD_OK) {
         
        errorstatus = SD_SelectDeselect((uint32_t) (SDCardInfo.RCA << 16));
    }

    if (errorstatus == SD_OK) {
        errorstatus = SD_EnableWideBusOperation(((uint32_t)0x00000000));
    }

    return;
}
