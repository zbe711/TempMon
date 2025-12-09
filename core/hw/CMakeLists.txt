# HW layer - collect sources and includes
set(HW_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/HwRev.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/HwRevA.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/HwRevB.cpp
    PARENT_SCOPE
)
set(HW_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/inc PARENT_SCOPE)
