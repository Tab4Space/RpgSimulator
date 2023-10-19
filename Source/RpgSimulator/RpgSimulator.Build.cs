// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RpgSimulator : ModuleRules
{
	public RpgSimulator(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PrivatePCHHeaderFile = "RpgSimulator.h";

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", "CoreUObject", "Engine",
			"InputCore", "Json", "JsonUtilities",
			"NavigationSystem", "AIModule", "GameplayTasks",
			"UMG"
		});

		PrivateIncludePaths.AddRange(new[] {
			"RpgSimulator/Abilities/BaseAbility/Public",
			"RpgSimulator/Animations/Notifies/Public",
			"RpgSimulator/Animations/NotifyStates/Public",
			"RpgSimulator/BehaviorTree/Decorators/Public",
			"RpgSimulator/BehaviorTree/Task/Public",
			"RpgSimulator/Characters/Public",
			"RpgSimulator/Components/Public",
			"RpgSimulator/Core/Public",
			"RpgSimulator/Interfaces/Public",
			"RpgSimulator/Structs",
			"RpgSimulator/Utils/FileIO/Public",
		});

	}
}
