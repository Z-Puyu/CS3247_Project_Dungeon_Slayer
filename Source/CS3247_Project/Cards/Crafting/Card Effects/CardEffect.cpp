// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEffect.h"

UCardEffect::UCardEffect() {
	this->ExtraDamageEffects = {};
	this->HealAmount = 0;
	this->SpecialEffects = FGameplayTagContainer();
}
