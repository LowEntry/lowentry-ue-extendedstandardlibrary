#pragma once


#include "Engine.h"
#include "Core.h"
#include "CoreUObject.h"
#include "LatentActions.h"


class FLowEntryTickSeconds : public FPendingLatentAction
{
public:
	const int32 Ticks;
	const float SecondsInterval;

	int32& Tick;
	float CurrentSecondsInterval = 0;

	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;

	FLowEntryTickSeconds(const FLatentActionInfo& LatentInfo, const int32 Ticks, const float SecondsInterval, int32& Tick)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, Ticks(Ticks)
		, SecondsInterval(SecondsInterval)
		, Tick(Tick)
	{
		Tick = 0;
	}

	void UpdateOperation(FLatentResponse& Response)
	{
		if(Tick >= Ticks)
		{
			Response.DoneIf(true);
			return;
		}

		CurrentSecondsInterval += Response.ElapsedTime();
		if(CurrentSecondsInterval >= SecondsInterval)
		{
			CurrentSecondsInterval -= SecondsInterval;
			Tick++;
			Response.TriggerLink(ExecutionFunction, OutputLink, CallbackTarget);
		}
	}

#if WITH_EDITOR
	// Returns a human readable description of the latent operation's current state
	virtual FString GetDescription() const override
	{
		return FString::Printf(TEXT("Ticking (%i ticks left)"), (Ticks - Tick));
	}
#endif
};
