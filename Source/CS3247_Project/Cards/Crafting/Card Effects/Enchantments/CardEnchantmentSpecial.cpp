// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEnchantmentSpecial.h"

UCardEffect* UCardEnchantmentSpecial::Enchant(UCardEffect* Effect) {
	Effect->SpecialEffects.AddTag(this->SpecialEffect);
	return Effect;
}

