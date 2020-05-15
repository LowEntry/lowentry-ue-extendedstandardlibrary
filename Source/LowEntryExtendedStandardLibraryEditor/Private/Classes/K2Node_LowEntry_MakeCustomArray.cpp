// Copyright Low Entry. Apache License, Version 2.0.

#include "K2Node_LowEntry_MakeCustomArray.h"

#include "EdGraph/EdGraphPin.h"
#include "Engine/Blueprint.h"
#include "Framework/Commands/UIAction.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "ToolMenus.h"
#include "EdGraph/EdGraphNodeUtils.h"
#include "Kismet2/BlueprintEditorUtils.h"

#include "ScopedTransaction.h"
#include "EdGraphUtilities.h"
#include "KismetCompiledFunctionContext.h"
#include "KismetCompilerMisc.h"
#include "BlueprintNodeSpawner.h"
#include "EditorCategoryUtils.h"
#include "BlueprintActionDatabaseRegistrar.h"

#define LOCTEXT_NAMESPACE "MakeArrayNode"


/////////////////////////////////////////////////////
// FKCHandler_LowEntry_MakeCustomArray

class FKCHandler_LowEntry_MakeCustomArray : public FNodeHandlingFunctor
{
public:
	FKCHandler_LowEntry_MakeCustomArray(FKismetCompilerContext& InCompilerContext) : FNodeHandlingFunctor(InCompilerContext)
	{
	}

	virtual void RegisterNets(FKismetFunctionContext& Context, UEdGraphNode* Node) override
	{
		UK2Node_LowEntry_MakeCustomArray* ArrayNode = CastChecked<UK2Node_LowEntry_MakeCustomArray>(Node);
		FNodeHandlingFunctor::RegisterNets(Context, Node);

		// Create a local term to drop the array into
		UEdGraphPin* ArrayOutputPin = ArrayNode->GetArrayOutputPin();
		FBPTerminal* ArrayTerm = Context.CreateLocalTerminalFromPinAutoChooseScope(ArrayOutputPin, Context.NetNameMap->MakeValidName(ArrayOutputPin) + TEXT("_Array"));
		ArrayTerm->bPassedByReference = false;
		ArrayTerm->Source = Node;
		Context.NetMap.Add(ArrayOutputPin, ArrayTerm);

		// Create a local term to drop the object into
		UEdGraphPin* ObjectOutputPin = ArrayNode->GetObjectOutputPin();
		FBPTerminal* ObjectTerm = Context.CreateLocalTerminalFromPinAutoChooseScope(ObjectOutputPin, Context.NetNameMap->MakeValidName(ObjectOutputPin) + TEXT("_Object"));
		ObjectTerm->bPassedByReference = false;
		ObjectTerm->Source = Node;
		Context.NetMap.Add(ObjectOutputPin, ObjectTerm);
	}

	virtual void Compile(FKismetFunctionContext& Context, UEdGraphNode* Node) override
	{
		UK2Node_LowEntry_MakeCustomArray* ArrayNode = CastChecked<UK2Node_LowEntry_MakeCustomArray>(Node);
		UEdGraphPin* ArrayOutputPin = ArrayNode->GetArrayOutputPin();
		UEdGraphPin* ObjectOutputPin = ArrayNode->GetObjectOutputPin();

		FBPTerminal** ArrayOutputVariable = Context.NetMap.Find(ArrayOutputPin);
		FBPTerminal** ObjectOutputVariable = Context.NetMap.Find(ObjectOutputPin);
		check(ArrayOutputVariable);
		check(ObjectOutputVariable);


		FBlueprintCompiledStatement& CreateArrayStatement = Context.AppendStatementForNode(Node);
		CreateArrayStatement.Type = KCST_CreateArray;
		CreateArrayStatement.LHS = *ArrayOutputVariable;

		for(UEdGraphPin* Pin : Node->Pins)
		{
			if(Pin && (Pin->Direction == EGPD_Input) && (Pin->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec))
			{
				FBPTerminal** InputTerm = Context.NetMap.Find(FEdGraphUtilities::GetNetFromPin(Pin));
				if(InputTerm)
				{
					CreateArrayStatement.RHS.Add(*InputTerm);
				}
			}
		}


		UFunction* ConvertFunctionPointer = FindUField<UFunction>(ArrayNode->LowEntry_ConverterClass, ArrayNode->LowEntry_ConverterFunctionName);
		check(ConvertFunctionPointer);

		FBlueprintCompiledStatement& CreateConvertStatement = Context.AppendStatementForNode(Node);
		CreateConvertStatement.Type = KCST_CallFunction;
		CreateConvertStatement.FunctionToCall = ConvertFunctionPointer;
		CreateConvertStatement.LHS = *ObjectOutputVariable;
		CreateConvertStatement.RHS.Add(*ArrayOutputVariable);


		if(!ArrayNode->LowEntry_IsNodePure)
		{
			GenerateSimpleThenGoto(Context, *Node);
		}
	}
};


/////////////////////////////////////////////////////
// UK2Node_LowEntry_MakeCustomArray

UK2Node_LowEntry_MakeCustomArray::UK2Node_LowEntry_MakeCustomArray(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ContainerType = EPinContainerType::Array;
}

FNodeHandlingFunctor* UK2Node_LowEntry_MakeCustomArray::CreateNodeHandler(FKismetCompilerContext& CompilerContext) const
{
	return new FKCHandler_LowEntry_MakeCustomArray(CompilerContext);
}

FText UK2Node_LowEntry_MakeCustomArray::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return FText::FromString(LowEntry_Name);
}

FName UK2Node_LowEntry_MakeCustomArray::GetOutputPinName() const
{
	return TEXT("TempArray");
}

UEdGraphPin* UK2Node_LowEntry_MakeCustomArray::GetArrayOutputPin() const
{
	return FindPin(GetOutputPinName());
}

UEdGraphPin* UK2Node_LowEntry_MakeCustomArray::GetObjectOutputPin() const
{
	return FindPin(LowEntry_ResultPinName);
}

FText UK2Node_LowEntry_MakeCustomArray::GetTooltipText() const
{
	return FText::FromString(LowEntry_Tooltip);
}

FSlateIcon UK2Node_LowEntry_MakeCustomArray::GetIconAndTint(FLinearColor& OutColor) const
{
	static FSlateIcon Icon("EditorStyle", "GraphEditor.MakeArray_16x");
	return Icon;
}

bool UK2Node_LowEntry_MakeCustomArray::IsNodePure() const
{
	return LowEntry_IsNodePure;
}

void UK2Node_LowEntry_MakeCustomArray::AllocateDefaultPins()
{
	if(!LowEntry_IsNodePure)
	{
		CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Exec, NULL, UEdGraphSchema_K2::PN_Execute);
		CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, NULL, UEdGraphSchema_K2::PN_Then);
	}

	// Create the output pins
	UEdGraphPin* ObjectOutputPin = CreatePin(EGPD_Output, LowEntry_OutputType, LowEntry_OutputClass, LowEntry_ResultPinName);
	FCreatePinParams ArrayOutputPinParams = FCreatePinParams();
	ArrayOutputPinParams.ContainerType = EPinContainerType::Array;
	UEdGraphPin* ArrayOutputPin = CreatePin(EGPD_Output, LowEntry_InputType, LowEntry_InputClass, GetOutputPinName(), ArrayOutputPinParams);

	ArrayOutputPin->bHidden = true;

	// Create the input pins to create the arrays from
	for(int32 i = 0; i < NumInputs; ++i)
	{
		CreatePin(EGPD_Input, LowEntry_InputType, LowEntry_InputClass, GetPinName(i));
	}
}

void UK2Node_LowEntry_MakeCustomArray::PostReconstructNode()
{
	Super::Super::PostReconstructNode();
}

void UK2Node_LowEntry_MakeCustomArray::NotifyPinConnectionListChanged(UEdGraphPin* Pin)
{
	Super::Super::NotifyPinConnectionListChanged(Pin);
}

void UK2Node_LowEntry_MakeCustomArray::GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
	Super::Super::GetNodeContextMenuActions(Menu, Context);

	if(!Context->bIsDebugging)
	{
		FToolMenuSection& Section = Menu->AddSection("K2NodeMakeArray", FText::FromString("Low Entry"));

		if(Context->Pin != NULL)
		{
			if((Context->Pin->Direction == EGPD_Input) && (Context->Pin->ParentPin == nullptr) && (Context->Pin->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec))
			{
				Section.AddMenuEntry(
					"RemovePin",
					LOCTEXT("RemovePin", "Remove array element pin"),
					LOCTEXT("RemovePinTooltip", "Remove this array element pin"),
					FSlateIcon(),
					FUIAction(
						FExecuteAction::CreateUObject(const_cast<UK2Node_LowEntry_MakeCustomArray*>(this), &UK2Node_LowEntry_MakeCustomArray::RemoveInputPin, const_cast<UEdGraphPin*>(Context->Pin))
					)
				);
			}
		}
		else
		{
			Section.AddMenuEntry(
				"AddPin",
				LOCTEXT("AddPin", "Add array element pin"),
				LOCTEXT("AddPinTooltip", "Add another array element pin"),
				FSlateIcon(),
				FUIAction(
					FExecuteAction::CreateUObject(const_cast<UK2Node_LowEntry_MakeCustomArray*>(this), &UK2Node_LowEntry_MakeCustomArray::InteractiveAddInputPin)
				)
			);
		}
	}
}

void UK2Node_LowEntry_MakeCustomArray::ReallocatePinsDuringReconstruction(TArray<UEdGraphPin*>& OldPins)
{
	Super::Super::ReallocatePinsDuringReconstruction(OldPins);
}

void UK2Node_LowEntry_MakeCustomArray::ValidateNodeDuringCompilation(class FCompilerResultsLog& MessageLog) const
{
	Super::Super::ValidateNodeDuringCompilation(MessageLog);
}

FText UK2Node_LowEntry_MakeCustomArray::GetMenuCategory() const
{
	return FText::FromString(LowEntry_Category);
}

bool UK2Node_LowEntry_MakeCustomArray::IsConnectionDisallowed(const UEdGraphPin* MyPin, const UEdGraphPin* OtherPin, FString& OutReason) const
{
	if(Super::Super::IsConnectionDisallowed(MyPin, OtherPin, OutReason))
	{
		return true;
	}

	if(!ensure(OtherPin))
	{
		return true;
	}

	return false;
}
#undef LOCTEXT_NAMESPACE
