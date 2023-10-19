#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GimmickData.h"
#include "HandleDamageInterface.h"
#include "GimmickComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTriggerGimmickSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClearGimmickSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFailGimmickSignature);

class ABaseCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPGSIMULATOR_API UGimmickComponent : public UActorComponent, public IHandleDamageInterface
{
	GENERATED_BODY()

public:	
	UGimmickComponent();
	virtual void InitializeComponent() override;
	bool InitializeFromFile();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "Gimmick | Function")
	void ChangeHP(float CurrentHP, float MaxHP);		// Next Phase �Ǵ� ��� ������ ���� HP ��ȭ üũ
	UFUNCTION(BlueprintCallable, Category = "Gimmick | Function")
	void CheckGimmick();								// ��� Ŭ���� ���� üũ
	UFUNCTION(BlueprintCallable, Category = "Gimmick | Function")
	void ExecGimmickAbility();							// ��� �߿� ���Ǵ� Ư�� ��ų
	UFUNCTION(BlueprintCallable, Category = "Gimmick | Function")
	void ClearGimmick();								// ��� ������ ��, Delegate broadcast
	UFUNCTION(BlueprintCallable, Category = "Gimmick | Function")
	void FailGimmick();									// ��� ������ ��, Delegate broadcast
	UFUNCTION(BlueprintCallable, Category = "Gimmick | Function")
	virtual void ChangeStat();							// Phase�� �Ѿ�� ĳ���� ���� ����

	/* Interface */
	virtual void HandleGimmick_Implementation(AActor* DamageCauser) override;

private:
	UFUNCTION()
	void SetNextPhase();		// ���� ������� �Ѿ ��, ���� ó��

public:
	/* Delegate */
	UPROPERTY()
	FOnTriggerGimmickSignature OnTriggerGimmick;
	UPROPERTY()
	FOnClearGimmickSignature OnClearGimmick;
	UPROPERTY()
	FOnFailGimmickSignature OnFailGimmick;

private:
	UPROPERTY(VisibleAnywhere, Category="Properties")
	ABaseCharacter* OwnerCharacter = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Properties", meta = (AllowPrivateAccess = "true"))
	TMap<int32, FGimmickData> OwnedGimmickData;				// csv�� Gimmick Data ����	
	UPROPERTY(VisibleAnywhere, Category = "Properties")
	int32 CurrentPhase = 1;									// ���� ������
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Properties", meta = (AllowPrivateAccess = "true"))
	bool bIsRunGimmick = false;								// ���� ���������
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Properties", meta = (AllowPrivateAccess = "true"))
	int32 CountOfHitStun = 0;								// ���ߵ� Stun ��ų Ƚ��
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Properties", meta = (AllowPrivateAccess = "true"))
	float StaggerAmount = 0.f;								// ���ߵ� Stagger Damage ��
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Properties", meta = (AllowPrivateAccess = "true"))
	TArray<bool> IsOnPhasePerGimmick;						// �� �������� ����� ����Ǿ�����
	UPROPERTY()
	TMap<FString, int32> CCNameToInt;						// <CC�̸�, ��ȣ> ����
	
public:
	UFUNCTION(BlueprintCallable, Category = "Gimmick | Function")
	FORCEINLINE int32 GetCurrentPhase() const { return CurrentPhase; }
	UFUNCTION(BlueprintCallable, Category = "Gimmick | Function")
	FORCEINLINE bool GetbIsRunGimmick() const { return bIsRunGimmick; }
	UFUNCTION(BlueprintCallable, Category = "Gimmick | Function")
	FORCEINLINE void SetIsRunGimmick(bool IsRun) { bIsRunGimmick = IsRun; }
	UFUNCTION(BlueprintCallable, Category = "Gimmick | Function")
	FORCEINLINE FGimmickData GetGimmickInfo(int32 Phase) { return OwnedGimmickData[Phase]; }
	UFUNCTION(BlueprintCallable, Category = "Gimmick | Function")
	FORCEINLINE TArray<int32> GetPhaseAbility(int32 Phase) { return OwnedGimmickData[Phase].SelectAbility; }

};
