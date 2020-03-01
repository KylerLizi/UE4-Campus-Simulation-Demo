// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskManager.h"
#include "Task.h"
#include "Engine/World.h"
#include "RecorderInstance.h"
#include "NormalSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "MainHUD.h"
#include "NierAssetManager.h"
#include "TaskDataAsset.h"


const FString ATaskManager::DefaultTaskPath = "/Game/DataDriven/Task/";

int32 ATaskManager::AddTask(UTask* Task) {
	if (Task!=nullptr && !IsInPlayerTaskList(Task)) {
		int32 Index= PlayerTaskList.Add(Task);
		Task->Receive();
		return Index;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Task Already In Tasklist or Task is null"));
		return -1;
	}
}

int32 ATaskManager::DeleteTask(UTask* Task)
{
	if (IsInPlayerTaskList(Task)) {
		return PlayerTaskList.Remove(Task);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Task Not Found"));
		return -1;
	}
}


void ATaskManager::Initial(UDataTable * Table)
{
	LoadPlayerTask();
}

void ATaskManager::AddTaskObserver(ITaskObserver * TaskObserver)
{
	OnTaskChange.AddRaw(TaskObserver, &ITaskObserver::TaskStateChanged_Implementation);
}


void ATaskManager::AddTaskObserver(const TScriptInterface<ITaskObserver>& TaskObserver)
{
	UObject* obj =  TaskObserver.GetObject();
	if (obj->GetClass()->ImplementsInterface(UTaskObserver::StaticClass())) {
		OnTaskChange.AddUFunction(obj, "TaskStateChanged");
	}
}

UTask * ATaskManager::ProduceTask(FName TaskNumber)
{
	auto TaskPtr= AllProducedTask.Find(TaskNumber);
	if (TaskPtr) {
		return *TaskPtr;
	}else{
		UTask* Task = nullptr;
		UTaskDataAsset* TaskData = Cast<UTaskDataAsset>(UNierAssetManager::Get().LoadObjectByStaticPath(GetTaskDataAssetPath(TaskNumber)));
		if (TaskData) {
			Task = NewObject<UTask>(this, TaskData->TaskClass.LoadSynchronous());
			Task->SetInfo(TaskData);
			AllProducedTask.Add(TaskNumber, Task);
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Not Find TaskData in %s"),*(ATaskManager::DefaultTaskPath));
		}
		return Task;
	}
}

const UTaskDataAsset* ATaskManager::GetTaskInfo(FName TaskNumber)
{
	return Cast<UTaskDataAsset>(UNierAssetManager::Get().LoadObjectByStaticPath(GetTaskDataAssetPath(TaskNumber)));
}

void ATaskManager::BeginPlay()
{
	Super::BeginPlay();
}

void ATaskManager::LoadPlayerTask()
{
	auto SaveSlot = Cast<URecorderInstance>(GetWorld()->GetGameInstance())->GetCurrentSaveGame();
	if (SaveSlot)
	{
		UE_LOG(LogTemp, Warning, TEXT("Task %d "), SaveSlot->GetTask().Num());
		for (TPair<FName, FTaskInfoRaw> Info : SaveSlot->GetTask()) {
			UE_LOG(LogTemp, Warning, TEXT("Task %s is load by Info"), *Info.Value.Name.ToString());
			UTask* Task = NewObject<UTask>(this);
			Task->SetInfo(Info.Value);
			AllProducedTask.Add(Info.Key, Task);
			if (Info.Value.TaskState == ETaskState::Received || Info.Value.TaskState == ETaskState::Finished) {
				PlayerTaskList.Add(Task);
			}
		}
		Cast<AMainHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD())->TaskListInitFinsih();
	}
}

void ATaskManager::SavePlayerTask(UTask* Task)
{
	auto SaveSlot = Cast<URecorderInstance>(GetWorld()->GetGameInstance())->GetCurrentSaveGame();
	SaveSlot->SaveTask(Task->GetTaskInfoRaw());
}

FString ATaskManager::GetTaskDataAssetPath(FName TaskNumber)
{
	return ATaskManager::DefaultTaskPath + TaskNumber.ToString() + "." + TaskNumber.ToString();
}

//void ATaskManager::NotifyTaskChanged(TArray<UTask*> Tasks)
//{
//	for (UTask* T : Tasks) {
//		auto InfoRaw = GetTaskInfo_Internal(T->GetNumber());
//		if (InfoRaw != nullptr) {
//			T->UpdateInfoRaw(*InfoRaw);
//		}
//	}
//	TaskChangeDelegate.Broadcast(Tasks);
//}

void ATaskManager::NotifyTaskChanged(UTask* Task)
{
	SavePlayerTask(Task);
	OnTaskChange.Broadcast(Task);
}
