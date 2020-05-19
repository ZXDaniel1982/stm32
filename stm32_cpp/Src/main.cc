#include "driver.hpp"
#include "spc.hpp"

int main()
{
    auto stm32f103vet = std::shared_ptr<STM32F103VET>();
    
    SinglePC singlePC(stm32f103vet);
    
    singlePC.Right();
    singlePC.Right();
    singlePC.Right();
    singlePC.Right();
    singlePC.Right();
    singlePC.Right();
    
    while (1) {
        
    }

    return 0;
}
