// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardEffectData.h"
#include "Engine/DataAsset.h"
#include "CardImpact.generated.h"

/**
 * 
 */
UCLASS(Abstract, EditInlineNew, DefaultToInstanced, CollapseCategories)
class CS3247_PROJECT_API UCardImpact : public UDataAsset {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cost")
	double UseCost = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cost")
	int32 CraftCost = 0;

	UFUNCTION()
	virtual TSoftObjectPtr<UCardEffect> Apply();
};
