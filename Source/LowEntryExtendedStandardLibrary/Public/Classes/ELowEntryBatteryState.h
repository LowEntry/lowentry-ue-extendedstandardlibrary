#pragma once


#include "Engine.h"
#include "Core.h"

#include "ELowEntryBatteryState.generated.h"


UENUM()
enum class ELowEntryBatteryState
{
	Charging,
	Discharging,
	Full,
	NotCharging,
	Unknown
};
