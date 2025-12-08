# ADC driver - collect sources and includes
set(MCAL_ADC_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/adc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/adc.cpp
    PARENT_SCOPE
)
set(MCAL_ADC_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/inc PARENT_SCOPE)

