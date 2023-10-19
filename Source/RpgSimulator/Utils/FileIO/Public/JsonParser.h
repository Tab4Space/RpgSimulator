// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectConverter.h"
#include "JsonParser.generated.h"

/**
 * 
 */
UCLASS()
class RPGSIMULATOR_API UJsonParser : public UObject
{
	GENERATED_BODY()

public:
	static bool LoadJsonFromFile(const FString& FilePath, FString& Result);

	// Convert json to struct
	template<typename T>
	static bool ConvertJsonToStruct(T* OutStruct, const FString& JsonString)
	{
		if (!FJsonObjectConverter::JsonObjectStringToUStruct<T>(JsonString, OutStruct, 0, 0))
			return false;
		
		return true;
	}
};

