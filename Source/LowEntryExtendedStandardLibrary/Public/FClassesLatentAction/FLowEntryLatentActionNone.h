// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "LatentActions.h"

#include "LowEntryLatentActionNone.h"


class FLowEntryLatentActionNone : public FPendingLatentAction
{
public:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;

	ULowEntryLatentActionNone* LatentActionObject = nullptr;

	bool Done = false;

	FLowEntryLatentActionNone(const FLatentActionInfo& LatentInfo, ULowEntryLatentActionNone* LatentActionObject0)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
	{
		this->LatentActionObject = LatentActionObject0;
	}

	virtual ~FLowEntryLatentActionNone() override
	{
		if (!Done)
		{
			if (IsValid(LatentActionObject))
			{
				Done = true;
				LatentActionObject->LatentActionDone();
			}
		}
	}

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		if (!IsValid(LatentActionObject))
		{
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
			return;
		}
		if (LatentActionObject->Finished)
		{
			Done = true;
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
