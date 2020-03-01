// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AdventureObject.h"
#include "AddTaskAdventure.generated.h"

/**
 * Add Task Adventure
 */
UCLASS()
class NIER_API UAddTaskAdventure : public UAdventureObject
{
	GENERATED_BODY()

public:
	void Play() override;
	void SetInfo(FName AdventureNumber, FName TaskNumber);
private:
	//Task Number
	FName TaskNumber;
};
