// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryLatentActionNone.h"
#include "FLowEntryLatentActionNone.h"

#include "Engine/Engine.h"


// init >>
	ULowEntryLatentActionNone::ULowEntryLatentActionNone(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
		KeepAliveCount = 1;
		AddToRoot();
	}

	ULowEntryLatentActionNone* ULowEntryLatentActionNone::Create()
	{
		return NewObject<ULowEntryLatentActionNone>();
	}
// init <<


void ULowEntryLatentActionNone::WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if(World == nullptr)
	{
		return;
	}
	if(World->GetLatentActionManager().FindExistingAction<FLowEntryLatentActionNone>(LatentInfo.CallbackTarget, LatentInfo.UUID) != NULL)
	{
		return;
	}
	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryLatentActionNone(LatentInfo, this));

	KeepAliveCount++;
	if(KeepAliveCount == 1)
	{
		AddToRoot();
	}
}

void ULowEntryLatentActionNone::LatentActionDone()
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

void ULowEntryLatentActionNone::Done()
{
	if(!Finished)
	{
		LatentActionDone(); // used to reduce KeepAliveCount by 1
		Finished = true;
	}
}

bool ULowEntryLatentActionNone::IsDone()
{
	return Finished;
}
