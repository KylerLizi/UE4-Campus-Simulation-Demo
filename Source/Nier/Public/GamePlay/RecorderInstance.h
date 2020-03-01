// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/StreamableManager.h"
#include "GameType.h"
#include "RecorderInstance.generated.h"

DECLARE_DYNAMIC_DELEGATE(FOpenLevelDelegate);

/**
 * SaveGame Infos
 */
UCLASS()
class NIER_API URecorderInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	FStreamableManager CommanStream;

	UFUNCTION(BlueprintCallable)
		class UDataTable* AsyncLoadDataTableByPath(UObject* WorldContext, FString Path);

	void LoadTestFinish(FSoftObjectPath Path, UObject* WorldContext);

	/*
	Save All Game
	*/
	UFUNCTION(BlueprintCallable)
	void SaveAllGame(const FString& SlotName, const int32 PlayerIndex, FString LevelName);


	UFUNCTION(BlueprintCallable)
	TArray<FString> GetAllSlotName();

	class UNormalSaveGame* GetCurrentSaveGame();
	
	UFUNCTION(BlueprintCallable)
	bool LoadOrCreateSlot(const FString& SlotName, const int32 PlayerIndex, FOpenLevelDelegate Callback);

	UFUNCTION(BlueprintCallable)
	void SavePlayerAttribute(EPlayerAttributeType AttributeType, int32 Number);
private:
	UPROPERTY()
	class UNormalSaveGame* CurrentSaveGame;

	void WriteToDisk(const FString& SlotName, const int32 UserIndex);
};
