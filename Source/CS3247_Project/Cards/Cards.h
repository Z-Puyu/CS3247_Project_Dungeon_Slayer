// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Cards.generated.h"
#include "Crafting/Card Effects/Enchantments/CardEnchantment.h"
#include "Crafting/Card Effects/Impacts/CardImpact.h"

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
	TMap<UCardImpact, TArray<UCardEnchantment>> Effects;
	
	UFUNCTION(BlueprintCallable)
	int GetCost() { return this->Cost; };

	UFUNCTION(BlueprintCallable)
	int GetDurability() { return this->Durability; };

	// To be called on creation of a card. Sets the energy cost of it.
	UFUNCTION(BlueprintCallable)
	void SetCost()
	{
		int Total = 0;
		for (TTuple<UCardImpact, TArray<UCardEnchantment>> Elem : this->Effects) {
			Total += Elem.Key.UseCost;
			for (UCardEnchantment Enchantment : Elem.Value) {
				Total += Enchantment.UseCost;
			}
		}
	}

	// To be called on creation of a card. Sets the initial durability of it.
	UFUNCTION(BlueprintCallable)
	void SetDurability()
	{
		int Total = 0;
		for (TTuple<UCardImpact, TArray<UCardEnchantment>> Elem : this->Effects) {
			Total += Elem.Key.CraftCost;
			for (UCardEnchantment Enchantment : Elem.Value) {
				Total += Enchantment.CraftCost;
			}
		}
		this->Durability = static_cast<int>(std::max(ceil(DURABILITYCOEFFICIENT / static_cast<float>(Total)), 1.0));
	}

	// Return the effects of the card in an array of UCardEffect.
	UFUNCTION(BlueprintCallable)
	TArray<UCardEffect*> Use()
	{
		this->Durability -= 1;
		TArray<UCardEffect*> Effects;
		for (TTuple<UCardImpact, TArray<UCardEnchantment>> Elem : this->Effects) {
			UCardEffect *Effect = Elem.Key.Apply();
			for (UCardEnchantment Enchantment : Elem.Value) {
				Effect = Enchantment.Enchant(Effect);
			}
			Effects.Add(Effect);
		}
		return Effects;
	};
};
