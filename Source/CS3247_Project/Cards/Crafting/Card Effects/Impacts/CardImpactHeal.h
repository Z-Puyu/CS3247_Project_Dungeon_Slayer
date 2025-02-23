// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardImpact.h"
#include "CardImpactHeal.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UCardImpactHeal : public UCardImpact {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 Value;

	UFUNCTION()
	virtual TSoftObjectPtr<UCardEffect> Apply() override;
};
