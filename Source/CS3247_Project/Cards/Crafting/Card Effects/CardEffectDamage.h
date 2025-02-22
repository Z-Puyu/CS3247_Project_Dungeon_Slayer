// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardEffect.h"
#include "GameplayTagContainer.h"
#include "CardEffectDamage.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UCardEffectDamage : public UCardEffect {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(Categories="Damage"))
	FGameplayTag DamageType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 Value;
};
