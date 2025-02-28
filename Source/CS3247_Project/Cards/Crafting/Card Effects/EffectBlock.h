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
class CS3247_PROJECT_API UEffectBlock : public UObject {
	GENERATED_BODY()

public:
	UEffectBlock();
	
	UFUNCTION(BlueprintCallable)
	UEffectBlock* WithImpact(UCardImpact* CardImpact);

	UFUNCTION(BlueprintCallable)
	UEffectBlock* Append(UCardEnchantment* Enchantment); 

	UFUNCTION(BlueprintCallable)
	UEffectBlock* AppendAll(const TArray<UCardEnchantment*> CardEnchantments);

	UFUNCTION(BlueprintCallable)
	UCardEffect* GetEffect();

private:
	TWeakObjectPtr<UCardImpact> Impact;
	
	TLinkedList<UCardEnchantment*> Enchantments;
};


