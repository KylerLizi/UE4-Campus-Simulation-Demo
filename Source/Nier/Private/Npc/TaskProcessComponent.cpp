// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskProcessComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NierGameMode.h"
#include "Task.h"
#include "TaskManager.h"

// Sets default values for this component's properties
UTaskProcessComponent::UTaskProcessComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	//set return state's sign string
	TaskStateSign.Add(ETaskState::NeverTrigger, "0");
	TaskStateSign.Add(ETaskState::NotReceive, "?");
	TaskStateSign.Add(ETaskState::Received, "...");
	TaskStateSign.Add(ETaskState::Finished, "!");
	TaskStateSign.Add(ETaskState::AlreadyEnd, "1");

}


// Called when the game starts
void UTaskProcessComponent::BeginPlay()
{
	Super::BeginPlay();

	auto MyMode = Cast<ANierGameMode>(UGameplayStatics::GetGameMode(GetOuter()));
	TaskManager = MyMode->GetTaskManager();
	
}

void UTaskProcessComponent::SetNpcTask(FName NpcTaskNumber)
{
	//get task from TaskManager
	NpcTask = TaskManager->ProduceTask(NpcTaskNumber);
	TaskManager->AddTaskObserver(this);
}

void UTaskProcessComponent::UpdateNpcTaskState(FName NpcId)
{
	//only update relative npc
	switch (NpcTask->GetState())
	{
	case ETaskState::NeverTrigger:
		if (NpcId == NpcTask->GetStartTaskNpc())
			NpcTask->Start();
		break;
	case ETaskState::NotReceive:
		if (NpcId == NpcTask->GetStartTaskNpc())
			TaskManager->AddTask(NpcTask);
		break;
	case ETaskState::Received:
		if (NpcId == NpcTask->GetEndTaskNpc())
			//if (TaskManager->IsInPlayerTaskList(NpcTask))
			NpcTask->Finish();
		break;
	case ETaskState::Finished:
		if (NpcId == NpcTask->GetEndTaskNpc())
			if (TaskManager->IsInPlayerTaskList(NpcTask))
			{
				NpcTask->End();
				//TODO: TaskManager->DeleteTask(NpcTask);
			}	
		break;
	case ETaskState::AlreadyEnd:
		break;
	default:
		break;
	}
}

FString UTaskProcessComponent::GetTaskStateSign()
{
	return *TaskStateSign.Find(NpcTask->GetState());
}

