namespace UnrealBuildTool.Rules
{
	public class LowEntryExtendedStandardLibrary : ModuleRules
	{
		public LowEntryExtendedStandardLibrary(TargetInfo Target)
		{
			PublicIncludePaths.AddRange(
				new string[] {
					"LowEntryExtendedStandardLibrary/Public/Module",
					"LowEntryExtendedStandardLibrary/Public/Classes",
					"LowEntryExtendedStandardLibrary/Public/ClassesTypes",
					"LowEntryExtendedStandardLibrary/Public/ClassesLatentAction",
					"LowEntryExtendedStandardLibrary/Public/FClassesLatentAction",
					"LowEntryExtendedStandardLibrary/Public/FClassesTick",
                    "LowEntryExtendedStandardLibrary/Public/FClassesDelay",
                    "LowEntryExtendedStandardLibrary/Public/FClassesExecutionQueue",
                }
			);

			PrivateIncludePaths.AddRange(
				new string[] {
					"LowEntryExtendedStandardLibrary/Private/Module",
					"LowEntryExtendedStandardLibrary/Private/Classes",
					"LowEntryExtendedStandardLibrary/Private/ClassesTypes",
					"LowEntryExtendedStandardLibrary/Private/ClassesLatentAction",
                }
			);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Engine",
					"Core",
					"CoreUObject",
                    "Slate",
                    "SlateCore",
                    "ImageWrapper",
                    "Media",
                    "MediaAssets",
                    "AIModule",
                }
			);

			PrivateDependencyModuleNames.AddRange(
				new string[]
                {
                }
			);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
                {
                }
			);
		}
	}
}
