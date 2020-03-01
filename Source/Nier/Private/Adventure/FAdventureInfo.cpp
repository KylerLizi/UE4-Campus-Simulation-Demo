// Fill out your copyright notice in the Description page of Project Settings.


#include "FAdventureInfo.h"
#include "NierGameMode.h"

FAdventureInfo::FAdventureInfo()
{
}

FAdventureInfo::FAdventureInfo(FName AdventureNumber, AdventureType Type)
{
	this->AdventureNumber = AdventureNumber;
	this->Type = Type;
}

FAdventureInfo::~FAdventureInfo()
{
}


FTaskAdvInfo::FTaskAdvInfo()
{
}

FTaskAdvInfo::FTaskAdvInfo(FName AdventureNumber, FName TaskNumber) {
	this->Type = AdventureType::AddTask;
	this->AdventureNumber = AdventureNumber;
	this->TaskNumber = TaskNumber;
}

FTaskAdvInfo::~FTaskAdvInfo()
{
}

UAdventureObject * FTaskAdvInfo::GetAdventureByInfo(AGameModeBase* Mode)
{
	ANierGameMode* MyMode = Cast<ANierGameMode>(Mode);
	return MyMode->GetAdventureManager()->ProduceTaskAdv(AdventureNumber);
}