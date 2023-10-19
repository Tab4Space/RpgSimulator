#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterEnums.h"
#include "HandleDamageInterface.h"
#include "StatusComponent.generated.h"


class ABaseCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPGSIMULATOR_API UStatusComponent : public UActorComponent, public IHandleDamageInterface
{
	GENERATED_BODY()

public:	
	UStatusComponent();
	virtual void InitializeComponent() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	bool CanUseAbility();				// ��ų�� ����� �� �ִ� Status���� Ȯ��
	UFUNCTION(BlueprintCallable)
	void AddCrowdControl(int32 AnomalyID, float Duration);		// CC ȿ�� �߰�
	UFUNCTION(BlueprintCallable)
	void ClearCrowdControl();									// CC ȿ�� ����

	/* Interface */
	virtual void HandleTakeCrowdControl_Implementation(AActor* DamageCauser) override;

	/* Delegate */
	UFUNCTION()
	void HandleOnDead();			// �׾��� ��, Delegate
	UFUNCTION()
	void SetReadyGimmick();			// ������϶�, Status �����ϴ� Delegate Bind
	UFUNCTION()
	void SetClearGimmick();			// ����� �������� ��, Status �����ϴ� Delegate Bind
	UFUNCTION()
	void SetFailGimmick();			// ��Ϳ� �������� ��, Status �����ϴ� Delegate Bind

private:
	UPROPERTY()
	ABaseCharacter* OwnerCharacter;
	UPROPERTY(EditAnywhere, Category = "Property", meta = (AllowPrivateAccess = "true"))
	EAnimStatus CurrentAnimStatus = EAnimStatus::E_Idle;			// ���� Status(�ִϸ��̼� ���)
	UPROPERTY(EditAnywhere, Category = "Property", meta = (AllowPrivateAccess = "true"))
	ECrowdControlType CurrentCC = ECrowdControlType::E_None;		// ���� CC��
	UPROPERTY(EditAnywhere, Category = "Property", meta = (AllowPrivateAccess = "true"))
	EImmunityLevel CurrentImmunity = EImmunityLevel::E_Normal;		// ���� �鿪 ����
	UPROPERTY(VisibleAnywhere, Category = "Property", meta = (AllowPrivateAccess = "true"))
	TMap<int32, FTimerHandle> CCManager;							// CC�� Timer ����
	UPROPERTY(VisibleAnywhere, Category = "Property", meta = (AllowPrivateAccess = "true"))
	bool IsHitCounter = false;										// ī����(����) ������ �������� Ȯ��(���� ����)
	UPROPERTY()
	TMap<FString, int32> CCNameToInt;								// <CC�̸�, ��ȣ> ����

public:
	UFUNCTION(BlueprintCallable, Category = "StatusComp | Function")
	FORCEINLINE EAnimStatus GetCurrentAnimStatus() const { return CurrentAnimStatus; }
	UFUNCTION(BlueprintCallable, Category = "StatusComp | Function")
	FORCEINLINE ECrowdControlType GetCurrentCrowd() const { return CurrentCC; }
	UFUNCTION(BlueprintCallable, Category = "StatusComp | Function")
	FORCEINLINE EImmunityLevel GetCurrentImmunity() const { return CurrentImmunity; }
	UFUNCTION(BlueprintCallable, Category = "StatusComp | Function")
	FORCEINLINE void SetCurrentAnimStatus(EAnimStatus AnimStatus) { CurrentAnimStatus = AnimStatus; }
	UFUNCTION(BlueprintCallable, Category = "StatusComp | Function")
	FORCEINLINE void SetCurrentCrowd(ECrowdControlType NewCrowd) { CurrentCC = NewCrowd; }
	UFUNCTION(BlueprintCallable, Category = "StatusComp | Function")
	FORCEINLINE void SetCurrentImmunity(EImmunityLevel NewImmunity) { CurrentImmunity = NewImmunity; }

};
