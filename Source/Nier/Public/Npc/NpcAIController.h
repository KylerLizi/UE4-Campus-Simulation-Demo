// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/UObjectGlobals.h"
#include "NpcAIController.generated.h"

/**
 * 
 */
UCLASS()
class NIER_API ANpcAIController : public AAIController
{
	GENERATED_BODY()

public:
	ANpcAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBehaviorTree* NpcBehaviorTree;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient)
		class UBehaviorTreeComponent* BehaviorTreeComp;*/
	//class UBlackboardComponent* BlackBoardComp;
		
public:
		void RunNpcBehaviorTree();
};
