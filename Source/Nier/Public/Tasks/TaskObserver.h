// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TaskObserver.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTaskObserver : public UInterface
{
	GENERATED_BODY()
};

/**
 * Those who want to know taskList's Changes should implement this Interface
 */
class NIER_API ITaskObserver
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent)
		void TaskStateChanged(const class UTask* Tasks);
};
