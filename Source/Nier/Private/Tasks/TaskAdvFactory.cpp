// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskAdvFactory.h"
#include "Engine/DataTable.h"
#include "FAdventureInfo.h"
#include "AddTaskAdventure.h"

UTaskAdvFactory::UTaskAdvFactory() {
	TableRaw = FAdventureInfoRaw::StaticStruct();
}

UAdventureObject* UTaskAdvFactory::ProduceAdventure(FName AdventureNumber) {
	UAddTaskAdventure* Adv = nullptr;
	if (ensure(Table)) {
		auto Info = Table->FindRow<FTaskAdvInfoRaw>(AdventureNumber, TEXT("AdvInfo"));
		if (ensure(Info)) {
			Adv = NewObject<UAddTaskAdventure>(this);
			Adv->SetInfo(AdventureNumber,Info->TaskNumber);
			UE_LOG(LogTemp, Warning, TEXT("Find TaskAdv Row"));
		}
	}
	return Adv;
}