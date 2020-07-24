using UnrealBuildTool;
using System.IO;

public class LowEntryExtendedStandardLibrary : ModuleRules
{
	public LowEntryExtendedStandardLibrary(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
			new string[] {
                Path.Combine(ModuleDirectory, "Public/Module"),
                Path.Combine(ModuleDirectory, "Public/Classes"),
                Path.Combine(ModuleDirectory, "Public/ClassesTypes"),
                Path.Combine(ModuleDirectory, "Public/ClassesLatentAction"),
                Path.Combine(ModuleDirectory, "Public/FClassesLatentAction"),
                Path.Combine(ModuleDirectory, "Public/FClassesTick"),
                Path.Combine(ModuleDirectory, "Public/FClassesDelay"),
                Path.Combine(ModuleDirectory, "Public/FClassesExecutionQueue"),
            }
		);

		PrivateIncludePaths.AddRange(
			new string[] {
                Path.Combine(ModuleDirectory, "Private/Module"),
                Path.Combine(ModuleDirectory, "Private/Classes"),
                Path.Combine(ModuleDirectory, "Private/ClassesTypes"),
                Path.Combine(ModuleDirectory, "Private/ClassesLatentAction"),
            }
		);

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
