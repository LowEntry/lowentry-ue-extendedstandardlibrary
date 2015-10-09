#include "LowEntryExtendedStandardLibraryPrivatePCH.h"

#include "LowEntryLatentActionInteger.h"
#include "FLowEntryLatentActionInteger.h"


// init >>
	ULowEntryLatentActionInteger::ULowEntryLatentActionInteger(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryLatentActionInteger* ULowEntryLatentActionInteger::Create()
	{
		return NewObject<ULowEntryLatentActionInteger>();
	}
// init <<


void ULowEntryLatentActionInteger::WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	if(World == nullptr)
	{
		return;
	}

	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryLatentActionInteger(LatentInfo, this, Result));
}

void ULowEntryLatentActionInteger::Done(int32 Result)
{
	this->Result = Result;
	Finished = true;
}

bool ULowEntryLatentActionInteger::IsDone()
{
	return Finished;
}

void ULowEntryLatentActionInteger::GetResult(int32& Result)
{
	Result = this->Result;
}
