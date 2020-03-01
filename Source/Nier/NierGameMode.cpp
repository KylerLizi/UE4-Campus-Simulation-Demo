// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "NierGameMode.h"
#include "NierCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "AdventureManager.h"
#include "TaskManager.h"
#include "NpcManager.h"
#include "Engine/World.h"

ANierGameMode::ANierGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

ATaskManager * ANierGameMode::GetTaskManager() const
{
	return TaskManager;
}

AAdventureManager * ANierGameMode::GetAdventureManager() const
{
	return AdventureManager;
}


ANpcManager * ANierGameMode::GetNpcManager() const
{
	return NpcManager;
}

void ANierGameMode::BeginPlay()
{
	Super::BeginPlay();

	AdventureManager = GetWorld()->SpawnActor<AAdventureManager>(AAdventureManager::StaticClass());
	AdventureManager->SetTaskAdventureTable(TaskAdventureTable);

	TaskManager = GetWorld()->SpawnActor<ATaskManager>(ATaskManager::StaticClass());
	TaskManager->Initial(TaskTable);

	NpcManager = GetWorld()->SpawnActor<ANpcManager>(ANpcManager::StaticClass());
	NpcManager->SpawnAllNpcCharacter();
}

void ANierGameMode::LoadGameFinish()
{
	
}
