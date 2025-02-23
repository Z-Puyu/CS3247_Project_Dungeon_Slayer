// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Crafting/Card Effects/Enchantments/CardEnchantment.h"
#include "../Crafting/Card Effects/Impacts/CardImpact.h"
#include "Engine/DataAsset.h"
#include "TestCard.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UTestCard : public UDataAsset {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<TSoftObjectPtr<UCardEnchantment>> Enchantments;
	
	UPROPERTY(Instanced, EditDefaultsOnly, BlueprintReadOnly, meta=(AllowAbstract))
	TObjectPtr<UCardImpact> Impact;
};
