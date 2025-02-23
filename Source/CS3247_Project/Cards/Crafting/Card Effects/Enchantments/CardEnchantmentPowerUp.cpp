// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEnchantmentPowerUp.h"

UCardEffect* UCardEnchantmentPowerUp::Enchant(UCardEffect* Effect) {
	Effect->Multiplier += this->Value;
	return Effect;
}