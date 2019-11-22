// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "K2Node_LowEntry_MakeCustomArray.h"
#include "K2Node_LowEntry_MergeBytesPure.generated.h"


UCLASS(MinimalAPI)
class UK2Node_LowEntry_MergeBytesPure : public UK2Node_LowEntry_MakeCustomArray
{
	GENERATED_UCLASS_BODY()

public:
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual FNodeHandlingFunctor* CreateNodeHandler(FKismetCompilerContext& CompilerContext) const override;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API UEdGraphPin* GetPin(const FString& PinName) const;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual void AllocateDefaultPins() override;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual void AddInputPin() override;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual void RemoveInputPin(UEdGraphPin* Pin) override;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual bool IsConnectionDisallowed(const UEdGraphPin* MyPin, const UEdGraphPin* OtherPin, FString& OutReason) const override { return !ensure(OtherPin); }
};
