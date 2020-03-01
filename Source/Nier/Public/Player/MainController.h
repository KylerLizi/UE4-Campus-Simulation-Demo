// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameType.h"
#include "MainController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPlayerAttributeDelegate, EPlayerAttributeType, AttributeType, int32,DeltaNumber);

/**
 * 
 */
UCLASS()
class NIER_API AMainController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
		class ANierCharacter* GetPlayerCharacter();

	UFUNCTION(BlueprintCallable)
	TMap<EPlayerAttributeType, int32> GetPlayerAttributeNumber() ;

	UFUNCTION(BlueprintCallable)
	void UpdatePlayerAttributeNumber(EPlayerAttributeType AttributeType, int32 DeltaNumber);

	UFUNCTION(BlueprintCallable)
	void RefreashPlayerAttributeNumber(TMap<EPlayerAttributeType, int32> Abilityies);

protected:
	UPROPERTY(BlueprintReadOnly)
	class UAbilityTree* AbilityTree;
	UPROPERTY(BlueprintAssignable)
	FPlayerAttributeDelegate OnAttributeChange;
};
