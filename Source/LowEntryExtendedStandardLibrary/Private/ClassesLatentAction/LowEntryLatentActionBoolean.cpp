// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryLatentActionBoolean.h"
#include "FLowEntryLatentActionBoolean.h"

#include "Engine/Engine.h"


// init >>
	ULowEntryLatentActionBoolean::ULowEntryLatentActionBoolean(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
		KeepAliveCount = 1;
		AddToRoot();
	}

	ULowEntryLatentActionBoolean* ULowEntryLatentActionBoolean::Create()
	{
		return NewObject<ULowEntryLatentActionBoolean>();
	}
// init <<


void ULowEntryLatentActionBoolean::WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result_)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if(World == nullptr)
	{
		return;
	}
	if(World->GetLatentActionManager().FindExistingAction<FLowEntryLatentActionBoolean>(LatentInfo.CallbackTarget, LatentInfo.UUID) != NULL)
	{
		return;
	}
	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryLatentActionBoolean(LatentInfo, this, Result_));

	KeepAliveCount++;
	if(KeepAliveCount == 1)
	{
		AddToRoot();
	}
}

void ULowEntryLatentActionBoolean::LatentActionDone()
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

void ULowEntryLatentActionBoolean::Done(bool Result_)
{
	Result = Result_;
	if(!Finished)
	{
		LatentActionDone(); // used to reduce KeepAliveCount by 1
		Finished = true;
	}
}

bool ULowEntryLatentActionBoolean::IsDone()
{
	return Finished;
}

void ULowEntryLatentActionBoolean::GetResult(bool& Result_)
{
	Result_ = Result;
}
