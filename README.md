# stm32

1. Boot argument struct
    | 0x4455  |  config src  |  current src  |  version  |  0x5566  |
    config src :  [NULL | EEPROM | SD]
    current src : [NULL | EEPROM | SD]

2. Image argument struct
    | 0x2233  |  version     |  size         |  0x8899   |

3. EEPROM data struct
    |  content      |  address  |  size  |
    ----------------------------------
    |  boot args    |  0x00     |  28B   |
    |  image args   |  4096     |  5B    |
    |  app image    |  8192     |  --    |

4. SD data struct
    |  content      |  address  |  size  |
    ----------------------------------
    |  boot args    |  0x00     |  5B    |
    |  image args   |  512      |  --    |

5. Bootloader commands
    * printenv
    * setenv :   setenv [ImageSrcConfig [EEPROM | SD] | ImageSrcState [EEPROM | SD] | ImageVersion <version>] 
    * saveenv
    * backup
    * bootm

