// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityData.h"
#include "UObject/Interface.h"
#include "AbilityInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAbilityInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RPGSIMULATOR_API IAbilityInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/* 인터페이스 함수 */
	// Ability Actor 정보 얻기
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FAbilityInfoForDamage GetAbilityInfoForDamage();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FAbilityInfoForBuff GetAbilityInfoForBuff();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FAbilityInfoForCC GetAbilityInfoForCC();

};
