#include "LowEntryExtendedStandardLibraryPrivatePCH.h"

#include "LowEntryLatentActionNone.h"
#include "FLowEntryLatentActionNone.h"


// init >>
	ULowEntryLatentActionNone::ULowEntryLatentActionNone(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryLatentActionNone* ULowEntryLatentActionNone::Create()
	{
		return NewObject<ULowEntryLatentActionNone>();
	}
// init <<


void ULowEntryLatentActionNone::WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	if(World == nullptr)
	{
		return;
	}

	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryLatentActionNone(LatentInfo, this));
}

void ULowEntryLatentActionNone::Done()
{
	Finished = true;
}

bool ULowEntryLatentActionNone::IsDone()
{
	return Finished;
}
