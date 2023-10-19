#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UAbilityComponent;
class UStatComponent;
class UCombatComponent;
class UStatusComponent;
class APlayerController;

UCLASS(Blueprintable)
class ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseCharacter();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void PostInitializeComponents() override;

private:
	UFUNCTION()
	void HandleOnDead();

private:
	/* Components */
	// Ŀ���� Actor Component ���� Blueprint���� �޾��ش�.
	UPROPERTY(VisibleAnywhere, Category="Component", meta=(AllowPrivateAccess="true"))
	UCameraComponent* TopDownCameraComponent;
	UPROPERTY(VisibleAnywhere, Category = "Component", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
	UAbilityComponent* AbilityComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
	UCombatComponent* CombatComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
	UStatComponent* StatComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component", meta = (AllowPrivateAccess = "true"))
	UStatusComponent* StatusComp;

	/* Properties */
	UPROPERTY(VisibleAnywhere, Category = "Combat")
	int32 CharacterUUID;


public:
	FORCEINLINE UAbilityComponent* GetAbilityComponent() const		{ return AbilityComp; }
	FORCEINLINE UCombatComponent* GetCombatComponent() const		{ return CombatComp; }
	FORCEINLINE UStatComponent* GetStatComponent() const			{ return StatComp; }
	FORCEINLINE UStatusComponent* GetStatusComponent() const		{ return StatusComp; }
	FORCEINLINE int32 GetCharacterUUID() const						{ return CharacterUUID; }

	FORCEINLINE void SetAbilityComponent(UAbilityComponent* Comp)	{ AbilityComp = Comp;}
	FORCEINLINE void SetCombatCompnent(UCombatComponent* Comp)		{ CombatComp = Comp;}
	FORCEINLINE void SetStatComponent(UStatComponent* Comp)			{ StatComp = Comp;}
	FORCEINLINE void SetStatusComponent(UStatusComponent* Comp)		{ StatusComp = Comp;}
	FORCEINLINE void SetCharacterUUID(int32 Uuid)					{ CharacterUUID = Uuid; }

};

