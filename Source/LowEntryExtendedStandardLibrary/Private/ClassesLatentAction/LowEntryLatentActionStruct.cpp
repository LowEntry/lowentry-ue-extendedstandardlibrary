// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryLatentActionStruct.h"
#include "FLowEntryLatentActionStruct.h"

#include "Engine/Engine.h"


ULowEntryLatentActionStruct::ULowEntryLatentActionStruct(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	KeepAliveCount = 1;
	AddToRoot();
}

ULowEntryLatentActionStruct* ULowEntryLatentActionStruct::Create()
{
	return NewObject<ULowEntryLatentActionStruct>();
}


void ULowEntryLatentActionStruct::WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FInstancedStruct& Result_)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (World == nullptr)
	{
		return;
	}
	if (World->GetLatentActionManager().FindExistingAction<FLowEntryLatentActionStruct>(LatentInfo.CallbackTarget, LatentInfo.UUID) != nullptr)
	{
		return;
	}
	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryLatentActionStruct(LatentInfo, this, Result_));

	KeepAliveCount++;
	if (KeepAliveCount == 1)
	{
		AddToRoot();
	}
}

void ULowEntryLatentActionStruct::LatentActionDone()
{
	KeepAliveCount--;
	if (KeepAliveCount == 0)
	{
		RemoveFromRoot();
	}
	if (KeepAliveCount < 0)
	{
		KeepAliveCount = 0;
	}
}

void ULowEntryLatentActionStruct::Done(const FInstancedStruct& Result_)
{
	Result = Result_;
	if (!Finished)
	{
		LatentActionDone(); // used to reduce KeepAliveCount by 1
		Finished = true;
	}
}

bool ULowEntryLatentActionStruct::IsDone()
{
	return Finished;
}

void ULowEntryLatentActionStruct::GetResult(FInstancedStruct& Result_)
{
	Result_ = Result;
}
