#include "driver.hpp"

int main()
{
	auto logger = std::make_shared<STM32F103VET_LOGGER>();
    auto stm32f103vet = std::make_shared<STM32F103VET>(logger);

    
    while (1) {
        
    }

    return 0;
}
