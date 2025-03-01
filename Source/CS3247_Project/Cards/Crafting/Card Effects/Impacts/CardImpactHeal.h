﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardImpact.h"
#include "../CardEffect.h"
#include "CardImpactHeal.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UCardImpactHeal : public UCardImpact {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Value;
	
	virtual UCardEffect* Apply() override;
	
	virtual FString ToRichText() const override;
};
