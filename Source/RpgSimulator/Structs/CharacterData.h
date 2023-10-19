#pragma once


#include "CharacterData.generated.h"


USTRUCT()
struct FCharacterData
{
	GENERATED_BODY()

	UPROPERTY()
	FString Type;					// Player / Monster
	UPROPERTY()
	FString CharacterClass;			// 캐릭터의 종류 개념
	UPROPERTY()
	TArray<int32> UsableAbilities;	// 사용할수있는 스킬
	UPROPERTY()
	FString StatConfigPath;			// 스탯이 정의된 파일 Path
	UPROPERTY()
	FString AbilityConfigPath;		// Ability Property가 정의된 파일 Path
	UPROPERTY()
	FString PatternConfigPath;		// 기믹 Property가 정의된 파일 Path

};
