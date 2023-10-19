#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameData.h"
#include "BaseGameInstance.generated.h"


DECLARE_MULTICAST_DELEGATE(FOnLevelChangeSinature)

UCLASS()
class RPGSIMULATOR_API UBaseGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UBaseGameInstance();
	void ResetTimerOnLevelChange();

protected:
	virtual void Init() override;

public:
	/* Delegate */
	FOnLevelChangeSinature OnLevelChange;

private:
	// Json 파일 읽기 함수
	bool InitSettingFromJson(const FString& FilePath, const FString& FileName);
	
	FGameData GameData;				// Json 파일의 값을 저장하는 구조체
	FString SettingFileName = "";	// 파일 이름
	FString SettingRootPath = "";	// 파일 경로
	
public:
	UFUNCTION(BlueprintCallable)
	FORCEINLINE FGameData GetGameData() const { return GameData; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool GetDevelopMode() const { return GameData.DevelopMode; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool GetDrawUI() const { return GameData.DrawUI; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE FString GetSettingRootPath() const { return SettingRootPath; }
};
