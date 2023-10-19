// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterData.h"
#include "GameData.generated.h"


USTRUCT(BlueprintType)
struct FGameData
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float EpisodeTime;		// Episode ���� �ð�
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float SimulatorSpeed;	// ����ȭ ���ǵ�(Global Time Dialation ������ �����ȴ�)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 AliveCount;		// ����ִ� Player �� (���� ���ϸ� ���� ����)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool DrawDebugTrace;	// Trace �Լ����� debug ����
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool DevelopMode;		// ���߸��
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool DrawUI;			// UI ������ ����
	UPROPERTY()
	TArray<FCharacterData> CharacterData;		// ĳ����(�÷��̾�+����) ������
};
