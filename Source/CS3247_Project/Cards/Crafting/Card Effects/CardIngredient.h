// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CardIngredient.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType)
class CS3247_PROJECT_API UCardIngredient : public UDataAsset {
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cost")
	double UseCost = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cost")
	int32 CraftCost = 0;
};
