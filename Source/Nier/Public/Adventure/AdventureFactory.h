// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AdventureFactory.generated.h"



/**
 * Adventure Factory Base Class, Any type of Adv Factory should derived from this
 */
UCLASS()
class NIER_API UAdventureFactory : public UObject
{
	GENERATED_BODY()
	
public:
	//set table
	virtual void InitTable(class UDataTable* Table);
	//should be override to produce specific Adventure
	virtual class UAdventureObject* ProduceAdventure(FName AdventureNumber);
protected:
	//DataTable type check
	UStruct* TableRaw;
	//Which table to use
	class UDataTable* Table;
};
