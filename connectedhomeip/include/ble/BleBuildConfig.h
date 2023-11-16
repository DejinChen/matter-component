#pragma once

#include "sdkconfig.h"

#define CONFIG_NETWORK_LAYER_BLE CONFIG_ENABLE_CHIPOBLE
#define CHIP_ENABLE_CHIPOBLE_TEST 0
#define BLE_PLATFORM_CONFIG_INCLUDE <platform/ESP32/BlePlatformConfig.h>
