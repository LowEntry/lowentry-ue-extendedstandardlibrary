#include "LowEntryExtendedStandardLibraryPrivatePCH.h"

#include "LowEntryLatentActionObject.h"
#include "FLowEntryLatentActionObject.h"


// init >>
	ULowEntryLatentActionObject::ULowEntryLatentActionObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryLatentActionObject* ULowEntryLatentActionObject::Create()
	{
		return NewObject<ULowEntryLatentActionObject>();
	}
// init <<


	void ULowEntryLatentActionObject::WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, UObject*& Result_)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	if(World == nullptr)
	{
		return;
	}

	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryLatentActionObject(LatentInfo, this, Result_));
}

void ULowEntryLatentActionObject::Done(UObject* Result_)
{
	Result = Result_;
	Finished = true;
}

bool ULowEntryLatentActionObject::IsDone()
{
	return Finished;
}

void ULowEntryLatentActionObject::GetResult(UObject*& Result_)
{
	Result_ = Result;
}
