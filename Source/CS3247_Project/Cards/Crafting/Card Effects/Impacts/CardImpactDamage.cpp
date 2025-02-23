// Fill out your copyright notice in the Description page of Project Settings.


#include "CardImpactDamage.h"

UCardEffect* UCardImpactDamage::Apply() {
	UCardEffect* Data = Super::Apply();
	if (Data->Damages.Contains(this->DamageType)) {
		Data->Damages[this->DamageType] += this->Value;
	} else {
		Data->Damages.Add(this->DamageType, this->Value);
	}
	return Data;
}