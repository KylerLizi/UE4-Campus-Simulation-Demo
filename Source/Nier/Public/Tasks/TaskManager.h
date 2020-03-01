// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "TaskObserver.h"
#include "TaskManager.generated.h"


class UTask;

//DECLARE_MULTICAST_DELEGATE_OneParam(FTaskChangeDelegate,TArray<UTask*>)
DECLARE_MULTICAST_DELEGATE_OneParam(FTaskChangeDelegate,const UTask*)

/**
 * 
 */
UCLASS()
class NIER_API ATaskManager : public AInfo
{
	GENERATED_BODY()

	//TODO: When task state change ,where shall we save it?
public:
	static const FString DefaultTaskPath;

	/*add a task to player's taskList
	@return -1 if falied
	*/
	int32 AddTask(UTask* Task);

	/*delete a task from player's taskList
	@return - 1 if falied
	*/
	int32 DeleteTask(UTask* Task);

	//Register Task Observer to listen changes of TaskList in cpp
	void AddTaskObserver(ITaskObserver* TaskObserver);

	/*
	produce a task by task number
	@return will be nullptr if not find in task table
	*/
	UTask* ProduceTask(FName TaskNumber);

	//Notify TaskManager Task has changed, should Only called by UTask
	/*void NotifyTaskChanged(TArray<UTask*> Tasks);*/
	void NotifyTaskChanged(UTask* Task);

	UFUNCTION(BlueprintCallable, Category = "TaskManager")
		bool IsInPlayerTaskList(UTask* Task) { return PlayerTaskList.Contains(Task); };

	//Load (if necessary) TaskDataAsset and return 
	const class UTaskDataAsset* GetTaskInfo(FName TaskNumber);

	UFUNCTION(BlueprintCallable)
		void Initial(class UDataTable* Table);

	//Register Task Observer to listen changes of TaskList in blueprints
	UFUNCTION(BlueprintCallable, Category = "Register")
		void AddTaskObserver(const TScriptInterface<ITaskObserver>& TaskObserver);

	UFUNCTION(BlueprintCallable)
	const TArray<UTask*>& GetPlayerTaskList() { return PlayerTaskList; };

protected:
	void BeginPlay() override;

private:
	//All tasks' info table
	class UDataTable* TaskTable;

	//player's current tasks
	TArray<UTask*> PlayerTaskList;

	TMap<FName, UTask*> AllProducedTask;

	FTaskChangeDelegate OnTaskChange;

	void LoadPlayerTask();
	void SavePlayerTask(UTask* Task);
	FString GetTaskDataAssetPath(FName TaskNumber);
};
