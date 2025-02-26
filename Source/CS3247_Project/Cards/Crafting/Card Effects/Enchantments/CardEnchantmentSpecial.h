// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardEnchantment.h"
#include "CardEnchantmentSpecial.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UCardEnchantmentSpecial : public UCardEnchantment {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(Categories = "SpecialCardEffect"))
	FGameplayTag SpecialEffect;

	virtual UCardEffect* Enchant(UCardEffect* Effect) override;
};
