// Fill out your copyright notice in the Description page of Project Settings.


#include "CardImpactHeal.h"

#include "CS3247_Project/UI/Texts/Text.h"

UCardEffect* UCardImpactHeal::Apply() {
	UCardEffect* Data = Super::Apply();
	Data->HealAmount += this->Value;
	return Data;
}

FString UCardImpactHeal::ToRichText() const {
	const FString HealNum = UText::Green(FString::Printf(TEXT("%d"), this->Value));
	return FString::Printf(TEXT("Heals %s HP"), *HealNum);
}