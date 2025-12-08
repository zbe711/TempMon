# GPIO driver - collect sources and includes
set(MCAL_GPIO_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gpio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gpio.cpp
    PARENT_SCOPE
)
set(MCAL_GPIO_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/inc PARENT_SCOPE)

