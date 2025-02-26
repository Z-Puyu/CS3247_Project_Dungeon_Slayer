// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../CardEffect.h"
#include "../CardIngredient.h"
#include "CardEnchantment.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class CS3247_PROJECT_API UCardEnchantment : public UCardIngredient {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual UCardEffect* Enchant(UCardEffect* Effect);
};
