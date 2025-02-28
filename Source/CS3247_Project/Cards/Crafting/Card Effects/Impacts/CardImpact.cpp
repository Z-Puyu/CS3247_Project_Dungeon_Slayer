// Fill out your copyright notice in the Description page of Project Settings.


#include "CardImpact.h"

UCardEffect* UCardImpact::Apply() {
	return NewObject<UCardEffect>();
}

FString UCardImpact::ToRichText() const {
	return FString::Printf(TEXT("Unknown Card Impact"));
}

