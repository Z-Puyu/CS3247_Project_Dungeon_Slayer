// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardEnchantment.h"
#include "CardEnchantmentPowerUp.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UCardEnchantmentPowerUp : public UCardEnchantment {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int Value;
	
	virtual UCardEffect* Enchant(UCardEffect* Effect) override;
};
