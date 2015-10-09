#pragma once


#include "Engine.h"
#include "Core.h"
#include "CoreUObject.h"
#include "LatentActions.h"

#include "LowEntryLatentActionNone.h"


class FLowEntryLatentActionNone : public FPendingLatentAction
{
public:
	ULowEntryLatentActionNone* LatentActionObject = NULL;

	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;

	FLowEntryLatentActionNone(const FLatentActionInfo& LatentInfo, ULowEntryLatentActionNone* LatentActionObject)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
	{
		this->LatentActionObject = LatentActionObject;
	}

	void UpdateOperation(FLatentResponse& Response)
	{
		if(LatentActionObject->Finished)
		{
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		}
	}

#if WITH_EDITOR
	// Returns a human readable description of the latent operation's current state
	virtual FString GetDescription() const override
	{
		return TEXT("Waiting...");
	}
#endif
};
