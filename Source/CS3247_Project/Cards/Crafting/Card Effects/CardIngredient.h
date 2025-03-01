// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CardIngredient.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class CS3247_PROJECT_API UCardIngredient : public UDataAsset {
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Info")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Info")
	FText Desc;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Info")
	TSoftObjectPtr<UTexture2D> Icon;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cost")
	double UseCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cost")
	int32 CraftCost;
};
