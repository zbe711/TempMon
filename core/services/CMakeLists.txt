# Services layer - Middle layer components
# Collect all sources and includes from Services components
set(SERVICES_SOURCES "")
set(SERVICES_INCLUDES "")

add_subdirectory(nvm)
add_subdirectory(time)
add_subdirectory(mon)

# Aggregate all Services sources and includes
list(APPEND SERVICES_SOURCES ${SERVICES_NVM_SOURCES})
list(APPEND SERVICES_SOURCES ${SERVICES_TIME_SOURCES})
list(APPEND SERVICES_SOURCES ${SERVICES_MON_SOURCES})

list(APPEND SERVICES_INCLUDES ${SERVICES_NVM_INCLUDES})
list(APPEND SERVICES_INCLUDES ${SERVICES_TIME_INCLUDES})
list(APPEND SERVICES_INCLUDES ${SERVICES_MON_INCLUDES})

# Export to parent scope
set(SERVICES_SOURCES ${SERVICES_SOURCES} PARENT_SCOPE)
set(SERVICES_INCLUDES ${SERVICES_INCLUDES} PARENT_SCOPE)

