// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryLatentActionFloat.h"
#include "FLowEntryLatentActionFloat.h"

#include "Engine/Engine.h"


// init >>
	ULowEntryLatentActionFloat::ULowEntryLatentActionFloat(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
		KeepAliveCount = 1;
		AddToRoot();
	}

	ULowEntryLatentActionFloat* ULowEntryLatentActionFloat::Create()
	{
		return NewObject<ULowEntryLatentActionFloat>();
	}
// init <<


void ULowEntryLatentActionFloat::WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result_)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if(World == nullptr)
	{
		return;
	}
	if(World->GetLatentActionManager().FindExistingAction<FLowEntryLatentActionFloat>(LatentInfo.CallbackTarget, LatentInfo.UUID) != NULL)
	{
		return;
	}
	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryLatentActionFloat(LatentInfo, this, Result_));

	KeepAliveCount++;
	if(KeepAliveCount == 1)
	{
		AddToRoot();
	}
}

void ULowEntryLatentActionFloat::LatentActionDone()
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

void ULowEntryLatentActionFloat::Done(float Result_)
{
	Result = Result_;
	if(!Finished)
	{
		LatentActionDone(); // used to reduce KeepAliveCount by 1
		Finished = true;
	}
}

bool ULowEntryLatentActionFloat::IsDone()
{
	return Finished;
}

void ULowEntryLatentActionFloat::GetResult(float& Result_)
{
	Result_ = Result;
}
