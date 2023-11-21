#pragma once

#include "sdkconfig.h"

#define CHIP_CONFIG_IM_PRETTY_PRINT CONFIG_CHIP_CONFIG_IM_PRETTY_PRINT
#define CHIP_CONFIG_IM_FORCE_FABRIC_QUOTA_CHECK 0
#define CHIP_CONFIG_ENABLE_SESSION_RESUMPTION 1
#define CHIP_CONFIG_ACCESS_CONTROL_POLICY_LOGGING_VERBOSITY 0
#define CHIP_CONFIG_PERSIST_SUBSCRIPTIONS 1
#define CHIP_CONFIG_SUBSCRIPTION_TIMEOUT_RESUMPTION 1
#define CHIP_CONFIG_ENABLE_EVENTLIST_ATTRIBUTE CONFIG_ENABLE_MATTER_EVENT_LIST
#define CHIP_CONFIG_ENABLE_ICD_SERVER 0
#define CHIP_CONFIG_ENABLE_READ_CLIENT (!CONFIG_DISABLE_READ_CLIENT)
#define ICD_REPORT_ON_ENTER_ACTIVE_MODE false
#define ICD_MAX_NOTIFICATION_SUBSCRIBERS 1