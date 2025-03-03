// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEffect.h"

UCardEffect::UCardEffect() {
	this->Multiplier = 100;
	this->Damages = {};
	this->MagicEnchantments = {};
	this->HealAmount = 0;
	this->SpecialEffects = FGameplayTagContainer();
}
