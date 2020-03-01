// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskDataAsset.h"

FTaskInfoRaw UTaskDataAsset::GetTaskInfo()
{
	FTaskInfoRaw Raw = FTaskInfoRaw();
	Raw.TaskState = TaskState;
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
