// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "LatentActions.h"

#include "LowEntryLatentActionBoolean.h"


class FLowEntryLatentActionBoolean : public FPendingLatentAction
{
public:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;

	ULowEntryLatentActionBoolean* LatentActionObject = nullptr;
	bool& Result;

	bool Done = false;

	FLowEntryLatentActionBoolean(const FLatentActionInfo& LatentInfo, ULowEntryLatentActionBoolean* LatentActionObject0, bool& Result0)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, Result(Result0)
	{
		this->LatentActionObject = LatentActionObject0;
	}

	virtual ~FLowEntryLatentActionBoolean() override
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
