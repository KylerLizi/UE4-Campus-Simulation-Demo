// Fill out your copyright notice in the Description page of Project Settings.


#include "Task.h"
#include "Kismet/GameplayStatics.h"
#include "NierGameMode.h"
#include "Engine/World.h"
#include "TaskDataAsset.h"
#include "TaskManager.h"
#include "Kismet/KismetSystemLibrary.h"

const FString UTask::BaseTaskTablePath="DataTable'/Game/DataDriven/TaskTable.TaskTable'";

void UTask::Receive()
{
	TaskState = ETaskState::Received;
	ReceiveBP();
	NotifyTaskManager();
}

void UTask::Progress(int32 DeltaProgress)
{
	
	if (TaskState == ETaskState::Received) {
		CurrentProgress += DeltaProgress;
		ProgressBP();
		if (CurrentProgress == MaxProgress) {
			Finish();
		}
		else {
			NotifyTaskManager();
		}
	}
}

void UTask::Finish()
{
	TaskState = ETaskState::Finished;
	FinishBP();
	NotifyTaskManager();
	StartNextTasks();
}
void UTask::End()
{
	TaskState = ETaskState::AlreadyEnd;
	NotifyTaskManager();
}

void UTask::SetInfo(UTaskDataAsset* DataInfo)
{
	SetInfo(DataInfo->GetTaskInfo());
}

void UTask::SetInfo(FTaskInfoRaw DataInfo)
{
	TaskState = DataInfo.TaskState;
	TaskNumber = DataInfo.TaskNumber;
	CurrentProgress = DataInfo.CurrentProgress;
	MaxProgress = DataInfo.MaxProgress;
	Name = DataInfo.Name;
	Description = DataInfo.Description;
	StartTaskNpc = DataInfo.StartTaskNpc;
	EndTaskNpc = DataInfo.EndTaskNpc;
}

FTaskInfoRaw UTask::GetTaskInfoRaw()
{
	FTaskInfoRaw Raw = FTaskInfoRaw();
	Raw.TaskState =TaskState;
	Raw.TaskNumber = TaskNumber;
	Raw.CurrentProgress = CurrentProgress;
	Raw.MaxProgress = MaxProgress;
	Raw.Name = Name;
	Raw.Description = Description;
	Raw.PreviousTaskNumber = PreviousTask;
	Raw.NextTaskNumber = NextTask;
	Raw.StartTaskNpc = StartTaskNpc;
	Raw.EndTaskNpc = EndTaskNpc;
	return Raw;
}

APlayerController * UTask::GetPlayerController()
{
	return GetWorld()->GetFirstPlayerController();
}

void UTask::NotifyTaskManager()
{
	/*TArray<UTask*> ThisTask;
	ThisTask.Add(this);*/
	auto Mode= Cast<ANierGameMode> (UGameplayStatics::GetGameMode(GetOuter()));
	/*Mode->GetTaskManager()->NotifyTaskChanged(ThisTask);*/
	Mode->GetTaskManager()->NotifyTaskChanged(this);
}

bool UTask::CanTaskStart()
{
	auto TaskManager = Cast<ANierGameMode>(UGameplayStatics::GetGameMode(GetOuter()))->GetTaskManager();
	for (FName T : PreviousTask) {
		if (TaskManager->GetTaskInfo(T)->TaskState != ETaskState::Finished) {
			return false;
		}
	}
	return true;
}

void UTask::StartNextTasks()
{
	auto TaskManager = Cast<ANierGameMode>(UGameplayStatics::GetGameMode(GetOuter()))->GetTaskManager();
	for (FName T : NextTask) {
		TaskManager->ProduceTask(T)->Start();
	}
}

void UTask::Start() {
	if (TaskState == ETaskState::NeverTrigger && CanTaskStart()) {
		TaskState = ETaskState::NotReceive;
		StartBP();
		NotifyTaskManager();
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Only NeverTrigger Task Can Start"));
	}
	
}