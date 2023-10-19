// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HandleDamageInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UHandleDamageInterface : public UInterface
{
	GENERATED_BODY()
};

class RPGSIMULATOR_API IHandleDamageInterface
{
	GENERATED_BODY()

public:
	/* 인터페이스 함수 */
	// 데미지 판정이 되었을 때, 각 컴포넌트 별로 다르게 처리하기 위해서 Interface 구성
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void HandleTakeDamage(AActor* DamageCauser, float Damage);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void HandleTakeBuff(AActor* DamageCauser);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void HandleTakeCrowdControl(AActor* DamageCauser);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void HandleGimmick(AActor* DamageCauser);
};
