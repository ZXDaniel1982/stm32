all:
	make -C stm32_application
	make -C stm32_cpp
	make -C stm32_manager

clean:
	make -C stm32_application clean
	make -C stm32_cpp clean
	make -C stm32_manager clean