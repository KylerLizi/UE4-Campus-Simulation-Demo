// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class NIER_API AMainHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	//this funciton will be called When TaskList initial Finished
	UFUNCTION(BlueprintImplementableEvent)
	void TaskListInitFinsih();
};
