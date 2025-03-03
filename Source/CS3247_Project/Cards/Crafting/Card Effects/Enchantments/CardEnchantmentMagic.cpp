// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEnchantmentMagic.h"

UCardEffect* UCardEnchantmentMagic::Enchant(UCardEffect* Effect) {
	if (Effect->MagicEnchantments.Contains(this->EnchantmentType)) {
		Effect->MagicEnchantments[this->EnchantmentType] += this->Strength;
	} else {
		Effect->MagicEnchantments.Add(this->EnchantmentType, this->Strength);
	}

	return Effect;
}

