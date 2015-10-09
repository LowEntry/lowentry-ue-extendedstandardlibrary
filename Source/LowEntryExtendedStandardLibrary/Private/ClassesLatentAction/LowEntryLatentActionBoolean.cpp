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


	void ULowEntryLatentActionBoolean::WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	if(World == nullptr)
	{
		return;
	}

	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryLatentActionBoolean(LatentInfo, this, Result));
}

void ULowEntryLatentActionBoolean::Done(bool Result)
{
	this->Result = Result;
	Finished = true;
}

bool ULowEntryLatentActionBoolean::IsDone()
{
	return Finished;
}

void ULowEntryLatentActionBoolean::GetResult(bool& Result)
{
	Result = this->Result;
}
