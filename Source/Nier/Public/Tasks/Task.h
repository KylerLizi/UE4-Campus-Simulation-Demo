// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FTaskInfo.h"
#include "GameFramework/PlayerController.h"
#include "Task.generated.h"

/**
 * Task Base Class
 */
UCLASS(Blueprintable)
class NIER_API UTask : public UObject
{
	GENERATED_BODY()

		//TODO:If different type of tasks behave same,we should extract them into a new class TaskBehaviour
		//And Blueprint should overrite new behaviour
public:
	static const FString BaseTaskTablePath;

	//try to start this task from "Nevertrigger" to "Not receive"
	virtual void Start();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void StartBP();
	//Try to receive this task,may restart
	virtual void Receive();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void ReceiveBP();
	//Change task progress
	virtual void Progress(int32 DeltaProgress);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void ProgressBP();
	//Try to Finish This Task
	UFUNCTION(BlueprintCallable)
	virtual void Finish();
	//This Task Has Finished
	virtual void End();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void FinishBP();

	//notify task manager to update this task
	void NotifyTaskManager();

	virtual void SetInfo(class UTaskDataAsset* DataInfo);
	virtual void SetInfo(FTaskInfoRaw DataInfo);

	//just for getter
	FTaskInfoRaw GetTaskInfoRaw();

	FName GetNumber() { return TaskNumber; };
	ETaskState GetState() { return TaskState; };
	int32 GetCurrentProgress() { return CurrentProgress; };
	int32 GetMaxProgress() { return MaxProgress; };
	FName GetName() { return Name; };
	FName GetDescription() { return Description; };
	FName GetStartTaskNpc() { return StartTaskNpc; };
	FName GetEndTaskNpc() { return EndTaskNpc; };

	void SetDescription(FName NewDescriotion) { Description = NewDescriotion; };

	UFUNCTION(BlueprintCallable)
	APlayerController* GetPlayerController();

protected:
	UPROPERTY(BlueprintReadOnly)
		ETaskState TaskState;
	UPROPERTY(BlueprintReadOnly)
		FName TaskNumber;
	UPROPERTY(BlueprintReadOnly)
		int32 CurrentProgress;
	UPROPERTY(BlueprintReadOnly)
		int32 MaxProgress;
	UPROPERTY(BlueprintReadOnly)
		FName Name;
	UPROPERTY(BlueprintReadOnly)
		FName Description;
	UPROPERTY(BlueprintReadOnly)
		FName StartTaskNpc;
	UPROPERTY(BlueprintReadOnly)
		FName EndTaskNpc;
	//TODO:I don't save TArray<UTask*> here because when I create this task, I should create all Task related If I do so.
	//Otherwise When start these next tasks, nextTask of these nextTask will be none
	//found by taskmanager won't be saved

	UPROPERTY(BlueprintReadOnly)
		TArray<FName> NextTask;
	UPROPERTY(BlueprintReadOnly)
		TArray<FName> PreviousTask;

	
	//check if PreviousTask all finish
	bool CanTaskStart();
	//start task after this task finished
	void StartNextTasks();
};
