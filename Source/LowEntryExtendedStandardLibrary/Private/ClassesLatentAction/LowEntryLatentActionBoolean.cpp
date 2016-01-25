#include "LowEntryExtendedStandardLibraryPrivatePCH.h"

#include "LowEntryLatentActionBoolean.h"
#include "FLowEntryLatentActionBoolean.h"


// init >>
	ULowEntryLatentActionBoolean::ULowEntryLatentActionBoolean(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryLatentActionBoolean* ULowEntryLatentActionBoolean::Create()
	{
		return NewObject<ULowEntryLatentActionBoolean>();
	}
// init <<


void ULowEntryLatentActionBoolean::WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result_)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	if(World == nullptr)
	{
		return;
	}

	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryLatentActionBoolean(LatentInfo, this, Result_));
}

void ULowEntryLatentActionBoolean::Done(bool Result_)
{
	Result = Result_;
	Finished = true;
}

bool ULowEntryLatentActionBoolean::IsDone()
{
	return Finished;
}

void ULowEntryLatentActionBoolean::GetResult(bool& Result_)
{
	Result_ = Result;
}
