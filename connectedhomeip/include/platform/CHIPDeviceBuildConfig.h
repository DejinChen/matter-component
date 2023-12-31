#pragma once

#include "sdkconfig.h"

#define CHIP_DEVICE_CONFIG_ENABLE_WPA 0
#define CHIP_ENABLE_OPENTHREAD CONFIG_ENABLE_MATTER_OVER_THREAD
#define CHIP_DEVICE_CONFIG_THREAD_FTD CONFIG_OPENTHREAD_FTD
#define CHIP_STACK_LOCK_TRACKING_ENABLED 1
#define CHIP_STACK_LOCK_TRACKING_ERROR_FATAL 1
#define CHIP_ENABLE_ADDITIONAL_DATA_ADVERTISING CONFIG_ENABLE_ROTATING_DEVICE_ID
#define CHIP_DEVICE_CONFIG_RUN_AS_ROOT 1
#define CHIP_DISABLE_PLATFORM_KVS 0
#define CHIP_DEVICE_CONFIG_ENABLE_OTA_REQUESTOR CONFIG_ENABLE_OTA_REQUESTOR
#define CHIP_DEVICE_PLATFORM_CONFIG_INCLUDE <platform/ESP32/CHIPDevicePlatformConfig.h>
#define CHIP_USE_TRANSITIONAL_COMMISSIONABLE_DATA_PROVIDER (!CONFIG_ENABLE_ESP32_FACTORY_DATA_PROVIDER)
#define CHIP_DEVICE_LAYER_TARGET_ESP32 1
#define CHIP_DEVICE_LAYER_TARGET ESP32
#define CHIP_DEVICE_CONFIG_MAX_DISCOVERED_IP_ADDRESSES 5
