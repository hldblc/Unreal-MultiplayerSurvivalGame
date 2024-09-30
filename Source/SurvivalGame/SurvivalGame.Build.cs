// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SurvivalGame : ModuleRules
{
    public SurvivalGame(ReadOnlyTargetRules Target) : base(Target)
    {
        // Use explicit or shared PCHs to speed up compilation
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // Public dependency modules are required by both this module and any module that depends on it
        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",      // For enhanced input handling
            "CommonUI",           // For CommonUI widgets
            "UMG",                // For UI functionalities
            "Slate",              // If you plan to use Slate directly
            "SlateCore"
        });

        // Private dependency modules are only required by this module
        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "GameplayAbilities",  // Only if you use Gameplay Abilities system
            "GameplayTags",       // Essential for using Gameplay Tags
            "GameplayTasks",      // If you use tasks within Gameplay Abilities
            "AIModule",           // For AI-related functionalities
            "NavigationSystem"    // If your game utilizes navigation features
        });

        // Dynamically loaded modules (if any)
        DynamicallyLoadedModuleNames.AddRange(new string[]
        {
            // Example: "OnlineSubsystemSteam"
        });

        // Enable support for Slate Editor if needed
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Additional settings for optimization

        // Optimize for shipping builds by disabling editor-only data
        if (Target.Configuration == UnrealTargetConfiguration.Shipping)
        {
            bEnableExceptions = false;
            OptimizeCode = CodeOptimization.Always;
        }

        // Enable RTTI if required (default is disabled in Unreal)
        // bEnableRTTI = true;

        // Enable or disable specific warnings
        // bEnableUndefinedIdentifierWarnings = false;
    }
}
