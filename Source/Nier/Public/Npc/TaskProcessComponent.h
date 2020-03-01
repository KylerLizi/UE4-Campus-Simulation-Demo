// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FTaskInfo.h"
#include "TaskProcessComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NIER_API UTaskProcessComponent : public UActorComponent
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UTask *NpcTask;

private:

	class ATaskManager *TaskManager;

	TMap<ETaskState, FString> TaskStateSign;

public:

	UTaskProcessComponent();

	class UTask* GetNpcTask() { return NpcTask; };
	
	/** produce and broadcast npc task */
	void SetNpcTask(FName NpcTaskNumber);

	/** update relative npc task according to current state */
	void UpdateNpcTaskState(FName NpcId);

	FString GetTaskStateSign();

protected:

	virtual void BeginPlay() override;
};
