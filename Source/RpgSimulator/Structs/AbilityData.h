// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataTable.h"
#include "Animation/AnimMontage.h"
#include "AbilityData.generated.h"


USTRUCT(Atomic, BlueprintType)
struct FAbilityFullData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Property | Basic")
	int32 AbilityId = -1;				// Ability ID
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Property | Basic")
	FString AbilityName = "";			// Ability �̸�
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Property | Basic")
	float CoolTime = 0.f;				// Ability ��Ÿ��
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Property | Basic")
	float DamageFactor = 0.f;			// Ability ������ ���, ĳ������ AttackPower�� ��������
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Property | Basic")
	float StaggerDamage = 0.f;			// Ability Stagger Damage, ��� Ŭ���� �ϱ� ���� ���
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Property | Basic")
	FString TraceShape="";				// Ability Actor Trace�� ��, Trace ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Property | Basic")
	float StartLocBias = 0.f;			// Actor�� ���� ��ġ, ĳ���� ���� �������� �����Ѵ�. 100.f�� ĳ���� forward vector�� 100�� ���� ������ ó��
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Property | Basic")
	float RangeModifier1 = 0.f;			// Ability Actor�� Trace ���� ����(ũ�� ��)�� ���� ��
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Property | Basic")
	float RangeModifier2 = 0.f;			// Ability Actor�� Trace ���� ����(ũ�� ��)�� ���� ��
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Property | Basic")
	float RangeModifier3 = 0.f;			// Ability Actor�� Trace ���� ����(ũ�� ��)�� ���� ��
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Property | Buff")
	FString BuffType="";				// Ability Actor�� ���Ե� ���� Ÿ��
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Property | Buff")
	float BuffDeltaAmount = 0.f;		// Ability Actor�� ���Ե� ������ ��
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Property | Buff")
	float BuffDuration = 0.f;			// Ability Actor�� ���Ե� ������ ���ӽð�
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Property | Crowd")
	FString CCType="";					// Ability Actor�� ���Ե� CC Ÿ��
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Property | Crowd")
	float CCDuration = 0.f;				// Ability Actor�� ���Ե� CC�� ���ӽð�
};

// Ability Interface���� Damage ���� ��� ���� ���
USTRUCT(BlueprintType)
struct FAbilityInfoForDamage
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "Property")
	int32 MatchedAbilityId = -1;
	UPROPERTY(VisibleAnywhere, Category = "Property")
	float DamageFactor = -1.f;
};

// Ability Interface���� Buff ���� ��� ���� ���
USTRUCT(BlueprintType)
struct FAbilityInfoForBuff
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Property", meta=(AllowPrivateAccess = "true"))
	int32 MatchedAbilityId = -1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Property", meta = (AllowPrivateAccess = "true"))
	FString BuffType="";
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Property", meta = (AllowPrivateAccess = "true"))
	float BuffDeltaAmount = -1.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Property", meta = (AllowPrivateAccess = "true"))
	float BuffDuration = -1.f;
};

// Ability Interface���� CC ���� ��� ���� ���
USTRUCT(BlueprintType)
struct FAbilityInfoForCC
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "Property")
	int32 MatchedAbilityId = 0;
	UPROPERTY(VisibleAnywhere, Category = "Property")
	FString CrowdType="";
	UPROPERTY(VisibleAnywhere, Category = "Property")
	float CrowdDuration = -1.f;
};

// Ability Data Table
USTRUCT(BlueprintType)
struct FManageAbilityTable : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FString AbilityName;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABaseAbility> AbilityClass;
	UPROPERTY(EditAnywhere)
	UAnimMontage* AbilityMontage;
	UPROPERTY(EditAnywhere)
	UParticleSystem* AbilityVFX;
};