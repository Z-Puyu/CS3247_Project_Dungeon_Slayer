// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Crafting/Card Effects/EffectBlock.h"
#include "../UI/Texts/TextDescribable.h"
#include "Card.generated.h"

#define DURABILITY_COEFFICIENT 100.0
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class CS3247_PROJECT_API UCard : public UObject, public ITextDescribable {
	GENERATED_BODY()

public:
	UCard();

	UFUNCTION(BlueprintCallable)
	virtual FText GetDescription() const override;

	UFUNCTION(BlueprintCallable)
	void GetCardInfo(FText& CardName, FText& Desc, int& UseCost, int& CardDurability, TArray<UEffectBlock*>& CardEffects) const;

	UFUNCTION(BlueprintCallable)
	UCard* WithData(const FText& CardName, const int UseCost, const int CardDurability, const TArray<UEffectBlock*>& CardEffects);
private:
	FText Name;
	
	int Cost;
	
	int Durability;

	UPROPERTY()
	TArray<UEffectBlock*> Effects;
};
