// Fill out your copyright notice in the Description page of Project Settings.


#include "CardImpactHeal.h"

TSoftObjectPtr<UCardEffect> UCardImpactHeal::Apply() {
	TSoftObjectPtr<UCardEffect> Data = Super::Apply();
	Data.Get()->HealAmount += this->Value;
	return Data;
}