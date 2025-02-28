// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Crafting/Card Effects/EffectBlock.h"
#include "UObject/NoExportTypes.h"
#include "Crafting/Card Effects/Enchantments/CardEnchantment.h"
#include "Crafting/Card Effects/Impacts/CardImpact.h"
#include "Card.generated.h"

#define DURABILITY_COEFFICIENT 100.0
/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UCard : public UObject
{
	GENERATED_BODY()

public:
	UCard();

	UPROPERTY(BlueprintReadOnly)
	int Cost;
	
	UPROPERTY(BlueprintReadOnly)
	int Durability;

	UPROPERTY(BlueprintReadOnly)
	TArray<UEffectBlock*> Effects;
};
