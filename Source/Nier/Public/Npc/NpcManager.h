// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "NpcManager.generated.h"

/**
 *
 */
UCLASS()
class NIER_API ANpcManager : public AInfo
{
	GENERATED_BODY()

public:
	ANpcManager();

	TMap<FName,class ANpcCharacter*> NpcList;

private:

	class UNpcFactory* NpcFactory;

	static const TCHAR* DefaultNpcPath;

public:

	/** spawn npc from save slot or data asset */
	void SpawnAllNpcCharacter();

	/*UFUNCTION(BlueprintImplementableEvent)
	void Produce*/

private:

	void LoadNpcFromSlot();

	//void SaveNpcSlot(ANpcCharacter* Npc);
};
