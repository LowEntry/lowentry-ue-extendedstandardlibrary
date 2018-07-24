// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "K2Node.h"

#include "Textures/SlateIcon.h"

#include "K2Node_LowEntry_LocalVariable.generated.h"


UCLASS(MinimalAPI)
class UK2Node_LowEntry_LocalVariable : public UK2Node
{
	GENERATED_UCLASS_BODY()

public:
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API UEdGraphPin* GetInputPin() const;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API UEdGraphPin* GetOutputPin() const;

public:
	// UEdGraphNode interface
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual void AllocateDefaultPins() override;
	virtual void PostReconstructNode() override;
	virtual FText GetTooltipText() const override;
	virtual void ValidateNodeDuringCompilation(class FCompilerResultsLog& MessageLog) const override;

	virtual FSlateIcon GetIconAndTint(FLinearColor& OutColor) const override
	{
		static FSlateIcon Icon("EditorStyle", "Kismet.AllClasses.FunctionIcon");
		return Icon;
	}
	// End of UEdGraphNode interface

	// UK2Node interface
	virtual bool IsNodePure() const override;
	virtual void NotifyPinConnectionListChanged(UEdGraphPin* Pin) override;
	virtual class FNodeHandlingFunctor* CreateNodeHandler(class FKismetCompilerContext& CompilerContext) const override;
	virtual bool IsConnectionDisallowed(const UEdGraphPin* MyPin, const UEdGraphPin* OtherPin, FString& OutReason) const override;
	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
	virtual FText GetMenuCategory() const override;
	virtual int32 GetNodeRefreshPriority() const override { return EBaseNodeRefreshPriority::Low_UsesDependentWildcard; }
	// End of UK2Node interface


protected:
	friend class FKismetCompilerContext;

	/** Propagates the pin type from the output (array) pin to the inputs, to make sure types are consistent */
	void PropagatePinType();

	bool ArePinTypesEqual(const FEdGraphPinType& A, const FEdGraphPinType& B);
};
