#include "LowEntryExtendedStandardLibraryPrivatePCH.h"

#include "LowEntryLatentActionNone.h"
#include "FLowEntryLatentActionNone.h"


// init >>
	ULatentActionClass::ULatentActionClass(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULatentActionClass* ULatentActionClass::Create()
	{
		return NewObject<ULatentActionClass>();
	}
// init <<


void ULatentActionClass::WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	if(World == nullptr)
	{
		return;
	}

	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLatentActionClass(LatentInfo, this));
}

void ULatentActionClass::Done()
{
	Finished = true;
}

bool ULatentActionClass::IsDone()
{
	return Finished;
}
