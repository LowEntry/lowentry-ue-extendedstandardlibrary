#pragma once


#include "Engine.h"
#include "Core.h"
#include "CoreUObject.h"
#include "LatentActions.h"


class FDelayFramesAction : public FPendingLatentAction
{
public:
	int32 FramesRemaining;

	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;

	FDelayFramesAction(int32 Frames, const FLatentActionInfo& LatentInfo)
		: FramesRemaining(Frames)
		, ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
	{
	}

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		FramesRemaining--;
		Response.FinishAndTriggerIf(FramesRemaining <= 0, ExecutionFunction, OutputLink, CallbackTarget);
	}

#if WITH_EDITOR
	// Returns a human readable description of the latent operation's current state
	virtual FString GetDescription() const override
	{
		return FString::Printf(TEXT("Delay (%i frames left)"), FramesRemaining);
	}
#endif
};