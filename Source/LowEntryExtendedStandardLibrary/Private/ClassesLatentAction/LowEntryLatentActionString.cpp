#include "LowEntryExtendedStandardLibraryPrivatePCH.h"

#include "LowEntryLatentActionString.h"
#include "FLowEntryLatentActionString.h"


// init >>
	ULatentActionClass::ULatentActionClass(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULatentActionClass* ULatentActionClass::Create()
	{
		return NewObject<ULatentActionClass>();
	}
// init <<


void ULatentActionClass::WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, LatentActionResultType& Result)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	if(World == nullptr)
	{
		return;
	}

	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLatentActionClass(LatentInfo, this, Result));
}

void ULatentActionClass::Done(LatentActionResultType Result)
{
	this->Result = Result;
	Finished = true;
}

bool ULatentActionClass::IsDone()
{
	return Finished;
}

void ULatentActionClass::GetResult(LatentActionResultType& Result)
{
	Result = this->Result;
}
