// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FTaskInfo.h"
#include "TaskDataAsset.generated.h"


/**
 * 
 */
UCLASS(BlueprintType)
class NIER_API UTaskDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		ETaskState TaskState;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		FName TaskNumber;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		int32 CurrentProgress;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		int32 MaxProgress;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		FName Description;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		TArray<FName> PreviousTask;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		TArray<FName> NextTask;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		TSoftClassPtr<class UTask> TaskClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		FName StartTaskNpc;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		FName EndTaskNpc;
	FTaskInfoRaw GetTaskInfo();
};
