// Fill out your copyright notice in the Description page of Project Settings.


#include "Text.h"
FString UText::Bf(FString Str) {
	return "<bf>" + Str + "</>";
}

FString UText::It(FString Str) {
	return "<it>" + Str + "</>";
}

FString UText::BfIt(FString Str) {
	return "<bfit>" + Str + "</>";
}

FString UText::Rm(FString Str) {
	return "<rm>" + Str + "</>";
}

FString UText::Red(FString Str) {
	return "<red>" + Str + "</>";
}

FString UText::Green(FString Str) {
	return "<green>" + Str + "</>";
}
