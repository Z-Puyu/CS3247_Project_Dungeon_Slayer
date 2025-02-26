// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../CardEffect.h"
#include "../CardIngredient.h"
#include "Engine/DataAsset.h"
#include "CardImpact.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class CS3247_PROJECT_API UCardImpact : public UCardIngredient {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual UCardEffect* Apply();
};
