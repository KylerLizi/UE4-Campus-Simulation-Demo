// Fill out your copyright notice in the Description page of Project Settings.


#include "BagItem.h"

// Sets default values
ABagItem::ABagItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ABagItem::ABagItem(FName name, FString des, UTexture2D* pic)
{
	PrimaryActorTick.bCanEverTick = true;
	BagItemName = name;
	BagItemDescription = des;
	BagItemPic = pic;
}

// Called when the game starts or when spawned
void ABagItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABagItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


