// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

/** Forward declaration to improve compiling times */
class ABaseCharacter;
class UBaseGameInstance;

UCLASS()
class ABasePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ABasePlayerController();
	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	virtual void SetupInputComponent() override;
	
	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
	void OnAttackPressed();

	/* Execute Skill */
	void ExecAbilitySlotQ();
	void ExecAbilitySlotW();
	void ExecAbilitySlotE();
	void ExecAbilitySlotR();
	void ExecAbilitySlotA();
	void ExecAbilitySlotS();
	void ExecAbilitySlotD();
	void ExecAbilitySlotF();

	/* Change View Target */
	void ChangeViewTarget();

public:
	/** Time Threshold to know if it was a short press */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	float ShortPressThreshold = 0.3f;

private:
	bool bInputPressed;								// Input is bring pressed
	float FollowTime;								// For how long it has been pressed
	
	ABaseCharacter* OwnedCharacter = nullptr;		// ��Ʈ�ѷ��� �����ϴ� Character
	UBaseGameInstance* EgoGameInstance = nullptr;	// GameInstance
	FVector CursorToLocation;						// ���콺�� ����Ű�� World Location

	int32 CameraTargetIndex = 0;					// DevelopMode�� false�϶�, ī�޶� ���� Target �ε���
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FString ViewTargetName = "";					// ī�޶�� ���ߴ� Ÿ�� �̸�
public:
	FORCEINLINE FVector GetCursorToLocation() const		{ return CursorToLocation; }
};


