// Fill out your copyright notice in the Description page of Project Settings.


#include "CardImpactDamage.h"

TSoftObjectPtr<UCardEffect> UCardImpactDamage::Apply() {
	TSoftObjectPtr<UCardEffect> Data = Super::Apply();
	if (Data.Get()->Damages.Contains(this->DamageType)) {
		Data.Get()->Damages[this->DamageType] += this->Value;
	} else {
		Data.Get()->Damages.Add(this->DamageType, this->Value);
	}
	return Data;
}