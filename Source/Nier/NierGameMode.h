// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AdventureManager.h"
#include "NierGameMode.generated.h"

UCLASS(minimalapi)
class ANierGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANierGameMode();

	class ATaskManager *GetTaskManager() const;

	class AAdventureManager *GetAdventureManager() const;

	class ANpcManager *GetNpcManager() const;

	void LoadGameFinish();

protected:
	void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	class AAdventureManager *AdventureManager = nullptr;
	UPROPERTY(BlueprintReadOnly)
	class ANpcManager *NpcManager = nullptr;
	UPROPERTY(BlueprintReadOnly)
	class ATaskManager *TaskManager = nullptr;

	//TODO::Maybe load hardcode path

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UDataTable *TaskAdventureTable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UDataTable *TaskTable;
};
