// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CS3247_Project/Cards/Crafting/Card Effects/CardEffect.h"
#include "Engine/DataAsset.h"
#include "TestCard.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UTestCard : public UDataAsset {
	GENERATED_BODY()

public:
	UPROPERTY(Instanced, EditDefaultsOnly, BlueprintReadOnly, meta=(AllowAbstract))
	TObjectPtr<UCardEffect> Effect;
};
