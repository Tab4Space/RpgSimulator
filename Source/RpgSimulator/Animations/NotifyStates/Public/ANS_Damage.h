// Trace와 데미지가 들어갈 타이밍(?)을 애니메이션 Frame에 삽입된 노티파이 기준으로 삼음

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
