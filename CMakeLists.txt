cmake_minimum_required(VERSION 3.15)

project(TempMon LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include core components (MCAL, Services)
add_subdirectory(core)

# Build language selector (C or Cpp)
set(BUILD_LANG "C" CACHE STRING "Language to build: C or Cpp")
set_property(CACHE BUILD_LANG PROPERTY STRINGS C Cpp)

if(BUILD_LANG STREQUAL "C")
    message(STATUS "Configuring C99 TempMon target")
    add_executable(tempmon_c
        core/app/main_c.c
        ${CORE_SOURCES}
    )
    # Add all include directories
    target_include_directories(tempmon_c PRIVATE
        ${CORE_INCLUDES}
    )
elseif(BUILD_LANG STREQUAL "Cpp")
    message(STATUS "Configuring C++ TempMon target")
    add_executable(tempmon_cpp
        core/app/main_cpp.cpp
    )
else()
    message(FATAL_ERROR "Unknown BUILD_LANG='${BUILD_LANG}'. Use 'C' or 'Cpp'.")
endif()


