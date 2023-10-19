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
	/* �������̽� �Լ� */
	// ������ ������ �Ǿ��� ��, �� ������Ʈ ���� �ٸ��� ó���ϱ� ���ؼ� Interface ����
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void HandleTakeDamage(AActor* DamageCauser, float Damage);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void HandleTakeBuff(AActor* DamageCauser);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void HandleTakeCrowdControl(AActor* DamageCauser);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void HandleGimmick(AActor* DamageCauser);
};
