# Mon service - collect sources and includes
set(SERVICES_MON_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mon.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mon.cpp
    PARENT_SCOPE
)
set(SERVICES_MON_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/inc PARENT_SCOPE)

