// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectBlock.h"

UEffectBlock::UEffectBlock() {
	this->Impact = nullptr;
	this->Enchantments = {};
}

UEffectBlock* UEffectBlock::WithImpact(UCardImpact* CardImpact) {
	this->Impact = CardImpact;
	return this;
}

UEffectBlock* UEffectBlock::Append(UCardEnchantment* Enchantment) {
	TLinkedList<UCardEnchantment*>* Head = new TLinkedList(Enchantment);
	this->Enchantments.LinkHead(Head);
	return this;
}

UEffectBlock* UEffectBlock::AppendAll(const TArray<UCardEnchantment*> CardEnchantments) {
	for (auto& Enchantment : CardEnchantments) {
		this->Append(Enchantment);
	}

	return this;
}

UCardEffect* UEffectBlock::GetEffect() {
	UCardEffect* CardEffect = this->Impact->Apply();
	for (auto& Enchantment : this->Enchantments) {
		CardEffect = Enchantment->Enchant(CardEffect);
	}

	return CardEffect;
}

FString UEffectBlock::ToRichText() const {
	return this->Impact->ToRichText();
}

