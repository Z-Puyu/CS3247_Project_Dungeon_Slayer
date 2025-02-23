// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEnchantmentPowerDown.h"

UCardEffect* UCardEnchantmentPowerDown::Enchant(UCardEffect* Effect) {
	Effect->Multiplier -= this->Value;
	return Effect;
}