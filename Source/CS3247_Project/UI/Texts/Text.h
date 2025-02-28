// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Text.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UText : public UObject {
	GENERATED_BODY()

public:
	static FString Bf(FString Str);

	static FString It(FString Str);

	static FString BfIt(FString Str);

	static FString Rm(FString Str);

	static FString Red(FString Str);

	static FString Green(FString Str);
};
