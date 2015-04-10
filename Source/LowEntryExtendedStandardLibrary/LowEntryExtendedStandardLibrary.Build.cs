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
				}
            );

            PrivateIncludePaths.AddRange(
                new string[] {
					"LowEntryExtendedStandardLibrary/Private/Module",
					"LowEntryExtendedStandardLibrary/Private/Classes",
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
