# include paths of this components.
set(COMPONENT_ADD_INCLUDEDIRS include)

# source files of this components.
set(COMPONENT_SRCDIRS src)
# Alternatively, use COMPONENT_SRCS to specify source files explicitly
# set(COMPONENT_SRCS src/utils.c)

# If the dependencies are from ESP-IDF, use these 2 variables. Note these need to be
# set before calling register_component().
set(COMPONENT_REQUIRES am_queue am_flags)
#set(COMPONENT_REQUIRES am_flags)
#set(COMPONENT_PRIV_REQUIRES lwip)

# add this components, this will define a CMake library target.
register_component()

target_link_libraries(${COMPONENT_TARGET} PRIVATE AFR::wifi)
#target_link_libraries(${COMPONENT_TARGET} PRIVATE am_queue)
