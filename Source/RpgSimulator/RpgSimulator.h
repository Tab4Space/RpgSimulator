// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(SIMLOG, Log, All);

#define SIMLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define SIMLOG_S(Verbosity) UE_LOG(SIMLOG, Verbosity, TEXT("%s"), *SIMLOG_CALLINFO)
#define SIMLOG(Verbosity, Format, ...) UE_LOG(SIMLOG, Verbosity, TEXT("%s %s"), *SIMLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))
#define SIMCHECK(Expr, ...) { if(!Expr)) {SIMLOG(Error, TEXT("ASSERTION : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__;} }