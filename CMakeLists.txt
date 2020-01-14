cmake_minimum_required(VERSION 3.13)

project(freertos_examples)


# Tell IDF build to link against this target.
set(IDF_PROJECT_EXECUTABLE my_app)


file(GLOB HEADERS "config_files/*.h")
file(GLOB SOURCES "src/*.c")
add_executable(my_app ${SOURCES} ${HEADERS})


#Configuration files
set(INCLUDE_DIRS ${INCLUDE_DIRS} 
    "config_files/"
    )
include_directories(${INCLUDE_DIRS})


# Add some extra components. IDF_EXTRA_COMPONENT_DIRS is an variable used by ESP-IDF
# to collect extra components.


get_filename_component(IP_CONFIG_COMPONENT "components/IP_config" ABSOLUTE)
#list(APPEND IDF_EXTRA_COMPONENT_DIRS ${EXTRA_COMPONENT_DIRS})

#get_filename_component(EXTRA_COMPONENT_DIRS "components/utils" ABSOLUTE)
get_filename_component(UTILS_COMPONENT "components/acua_utils" ABSOLUTE)
#list(APPEND IDF_EXTRA_COMPONENT_DIRS ${EXTRA_COMPONENT_DIRS})

#get_filename_component(EXTRA_COMPONENT_DIRS "components/flags" ABSOLUTE)
get_filename_component(FLAGS_COMPONENT "components/am_flags" ABSOLUTE)
#list(APPEND IDF_EXTRA_COMPONENT_DIRS ${EXTRA_COMPONENT_DIRS})

get_filename_component(AUTH_COMPONENT "components/am_authentication" ABSOLUTE)

get_filename_component(QUEUE_COMPONENT "components/am_queue" ABSOLUTE)

get_filename_component(MQTT_COMPONENT "components/am_mqtt" ABSOLUTE)

get_filename_component(WIFI_COMPONENT "components/am_wifi" ABSOLUTE)

get_filename_component(GPIO_COMPONENT "components/am_gpio" ABSOLUTE)

get_filename_component(RTC_COMPONENT "components/am_rtc" ABSOLUTE)




get_filename_component(ESPRESSIF_CODE_COMPONENT "/amazon-freertos/vendors/espressif/boards/esp32/aws_demos/config_files" ABSOLUTE)
#get_filename_component(ESPRESSIF_CODE_COMPONENT "/amazon-freertos/vendors/espressif/boards/esp32/aws_demos/application_code/espressif_code" ABSOLUTE)


# Add some external components to the project
set(IDF_EXTRA_COMPONENT_DIRS 
    ${IP_CONFIG_COMPONENT}
    ${UTILS_COMPONENT}
    ${FLAGS_COMPONENT}
    #${ESPRESSIF_CODE_COMPONENT}
    ${AUTH_COMPONENT}
    ${QUEUE_COMPONENT}
    ${MQTT_COMPONENT}
    ${WIFI_COMPONENT}
    ${GPIO_COMPONENT}
    ${RTC_COMPONENT}
)

# Override the configurations for Amazon FreeRTOS.
include_directories(BEFORE amazon-freertos-configs)

# Add amazon freertos as a subdirectory. AFR_BOARD tells which board to target.
set(AFR_BOARD espressif.esp32_devkitc CACHE INTERNAL "")
add_subdirectory(amazon-freertos)

# Link against the mqtt library so that we can use it. Dependencies are transitively
# linked.
target_link_libraries(my_app PRIVATE AFR::platform)
#target_link_libraries(my_app PRIVATE AFR::demo_mqtt)
target_link_libraries(my_app PRIVATE AFR::dev_mode_key_provisioning)
#target_link_libraries(my_app PRIVATE 3rdparty::jsmn)
#target_link_libraries(my_app PRIVATE AFR::wifi)
#target_link_libraries(my_app PRIVATE AFR::ota)
#target_link_libraries(my_app PRIVATE AFR::demo_mqtt)



