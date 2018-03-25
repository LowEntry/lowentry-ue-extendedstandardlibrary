// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "LatentActions.h"

#include "LowEntryLatentActionFloat.h"


class FLowEntryLatentActionFloat : public FPendingLatentAction
{
public:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;

	ULowEntryLatentActionFloat* LatentActionObject = NULL;
	float& Result;

	bool Done = false;

	FLowEntryLatentActionFloat(const FLatentActionInfo& LatentInfo, ULowEntryLatentActionFloat* LatentActionObject0, float& Result0)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, Result(Result0)
	{
		this->LatentActionObject = LatentActionObject0;
	}

	~FLowEntryLatentActionFloat()
	{
		if(!Done)
		{
			if((LatentActionObject != nullptr) && LatentActionObject->IsValidLowLevel() && !LatentActionObject->IsPendingKill())
			{
				Done = true;
				LatentActionObject->LatentActionDone();
			}
		}
	}

	void UpdateOperation(FLatentResponse& Response)
	{
		if((LatentActionObject == nullptr) || !LatentActionObject->IsValidLowLevel() || LatentActionObject->IsPendingKill())
		{
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
			return;
		}
		if(LatentActionObject->Finished)
		{
			Done = true;
			Result = LatentActionObject->Result;
			LatentActionObject->LatentActionDone();
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
