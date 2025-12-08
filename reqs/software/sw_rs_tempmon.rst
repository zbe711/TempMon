.. req:: Placerholder for software requirements
   :id: SW_RS_ID_{n}

   The {placeholder requirements} shall follow **EARS Method** 
   The Easy Approach to Requirements Syntax.

.. req:: NVM initialization
   :id: SW_RS_ID_1

   The software shall initialize the NVM interface at system startup.

.. req:: GPIO initialization
   :id: SW_RS_ID_2

   The software shall initialize GPIO pins for the three LEDs during system startup.

.. req:: Timer configuration for ADC triggering
   :id: SW_RS_ID_3

   The software shall configure a 10 KHz timer to trigger ADC sampling every 100 microseconds.

.. req:: ADC configuration with DMA
   :id: SW_RS_ID_4

   The software shall configure the ADC to be triggered by the timer and transfer sample to shared memory via DMA.

.. req:: Hardware revision reading
   :id: SW_RS_ID_5

   The software shall read the hardware revision from EEPROM during initialization.

.. req:: Serial number reading
   :id: SW_RS_ID_6

   The software shall read the hardware serial number from EEPROM during initialization.

.. req:: Temperature threshold reading
   :id: SW_RS_ID_7

   The software shall read temperature thresholds from EEPROM during initialization.

.. req:: Rev-A threshold normalization
   :id: SW_RS_ID_8

   When the hardware revision is Rev-A, the software shall apply a normalization factor of 1.0 to the temperature thresholds.

.. req:: Rev-B threshold normalization
   :id: SW_RS_ID_9

   When the hardware revision is Rev-B, the software shall apply a normalization factor of 10 to the temperature thresholds.

.. req:: DMA transfer complete ISR processing
   :id: SW_RS_ID_10

   When DMA completes a transfer, the interrupt service routine shall directly process the temperature sample for LED update.

.. req:: Temperature sample processing in ISR
   :id: SW_RS_ID_11

   The ISR shall process new temperature samples immediately upon DMA completion, ensuring execution completes within 1% of the sampling period.

.. req:: Temperature range evaluation in ISR
   :id: SW_RS_ID_12

   When a new sample is received via DMA, the ISR shall compare the ADC raw value against the normalized thresholds.

.. req:: Range determination
   :id: SW_RS_ID_13

   The ISR shall determine the temperature range as normal, warning, or critical based on the comparison result.

.. req:: LED state update in ISR
   :id: SW_RS_ID_14

   The ISR shall update the LED states based on the evaluated temperature range immediately after processing the sample.

