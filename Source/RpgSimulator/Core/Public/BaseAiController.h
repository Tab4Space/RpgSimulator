// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseAiController.generated.h"


class UBehaviorTree;
class UBlackboardData;
class UBlackboardComponent;
class UGimmickComponent;

UCLASS()
class RPGSIMULATOR_API ABaseAiController : public AAIController
{
	GENERATED_BODY()
	
public:
	ABaseAiController();
	virtual void Tick(float DeltaSeconds) override;
	
	/* Delegate ���ε��� ���� �Լ� */
	UFUNCTION()
	void OnTriggerGimmick();
	UFUNCTION()
	void OnClearGimmick();
	UFUNCTION()
	void OnFailGimmick();

	/* Behavior Tree ���� �� ���� �Լ� */
	UFUNCTION(BlueprintCallable, Category = "Boss AI | Function")
	void RunBehaviorAI();

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Boss AI", meta = (AllowPrivateAccess = "true"))
	UBlackboardData* BBAsset;		// Blackboard �ּ� ����, Blueprint���� �����Ѵ�
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Boss AI", meta = (AllowPrivateAccess = "true"))
	UBehaviorTree* BTAsset;			// Behavior tree �ּ� ����, Blueprint���� �����Ѵ�
	
	UPROPERTY()
	UBlackboardComponent* BlackboardComp;
	UPROPERTY()
	UGimmickComponent* GimmickComp;
};
