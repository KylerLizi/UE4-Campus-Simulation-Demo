// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FAdventureInfo.h"
#include "FContainerInfo.generated.h"

/*
* ContainerInfo for DataTable
*/
USTRUCT(BlueprintType)
struct NIER_API FContainerInfoRaw :public FTableRowBase 
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		FName ContainerNumber;

	UPROPERTY(EditAnywhere)
		FAdventureInfoRaw AdvInfo;

	FContainerInfoRaw(FName ContainerNumber = "-1", FAdventureInfoRaw AdvInfo = FAdventureInfoRaw()) {
		this->ContainerNumber = ContainerNumber;
		this->AdvInfo = AdvInfo;
	}
};

/**
 * ContainerTable use in cpp
 */
class NIER_API FContainerInfo
{
public:
	FContainerInfo();
	FContainerInfo(FName ContainerNumber, FAdventureInfo* AdvInfo);
	class FAdventureInfo* GetAdvInfo() { return AdvInfo; };
	
	~FContainerInfo();
protected:
	FName ContainerNumber;
	//TODO:may be should be TsharedPtr<FAdventureInfo>
	class FAdventureInfo* AdvInfo;

};
