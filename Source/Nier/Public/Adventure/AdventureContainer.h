// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FContainerInfo.h"
#include "AdventureContainer.generated.h"

//USTRUCT(BlueprintType)
//struct FContainerInfoRaw :public FTableRowBase{
//	GENERATED_BODY()
//
//	UPROPERTY(EditAnywhere)
//		FName ContainerNumber;
//
//	UPROPERTY(EditAnywhere)
//		FAdventureInfo AdvInfo;
//
//	FContainerInfoRaw(FName ContainerNumber="-1", FAdventureInfo AdvInfo= FAdventureInfo()) {
//		this->ContainerNumber = ContainerNumber;
//		this->AdvInfo = AdvInfo;
//	}
//};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAdventureContainer : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class NIER_API IAdventureContainer
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void PlayAdventure();
	virtual TSharedRef<FContainerInfo> GetContainerInfo() const;
	//TODO 
	//if adventure type check function is duplicated and some new kind of containers come out,
	//we need an abstract ContainerBase including type check funciton
};
