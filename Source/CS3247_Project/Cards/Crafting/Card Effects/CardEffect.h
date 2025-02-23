// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "CardEffect.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UCardEffect : public UObject {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	TMap<FGameplayTag, int> Damages = {};

	UPROPERTY(BlueprintReadOnly)
	int HealAmount = 0;

	UPROPERTY(BlueprintReadOnly)
	FGameplayTagContainer SpecialEffects;
};
