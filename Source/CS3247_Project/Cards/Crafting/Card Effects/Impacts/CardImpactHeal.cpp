// Fill out your copyright notice in the Description page of Project Settings.


#include "CardImpactHeal.h"

UCardEffect* UCardImpactHeal::Apply() {
	UCardEffect* Data = Super::Apply();
	Data->HealAmount += this->Value;
	return Data;
}