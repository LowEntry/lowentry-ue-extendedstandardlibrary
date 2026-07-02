// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "LatentActions.h"
#include "StructUtils/InstancedStruct.h"

#include "LowEntryLatentActionStruct.h"


class FLowEntryLatentActionStruct : public FPendingLatentAction
{
public:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;

	ULowEntryLatentActionStruct* LatentActionStruct = nullptr;
	FInstancedStruct& Result;

	bool Done = false;

	FLowEntryLatentActionStruct(const FLatentActionInfo& LatentInfo, ULowEntryLatentActionStruct* LatentActionStruct0, FInstancedStruct& Result0)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, Result(Result0)
	{
		this->LatentActionStruct = LatentActionStruct0;
	}

	virtual ~FLowEntryLatentActionStruct() override
	{
		if (!Done)
		{
			if (IsValid(LatentActionStruct))
			{
				Done = true;
				LatentActionStruct->LatentActionDone();
			}
		}
	}

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		if (!IsValid(LatentActionStruct))
		{
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
			return;
		}
		if (LatentActionStruct->Finished)
		{
			Done = true;
			Result = LatentActionStruct->Result;
			LatentActionStruct->LatentActionDone();
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
