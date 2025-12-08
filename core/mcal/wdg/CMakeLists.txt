# WDG driver - collect sources and includes
set(MCAL_WDG_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/wdg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/wdg.cpp
    PARENT_SCOPE
)
set(MCAL_WDG_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/inc PARENT_SCOPE)

