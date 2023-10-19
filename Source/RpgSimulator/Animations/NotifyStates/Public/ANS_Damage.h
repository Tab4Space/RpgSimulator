// Trace�� �������� �� Ÿ�̹�(?)�� �ִϸ��̼� Frame�� ���Ե� ��Ƽ���� �������� ����

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "ANS_Damage.generated.h"

/**
 * 
 */
UCLASS()
class RPGSIMULATOR_API UANS_Damage : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
};
