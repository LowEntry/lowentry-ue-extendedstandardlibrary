#pragma once


#include "Engine.h"
#include "GraphEditorSettings.h"
#include "BlueprintGraphDefinitions.h"
#include "BlueprintUtilities.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "UnrealEd.h"
#include "EditorStyle.h"

#include "SlateBasics.h"
#include "Kismet/KismetArrayLibrary.h"
#include "ScopedTransaction.h"
#include "KismetCompiler.h"
#include "BlueprintNodeSpawner.h"
#include "EditorCategoryUtils.h"
#include "BlueprintActionDatabaseRegistrar.h"
#include "EdGraph/EdGraphNodeUtils.h"

#include "K2Node.h"

#include "Runtime/Launch/Resources/Version.h"

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

#if ENGINE_MINOR_VERSION <= 12
	virtual FName GetPaletteIcon(FLinearColor& OutColor) const override
	{
		return TEXT("GraphEditor.MakeArray_16x");
	}
#else
	virtual FSlateIcon GetIconAndTint(FLinearColor& OutColor) const override
	{
		static FSlateIcon Icon("EditorStyle", "GraphEditor.MakeArray_16x");
		return Icon;
	}
#endif
	// End of UEdGraphNode interface

	// UK2Node interface
	virtual bool IsNodePure() const override;
	void NotifyPinConnectionListChanged(UEdGraphPin* Pin) override;
	void GetContextMenuActions(const FGraphNodeContextMenuBuilder& Context) const override;
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
