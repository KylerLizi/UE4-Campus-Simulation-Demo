// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FNpcInfo.h"
#include "NpcDataAsset.generated.h"
/**
 * 
 */
UCLASS()
class NIER_API UNpcDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		FName NpcId;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		FName NpcName;//名称
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		TSoftObjectPtr<class USkeletalMesh> NpcMesh;//模型
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		TSubclassOf<class UAnimInstance> NpcAnimClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		ENpcState NpcState;//运动状态
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		FName NpcTaskNumber;//该Npc相关任务编号
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		FVector NpcInitLocation;//初始位置
	FNpcInfoRaw GetNpcInfo();
};
