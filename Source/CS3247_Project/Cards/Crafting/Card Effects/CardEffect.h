// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CardEffect.generated.h"

/**
 * 
 */
UCLASS(Abstract, EditInlineNew, DefaultToInstanced, CollapseCategories)
class CS3247_PROJECT_API UCardEffect : public UDataAsset {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cost")
	int32 UseCost = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cost")
	int32 CraftCost = 0;
};
