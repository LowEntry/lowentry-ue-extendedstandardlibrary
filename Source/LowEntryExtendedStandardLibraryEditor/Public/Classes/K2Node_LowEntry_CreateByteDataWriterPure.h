// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "K2Node.h"

#include "Textures/SlateIcon.h"

#include "K2Node_LowEntry_CreateByteDataWriterPure.generated.h"


UCLASS(MinimalAPI)
class UK2Node_LowEntry_CreateByteDataWriterPure : public UK2Node
{
	GENERATED_UCLASS_BODY()

	/** The number of input pins to generate for this node */
	UPROPERTY()
	int32 NumInputs;

public:
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API void AddInputPin();
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API void RemoveInputPin(UEdGraphPin* Pin);

	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API UEdGraphPin* GetArrayOutputPin() const;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API UEdGraphPin* GetObjectOutputPin() const;

public:
	// UEdGraphNode interface
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual void AllocateDefaultPins() override;
	virtual FText GetTooltipText() const override;

	virtual FSlateIcon GetIconAndTint(FLinearColor& OutColor) const override
	{
		static FSlateIcon Icon("EditorStyle", "GraphEditor.MakeArray_16x");
		return Icon;
	}
	// End of UEdGraphNode interface

	// UK2Node interface
	virtual bool IsNodePure() const override;
	virtual void NotifyPinConnectionListChanged(UEdGraphPin* Pin) override;
	virtual void GetContextMenuActions(const FGraphNodeContextMenuBuilder& Context) const override;
	virtual class FNodeHandlingFunctor* CreateNodeHandler(class FKismetCompilerContext& CompilerContext) const override;
	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
	virtual FText GetMenuCategory() const override;
	virtual int32 GetNodeRefreshPriority() const override
	{
		return EBaseNodeRefreshPriority::Normal;
	}
	// End of UK2Node interface


protected:
	friend class FKismetCompilerContext;
};
