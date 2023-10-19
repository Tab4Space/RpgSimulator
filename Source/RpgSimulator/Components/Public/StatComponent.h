#pragma once

#include "CoreMinimal.h"
#include "StatData.h"
#include "Components/ActorComponent.h"
#include "HandleDamageInterface.h"
#include "StatComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeadSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUpdateHpSignature, float, CurrentHP, float, MaxHp);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHandleBuffSignature, int32, BuffID, float, Duration);

class ABaseCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPGSIMULATOR_API UStatComponent : public UActorComponent, public IHandleDamageInterface
{
	GENERATED_BODY()

public:	
	UStatComponent();
	virtual void InitializeComponent() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);

	UFUNCTION(BlueprintCallable, Category = "StatComp | Function")		
	bool InitializeFromFile(int32 CharacterUuid, const FString& FileName);	// Component �ʱ�ȭ
	UFUNCTION(BlueprintCallable, Category = "StatComp | Function")		
	void UpdateCurrentHP(float NewHP);										// ���� HP Update
	UFUNCTION(BlueprintCallable, Category = "StatComp | Function")
	void AddBuff(int32 BuffID, float Duration);								// Buff ���� TMap�� Add
	UFUNCTION(BlueprintCallable, Category = "StatComp | Function")
	void ClearBuff(int32 BuffID);											// ���� ���ӽð� ���� ���� �ʱ�ȭ

	/* Interface */
	virtual void HandleTakeDamage_Implementation(AActor* DamageCauser, float Damage) override;		// Damage ó��
	virtual void HandleTakeBuff_Implementation(AActor* DamageCauser) override;						// Buff ó��

protected:
	virtual void BeginPlay() override;

public:
	/* Delegate (Widget ������Ʈ�� ���ȴ�) */
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FHandleBuffSignature HandleBuffDelegate;
	UPROPERTY()
	FUpdateHpSignature UpdateHpDelegate;
	UPROPERTY()
	FOnDeadSignature OnDead;

private:
	UFUNCTION()
	virtual void Dead();		// ĳ���� Death ó��

	/* ���� ȿ�� ó�� */
	UFUNCTION()
	virtual void ApplyHPRecovery(int32 Id, float DeltaAmount, float Duration);			// ü�� ȸ�� ���� ó��
	UFUNCTION()
	virtual void ApplyAttackPower(int32 Id, float DeltaAmount, float Duration);			// ���ݷ� ���� ���� ó��
	UFUNCTION()
	virtual void ApplyCriticalProbUp(int32 Id, float DeltaAmount, float Duration);		// ũ��Ƽ�� Ȯ�� ���� ó��

private:
	UPROPERTY(VisibleAnywhere)
	ABaseCharacter* OwnerCharacter = nullptr;
	UPROPERTY(VisibleAnywhere, Category="Init values")
	FStatData StatData;						// CSV�� �����ϴ� Stat ������
	UPROPERTY(VisibleAnywhere, Category="Stats")
	float CurrentHP;						// ���� HP
	UPROPERTY(VisibleAnywhere, Category = "Stats")
	float CurrentAttackPower;				// ���� ���ݷ�
	UPROPERTY(VisibleAnywhere, Category = "Stats")
	float CurrentMoveSpeed;					// ���� �̵��ӵ�
	UPROPERTY(VisibleAnywhere, Category = "Stats")
	float CurrentCriticalProb;				// ���� ũ��Ƽ�� Ȯ��
	UPROPERTY(VisibleAnywhere, Category = "Property", meta = (AllowPrivateAccess = "true"))
	TMap<FString, int32> BuffNameToInt;		// <�����̸�, ID> ����
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Property", meta = (AllowPrivateAccess = "true"))
	TMap<int32, FTimerHandle> BuffManager;	// ���� ���ӽð� ����

	typedef void (UStatComponent::* FunctionPtrType)(int32, float, float);
	TMap<int32, FunctionPtrType> BuffMap;	// <����, ȿ�� ó�� �Լ�> ����

public:
	FORCEINLINE FStatData& GetStatData() { return StatData; }

	UFUNCTION(BlueprintCallable, Category = "StatComp | Function")
	FORCEINLINE float GetCurrentHP() const { return CurrentHP; }
	UFUNCTION(BlueprintCallable, Category = "StatComp | Function")
	FORCEINLINE float GetCurrentAttackPower() const { return CurrentAttackPower; }
	UFUNCTION(BlueprintCallable, Category = "StatComp | Function")
	FORCEINLINE float GetCurrentCriticalProb() const { return CurrentCriticalProb; }
	UFUNCTION(BlueprintCallable, Category = "StatComp | Function")
	FORCEINLINE float GetMaxHP() const { return StatData.MaxHP; }
	UFUNCTION(BlueprintCallable, Category = "StatComp | Function")
	FORCEINLINE void SetCurrentHP(float NewHP) { CurrentHP = NewHP; }
	UFUNCTION(BlueprintCallable, Category = "StatComp | Function")
	FORCEINLINE void SetCurrentAttackPower(float NewAttackPower) { CurrentAttackPower = NewAttackPower; }
	UFUNCTION(BlueprintCallable, Category = "StatComp | Function")
	FORCEINLINE void SetCurrentCriticalProb(float NewProb) { CurrentCriticalProb = NewProb; }

};
