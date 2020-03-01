// Fill out your copyright notice in the Description page of Project Settings.


#include "AdventureManager.h"
#include "AdventureContainer.h"
#include "Engine/DataTable.h"
#include "AdventureObject.h"
#include "TaskAdvFactory.h"


AAdventureManager::AAdventureManager() {
	TaskAdvFactory = NewObject<UTaskAdvFactory>(this,TEXT("TaskAdvFactory"));
}



void AAdventureManager::StartAdventure(UAdventureObject * Adv)
{
	if (Adv) {
		Adv->Play();
	}
}

void AAdventureManager::SetTaskAdventureTable(UDataTable* Table)
{
	checkf(Table != nullptr, TEXT("Task AdvTabel is null"));
	checkf(TaskAdvFactory != nullptr, TEXT("TaskAdvFactory is null"));
	TaskAdvFactory->InitTable(Table);
}

UAdventureObject * AAdventureManager::ProduceTaskAdv(FName AdventureNumber)
{
	return TaskAdvFactory->ProduceAdventure(AdventureNumber);
}