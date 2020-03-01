// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FAdventureInfo.generated.h"


/*
* Adventure Type
*/
UENUM()
enum class AdventureType :uint8 {
	AddTask,
	OpenLevel
};


/*
* AdventureInfo for DataTable
*/
USTRUCT(BlueprintType)
struct FAdventureInfoRaw :public FTableRowBase {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		AdventureType Type;
	UPROPERTY(EditAnywhere)
		FName AdventureNumber;

	FAdventureInfoRaw(AdventureType Type = AdventureType::AddTask, FName AdventureNumber = "-1") {
		this->Type = Type;
		this->AdventureNumber = AdventureNumber;
	}
};

/*
* TaskAdventureInfo for DataTable
*/
USTRUCT(BlueprintType)
struct FTaskAdvInfoRaw :public FAdventureInfoRaw {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		FName TaskNumber;

	FTaskAdvInfoRaw(FName TaskNumber = "-1", FName AdventureNumber = "-1") {
		this->TaskNumber = TaskNumber;
	}

};

/**
 * AdventureInfo used in cpp
 */
class NIER_API FAdventureInfo
{
public:
	FAdventureInfo();
	FAdventureInfo(FName AdventureNumber, AdventureType Type);
	virtual ~FAdventureInfo();

	virtual class UAdventureObject* GetAdventureByInfo(class AGameModeBase* Mode) { return nullptr; };

protected:
	AdventureType Type;
	FName AdventureNumber;
};


/*
* TaskAdventureInfo used in cpp
*/

class NIER_API FTaskAdvInfo :public FAdventureInfo {
public:
	FTaskAdvInfo();
	FTaskAdvInfo(FName AdventureNumber,FName TaskNumber);
	virtual ~FTaskAdvInfo();

	class UAdventureObject* GetAdventureByInfo(class AGameModeBase* Mode) override;
	FName GetTaskNumber() { return TaskNumber; };
protected:
	FName TaskNumber;
};
