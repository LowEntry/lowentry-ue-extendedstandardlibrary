#pragma once


#include "CoreMinimal.h"

#include "ELowEntryBatteryState.generated.h"


UENUM()
enum class ELowEntryBatteryState : uint8
{
	Charging,
	Discharging,
	Full,
	NotCharging,
	Unknown
};
