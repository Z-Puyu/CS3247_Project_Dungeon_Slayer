// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageData.h"
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
	UCardEffect();

	UPROPERTY(BlueprintReadOnly)
	FDamageData BaseDamage;
	
	UPROPERTY(BlueprintReadOnly)
	TMap<FGameplayTag, FDamageData> ExtraDamageEffects;

	UPROPERTY(BlueprintReadOnly)
	double HealAmount;

	UPROPERTY(BlueprintReadOnly)
	FGameplayTagContainer SpecialEffects;
};
