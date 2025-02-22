// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardEffect.h"
#include "Enchantments/Enchantment.h"
#include "CardEffectEnchantment.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UCardEffectEnchantment : public UCardEffect {
	GENERATED_BODY()

public:
	UPROPERTY(Instanced, EditDefaultsOnly, BlueprintReadOnly, meta=(AllowAbstract))
	TObjectPtr<UEnchantment> Enchantment;
};
