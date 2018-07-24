// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "LatentActions.h"


class FLowEntryDelayFramesAction : public FPendingLatentAction
{
public:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;

	int32 FramesRemaining;

	FLowEntryDelayFramesAction(int32 Frames, const FLatentActionInfo& LatentInfo)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, FramesRemaining(Frames)
	{
	}

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		FramesRemaining--;
		Response.FinishAndTriggerIf((FramesRemaining <= 0), ExecutionFunction, OutputLink, CallbackTarget);
	}

#if WITH_EDITOR
	// Returns a human readable description of the latent operation's current state
	virtual FString GetDescription() const override
	{
		return FString::Printf(TEXT("Delay (%i frames left)"), FramesRemaining);
	}
#endif
};