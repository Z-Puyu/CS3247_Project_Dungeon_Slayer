// Fill out your copyright notice in the Description page of Project Settings.


#include "CardNode.h"
TArray<UEffectBlock*> UCardNode::Build() {
	if (this->IsTerminal()) {
		return {NewObject<UEffectBlock>()->WithImpact(Cast<UCardImpact>(this->Ingredient))};
	}

	TArray<UEffectBlock*> Blocks = {};
	
	if (this->Ingredient->IsA(UCardEnchantment::StaticClass())) {
		UCardEnchantment* Enchantment = Cast<UCardEnchantment>(this->Ingredient);
		for (UCardNode* Successor : this->Successors) {
			for (UEffectBlock* Block : Successor->Build()) {
				Blocks.Add(Block->Append(Enchantment));
			}
		}
		
		return Blocks;
	}

	for (UCardNode* Successor : this->Successors) {
		Blocks.Append(Successor->Build());
	}
	
	return Blocks;
}
