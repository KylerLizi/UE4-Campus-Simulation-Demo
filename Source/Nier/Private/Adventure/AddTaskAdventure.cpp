// Fill out your copyright notice in the Description page of Project Settings.


#include "AddTaskAdventure.h"
#include "Kismet/GameplayStatics.h"
#include "NierGameMode.h"
#include "TaskManager.h"


void UAddTaskAdventure::Play() {
	UObject* MOuter = GetOuter();
	if (ensure(MOuter)) {
		ANierGameMode* Mode = Cast<ANierGameMode>(UGameplayStatics::GetGameMode(MOuter));
		auto TaskManager=Mode->GetTaskManager();
		TaskManager->AddTask(TaskManager->ProduceTask(TaskNumber));
	}
	
}

void UAddTaskAdventure::SetInfo(FName AdventureNumber, FName TaskNumber)
{
	this->AdventureNumber = AdventureNumber;
	this->TaskNumber = TaskNumber;
}


