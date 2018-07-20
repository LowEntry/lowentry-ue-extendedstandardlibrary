namespace UnrealBuildTool.Rules
{
	public class LowEntryExtendedStandardLibrary : ModuleRules
	{
		public LowEntryExtendedStandardLibrary(ReadOnlyTargetRules Target) : base(Target)
        {
            PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Engine",
                    "Core",
                    "ApplicationCore",
                    "CoreUObject",
                    "Slate",
                    "SlateCore",
                    "ImageWrapper",
                    "Media",
                    "MediaAssets",
                    "AIModule",
                    "EngineSettings"
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
