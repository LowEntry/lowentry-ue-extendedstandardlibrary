// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryExecutionQueue.h"


// init >>
	ULowEntryExecutionQueue::ULowEntryExecutionQueue(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryExecutionQueue* ULowEntryExecutionQueue::Create()
	{
		return NewObject<ULowEntryExecutionQueue>();
	}

	ULowEntryExecutionQueue* ULowEntryExecutionQueue::Create(const int32 Count, const bool Next)
	{
		ULowEntryExecutionQueue* Instance = NewObject<ULowEntryExecutionQueue>();
		Instance->Count = Count;
		Instance->Next = Next;
		if(Count > 0)
		{
			Instance->AddToRoot();
		}
		return Instance;
	}
// init <<


void ULowEntryExecutionQueue::IncreaseCount()
{
	Count++;
	if(Count == 1)
	{
		AddToRoot();
	}
}

void ULowEntryExecutionQueue::DecreaseCount()
{
	Count--;
	if(Count == 0)
	{
		RemoveFromRoot();
	}
	if(Count < 0)
	{
		Count = 0;
	}
}
