#pragma once

#include "CharacterEnums.generated.h"

// 애니메이션에 따른 상태
UENUM(BlueprintType)
enum class EAnimStatus : uint8
{
	E_Idle			UMETA(DisplayName = "Idle"),
	E_Moving		UMETA(DisplayName = "Moving"),
	E_Attacking		UMETA(DisplayName = "Attacking"),
	E_CastingSkill	UMETA(DisplayName = "Casting skill"),
	E_Death			UMETA(DisplayName = "Death")
};

// 스킬의 부가 효과로 추가할수 있고, 캐릭터의 상태에도 영향을 준다
// 움직이거나 스킬을 사용하는데 제한을 두는 상태들
UENUM(BlueprintType)
enum class ECrowdControlType : uint8
{
	E_None			UMETA(DisplayName = "None"),				// 일반
	E_Frozen		UMETA(DisplayName = "Frozen"),				// 빙결(이동 불가, 스킬은 사용가능)
	E_Stun			UMETA(DisplayName = "Stun"),				// 스턴(이동 불가, 스킬 불가능 => 보스는 무력화 성공될시)
	E_Fear			UMETA(DisplayName = "Fear"),				// 공포(이동 불가, 스킬 불가능, 받는 데미지 증가)
};

// 상태 이상 면역 단계
UENUM(BlueprintType)
enum class EImmunityLevel : uint8
{
	E_Normal			UMETA(DisplayName = "Normal"),
	E_CCImmunity		UMETA(DisplayName = "CC Immunity"),			// 상태 이상 면역(일반 데미지는 들어가되, 상태이상 면역)
	E_DamageImmunity	UMETA(DisplayName = "Damage Immunity"),		// 데미지 면역(일반 데미지에는 무적이되, 상태이상은 걸림)
	E_Invincibility		UMETA(DisplayName = "Invincibility"),		// 모든 데미지, 상태 이상에 무적
};

// 버프 효과
// 캐릭터에 포함된 스탯에 영향을 준다 or 상태 이상(frozen, stun, fear) 해제
UENUM(BlueprintType)
enum class EBuffType : uint8
{
	E_NoneBuff			UMETA(DisplayName = "None Buff"),
	E_HPRecorvery		UMETA(DisplayName = "HP Recovery"),
	E_AttackUp			UMETA(DisplayName = "AttackPower Up"),
	E_CriticalProbUp	UMETA(DisplayName = "CriticalProb Up"),
	E_ClearCrowd		UMETA(DisplayName = "Clear Crowd contrl"),
};

// Hit 리액션
UENUM(BlueprintType)
enum class EHitReaction : uint8
{
	E_None			UMETA(DisplayName = "None Reaction"),
	E_KnockDown		UMETA(DisplayName = "Flying Knock Down"),
};

// 보스 페이즈
UENUM(BlueprintType)
enum class EGimmickPhase : uint8
{
	E_Phase1		UMETA(DisplayName = "Phase 1"),
	E_Phase2		UMETA(DisplayName = "Phase 2"),
	E_Phase3		UMETA(DisplayName = "Phase 3"),
};

