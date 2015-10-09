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


	void ULowEntryLatentActionObject::WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, UObject*& Result)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	if(World == nullptr)
	{
		return;
	}

	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryLatentActionObject(LatentInfo, this, Result));
}

void ULowEntryLatentActionObject::Done(UObject* Result)
{
	this->Result = Result;
	Finished = true;
}

bool ULowEntryLatentActionObject::IsDone()
{
	return Finished;
}

void ULowEntryLatentActionObject::GetResult(UObject*& Result)
{
	Result = this->Result;
}
