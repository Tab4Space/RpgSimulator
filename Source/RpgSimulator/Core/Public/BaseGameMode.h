// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CharacterData.h"
#include "BaseGameMode.generated.h"

class UBaseGameInstance;
class ABaseCharacter;
class APlayerStart;
class ACharacter;

UCLASS(minimalapi)
class ABaseGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABaseGameMode();
	virtual void StartPlay() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION(BlueprintCallable)
	void RestartEpisode(FString& Reason);

private:
	void SpawnCharacters();			// ĳ���� ����, Type�� ���� Player, Boss �������� �б�
	void SpawnPlayer(int32 Uuid, FCharacterData Data);		// �÷��̾� ����
	void SpawnBoss(int32 Uuid, FCharacterData Data);		// ���� ����

	/* Delegate */
	UFUNCTION()
	void HandleOnDead();			// �÷��̾ �׾��� ��, Delegate ���ε� �Լ�
	
public:
	UPROPERTY()
	UBaseGameInstance* EgoGameInstance = nullptr;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setting | Agents", meta = (AllowPrivateAccess = "true"))
	TArray<ABaseCharacter*> AllAgents;		// Player + Boss ��� �����ϴ� �迭
	UPROPERTY(VisibleAnywhere, Category = "Setting | StartLocation")
	TArray<APlayerStart*> PlayerStarts;		// Player ���� ��ġ
	UPROPERTY(VisibleAnywhere, Category = "Setting | StartLocation")
	TArray<APlayerStart*> BossStarts;		// ���� ���� ��ġ
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Setting | Characters", meta = (AllowPrivateAccess="true"))
	TMap<FString, TSubclassOf<ACharacter>> PlayerTypeMap;		// �÷��̾� Type Map <����, Class>
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Setting | Characters", meta = (AllowPrivateAccess="true"))
	TMap<FString, TSubclassOf<ACharacter>> MonsterTypeMap;		// ���� Type Map <��������, Class>
	UPROPERTY(VisibleAnywhere, Category = "Setting")
	int32 AliveCount = 0;
	UPROPERTY()
	FTimerHandle EpisodeTimer;		// Episode ���� �ð� Ÿ�̸�

public:
	FORCEINLINE TArray<ABaseCharacter*> GetAllAgents() { return AllAgents; }

};



