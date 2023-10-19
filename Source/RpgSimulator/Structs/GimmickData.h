#pragma once


#include "GimmickData.generated.h"


USTRUCT(blueprintable)
struct FGimmickData
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	int32 Phase;
	UPROPERTY(VisibleAnywhere)
	int32 GimmickID;
	UPROPERTY(VisibleAnywhere)
	float NextPhaseHP;
	UPROPERTY(VisibleAnywhere)
	float TriggerHP;
	UPROPERTY(VisibleAnywhere)
	float LimmitTime;
	UPROPERTY(VisibleAnywhere)
	float IncreaseStat;
	UPROPERTY(VisibleAnywhere)
	TArray<int32> SelectAbility = { 0, 0, 0, 0 };
	UPROPERTY(VisibleAnywhere)
	int32 ClearStunCount;
	UPROPERTY(VisibleAnywhere)
	float ClearStaggerAmount;
};

