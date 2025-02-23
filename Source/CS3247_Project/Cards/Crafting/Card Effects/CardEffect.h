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
	UCardEffect();
	
	int Multiplier;
	TMap<FGameplayTag, int> Damages;
	TMap<FGameplayTag, int> MagicEnchantments;
	int HealAmount;

	UPROPERTY(BlueprintReadOnly)
	FGameplayTagContainer SpecialEffects;

	UFUNCTION(BlueprintCallable)
	int GetDamage(const FGameplayTag DamageType) {
		if (this->Damages.Contains(DamageType)) {
			return this->Damages[DamageType] * this->GetMultiplier();
		} else {
			return 0;
		}
	}

	UFUNCTION(BlueprintCallable)
	int GetMagicEnchantment(const FGameplayTag EnchantmentType) {
		if (this->MagicEnchantments.Contains(EnchantmentType)) {
			return this->MagicEnchantments[EnchantmentType] * this->GetMultiplier();
		} else {
			return 0;
		}
	}

	UFUNCTION(BlueprintCallable)
	int GetHealAmount() const {
		return this->HealAmount * this->GetMultiplier();
	}

private:
	double GetMultiplier() const {
		return this->Multiplier / 100.0;
	}
};
