// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardEnchantment.h"
#include "CardEnchantmentMagic.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UCardEnchantmentMagic : public UCardEnchantment {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(Categories="Damage.Magic"))
	FGameplayTag EnchantmentType;

	// The strength of the enchantment is in terms of percentage of impact amount.
	// On a hostile target, this translates to an additional damage;
	// On a friendly target, this translates to an additional magical aversion.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int Strength;
	
	virtual UCardEffect* Enchant(UCardEffect* Effect) override;
};
