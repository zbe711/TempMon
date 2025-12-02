.. req:: Placerholder for hardware requirements
   :id: HW_RS_ID_{n}

   The {placeholder requirements} shall follow **EARS Method** 
   The Easy Approach to Requirements Syntax.

.. req:: ADC channel for temperature sensor
   :id: HW_RS_ID_1

   The hardware shall provide at least one ADC channel dedicated to the
   connection of the temperature sensor used by the TempMon system.

.. req:: GPIOs for three LEDs
   :id: HW_RS_ID_2

   The hardware shall provide three GPIO pins that can drive the Green (G),
   Yellow (Y) and Red (R) LEDs for temperature visualization.

.. req:: Non-volatile memory for configuration
   :id: HW_RS_ID_3

   The hardware shall include an EEPROM (or equivalent NVM) accessible by
   the MCU, which stores at least the hardware revision and a hardware
   serial number.

.. req:: Further HW Requirements Handling...
   :id: HW_RS_ID_{m}

   The {HW Engineers} shall follow **EARS Method** 
   The Easy Approach to Requirements Syntax to handle further HWRS.



