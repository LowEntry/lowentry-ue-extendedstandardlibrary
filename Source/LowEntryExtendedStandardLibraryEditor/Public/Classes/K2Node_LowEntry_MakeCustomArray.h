// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "K2Node_LowEntry_MakeContainer.h"
#include "EdGraphSchema_K2.h"
#include "K2Node_LowEntry_MakeCustomArray.generated.h"


class FBlueprintActionDatabaseRegistrar;
class UEdGraphPin;


UCLASS(MinimalAPI, abstract)
class UK2Node_LowEntry_MakeCustomArray : public UK2Node_LowEntry_MakeContainer
{
	GENERATED_UCLASS_BODY()

public:
	UPROPERTY()
	FString LowEntry_Name = TEXT("");

	UPROPERTY()
	FString LowEntry_Category = TEXT("");

	UPROPERTY()
	FString LowEntry_Tooltip = TEXT("");

	UPROPERTY()
	FName LowEntry_ResultPinName = TEXT("");

	UPROPERTY()
	bool LowEntry_IsNodePure = false;

	UPROPERTY()
	FName LowEntry_InputType = UEdGraphSchema_K2::PC_Object;

	UPROPERTY()
	UClass* LowEntry_InputClass = NULL;

	UPROPERTY()
	FName LowEntry_OutputType = UEdGraphSchema_K2::PC_Object;

	UPROPERTY()
	UClass* LowEntry_OutputClass = NULL;

	UPROPERTY()
	UClass* LowEntry_ConverterClass = NULL;

	UPROPERTY()
	FName LowEntry_ConverterFunctionName = TEXT("");

public:
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API UEdGraphPin* GetArrayOutputPin() const;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API UEdGraphPin* GetObjectOutputPin() const;

public:
	// UEdGraphNode interface
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual FText GetTooltipText() const override;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual FSlateIcon GetIconAndTint(FLinearColor& OutColor) const override;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual void ValidateNodeDuringCompilation(class FCompilerResultsLog& MessageLog) const override;
	// End of UEdGraphNode interface

	// UK2Node interface
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual void GetNodeContextMenuActions(class UToolMenu* Menu, class UGraphNodeContextMenuContext* Context) const override;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual bool IncludeParentNodeContextMenu() const override { return true; }
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual class FNodeHandlingFunctor* CreateNodeHandler(class FKismetCompilerContext& CompilerContext) const override;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual FText GetMenuCategory() const override;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual FName GetOutputPinName() const override;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual bool IsNodePure() const override;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual void AllocateDefaultPins() override;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual void PostReconstructNode() override;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual void NotifyPinConnectionListChanged(UEdGraphPin* Pin) override;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual void ReallocatePinsDuringReconstruction(TArray<UEdGraphPin*>& OldPins) override;
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual int32 GetNodeRefreshPriority() const override { return EBaseNodeRefreshPriority::Normal; }
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API virtual bool IsConnectionDisallowed(const UEdGraphPin* MyPin, const UEdGraphPin* OtherPin, FString& OutReason) const override;
	// UK2Node_MakeContainer interface
};
