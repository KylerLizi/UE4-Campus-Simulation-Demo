// Fill out your copyright notice in the Description page of Project Settings.


#include "AdventureObject.h"
#include "Kismet/GameplayStatics.h"

void UAdventureObject::Play(){
	UE_LOG(LogTemp, Warning, TEXT("AdventureNumber %s"),*AdventureNumber.ToString());
}

void UAdventureObject::SetInfo(FName AdventureNumber)
{
	this->AdventureNumber = AdventureNumber;
}


