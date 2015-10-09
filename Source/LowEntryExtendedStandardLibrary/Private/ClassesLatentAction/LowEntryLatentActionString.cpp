#include "LowEntryExtendedStandardLibraryPrivatePCH.h"

#include "LowEntryLatentActionString.h"
#include "FLowEntryLatentActionString.h"


// init >>
	ULowEntryLatentActionString::ULowEntryLatentActionString(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryLatentActionString* ULowEntryLatentActionString::Create()
	{
		return NewObject<ULowEntryLatentActionString>();
	}
// init <<


	void ULowEntryLatentActionString::WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	if(World == nullptr)
	{
		return;
	}

	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryLatentActionString(LatentInfo, this, Result));
}

void ULowEntryLatentActionString::Done(FString Result)
{
	this->Result = Result;
	Finished = true;
}

bool ULowEntryLatentActionString::IsDone()
{
	return Finished;
}

void ULowEntryLatentActionString::GetResult(FString& Result)
{
	Result = this->Result;
}
