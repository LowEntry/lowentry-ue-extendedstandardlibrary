namespace UnrealBuildTool.Rules
{
	public class LowEntryExtendedStandardLibraryEditor : ModuleRules
	{
		public LowEntryExtendedStandardLibraryEditor(ReadOnlyTargetRules Target) : base(Target)
        {
            PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Engine",
					"Core",
					"CoreUObject",
					"InputCore",
					"Slate",
					"EditorStyle",
					"AIModule",
					"BlueprintGraph",
					"LowEntryExtendedStandardLibrary",
				}
			);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"EditorStyle",
					"KismetCompiler",
					"UnrealEd",
					"GraphEditor",
					"SlateCore",
                    "Kismet",
                    "KismetWidgets",
                    "PropertyEditor",
                }
			);
		}
	}
}
