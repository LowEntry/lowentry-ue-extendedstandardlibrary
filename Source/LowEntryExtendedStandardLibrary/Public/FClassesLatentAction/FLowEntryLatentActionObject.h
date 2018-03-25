// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "LatentActions.h"

#include "LowEntryLatentActionObject.h"


class FLowEntryLatentActionObject : public FPendingLatentAction
{
public:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;

	ULowEntryLatentActionObject* LatentActionObject = NULL;
	UObject*& Result;

	bool Done = false;

	FLowEntryLatentActionObject(const FLatentActionInfo& LatentInfo, ULowEntryLatentActionObject* LatentActionObject0, UObject*& Result0)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, Result(Result0)
	{
		this->LatentActionObject = LatentActionObject0;
	}

	~FLowEntryLatentActionObject()
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
