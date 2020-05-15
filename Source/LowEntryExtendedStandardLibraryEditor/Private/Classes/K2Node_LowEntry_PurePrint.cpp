// Copyright Low Entry. Apache License, Version 2.0.

#include "K2Node_LowEntry_PurePrint.h"

#include "LowEntryExtendedStandardLibrary.h"


#include "EdGraph/EdGraphPin.h"
#include "Engine/Blueprint.h"
#include "Framework/Commands/UIAction.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "EdGraphSchema_K2.h"
#include "EdGraph/EdGraphNodeUtils.h"
#include "Kismet2/BlueprintEditorUtils.h"

#include "Kismet/KismetArrayLibrary.h"
#include "ScopedTransaction.h"
#include "EdGraphUtilities.h"
#include "KismetCompiledFunctionContext.h"
#include "KismetCompilerMisc.h"
#include "BlueprintNodeSpawner.h"
#include "EditorCategoryUtils.h"
#include "BlueprintActionDatabaseRegistrar.h"


#define LOCTEXT_NAMESPACE "MakeArrayNode"


/////////////////////////////////////////////////////
// FKCHandler_LowEntry_PurePrint

class FKCHandler_LowEntry_PurePrint : public FNodeHandlingFunctor
{
public:
	FKCHandler_LowEntry_PurePrint(FKismetCompilerContext& InCompilerContext) : FNodeHandlingFunctor(InCompilerContext)
	{
	}

	virtual void RegisterNets(FKismetFunctionContext& Context, UEdGraphNode* Node) override
	{
		UK2Node_LowEntry_PurePrint* CastedNode = CastChecked<UK2Node_LowEntry_PurePrint>(Node);
		FNodeHandlingFunctor::RegisterNets(Context, Node);

		// Create a local term to drop the object into
		UEdGraphPin* OutputPin = CastedNode->GetOutputPin();
		FBPTerminal* OutputPinTerm = Context.CreateLocalTerminalFromPinAutoChooseScope(OutputPin, Context.NetNameMap->MakeValidName(OutputPin) + TEXT("_Object"));
		OutputPinTerm->bPassedByReference = false;
		OutputPinTerm->Source = Node;
		Context.NetMap.Add(OutputPin, OutputPinTerm);
	}

	virtual void Compile(FKismetFunctionContext& Context, UEdGraphNode* Node) override
	{
		UK2Node_LowEntry_PurePrint* CastedNode = CastChecked<UK2Node_LowEntry_PurePrint>(Node);
		UEdGraphPin* InputPin = CastedNode->GetInputPin();
		UEdGraphPin* StringInputPin = CastedNode->GetStringInputPin();
		UEdGraphPin* OutputPin = CastedNode->GetOutputPin();

		FBPTerminal** InputPinVariable = Context.NetMap.Find(FEdGraphUtilities::GetNetFromPin(InputPin));
		FBPTerminal** StringInputPinVariable = Context.NetMap.Find(FEdGraphUtilities::GetNetFromPin(StringInputPin));
		FBPTerminal** OutputPinVariable = Context.NetMap.Find(OutputPin);
		check(InputPinVariable);
		check(StringInputPinVariable);
		check(OutputPinVariable);


		FBlueprintCompiledStatement& AssignStatement = Context.AppendStatementForNode(Node);
		AssignStatement.Type = KCST_Assignment;
		AssignStatement.RHS.Add(*InputPinVariable);
		AssignStatement.LHS = *OutputPinVariable;


		UClass* PrintFunctionClass = Cast<UClass>(ULowEntryExtendedStandardLibrary::StaticClass());
		UFunction* PrintFunctionPointer = FindUField<UFunction>(PrintFunctionClass, TEXT("SimpleKismetSystemLibraryPrintString"));
		check(PrintFunctionPointer);

		FBlueprintCompiledStatement& CreatePrintStatement = Context.AppendStatementForNode(Node);
		CreatePrintStatement.Type = KCST_CallFunction;
		CreatePrintStatement.FunctionToCall = PrintFunctionPointer;
		CreatePrintStatement.RHS.Add(*StringInputPinVariable);


		if(!true)
		{
			GenerateSimpleThenGoto(Context, *Node);
		}
	}
};


/////////////////////////////////////////////////////
// UK2Node_LowEntry_PurePrint

UK2Node_LowEntry_PurePrint::UK2Node_LowEntry_PurePrint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

FNodeHandlingFunctor* UK2Node_LowEntry_PurePrint::CreateNodeHandler(FKismetCompilerContext& CompilerContext) const
{
	return new FKCHandler_LowEntry_PurePrint(CompilerContext);
}

FText UK2Node_LowEntry_PurePrint::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return FText::FromString("Pure Print");
}

UEdGraphPin* UK2Node_LowEntry_PurePrint::GetInputPin() const
{
	return FindPin(TEXT("Value"));
}

UEdGraphPin* UK2Node_LowEntry_PurePrint::GetStringInputPin() const
{
	return FindPin(TEXT("Message"));
}

UEdGraphPin* UK2Node_LowEntry_PurePrint::GetOutputPin() const
{
	return FindPin(TEXT("Value "));
}

bool UK2Node_LowEntry_PurePrint::IsNodePure() const
{
	return true;
}

void UK2Node_LowEntry_PurePrint::AllocateDefaultPins()
{
	if(!true)
	{
		CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Exec, TEXT(""), NULL, UEdGraphSchema_K2::PN_Execute);
		CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, TEXT(""), NULL, UEdGraphSchema_K2::PN_Then);
	}

	UEdGraphPin* InputPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Wildcard, TEXT(""), NULL, TEXT("Value"));
	UEdGraphPin* StringInputPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_String, TEXT(""), NULL, TEXT("Message"));
	UEdGraphPin* OutputPin = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Wildcard, TEXT(""), NULL, TEXT("Value "));
}

void UK2Node_LowEntry_PurePrint::NotifyPinConnectionListChanged(UEdGraphPin* Pin)
{
	Super::NotifyPinConnectionListChanged(Pin);

	if(Pin != nullptr)
	{
		if((Pin->Direction == EGPD_Output) || (Pin->PinType.PinCategory == UEdGraphSchema_K2::PC_Exec))
		{
			return;
		}

		PropagatePinType();
	}
}

void UK2Node_LowEntry_PurePrint::PropagatePinType()
{
	UEdGraphPin* InputPin = GetInputPin();
	UEdGraphPin* OutputPin = GetOutputPin();

	if(InputPin->LinkedTo.Num() > 0)
	{
		InputPin->PinType = InputPin->LinkedTo[0]->PinType;
	}
	else
	{
		InputPin->PinType.PinCategory = UEdGraphSchema_K2::PC_Wildcard;
		InputPin->PinType.PinSubCategory = TEXT("");
		InputPin->PinType.PinSubCategoryObject = NULL;
	}

	if(!ArePinTypesEqual(InputPin->PinType, OutputPin->PinType))
	{
		OutputPin->PinType = InputPin->PinType;
		if((OutputPin->GetOwningNode() != NULL) && (OutputPin->GetOwningNode()->GetGraph() != NULL))
		{
			OutputPin->GetOwningNode()->GetGraph()->NotifyGraphChanged();
		}
	}
}

bool UK2Node_LowEntry_PurePrint::ArePinTypesEqual(const FEdGraphPinType& A, const FEdGraphPinType& B)
{
	if(A.PinCategory != B.PinCategory)
	{
		return false;
	}
	if(A.PinSubCategory != B.PinSubCategory)
	{
		return false;
	}
	if(A.PinSubCategoryObject != B.PinSubCategoryObject)
	{
		return false;
	}
	return true;
}

void UK2Node_LowEntry_PurePrint::PostReconstructNode()
{
	PropagatePinType();
}

FText UK2Node_LowEntry_PurePrint::GetTooltipText() const
{
	return FText::FromString("Prints a message when a variable is accessed.");
}

bool UK2Node_LowEntry_PurePrint::IsConnectionDisallowed(const UEdGraphPin* MyPin, const UEdGraphPin* OtherPin, FString& OutReason) const
{
	auto Schema = Cast<const UEdGraphSchema_K2>(GetSchema());
	if(!ensure(Schema) || (ensure(OtherPin) && Schema->IsExecPin(*OtherPin) && !Schema->IsExecPin(*MyPin)))
	{
		OutReason = NSLOCTEXT("K2Node", "MakeArray_InputIsExec", "Doesn't allow execution input!").ToString();
		return true;
	}

	return false;
}

void UK2Node_LowEntry_PurePrint::ValidateNodeDuringCompilation(class FCompilerResultsLog& MessageLog) const
{
	auto Schema = Cast<const UEdGraphSchema_K2>(GetSchema());
	auto OutputPin = GetOutputPin();
	if(!ensure(Schema) || !ensure(OutputPin) || Schema->IsExecPin(*OutputPin))
	{
		MessageLog.Error(*NSLOCTEXT("K2Node", "MakeArray_OutputIsExec", "Uaccepted type in @@").ToString(), this);
	}
}

void UK2Node_LowEntry_PurePrint::GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const
{
	// actions get registered under specific object-keys; the idea is that 
	// actions might have to be updated (or deleted) if their object-key is  
	// mutated (or removed)... here we use the node's class (so if the node 
	// type disappears, then the action should go with it)
	UClass* ActionKey = GetClass();
	// to keep from needlessly instantiating a UBlueprintNodeSpawner, first   
	// check to make sure that the registrar is looking for actions of this type
	// (could be regenerating actions for a specific asset, and therefore the 
	// registrar would only accept actions corresponding to that asset)
	if(ActionRegistrar.IsOpenForRegistration(ActionKey))
	{
		UBlueprintNodeSpawner* NodeSpawner = UBlueprintNodeSpawner::Create(GetClass());
		check(NodeSpawner != nullptr);

		ActionRegistrar.AddBlueprintAction(ActionKey, NodeSpawner);
	}
}

FText UK2Node_LowEntry_PurePrint::GetMenuCategory() const
{
	return FText::FromString("Low Entry|Extended Standard Library|Utilities|Other");
}

#undef LOCTEXT_NAMESPACE
