#pragma once

#include "CoreMinimal.h"
#include "BaseAbility.h"
#include "Ability_ProjectileType.generated.h"


class UStaticMeshComponent;
class USphereComponent;
class UArrowComponent;
class UProjectileMovementComponent;

UCLASS()
class RPGSIMULATOR_API AAbility_ProjectileType : public ABaseAbility
{
	GENERATED_BODY()

public:
	AAbility_ProjectileType();
	virtual void PostInitializeComponents() override;
	virtual void OnBeginDamage_Implementation() override;

protected:
	virtual void BeginPlay() override;

	/* OnComponentBeginOverlap Delegate ���ε�*/
	// C++ or Blueprint �� �� ��밡��
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Ability")
	void OnOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void OnOverlap_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void LaunchProjectile(float StartBias, float Radius, float Speed);

public:

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MeshComp = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USphereComponent* SphereCollisionComp = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UArrowComponent* ArrowComp = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovementComp = nullptr;
};
