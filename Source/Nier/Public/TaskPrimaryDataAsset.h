// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TaskPrimaryDataAsset.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class NIER_API UTaskPrimaryDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UTaskPrimaryDataAsset();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FPrimaryAssetType Type;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName TaskNumber;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FName> PreviousTaskNumber;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FName> NextTaskNumber;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSoftClassPtr<class UTask> TaskClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSoftObjectPtr<class UTexture2D> SoftTexture;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class UTexture2D* Texture;
	
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;
};
