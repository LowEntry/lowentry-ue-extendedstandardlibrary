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
					"LowEntryExtendedStandardLibrary/Public/ClassesLatentAction",
					"LowEntryExtendedStandardLibrary/Public/FClassesLatentAction",
					"LowEntryExtendedStandardLibrary/Public/FClassesTick",
				}
			);

			PrivateIncludePaths.AddRange(
				new string[] {
					"LowEntryExtendedStandardLibrary/Private/Module",
					"LowEntryExtendedStandardLibrary/Private/Classes",
					"LowEntryExtendedStandardLibrary/Private/ClassesLatentAction",
				}
			);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Engine",
					"Core",
					"CoreUObject",
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
