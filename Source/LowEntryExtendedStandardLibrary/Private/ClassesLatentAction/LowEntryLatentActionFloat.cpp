#include "LowEntryExtendedStandardLibraryPrivatePCH.h"

#include "LowEntryLatentActionFloat.h"
#include "FLowEntryLatentActionFloat.h"


// init >>
	ULowEntryLatentActionFloat::ULowEntryLatentActionFloat(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryLatentActionFloat* ULowEntryLatentActionFloat::Create()
	{
		return NewObject<ULowEntryLatentActionFloat>();
	}
// init <<


void ULowEntryLatentActionFloat::WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	if(World == nullptr)
	{
		return;
	}

	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryLatentActionFloat(LatentInfo, this, Result));
}

void ULowEntryLatentActionFloat::Done(float Result)
{
	this->Result = Result;
	Finished = true;
}

bool ULowEntryLatentActionFloat::IsDone()
{
	return Finished;
}

void ULowEntryLatentActionFloat::GetResult(float& Result)
{
	Result = this->Result;
}
