# I2C driver - collect sources and includes
set(MCAL_I2C_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/i2c.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/i2c.cpp
    PARENT_SCOPE
)
set(MCAL_I2C_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/inc PARENT_SCOPE)

