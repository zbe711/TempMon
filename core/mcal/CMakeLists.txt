# MCAL layer - Microcontroller Abstraction Layer
# Collect all sources and includes from MCAL components
set(MCAL_SOURCES "")
set(MCAL_INCLUDES "")

add_subdirectory(gpio)
add_subdirectory(gpt)
add_subdirectory(i2c)
add_subdirectory(adc)
add_subdirectory(wdg)

# Aggregate all MCAL sources and includes
list(APPEND MCAL_SOURCES ${MCAL_GPIO_SOURCES})
list(APPEND MCAL_SOURCES ${MCAL_GPT_SOURCES})
list(APPEND MCAL_SOURCES ${MCAL_I2C_SOURCES})
list(APPEND MCAL_SOURCES ${MCAL_ADC_SOURCES})
list(APPEND MCAL_SOURCES ${MCAL_WDG_SOURCES})

list(APPEND MCAL_INCLUDES ${MCAL_GPIO_INCLUDES})
list(APPEND MCAL_INCLUDES ${MCAL_GPT_INCLUDES})
list(APPEND MCAL_INCLUDES ${MCAL_I2C_INCLUDES})
list(APPEND MCAL_INCLUDES ${MCAL_ADC_INCLUDES})
list(APPEND MCAL_INCLUDES ${MCAL_WDG_INCLUDES})

# Export to parent scope
set(MCAL_SOURCES ${MCAL_SOURCES} PARENT_SCOPE)
set(MCAL_INCLUDES ${MCAL_INCLUDES} PARENT_SCOPE)

