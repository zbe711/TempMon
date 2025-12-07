# Core software components
# Collect all sources and includes
set(CORE_SOURCES "")
set(CORE_INCLUDES "")

add_subdirectory(mcal)
add_subdirectory(services)

# Aggregate all core sources and includes
list(APPEND CORE_SOURCES ${MCAL_SOURCES})
list(APPEND CORE_SOURCES ${SERVICES_SOURCES})

list(APPEND CORE_INCLUDES ${MCAL_INCLUDES})
list(APPEND CORE_INCLUDES ${SERVICES_INCLUDES})

# Export to parent scope
set(CORE_SOURCES ${CORE_SOURCES} PARENT_SCOPE)
set(CORE_INCLUDES ${CORE_INCLUDES} PARENT_SCOPE)

