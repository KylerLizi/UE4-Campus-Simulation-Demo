// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "AdventureManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class NIER_API AAdventureManager : public AInfo
{
	GENERATED_BODY()
	
public:
	AAdventureManager();

	void StartAdventure(class UAdventureObject* Adv);

	UFUNCTION(BlueprintCallable)
	void SetTaskAdventureTable(class UDataTable* Table);

	class UAdventureObject* ProduceTaskAdv(FName AdventureNumber);
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UDataTable* TaskAdvTable;

private:
	class UTaskAdvFactory* TaskAdvFactory;

};
