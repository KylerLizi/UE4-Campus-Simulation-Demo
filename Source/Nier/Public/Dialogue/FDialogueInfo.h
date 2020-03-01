// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FTaskInfo.h"
#include "FDialogueInfo.generated.h"

USTRUCT(BlueprintType)
struct NIER_API FDialogueInfoRaw : public FTableRowBase
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, SaveGame)
		FName TaskName;
	UPROPERTY(EditAnywhere, SaveGame)
		TMap<ETaskState, FString> DialogueText;
	UPROPERTY(EditAnywhere, SaveGame)
		TSoftObjectPtr<class UDialogueVoice> SourceVoice;
	UPROPERTY(EditAnywhere, SaveGame)
		TSoftObjectPtr<class UDialogueVoice> TargetVoice;
	UPROPERTY(EditAnywhere, SaveGame)
		TSoftObjectPtr<class USoundWave> DialogueSound;
};