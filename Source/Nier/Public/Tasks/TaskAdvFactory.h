// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AdventureFactory.h"
#include "TaskAdvFactory.generated.h"

/**
 * Task Adventury Factory
 */
UCLASS()
class NIER_API UTaskAdvFactory : public UAdventureFactory
{
	GENERATED_BODY()
	
public:
	UTaskAdvFactory();
	class UAdventureObject* ProduceAdventure(FName AdventureNumber) override;
};
