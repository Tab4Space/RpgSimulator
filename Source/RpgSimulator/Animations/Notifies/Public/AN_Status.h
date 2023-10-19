// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "CharacterEnums.h"
#include "AN_Status.generated.h"


UCLASS()
class RPGSIMULATOR_API UAN_Status : public UAnimNotify
{
	GENERATED_BODY()
	
public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

public:
	UPROPERTY(EditAnywhere, meta = (InlineEditConditionToggle))
	bool bIsChangeStatus;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bIsChangeStatus"))
	EAnimStatus CharacterAnimStatus;

	UPROPERTY(EditAnywhere, meta = (InlineEditConditionToggle))
	bool bIsChangeMovementMode;
};
