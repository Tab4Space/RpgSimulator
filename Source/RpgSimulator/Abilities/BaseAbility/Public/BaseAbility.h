// 캐릭터의 AbilityComponent에 의해 스폰된다.
// Ability Component에서 속성 값들을 초기화해준다
// 스폰 이후에 Montage의 notify 시그널이 들어오면 Trace한다
// Trace에 걸린 actor를 구한다


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilityInterface.h"
#include "AbilityData.h"
#include "BaseAbility.generated.h"


class ABaseCharacter;
class USceneComponent;
class UParticleSystem;

//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTraceDelegate, int32)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTraceFinishDelegate);

UCLASS()
class RPGSIMULATOR_API ABaseAbility : public AActor, public IAbilityInterface
{
	GENERATED_BODY()

public:
	ABaseAbility();
	virtual void PostInitializeComponents() override;
	virtual void Tick(float DeltaTime) override;

	// C++ or Blueprint 둘 다 사용 가능
	UFUNCTION(BlueprintNativeEvent, Category = "Function | Apply Damage")
	void OnBeginDamage();
	virtual void OnBeginDamage_Implementation();

	/* Interface */
	virtual FAbilityInfoForDamage GetAbilityInfoForDamage_Implementation() override;
	virtual FAbilityInfoForBuff GetAbilityInfoForBuff_Implementation() override;
	virtual FAbilityInfoForCC GetAbilityInfoForCC_Implementation() override;

protected:
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable, Category = "Function | Apply Damage")
	void ApplyDamageToTarget();						// 데미지 전달

/* Variables */
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat")
	TArray<AActor*> TraceResultActors;				// Trace 또는 overlap에 걸린 Actor 저장

protected:
	UPROPERTY(VisibleAnywhere)
	ABaseCharacter* OwnedCharacter = nullptr;
	UPROPERTY(EditAnywhere, Category = "Properties")
	FAbilityFullData AbilityFullData;				// 해당 Ability Actor의 정보
	UPROPERTY(VisibleInstanceOnly, Category = "Properties")
	UParticleSystem* AbilityVFX;					// Ability에서 필요한 VFX

private:
	/* Component */
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneComponent* DefaultSceneComp = nullptr;	// RootComponent로 사용
	
/* Get() and Set () */
public:
	FORCEINLINE FAbilityFullData GetAbilityFullData() { return AbilityFullData; }
	FORCEINLINE void SetAbilityFullData(FAbilityFullData& Data) { AbilityFullData = Data; }
	FORCEINLINE void SetAbilityVFX(UParticleSystem* Vfx) { AbilityVFX = Vfx; }
};
