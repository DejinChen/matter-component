if(NOT MATTER_SDK_PATH)
    get_filename_component(MATTER_SDK_PATH ${CMAKE_CURRENT_SOURCE_DIR}/connectedhomeip/ REALPATH)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/ota-image.cmake)

set(CHIP_REQUIRE_COMPONENTS esp_eth freertos lwip bt mbedtls fatfs app_update console openthread nvs_flash spi_flash)

if(NOT "${IDF_TARGET}" STREQUAL "esp32h2")
    list(APPEND CHIP_REQUIRE_COMPONENTS mdns)
endif()

set(SRC_DIRS_LIST "${MATTER_SDK_PATH}/src/access"
                  "${MATTER_SDK_PATH}/src/access/examples"
                  "${MATTER_SDK_PATH}/src/app"
                  "${MATTER_SDK_PATH}/src/app/icd/"
                  "${MATTER_SDK_PATH}/src/app/MessageDef"
                  "${MATTER_SDK_PATH}/src/app/reporting"
                  "${MATTER_SDK_PATH}/src/app/server"
                  "${MATTER_SDK_PATH}/src/ble"
                  "${MATTER_SDK_PATH}/src/credentials"
                  "${MATTER_SDK_PATH}/src/credentials/attestation_verifier"
                  "${MATTER_SDK_PATH}/src/credentials/examples"
                  "${MATTER_SDK_PATH}/src/credentials/tests"
                  "${MATTER_SDK_PATH}/src/crypto"
                  "${MATTER_SDK_PATH}/src/inet"
                  "${MATTER_SDK_PATH}/src/lib/address_resolve"
                  "${MATTER_SDK_PATH}/src/lib/asn1"
                  "${MATTER_SDK_PATH}/src/lib/core"
                  "${MATTER_SDK_PATH}/src/lib/dnssd"
                  "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns"
                  "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/core"
                  "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/records"
                  "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/responders"
                  "${MATTER_SDK_PATH}/src/lib/support"
                  "${MATTER_SDK_PATH}/src/lib/support/logging"
                  "${MATTER_SDK_PATH}/src/lib/support/verhoeff"
                  "${MATTER_SDK_PATH}/src/messaging"
                  "${MATTER_SDK_PATH}/src/platform"
                  "${MATTER_SDK_PATH}/src/platform/ESP32"
                  "${MATTER_SDK_PATH}/src/platform/ESP32/route_hook"
                  "${MATTER_SDK_PATH}/src/platform/OpenThread"
                  "${MATTER_SDK_PATH}/src/protocols"
                  "${MATTER_SDK_PATH}/src/protocols/bdx"
                  "${MATTER_SDK_PATH}/src/protocols/echo"
                  "${MATTER_SDK_PATH}/src/protocols/secure_channel"
                  "${MATTER_SDK_PATH}/src/protocols/user_directed_commissioning"
                  "${MATTER_SDK_PATH}/src/setup_payload"
                  "${MATTER_SDK_PATH}/src/system"
                  "${MATTER_SDK_PATH}/src/tracing"
                  "${MATTER_SDK_PATH}/src/transport"
                  "${MATTER_SDK_PATH}/src/transport/raw"
                  "${MATTER_SDK_PATH}/third_party/nlfaultinjection/src"
                  "${MATTER_SDK_PATH}/zzz_generated/app-common/app-common/zap-generated")

set(INCLUDE_DIRS_LIST "."
                      "${MATTER_SDK_PATH}"
                      "${MATTER_SDK_PATH}/src"
                      "${MATTER_SDK_PATH}/src/access"
                      "${MATTER_SDK_PATH}/src/access/examples"
                      "${MATTER_SDK_PATH}/src/app"
                      "${MATTER_SDK_PATH}/src/app/icd/"
                      "${MATTER_SDK_PATH}/src/app/MessageDef"
                      "${MATTER_SDK_PATH}/src/app/reporting"
                      "${MATTER_SDK_PATH}/src/app/server"
                      "${MATTER_SDK_PATH}/src/ble"
                      "${MATTER_SDK_PATH}/src/controller"
                      "${MATTER_SDK_PATH}/src/credentials"
                      "${MATTER_SDK_PATH}/src/credentials/attestation_verifier"
                      "${MATTER_SDK_PATH}/src/credentials/tests"
                      "${MATTER_SDK_PATH}/src/crypto"
                      "${MATTER_SDK_PATH}/src/include"
                      "${MATTER_SDK_PATH}/src/inet"
                      "${MATTER_SDK_PATH}/src/lib"
                      "${MATTER_SDK_PATH}/src/lib/address_resolve"
                      "${MATTER_SDK_PATH}/src/lib/asn1"
                      "${MATTER_SDK_PATH}/src/lib/core"
                      "${MATTER_SDK_PATH}/src/lib/dnssd"
                      "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns"
                      "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/core"
                      "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/records"
                      "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/responders"
                      "${MATTER_SDK_PATH}/src/lib/support"
                      "${MATTER_SDK_PATH}/src/lib/support/logging"
                      "${MATTER_SDK_PATH}/src/lib/support/verhoeff"
                      "${MATTER_SDK_PATH}/src/lib/shell"
                      "${MATTER_SDK_PATH}/src/lib/shell/commands"
                      "${MATTER_SDK_PATH}/src/messaging"
                      "${MATTER_SDK_PATH}/src/platform"
                      "${MATTER_SDK_PATH}/src/platform/ESP32"
                      "${MATTER_SDK_PATH}/src/platform/ESP32/bluedroid"
                      "${MATTER_SDK_PATH}/src/platform/ESP32/nimble"
                      "${MATTER_SDK_PATH}/src/platform/ESP32/route_hook"
                      "${MATTER_SDK_PATH}/src/platform/OpenThread"
                      "${MATTER_SDK_PATH}/src/protocols"
                      "${MATTER_SDK_PATH}/src/protocols/bdx"
                      "${MATTER_SDK_PATH}/src/protocols/echo"
                      "${MATTER_SDK_PATH}/src/protocols/secure_channel"
                      "${MATTER_SDK_PATH}/src/pybindings"
                      "${MATTER_SDK_PATH}/src/setup_payload"
                      "${MATTER_SDK_PATH}/src/system"
                      "${MATTER_SDK_PATH}/src/tracing"
                      "${MATTER_SDK_PATH}/src/transport"
                      "${MATTER_SDK_PATH}/src/transport/raw"
                      "${MATTER_SDK_PATH}/third_party/nlfaultinjection/include"
                      "${MATTER_SDK_PATH}/third_party/nlassert/repo/include"
                      "${MATTER_SDK_PATH}/third_party/nlio/repo/include"
                      "${MATTER_SDK_PATH}/zzz_generated/app-common")

set(EXCLUDE_SRCS_LIST "${MATTER_SDK_PATH}/src/app/icd/ICDEventManager.cpp"
                      "${MATTER_SDK_PATH}/src/app/icd/ICDManager.cpp"
                      "${MATTER_SDK_PATH}/src/controller/ExamplePersistentStorage.cpp"
                      "${MATTER_SDK_PATH}/src/credentials/attestation_verifier/FileAttestationTrustStore.cpp"
                      "${MATTER_SDK_PATH}/src/credentials/tests/CHIPCert_error_test_vectors.cpp"
                      "${MATTER_SDK_PATH}/src/credentials/tests/CHIPCert_test_vectors.cpp"
                      "${MATTER_SDK_PATH}/src/credentials/tests/CHIPCert_unit_test_vectors.cpp"
                      "${MATTER_SDK_PATH}/src/credentials/tests/FuzzChipCert.cpp"
                      "${MATTER_SDK_PATH}/src/credentials/tests/TestCertificationDeclaration.cpp"
                      "${MATTER_SDK_PATH}/src/credentials/tests/TestChipCert.cpp"
                      "${MATTER_SDK_PATH}/src/credentials/tests/TestCommissionerDUTVectors.cpp"
                      "${MATTER_SDK_PATH}/src/credentials/tests/TestDeviceAttestationConstruction.cpp"
                      "${MATTER_SDK_PATH}/src/credentials/tests/TestDeviceAttestationCredentials.cpp"
                      "${MATTER_SDK_PATH}/src/credentials/tests/TestFabricTable.cpp"
                      "${MATTER_SDK_PATH}/src/credentials/tests/TestGroupDataProvider.cpp"
                      "${MATTER_SDK_PATH}/src/credentials/tests/TestPersistentStorageOpCertStore.cpp"
                      "${MATTER_SDK_PATH}/src/crypto/CHIPCryptoPALOpenSSL.cpp"
                      "${MATTER_SDK_PATH}/src/crypto/CHIPCryptoPALPSA.cpp"
                      "${MATTER_SDK_PATH}/src/crypto/PSAOperationalKeystore.cpp"
                      "${MATTER_SDK_PATH}/src/crypto/PSASessionKeystore.cpp"
                      "${MATTER_SDK_PATH}/src/inet/TCPEndPointImplOpenThread.cpp"
                      "${MATTER_SDK_PATH}/src/inet/TCPEndPointImplSockets.cpp"
                      "${MATTER_SDK_PATH}/src/inet/UDPEndPointImplNetworkFramework.cpp"
                      "${MATTER_SDK_PATH}/src/inet/UDPEndPointImplOpenThread.cpp"
                      "${MATTER_SDK_PATH}/src/inet/UDPEndPointImplSockets.cpp"
                      "${MATTER_SDK_PATH}/src/lib/address_resolve/tool.cpp"
                      "${MATTER_SDK_PATH}/src/lib/dnssd/Advertiser_ImplNone.cpp"
                      "${MATTER_SDK_PATH}/src/lib/dnssd/Resolver_ImplNone.cpp"
                      "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/AddressPolicy_LibNlImpl.cpp"
                      "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/Logging.cpp"
                      "${MATTER_SDK_PATH}/src/lib/support/UnitTestRegistration.cpp"
                      "${MATTER_SDK_PATH}/src/lib/support/UnitTestUtils.cpp"
                      "${MATTER_SDK_PATH}/src/lib/support/JniReferences.cpp"
                      "${MATTER_SDK_PATH}/src/lib/support/CHIPMem-Simple.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/MainLoopAmeba.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/MainLoopCYW30739.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/MainLoopDefault.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/MainLoopMW320.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/MainLoopSilabs.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/MainLoopZephyr.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/streamer_ameba.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/streamer_asr.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/streamer_bouffalolab.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/streamer_cc13x2_26x2.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/streamer_cc13x4_26x4.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/streamer_cyw30739.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/streamer_k32w.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/streamer_mbed.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/streamer_mt793x.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/streamer_mw320.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/streamer_nxp.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/streamer_openiotsdk.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/streamer_qpg.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/streamer_silabs.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/streamer_stdio.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/streamer_zephyr.cpp"
                      "${MATTER_SDK_PATH}/src/lib/shell/commands/NFC.cpp"
                      "${MATTER_SDK_PATH}/src/platform/DeviceSafeQueue.cpp"
                      "${MATTER_SDK_PATH}/src/platform/SyscallStubs.cpp"
                      "${MATTER_SDK_PATH}/src/platform/ESP32/WiFiDnssdImpl.cpp"
                      "${MATTER_SDK_PATH}/src/platform/OpenThread/GenericThreadStackManagerImpl_OpenThread_LwIP.cpp"
                      "${MATTER_SDK_PATH}/src/system/SystemLayerImplSelect.cpp"
                      "${MATTER_SDK_PATH}/src/transport/TraceMessage.cpp")

list(APPEND INCLUDE_DIRS_LIST "${CMAKE_CURRENT_SOURCE_DIR}/include")
list(APPEND INCLUDE_DIRS_LIST "${CMAKE_CURRENT_BINARY_DIR}")

# ESP-IDF lets user set software version string by two ways:
# 1. Project's CMakeLists.txt file and 2. Config option
# It depends on CONFIG_APP_PROJECT_VER_FROM_CONFIG option
# So, below makes the same provision for software version number
if (CONFIG_APP_PROJECT_VER_FROM_CONFIG)
    set(chip_config_software_version_number ${CONFIG_DEVICE_SOFTWARE_VERSION_NUMBER})
elseif (DEFINED PROJECT_VER_NUMBER)
    set(chip_config_software_version_number ${PROJECT_VER_NUMBER})
else()
    set(chip_config_software_version_number 0)
endif()

if(CONFIG_DISABLE_READ_CLIENT)
    list(APPEND EXCLUDE_SRCS_LIST "${MATTER_SDK_PATH}/src/app/BufferedReadCallback.cpp"
                                  "${MATTER_SDK_PATH}/src/app/ClusterStateCache.cpp"
                                  "${MATTER_SDK_PATH}/src/app/ReadClient.cpp")
endif()

if (NOT CONFIG_BUILD_CHIP_TESTS)
    list(APPEND EXCLUDE_SRCS_LIST "${MATTER_SDK_PATH}/src/inet/InetFaultInjection.cpp"
                                  "${MATTER_SDK_PATH}/src/lib/support/CHIPFaultInjection.cpp"
                                  "${MATTER_SDK_PATH}/src/system/SystemFaultInjection.cpp"
                                  "${MATTER_SDK_PATH}/third_party/nlfaultinjection/src/nlfaultinjection.cpp")
endif()

if (NOT CONFIG_USE_MINIMAL_MDNS)
    list(APPEND EXCLUDE_SRCS_LIST "${MATTER_SDK_PATH}/src/lib/dnssd/ActiveResolveAttempts.cpp"
                                  "${MATTER_SDK_PATH}/src/lib/dnssd/Advertiser_ImplMinimalMdns.cpp"
                                  "${MATTER_SDK_PATH}/src/lib/dnssd/IncrementalResolve.cpp"
                                  "${MATTER_SDK_PATH}/src/lib/dnssd/MinimalMdnsServer.cpp"
                                  "${MATTER_SDK_PATH}/src/lib/dnssd/Resolver_ImplMinimalMdns.cpp"
                                  "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/Parser.cpp"
                                  "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/RecordData.cpp"
                                  "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/ResponseSender.cpp"
                                  "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/Server.cpp"
                                  "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/AddressPolicy.cpp"
                                  "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/core/QName.cpp"
                                  "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/core/QNameString.cpp"
                                  "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/core/RecordWriter.cpp"
                                  "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/responders/IP.cpp"
                                  "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/responders/QueryResponder.cpp"
                                  "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/records/IP.cpp"
                                  "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/records/ResourceRecord.cpp"
                                  "${MATTER_SDK_PATH}/src/lib/dnssd/minimal_mdns/AddressPolicy_DefaultImpl.cpp")
else()
    list(APPEND EXCLUDE_SRCS_LIST "${MATTER_SDK_PATH}/src/lib/dnssd/Discovery_ImplPlatform.cpp"
                                  "${MATTER_SDK_PATH}/src/platform/ESP32/DnssdImpl.cpp")
endif()

if (CONFIG_ENABLE_CHIP_SHELL)
    list(APPEND SRC_DIRS_LIST "${MATTER_SDK_PATH}/src/lib/shell"
                              "${MATTER_SDK_PATH}/src/lib/shell/commands")
endif()

if (CONFIG_ENABLE_CHIP_CONTROLLER_BUILD)
    list(APPEND SRC_DIRS_LIST "${MATTER_SDK_PATH}/src/controller")
endif()

if((NOT CONFIG_ENABLE_WIFI_STATION) AND (NOT CONFIG_ENABLE_WIFI_AP))
    list(APPEND EXCLUDE_SRCS_LIST "${MATTER_SDK_PATH}/src/platform/ESP32/ConnectivityManagerImpl_WiFi.cpp"
                                  "${MATTER_SDK_PATH}/src/platform/ESP32/NetworkCommissioningDriver.cpp"
                                  "${MATTER_SDK_PATH}/src/platform/ESP32/route_hook/ESP32RouteHook.c"
                                  "${MATTER_SDK_PATH}/src/platform/ESP32/route_hook/ESP32RouteTable.c"
                                  "${MATTER_SDK_PATH}/src/lib/shell/commands/WiFi.cpp")
endif()

if ((CONFIG_BT_ENABLED) AND (CONFIG_ENABLE_CHIPOBLE))
	if (CONFIG_BT_NIMBLE_ENABLED)
        list(APPEND SRC_DIRS_LIST "${MATTER_SDK_PATH}/src/platform/ESP32/nimble")
        list(APPEND EXCLUDE_SRCS_LIST "${MATTER_SDK_PATH}/src/platform/ESP32/bluedroid/BLEManagerImpl.cpp")
        if(NOT CONFIG_ENABLE_ESP32_BLE_CONTROLLER)
            list(APPEND EXCLUDE_SRCS_LIST "${MATTER_SDK_PATH}/src/platform/ESP32/bluedroid/ChipDeviceScanner.cpp")
        endif()
    else()
        list(APPEND SRC_DIRS_LIST "${MATTER_SDK_PATH}/src/platform/ESP32/bluedroid")
        list(APPEND EXCLUDE_SRCS_LIST "${MATTER_SDK_PATH}/src/platform/ESP32/nimble/BLEManagerImpl.cpp")
        if(NOT CONFIG_ENABLE_ESP32_BLE_CONTROLLER)
            list(APPEND EXCLUDE_SRCS_LIST "${MATTER_SDK_PATH}/src/platform/ESP32/nimble/ChipDeviceScanner.cpp"
                                          "${MATTER_SDK_PATH}/src/platform/ESP32/nimble/misc.c"
                                          "${MATTER_SDK_PATH}/src/platform/ESP32/nimble/peer.c")
        endif()
    endif()
endif()

if (NOT CONFIG_ENABLE_ETHERNET_TELEMETRY)
    list(APPEND EXCLUDE_SRCS_LIST "${MATTER_SDK_PATH}/src/platform/ESP32/ConnectivityManagerImpl_Ethernet.cpp"
                                  "${MATTER_SDK_PATH}/src/platform/ESP32/NetworkCommissioningDriver_Ethernet.cpp")
endif()

if (NOT CONFIG_ENABLE_MATTER_OVER_THREAD)
    list(APPEND EXCLUDE_SRCS_LIST "${MATTER_SDK_PATH}/src/platform/ESP32/OpenthreadLauncher.c"
                                  "${MATTER_SDK_PATH}/src/platform/ESP32/ThreadStackManagerImpl.cpp"
                                  "${MATTER_SDK_PATH}/src/platform/OpenThread/DnssdImpl.cpp"
                                  "${MATTER_SDK_PATH}/src/platform/OpenThread/GenericNetworkCommissioningThreadDriver.cpp"
                                  "${MATTER_SDK_PATH}/src/platform/OpenThread/OpenThreadUtils.cpp"
                                  "${MATTER_SDK_PATH}/src/platform/OpenThread/OpenThreadDnssdImpl.cpp")
endif()

if (NOT CONFIG_ENABLE_OTA_REQUESTOR)
    list(APPEND EXCLUDE_SRCS_LIST "${MATTER_SDK_PATH}/src/platform/ESP32/OTAImageProcessorImpl.cpp")
endif()

# Set up CHIP project configuration file

if (CONFIG_CHIP_PROJECT_CONFIG)
    get_filename_component(CHIP_PROJECT_CONFIG
        ${CONFIG_CHIP_PROJECT_CONFIG}
        REALPATH
        BASE_DIR ${CMAKE_SOURCE_DIR}
    )
    set(CHIP_PROJECT_CONFIG "<${CHIP_PROJECT_CONFIG}>")
else()
    set(CHIP_PROJECT_CONFIG "")
endif()

if (NOT CONFIG_ENABLE_ESP32_FACTORY_DATA_PROVIDER)
    list(APPEND EXCLUDE_SRCS_LIST "${MATTER_SDK_PATH}/src/platform/ESP32/ESP32FactoryDataProvider.cpp")
endif()

if (NOT CONFIG_ENABLE_ESP32_DEVICE_INFO_PROVIDER)
    list(APPEND EXCLUDE_SRCS_LIST "${MATTER_SDK_PATH}/src/platform/ESP32/ESP32DeviceInfoProvider.cpp")
endif()

if (NOT CONFIG_SEC_CERT_DAC_PROVIDER)
    list(APPEND EXCLUDE_SRCS_LIST "${MATTER_SDK_PATH}/src/platform/ESP32/ESP32SecureCertDACProvider.cpp")
endif()

if (NOT CONFIG_USE_ESP32_ECDSA_PERIPHERAL)
    list(APPEND EXCLUDE_SRCS_LIST "${MATTER_SDK_PATH}/src/platform/ESP32/ESP32CHIPCryptoPAL.cpp")
endif()

if (CONFIG_ENABLE_ESP_INSIGHTS_TRACE)
    list(APPEND SRC_DIRS_LIST "${MATTER_SDK_PATH}/src/tracing/esp32_trace")
endif()

idf_component_register(SRC_DIRS             ${SRC_DIRS_LIST}
                       EXCLUDE_SRCS         ${EXCLUDE_SRCS_LIST}
                       INCLUDE_DIRS         ${INCLUDE_DIRS_LIST}
                       PRIV_REQUIRES        ${CHIP_REQUIRE_COMPONENTS})

target_compile_options(${COMPONENT_LIB} PUBLIC
                       "-DCHIP_ADDRESS_RESOLVE_IMPL_INCLUDE_HEADER=<lib/address_resolve/AddressResolve_DefaultImpl.h>"
                       "-DCHIP_CONFIG_SOFTWARE_VERSION_NUMBER=${chip_config_software_version_number}")

if (CHIP_PROJECT_CONFIG)
    target_compile_options(${COMPONENT_LIB} PUBLIC
                           "-DCHIP_PROJECT_CONFIG_INCLUDE=\"${CHIP_PROJECT_CONFIG}\""
                           "-DSYSTEM_PROJECT_CONFIG_INCLUDE=\"${CHIP_PROJECT_CONFIG}\"")
endif()

idf_build_set_property(C_COMPILE_OPTIONS "-Wno-error=uninitialized;-Wno-error=maybe-uninitialized;-Wno-format-nonliteral;-Wno-missing-field-initializers" APPEND)
idf_build_set_property(CXX_COMPILE_OPTIONS "-Wno-error=uninitialized;-Wno-error=maybe-uninitialized;-Wno-format-nonliteral;-Wno-missing-field-initializers" APPEND)

idf_component_get_property(freertos_dir freertos COMPONENT_DIR)
target_include_directories(${COMPONENT_LIB} PRIVATE
    "${freertos_dir}/include/freertos"
    "${freertos_dir}/FreeRTOS-Kernel/include/freertos")

target_include_directories(${COMPONENT_LIB} INTERFACE
    "${MATTER_SDK_PATH}/examples/platform/esp32"
    "${MATTER_SDK_PATH}/third_party/nlassert/repo/include"
    "${MATTER_SDK_PATH}/third_party/nlio/repo/include"
    "${CMAKE_CURRENT_BINARY_DIR}/src/include"
    "${CMAKE_CURRENT_BINARY_DIR}/include"
    "${CMAKE_CURRENT_BINARY_DIR}/gen/include"
    "${MATTER_SDK_PATH}/config/esp32/${CONFIG_CHIP_EXTERNAL_PLATFORM_DIR}"
    "${MATTER_SDK_PATH}/config/esp32/${CONFIG_CHIP_EXTERNAL_PLATFORM_DIR}/../../"
)

#TODO: Check which lib should be included in chip_libraries for target_link_libraries
idf_component_get_property(main_lib main COMPONENT_LIB)
set(chip_libraries $<TARGET_FILE:${main_lib}>)

if (CONFIG_ENABLE_ESP_INSIGHTS_TRACE)
    target_include_directories(${COMPONENT_LIB} INTERFACE "${CHIP_ROOT}/src/tracing/esp32_trace/include")
endif()

idf_component_get_property(mbedtls_lib mbedtls COMPONENT_LIB)

idf_build_get_property(idf_target IDF_TARGET)
set(target_name "${idf_target}")

if(CONFIG_BT_ENABLED)
    idf_component_get_property(bt_lib bt COMPONENT_LIB)
    if((target_name STREQUAL "esp32h2") OR (target_name STREQUAL "esp32c2") OR (target_name STREQUAL "esp32c6"))
        idf_component_get_property(bt_dir bt COMPONENT_DIR)
        list(APPEND chip_libraries $<TARGET_FILE:${bt_lib}>)
        list(APPEND chip_libraries "${bt_dir}/controller/lib_${target_name}/${target_name}-bt-lib/libble_app.a")
    else()
        list(APPEND chip_libraries $<TARGET_FILE:${bt_lib}> -lbtdm_app)
    endif()
endif()

if (CONFIG_ENABLE_CHIP_SHELL)
    idf_component_get_property(console_lib console COMPONENT_LIB)
    list(APPEND chip_libraries $<TARGET_FILE:${console_lib}>)
endif()

if(CONFIG_OPENTHREAD_ENABLED)
    idf_component_get_property(openthread_lib openthread COMPONENT_LIB)
    list(APPEND chip_libraries $<TARGET_FILE:${openthread_lib}>)
    if (CONFIG_IEEE802154_ENABLED)
        idf_component_get_property(ieee802154_lib ieee802154 COMPONENT_LIB)
        list(APPEND chip_libraries $<TARGET_FILE:${ieee802154_lib}>)
    endif()
endif()

if((NOT CONFIG_USE_MINIMAL_MDNS) AND (CONFIG_ENABLE_WIFI_STATION OR CONFIG_ENABLE_WIFI_AP))
    idf_build_get_property(build_components BUILD_COMPONENTS)
    # For IDF v5.x, the mdns component was moved to idf_managed_components.
    # We should use 'espressif__mdns' for 'idf_component_get_property'.
    if("espressif__mdns" IN_LIST build_components)
        idf_component_get_property(mdns_lib espressif__mdns COMPONENT_LIB)
    elseif("mdns" IN_LIST build_components)
        idf_component_get_property(mdns_lib mdns COMPONENT_LIB)
    endif()
    list(APPEND chip_libraries $<TARGET_FILE:${mdns_lib}>)
endif()

if (CONFIG_ENABLE_ENCRYPTED_OTA)
    idf_component_get_property(esp_encrypted_img_lib espressif__esp_encrypted_img COMPONENT_LIB)
    list(APPEND chip_libraries $<TARGET_FILE:${esp_encrypted_img_lib}>)
endif()

if (CONFIG_SEC_CERT_DAC_PROVIDER)
    idf_component_get_property(esp32_secure_cert_mgr_lib espressif__esp_secure_cert_mgr COMPONENT_LIB)
    list(APPEND chip_libraries $<TARGET_FILE:${esp32_secure_cert_mgr_lib}>)
endif()

if (CONFIG_ENABLE_ESP_INSIGHTS_TRACE)
    idf_component_get_property(esp_insights_lib espressif__esp_insights COMPONENT_LIB)
    list(APPEND chip_libraries $<TARGET_FILE:${esp_insights_lib}>)
endif()

idf_component_get_property(lwip_lib lwip COMPONENT_LIB)
list(APPEND chip_libraries $<TARGET_FILE:${lwip_lib}>)

if (CONFIG_ESP32_WIFI_ENABLED)
    idf_component_get_property(esp_wifi_lib esp_wifi COMPONENT_LIB)
    idf_component_get_property(esp_wifi_dir esp_wifi COMPONENT_DIR)
    list(APPEND chip_libraries $<TARGET_FILE:${esp_wifi_lib}>)
    if (CONFIG_IDF_TARGET_ESP32C2)
        set(blobs core net80211 pp)
    else()
        set(blobs core mesh net80211 pp)
    endif()

    foreach(blob ${blobs})
    list(APPEND chip_libraries "${esp_wifi_dir}/lib/${target_name}/lib${blob}.a")
    endforeach()

    idf_component_get_property(wpa_supplicant_lib wpa_supplicant COMPONENT_LIB)
    list(APPEND chip_libraries $<TARGET_FILE:${wpa_supplicant_lib}>)
endif()

if (CONFIG_ETH_ENABLED)
    idf_component_get_property(esp_eth_lib esp_eth COMPONENT_LIB)
    list(APPEND chip_libraries $<TARGET_FILE:${esp_eth_lib}>)
endif()

idf_component_get_property(esp_netif_lib esp_netif COMPONENT_LIB)
list(APPEND chip_libraries $<TARGET_FILE:${esp_netif_lib}>)

idf_component_get_property(esp_hw_support_lib esp_hw_support COMPONENT_LIB)
list(APPEND chip_libraries $<TARGET_FILE:${esp_hw_support_lib}>)

idf_component_get_property(esp_phy_lib esp_phy COMPONENT_LIB)
idf_component_get_property(esp_phy_dir esp_phy COMPONENT_DIR)
list(APPEND chip_libraries $<TARGET_FILE:${esp_phy_lib}>)

if (CONFIG_IDF_TARGET_ESP32)
    set(phy_blobs phy rtc)
elseif (CONFIG_IDF_TARGET_ESP32S2)
    set(phy_blobs phy)
else()
    set(phy_blobs phy btbb)
endif()
foreach(phy_blob ${phy_blobs})
    list(APPEND chip_libraries "${esp_phy_dir}/lib/${target_name}/lib${phy_blob}.a")
endforeach()

set(components_to_link esp_event hal esp_system soc efuse vfs driver esp_coex freertos)
idf_build_get_property(build_components BUILD_COMPONENTS)
foreach(component ${components_to_link})
    # Some of the components are not present in IDF v4.x
    # So, Check if the component is in the list of build components
    if("${component}" IN_LIST build_components)
        idf_component_get_property(lib_name ${component} COMPONENT_LIB)
        list(APPEND chip_libraries $<TARGET_FILE:${lib_name}>)
    endif()
endforeach()

target_link_libraries(${COMPONENT_LIB} INTERFACE -Wl,--start-group
                                                ${chip_libraries}
                                                -Wl,--end-group)

if (CONFIG_USE_MINIMAL_MDNS)
    target_compile_options(${COMPONENT_LIB} PUBLIC "-DCHIP_MINMDNS_DEFAULT_POLICY=1"
                                                   "-DCHIP_MINMDNS_USE_EPHEMERAL_UNICAST_PORT=0"
                                                   "-DCHIP_MINMDNS_HIGH_VERBOSITY=0")
endif()

if (NOT CMAKE_BUILD_EARLY_EXPANSION)
    if (CONFIG_COMPILER_OPTIMIZATION_DEFAULT OR CONFIG_COMPILER_OPTIMIZATION_NONE)
        target_compile_options(${COMPONENT_LIB} PUBLIC "-DLWIP_DEBUG=1")
    else()
        if (NOT CONFIG_COMPILER_OPTIMIZATION_ASSERTIONS_DISABLE)
            message(FATAL_ERROR "CONFIG_COMPILER_OPTIMIZATION_ASSERTIONS_DISABLE shall be set")
        endif()
    endif()
endif()

execute_process(
    COMMAND date "+%s"
    OUTPUT_VARIABLE BUILD_SECONDS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
math(EXPR BUILD_SECONDS "${BUILD_SECONDS} - (946684800)")
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/FirmwareBuildTime.h "#pragma once\n\n")
file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/FirmwareBuildTime.h "#define CHIP_DEVICE_CONFIG_FIRMWARE_BUILD_TIME_MATTER_EPOCH_S ${BUILD_SECONDS}\n\n")

# Build Matter OTA image
if (CONFIG_CHIP_OTA_IMAGE_BUILD)
    chip_ota_image(chip-esp-ota-image
        INPUT_FILES ${BUILD_DIR}/${CMAKE_PROJECT_NAME}.bin
        OUTPUT_FILE ${BUILD_DIR}/${CMAKE_PROJECT_NAME}-esp-ota.bin
    )
    # Adding dependecy as app target so that this runs after images are ready
    add_dependencies(chip-esp-ota-image app)
endif()
