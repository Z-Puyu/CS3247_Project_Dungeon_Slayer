// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TextDescribable.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UTextDescribable : public UInterface {
	GENERATED_BODY()
};

/**
 * 
 */
class CS3247_PROJECT_API ITextDescribable {
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual FText GetDescription() const = 0;
};
