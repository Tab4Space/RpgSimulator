// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_ExecuteGimmick.generated.h"


class APawn;
class UGimmickComponent;
class UBehaviorTreeComponent;

UCLASS()
class RPGSIMULATOR_API UBTT_ExecuteGimmick : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTT_ExecuteGimmick();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	virtual void OnTaskFinished(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTNodeResult::Type TaskResult) override;

public:
	void ExecuteGimmick_1(UBehaviorTreeComponent& OwnerComp);
	void ExecuteGimmick_2(UBehaviorTreeComponent& OwnerComp);
	void ExecuteGimmick_3(UBehaviorTreeComponent& OwnerComp);

	void ApplyDamageIfFailed();
	UFUNCTION()
	void ClearInterept();

private:
	UPROPERTY()
	APawn* ControlledPawn;
	UPROPERTY()
	UGimmickComponent* GimmickComp;
	UPROPERTY()
	UBehaviorTreeComponent* BTComp;
	UPROPERTY()
	FTimerHandle LimitTimerHandler;
	UPROPERTY()
	FTimerHandle ExecAbilityTimerHandler;
	UPROPERTY()
	bool IsClear = false;
	UPROPERTY()
	float SumDeltaTime;
	UPROPERTY()
	float LimmitTime;
};
