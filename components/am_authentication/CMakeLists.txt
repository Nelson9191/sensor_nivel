# include paths of this components.
set(COMPONENT_ADD_INCLUDEDIRS include)

# source files of this components.
set(COMPONENT_SRCDIRS src)
# Alternatively, use COMPONENT_SRCS to specify source files explicitly
# set(COMPONENT_SRCS src/flags.c)

# add this components, this will define a CMake library target.
register_component()

target_link_libraries(${COMPONENT_TARGET} PRIVATE AFR::dev_mode_key_provisioning)
#target_link_libraries(${COMPONENT_TARGET} PRIVATE AFR::demo_base)
