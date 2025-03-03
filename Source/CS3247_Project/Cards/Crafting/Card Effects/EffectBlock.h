// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enchantments/CardEnchantment.h"
#include "Impacts/CardImpact.h"
#include "UObject/NoExportTypes.h"
#include "EffectBlock.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UEffectBlock : public UObject
{
	GENERATED_BODY()

public:
    UEffectBlock();

	int Cost;
	int CraftCost;
	TSoftObjectPtr<UCardImpact> Impact;
	TArray<TSoftObjectPtr<UCardEnchantment>> Enchantments;

	void SetCost()
	{
		int Total = 0;
		for (TSoftObjectPtr<UCardEnchantment> Elem : this->Enchantments) {
			Total += Elem.Get()->UseCost;
		}
		Total += this->Impact.Get()->UseCost;
		this->Cost = Total;
	}

	int GetCost() const { return this->Cost; }

	// To be called on creation of a card. Sets the initial durability of it.
	UFUNCTION(BlueprintCallable)
	void SetCraftCost()
	{
		int Total = 0;
		for (TSoftObjectPtr<UCardEnchantment> Elem : this->Enchantments) {
			Total += Elem.Get()->CraftCost;
		}
		Total += this->Impact.Get()->CraftCost;
		this->CraftCost = Total;
	}

	int GetCraftCost() const { return this->CraftCost; }

	UCardEffect * Use() const
	{
		UCardEffect *Result = this->Impact.Get()->Apply();
		for (TSoftObjectPtr<UCardEnchantment> Enhancement : this->Enchantments)
		{
			Result = Enhancement->Enchant(Result);
		}
		return Result;
	}
};
