// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryLatentActionInteger.h"
#include "FLowEntryLatentActionInteger.h"

#include "Engine/Engine.h"


// init >>
	ULowEntryLatentActionInteger::ULowEntryLatentActionInteger(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
		KeepAliveCount = 1;
		AddToRoot();
	}

	ULowEntryLatentActionInteger* ULowEntryLatentActionInteger::Create()
	{
		return NewObject<ULowEntryLatentActionInteger>();
	}
// init <<


void ULowEntryLatentActionInteger::WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result_)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if(World == nullptr)
	{
		return;
	}
	if(World->GetLatentActionManager().FindExistingAction<FLowEntryLatentActionInteger>(LatentInfo.CallbackTarget, LatentInfo.UUID) != NULL)
	{
		return;
	}
	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryLatentActionInteger(LatentInfo, this, Result_));

	KeepAliveCount++;
	if(KeepAliveCount == 1)
	{
		AddToRoot();
	}
}

void ULowEntryLatentActionInteger::LatentActionDone()
{
	KeepAliveCount--;
	if(KeepAliveCount == 0)
	{
		RemoveFromRoot();
	}
	if(KeepAliveCount < 0)
	{
		KeepAliveCount = 0;
	}
}

void ULowEntryLatentActionInteger::Done(int32 Result_)
{
	Result = Result_;
	if(!Finished)
	{
		LatentActionDone(); // used to reduce KeepAliveCount by 1
		Finished = true;
	}
}

bool ULowEntryLatentActionInteger::IsDone()
{
	return Finished;
}

void ULowEntryLatentActionInteger::GetResult(int32& Result_)
{
	Result_ = Result;
}
