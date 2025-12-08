# Time service - collect sources and includes
set(SERVICES_TIME_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/time.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/time.cpp
    PARENT_SCOPE
)
set(SERVICES_TIME_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/inc PARENT_SCOPE)

