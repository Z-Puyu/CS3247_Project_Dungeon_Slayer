// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Crafting/Card Effects/EffectBlock.h"
#include "UObject/NoExportTypes.h"
#include "Crafting/Card Effects/Enchantments/CardEnchantment.h"
#include "Crafting/Card Effects/Impacts/CardImpact.h"
#include "Cards.generated.h"

#define DURABILITYCOEFFICIENT 100.0
/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UCards : public UObject
{
	GENERATED_BODY()

public:
	UCards();

	int Cost;
	int Durability;
	TArray<TSoftObjectPtr<UEffectBlock>> Effects;
	
	UFUNCTION(BlueprintCallable)
	int GetCost() { return this->Cost; };

	UFUNCTION(BlueprintCallable)
	int GetDurability() { return this->Durability; };

	// To be called on creation of a card. Sets the energy cost of it.
	UFUNCTION(BlueprintCallable)
	void SetCost()
	{
		int Total = 0;
		for (TSoftObjectPtr<UEffectBlock> Elem : this->Effects) {
			Total += Elem.Get()->GetCost();
		}
		Cost = Total;
	}

	// To be called on creation of a card. Sets the initial durability of it.
	UFUNCTION(BlueprintCallable)
	void SetDurability()
	{
		int Total = 0;
		for (TSoftObjectPtr<UEffectBlock> Elem : this->Effects) {
			Total += Elem.Get()->GetCraftCost();
		}
		this->Durability = static_cast<int>(std::max(ceil(DURABILITYCOEFFICIENT / static_cast<float>(Total)), 1.0));
	}

	// Return the effects of the card in an array of UCardEffect.
	UFUNCTION(BlueprintCallable)
	TArray<UCardEffect*> Use()
	{
		this->Durability -= 1;
		TArray<UCardEffect*> Effects;
		for (TSoftObjectPtr<UEffectBlock> Elem : this->Effects)
		{
			Effects.Add(Elem.Get()->Use());
		}
		return Effects;
	};
};
