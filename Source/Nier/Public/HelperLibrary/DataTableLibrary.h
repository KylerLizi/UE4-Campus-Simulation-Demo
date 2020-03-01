// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameType.h"
#include "DataTableLibrary.generated.h"

/**
 * 
 */

UCLASS()
class NIER_API UDataTableLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static TMap<EPlayerAttributeType, int32> TransFormGradeToAttribute(int32 Math,int32 Chinese,int32 English,int32 Comprehension);
};
