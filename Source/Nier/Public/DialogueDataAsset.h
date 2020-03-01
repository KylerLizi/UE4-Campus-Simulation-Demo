// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FDialogueInfo.h"
#include "DialogueDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class NIER_API UDialogueDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AssetRegistrySearchable)
		FName TaskName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AssetRegistrySearchable)
		TMap<ETaskState, FString> DialogueText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AssetRegistrySearchable)
		TSoftObjectPtr<class UDialogueVoice> SourceVoice;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AssetRegistrySearchable)
		TSoftObjectPtr<class UDialogueVoice> TargetVoice;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AssetRegistrySearchable)
		TSoftObjectPtr<class USoundWave> DialogueSound;
	FDialogueInfoRaw GetDialogueInfo();
};
