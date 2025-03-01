// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Card Effects/CardIngredient.h"
#include "Card Effects/EffectBlock.h"
#include "UObject/Object.h"
#include "CardNode.generated.h"

/**
 * 
 */
UCLASS(EditInlineNew, BlueprintType, Blueprintable)
class CS3247_PROJECT_API UCardNode : public UDataAsset {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UCardIngredient* Ingredient;

	UPROPERTY(Instanced, EditAnywhere, BlueprintReadOnly)
	TArray<UCardNode*> Successors;

	UFUNCTION(BlueprintCallable)
	TArray<UEffectBlock*> Build();

	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool IsReadyToCraft() const { return this->IsTerminal() || this->Successors.Num() > 0; }
private:
	FORCEINLINE bool IsTerminal() const {
		return this->Ingredient->IsA(UCardImpact::StaticClass()) &&
			this->Successors.Num() == 0;
	}
};
