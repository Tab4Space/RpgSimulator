// Parse csv file

#pragma once

#include "CoreMinimal.h"
#include "CsvParser.generated.h"

UCLASS()
class RPGSIMULATOR_API UCsvParser : public UObject
{
	GENERATED_BODY()

public:
	static bool GetFromCsvFile(const FString& FilePath, int32 Index, FString& OutString);
	static bool GetFromCsvFile(const FString& FilePath, TArray<FString>& OutArray);
};

