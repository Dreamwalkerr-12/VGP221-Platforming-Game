// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EE : ModuleRules
{
	public EE(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"EE",
			"EE/Variant_Platforming",
			"EE/Variant_Platforming/Animation",
			"EE/Variant_Combat",
			"EE/Variant_Combat/AI",
			"EE/Variant_Combat/Animation",
			"EE/Variant_Combat/Gameplay",
			"EE/Variant_Combat/Interfaces",
			"EE/Variant_Combat/UI",
			"EE/Variant_SideScrolling",
			"EE/Variant_SideScrolling/AI",
			"EE/Variant_SideScrolling/Gameplay",
			"EE/Variant_SideScrolling/Interfaces",
			"EE/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
