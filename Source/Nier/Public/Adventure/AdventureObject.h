// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FAdventureInfo.h"
#include "AdventureObject.generated.h"


/*
*Adventure Base ,may be should all abstract
*/
UCLASS()
class NIER_API UAdventureObject : public UObject
{
	GENERATED_BODY()
public:
	//should be override to implement what will happen when adventure play
	virtual void Play();
	virtual void SetInfo(FName AdventureNumber);
protected:
	FName AdventureNumber;
	FAdventureInfo* Info;
};
