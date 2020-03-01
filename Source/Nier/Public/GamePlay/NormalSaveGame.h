// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "FTaskInfo.h"
#include "FNpcInfo.h"
#include "Ability.h"
#include "NormalSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class NIER_API UNormalSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	void SaveTask(FTaskInfoRaw Raw);
	void SaveMapName(FString LevelName) { CurrentMap = LevelName; };
	const TMap<FName, FTaskInfoRaw>& GetTask() { return PlayerTaskInfo; };
	void SaveNpc(FNpcInfoRaw Raw);
	const TMap<FName, FNpcInfoRaw>& GetNpc() { return NpcInfoMap; };
	void SavePlayerAttribute(EPlayerAttributeType AttributeType, int32 Number);
	const TMap<EPlayerAttributeType, int32>& GetPlayerAttribute() { return PlayerAttribute; };

private:
	UPROPERTY()
		TMap<FName, FTaskInfoRaw> PlayerTaskInfo = TMap<FName, FTaskInfoRaw>(); 
	UPROPERTY()
		FString CurrentMap;
	UPROPERTY()
		TMap<FName, FNpcInfoRaw> NpcInfoMap;
	UPROPERTY()
		TMap<EPlayerAttributeType, int32> PlayerAttribute;
};
