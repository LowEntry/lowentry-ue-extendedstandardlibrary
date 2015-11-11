namespace UnrealBuildTool.Rules
{
	public class LowEntryExtendedStandardLibraryEditor : ModuleRules
	{
		public LowEntryExtendedStandardLibraryEditor(TargetInfo Target)
		{
			PublicIncludePaths.AddRange(
				new string[] {
					"LowEntryExtendedStandardLibraryEditor/Public/Module",
					"LowEntryExtendedStandardLibraryEditor/Public/Classes",
				}
			);

			PrivateIncludePaths.AddRange(
				new string[] {
					"LowEntryExtendedStandardLibraryEditor/Private/Module",
					"LowEntryExtendedStandardLibraryEditor/Private/Classes",
				}
			);

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
				}
			);
		}
	}
}
