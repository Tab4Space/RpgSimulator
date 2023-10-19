// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "StatData.generated.h"


USTRUCT()
struct FStatData
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category="AI Agent")
	int32 ClassType;
	UPROPERTY(VisibleAnywhere, Category = "AI Agent")
	float MaxHP;
	UPROPERTY(VisibleAnywhere, Category = "AI Agent")
	float AttackPower;
	UPROPERTY(VisibleAnywhere, Category = "AI Agent")
	float MoveSpeed;
	UPROPERTY(VisibleAnywhere, Category = "AI Agent")
	float CriticalProb;
};
