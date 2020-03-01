// Fill out your copyright notice in the Description page of Project Settings.


#include "BagManager.h"

// Sets default values
ABagManager::ABagManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABagManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABagManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UFUNCTION()
void ABagManager::AcquireItem(ABagItem* item)
{
	BagIemArray.Add(item);
}

void ABagManager::DeleteItem(ABagItem* item)
{
	if (BagIemArray.Contains(item))
	{
		BagIemArray.Remove(item);
	}
}

void ABagManager::UseItem(ABagItem* item)
{
	item->Use();
}

void ABagManager::ShowItem(ABagItem* item)
{

}
