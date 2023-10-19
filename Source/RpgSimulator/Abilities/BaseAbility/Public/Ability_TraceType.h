#pragma once

#include "CoreMinimal.h"
#include "BaseAbility.h"
#include "Ability_TraceType.generated.h"


UCLASS()
class RPGSIMULATOR_API AAbility_TraceType : public ABaseAbility
{
	GENERATED_BODY()
	
public:
	AAbility_TraceType();
	virtual void PostInitializeComponents() override;
	virtual void OnBeginDamage_Implementation() override;

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Function | TraceType", meta=(ToolTip="M1: BoxLength, M2: Box Half Size, M3: Not use"))
	void TraceBox(float StartBias, float Modifier1, float Modifier2, float Modifier3);			// Box ��� Trace
	UFUNCTION(BlueprintCallable, Category = "Function | TraceType", meta = (ToolTip = "M1: Radius, M2: MinAngle, M3: MaxAngle"))
	void TraceCone(float StartBias, float Modifier1, float Modifier2, float Modifier3);			// Cone ��� Trace
	UFUNCTION(BlueprintCallable, Category = "Function | TraceType", meta = (ToolTip = "M1: Out Radius, M2: Inner Radius, M3: Not use"))
	void TraceDonut(float StartBias, float Modifier1, float Modifier2, float Modifier3);			// Donut ��� Trace
	UFUNCTION(BlueprintCallable, Category = "Function | TraceType", meta = (ToolTip = "M1: Radius, M2: Not use, M3: Not use"))
	void TraceSphere(float StartBias, float Modifier1, float Modifier2, float Modifier3);			// Sphere ��� Trace

private:
	typedef void (AAbility_TraceType::* TraceFunctionPtrType)(float StartBias, float Modifier1, float Modifier2, float Modifier3);
	TMap<FString, TraceFunctionPtrType> TraceFuncMap;
};
