#pragma once


#include "Engine.h"
#include "Core.h"
#include "CoreUObject.h"
#include "LatentActions.h"

#include "LowEntryLatentActionInteger.h"


class FLowEntryLatentActionInteger : public FPendingLatentAction
{
public:
	ULowEntryLatentActionInteger* LatentActionObject = NULL;
	int32& Result;

	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;

	FLowEntryLatentActionInteger(const FLatentActionInfo& LatentInfo, ULowEntryLatentActionInteger* LatentActionObject, int32& Result)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, Result(Result)
	{
		this->LatentActionObject = LatentActionObject;
	}

	void UpdateOperation(FLatentResponse& Response)
	{
		if(LatentActionObject->Finished)
		{
			Result = LatentActionObject->Result;
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
