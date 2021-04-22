# Instruction to add a new sensor.

## Add new sensor type

Add new sensor type to `Timer_Enum_t` in file `Core/Inc/timer.h`, new the sensor with format `Sensor<type>`

## Add new sensor Get and Set function

Add new sensor Get and Set function in file `Spc/Data/data.c`, new function with format `SpcData_Set<type>`

## Add new sensor file with process function

Create a new sensor file in folder `Spc/Sensor/Obj/`, add new sensor process function to this sensor file, function format `Sensor_Process<type>`