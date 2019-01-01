// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryLatentActionObject.h"
#include "FLowEntryLatentActionObject.h"

#include "Engine/Engine.h"


// init >>
	ULowEntryLatentActionObject::ULowEntryLatentActionObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
		KeepAliveCount = 1;
		AddToRoot();
	}

	ULowEntryLatentActionObject* ULowEntryLatentActionObject::Create()
	{
		return NewObject<ULowEntryLatentActionObject>();
	}
// init <<


void ULowEntryLatentActionObject::WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, UObject*& Result_)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if(World == nullptr)
	{
		return;
	}
	if(World->GetLatentActionManager().FindExistingAction<FLowEntryLatentActionObject>(LatentInfo.CallbackTarget, LatentInfo.UUID) != NULL)
	{
		return;
	}
	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryLatentActionObject(LatentInfo, this, Result_));

	KeepAliveCount++;
	if(KeepAliveCount == 1)
	{
		AddToRoot();
	}
}

void ULowEntryLatentActionObject::LatentActionDone()
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

void ULowEntryLatentActionObject::Done(UObject* Result_)
{
	Result = Result_;
	if(!Finished)
	{
		LatentActionDone(); // used to reduce KeepAliveCount by 1
		Finished = true;
	}
}

bool ULowEntryLatentActionObject::IsDone()
{
	return Finished;
}

void ULowEntryLatentActionObject::GetResult(UObject*& Result_)
{
	Result_ = Result;
}
