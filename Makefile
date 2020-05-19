all:
	make -C stm32_application
	make -C stm32_cpp
	make -C stm32_manager

app:
	make -C stm32_application

cpp:
	make -C stm32_cpp

mgr:
	make -C stm32_manager

clean:
	make -C stm32_application clean
	make -C stm32_cpp clean
	make -C stm32_manager clean