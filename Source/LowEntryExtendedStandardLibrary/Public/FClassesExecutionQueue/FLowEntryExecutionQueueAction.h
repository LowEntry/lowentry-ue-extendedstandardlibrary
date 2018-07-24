// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "LowEntryExecutionQueue.h"


class FLowEntryExecutionQueueAction : public FPendingLatentAction
{
public:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;

	ULowEntryExecutionQueue* Queue;

	FLowEntryExecutionQueueAction(ULowEntryExecutionQueue* Queue0, const FLatentActionInfo& LatentInfo)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, Queue(Queue0)
	{
	}

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		if((Queue == nullptr) || !Queue->IsValidLowLevel() || Queue->IsPendingKill() || (Queue->Count <= 0))
		{
            Response.DoneIf(true);
            return;
        }
        if(Queue->Next)
        {
			Queue->Next = false;
			Queue->DecreaseCount();
            Response.TriggerLink(ExecutionFunction, OutputLink, CallbackTarget);
        }
	}

	ULowEntryExecutionQueue* GetOrCreateQueueAndIncreaseCount()
	{
		if((Queue == nullptr) || !Queue->IsValidLowLevel() || Queue->IsPendingKill())
		{
			Queue = ULowEntryExecutionQueue::Create(1, true);
			return Queue;
		}
		Queue->IncreaseCount();
		return Queue;
	}

#if WITH_EDITOR
	// Returns a human readable description of the latent operation's current state
	virtual FString GetDescription() const override
	{
		if((Queue == nullptr) || !Queue->IsValidLowLevel() || Queue->IsPendingKill() || (Queue->Count <= 0))
		{
			return FString::Printf(TEXT("Queued (0 executions remaining)"));
		}
		return FString::Printf(TEXT("Queued (%i executions remaining)"), Queue->Count);
	}
#endif
};
