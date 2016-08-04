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

#if ENGINE_MINOR_VERSION <= 12
	virtual FName GetPaletteIcon(FLinearColor& OutColor) const override
	{
		return TEXT("Kismet.AllClasses.FunctionIcon");
	}
#else
	virtual FSlateIcon GetIconAndTint(FLinearColor& OutColor) const override
	{
		static FSlateIcon Icon("EditorStyle", "Kismet.AllClasses.FunctionIcon");
		return Icon;
	}
#endif
	// End of UEdGraphNode interface

	// UK2Node interface
	virtual bool IsNodePure() const override;
	void NotifyPinConnectionListChanged(UEdGraphPin* Pin) override;
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
