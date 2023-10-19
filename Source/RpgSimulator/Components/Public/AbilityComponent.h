#pragma once

#include "CoreMinimal.h"
#include "AbilityData.h"
#include "Components/ActorComponent.h"
#include "AbilityComponent.generated.h"


class ABaseCharacter;
class ABaseAbility;
class UParticleSystem;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPGSIMULATOR_API UAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAbilityComponent();
	virtual void InitializeComponent() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);
	bool InitializeFromFile(const FString& FileName);

	UFUNCTION(BlueprintCallable)
	void ExecBasicAttack();
	UFUNCTION(BlueprintCallable)
	void ExecAbility(int32 AbilityID);

protected:
	virtual void BeginPlay() override;
	
private:
	UFUNCTION(BlueprintCallable)
	void SpawnAbilityActor(TSubclassOf<class ABaseAbility> ActorClass, int32 AbilityID, UParticleSystem* Vfx);
	UFUNCTION(BlueprintCallable)
	void PlayAbilityMontage(UAnimMontage* Montage);

private:
	UPROPERTY(VisibleAnywhere, Category = "Ability Properies")
	ABaseCharacter* OwnerCharacter = nullptr;
	
	UPROPERTY(EditAnywhere, Category = "Ability Properies")
	TMap<int32, FAbilityFullData> OwnedAbilities;	// 소유한 스킬들
	UPROPERTY(EditAnywhere, Category = "Ability Properies | Combat")
	TArray<int32> UsableAbilities;					// 사용 가능한 스킬들
	UPROPERTY(EditAnywhere, Category = "Ability Properies | Combat")
	UDataTable* AbilityTable;						// 스킬 테이블
	UPROPERTY(VisibleAnywhere, Category = " Ability Properies | Combat")
	ABaseAbility* CurrentAbility;					// 현재 스킬
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ability Properies | Combat", meta = (AllowPrivateAccess = "true"))
	TMap<int32, FTimerHandle> CoolTimeManager;		// TMap<스킬ID/쿨타임타이머>


public:
	UFUNCTION(BlueprintCallable)
	FORCEINLINE FAbilityFullData GetAbilityData(int AbilityID) { return OwnedAbilities[AbilityID]; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE TArray<int32> GetUsableAbilities() { return UsableAbilities; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetUsableAbilities(TArray<int32> UsableAbilityLists) { UsableAbilities = UsableAbilityLists; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE ABaseAbility* GetCurrentAbility() { return CurrentAbility; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetCurrentAbilityNull() { CurrentAbility = nullptr; }
};
