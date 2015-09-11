#pragma once


#include "Engine.h"
#include "Core.h"
#include "CoreUObject.h"
#include "LatentActions.h"


class FLowEntryTickFrames : public FPendingLatentAction
{
public:
	const int32 Ticks;
	const int32 FramesInterval;

	int32 CurrentTicks = 0;
	int32 CurrentFramesInterval = 0;

	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;

	FLowEntryTickFrames(const FLatentActionInfo& LatentInfo, const int32 Ticks, const int32 FramesInterval)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, Ticks(Ticks)
		, FramesInterval(FramesInterval)
	{
	}

	void UpdateOperation(FLatentResponse& Response)
	{
		if(CurrentTicks >= Ticks)
		{
			Response.DoneIf(true);
			return;
		}

		CurrentFramesInterval++;
		if(CurrentFramesInterval > FramesInterval)
		{
			CurrentFramesInterval = 0;
			CurrentTicks++;
			Response.TriggerLink(ExecutionFunction, OutputLink, CallbackTarget);
		}
	}

#if WITH_EDITOR
	// Returns a human readable description of the latent operation's current state
	virtual FString GetDescription() const override
	{
		return FString::Printf(TEXT("Ticking (%i ticks left)"), (Ticks - CurrentTicks));
	}
#endif
};
