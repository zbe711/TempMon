.. req:: Placerholder for system requirements
   :id: SYS_RS_ID_{n}

   The {placeholder requirements} shall follow **EARS Method** 
   The Easy Approach to Requirements Syntax.

.. req:: Temperature sensor via ADC
   :id: SYS_RS_ID_1

   The system shall acquire temperature measurements from a sensor connected via the ADC interface.

.. req:: Temperature sampling period
   :id: SYS_RS_ID_2

   The system shall sample the temperature sensor every 100 microseconds with very low jitter.

.. req:: Temperature Visual Monitoring
	:id: SYS_RS_ID_3

   The system shall visualize temperature conditions using three LEDs connected via GPIOs: Green (G), Yellow (Y), and Red (R).

.. req:: Green LED indication for normal operation
   :id: SYS_RS_ID_4

   When the measured temperature is less than 85°C, the system shall activate the Green LED to indicate normal operation.

.. req:: Yellow LED indication for warning level
   :id: SYS_RS_ID_5

   When the measured temperature is greater than or equal to 85°C and less than 105°C, the system shall activate the Yellow LED to indicate a warning level.

.. req:: Red LED indication for critical level
   :id: SYS_RS_ID_6

   When the measured temperature is greater than or equal to 105°C or less than 5°C, the system shall activate the Red LED to indicate a critical level.

.. req:: Support for Rev-A sensor resolution
   :id: SYS_RS_ID_7

   The system shall support sensor hardware revision Rev-A, which has a resolution of 1 degree Celsius per digit, where a digit value of 10 corresponds to 10°C.

.. req:: Support for Rev-B sensor resolution
   :id: SYS_RS_ID_8

   The system shall support sensor hardware revision Rev-B, which has a resolution of 0.1 degrees Celsius per digit, where a digit value of 100 corresponds to 10°C.

.. req:: Single sensor type operation
   :id: SYS_RS_ID_9

   The system shall operate with only one sensor type (Rev-A or Rev-B) at any given time during the same power cycle.

.. req:: EEPROM hardware revision configuration
   :id: SYS_RS_ID_10

   The system shall read the hardware revision from EEPROM and handle the resolutions accordingly.

.. req:: EEPROM hardware serial number configuration
   :id: SYS_RS_ID_11

   The system shall read a hardware configuration meta data from EEPROM such as serial number (for example: "ABC1234").


