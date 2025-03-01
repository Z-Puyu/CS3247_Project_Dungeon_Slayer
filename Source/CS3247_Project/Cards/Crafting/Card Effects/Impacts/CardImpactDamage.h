// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardImpact.h"
#include "GameplayTagContainer.h"
#include "../CardEffect.h"
#include "CardImpactDamage.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UCardImpactDamage : public UCardImpact {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(Categories="Damage"))
	FGameplayTag DamageType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Value;
	
	virtual UCardEffect* Apply() override;

	virtual FString ToRichText() const override;

private:
	FString GetDamageType() const;
};
