// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "LatentActions.h"


class FLowEntryTickSeconds : public FPendingLatentAction
{
public:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;

	const int32 Ticks;
	const float SecondsInterval;

	int32& Tick;
	float CurrentSecondsInterval = 0;

	FLowEntryTickSeconds(const FLatentActionInfo& LatentInfo, const int32 Ticks0, const float SecondsInterval0, int32& Tick0)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, Ticks(Ticks0)
		, SecondsInterval(SecondsInterval0)
		, Tick(Tick0)
	{
		Tick0 = 0;
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
