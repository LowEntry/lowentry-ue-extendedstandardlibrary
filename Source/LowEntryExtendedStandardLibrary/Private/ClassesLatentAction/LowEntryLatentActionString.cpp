// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryLatentActionString.h"
#include "FLowEntryLatentActionString.h"

#include "Engine/Engine.h"


// init >>
	ULowEntryLatentActionString::ULowEntryLatentActionString(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
		KeepAliveCount = 1;
		AddToRoot();
	}

	ULowEntryLatentActionString* ULowEntryLatentActionString::Create()
	{
		return NewObject<ULowEntryLatentActionString>();
	}
// init <<


void ULowEntryLatentActionString::WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result_)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if(World == nullptr)
	{
		return;
	}
	if(World->GetLatentActionManager().FindExistingAction<FLowEntryLatentActionString>(LatentInfo.CallbackTarget, LatentInfo.UUID) != NULL)
	{
		return;
	}
	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryLatentActionString(LatentInfo, this, Result_));

	KeepAliveCount++;
	if(KeepAliveCount == 1)
	{
		AddToRoot();
	}
}

void ULowEntryLatentActionString::LatentActionDone()
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

void ULowEntryLatentActionString::Done(FString Result_)
{
	Result = Result_;
	if(!Finished)
	{
		LatentActionDone(); // used to reduce KeepAliveCount by 1
		Finished = true;
	}
}

bool ULowEntryLatentActionString::IsDone()
{
	return Finished;
}

void ULowEntryLatentActionString::GetResult(FString& Result_)
{
	Result_ = Result;
}
