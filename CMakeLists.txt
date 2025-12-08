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

# Filter sources based on language
set(CORE_C_SOURCES "")
set(CORE_CPP_SOURCES "")
set(CORE_C_INCLUDES "")
set(CORE_CPP_INCLUDES "")

foreach(SOURCE ${CORE_SOURCES})
    if(SOURCE MATCHES "\\.c$")
        list(APPEND CORE_C_SOURCES ${SOURCE})
    elseif(SOURCE MATCHES "\\.cpp$")
        list(APPEND CORE_CPP_SOURCES ${SOURCE})
    endif()
endforeach()

if(BUILD_LANG STREQUAL "C")
    message(STATUS "Configuring C99 TempMon target")
    add_executable(tempmon_c
        core/app/main_c.c
        core/app/mock.c
        ${CORE_C_SOURCES}
    )
    target_include_directories(tempmon_c PRIVATE
        ${CORE_INCLUDES}
        core/app
    )
    if(UNIX)
        target_link_libraries(tempmon_c PRIVATE pthread)
    endif()
elseif(BUILD_LANG STREQUAL "Cpp")
    message(STATUS "Configuring C++ TempMon target")
    add_executable(tempmon_cpp
        core/app/main_cpp.cpp
        core/app/mock.cpp
        ${CORE_CPP_SOURCES}
    )
    target_include_directories(tempmon_cpp PRIVATE
        ${CORE_INCLUDES}
        core/app
    )
    if(UNIX)
        target_link_libraries(tempmon_cpp PRIVATE pthread)
    endif()
else()
    message(FATAL_ERROR "Unknown BUILD_LANG='${BUILD_LANG}'. Use 'C' or 'Cpp'.")
endif()


