// Copyright Low Entry. Apache License, Version 2.0.

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
