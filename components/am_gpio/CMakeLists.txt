# include paths of this components.
set(COMPONENT_ADD_INCLUDEDIRS include)

# source files of this components.
set(COMPONENT_SRCDIRS src)

# Project dependencies.
# set before calling register_component().
set(COMPONENT_REQUIRES am_queue am_flags am_rtc)


# add this components, this will define a CMake library target.
register_component()