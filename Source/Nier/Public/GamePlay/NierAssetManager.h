// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "NierAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class NIER_API UNierAssetManager : public UAssetManager
{
	GENERATED_BODY()
	
public:

	static UNierAssetManager& Get();

	UObject* LoadObjectByStaticPath(FString Path);

	void AsyncLoadObjectByStaticPath(FString Path, TFunctionRef<void(FSoftObjectPtr)> Callback);

private:
	FStreamableManager CommanStream;
};


