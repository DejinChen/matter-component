set(srcs_list)
if (CONFIG_ENABLE_CHIP_SHELL)
    list(APPEND srcs_list esp_matter_console.cpp esp_matter_console_diagnostics.cpp esp_matter_console_wifi.cpp)
endif()
idf_component_register(SRCS ${srcs_list}
                    INCLUDE_DIRS .
                    PRIV_REQUIRES connectedhomeip mbedtls esp_timer bt openthread)
