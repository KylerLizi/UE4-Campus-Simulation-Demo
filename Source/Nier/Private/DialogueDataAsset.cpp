// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueDataAsset.h"

FDialogueInfoRaw UDialogueDataAsset::GetDialogueInfo()
{
	FDialogueInfoRaw Raw = FDialogueInfoRaw();
	Raw.TaskName = TaskName;
	Raw.DialogueText = DialogueText;
	Raw.SourceVoice = SourceVoice;
	Raw.TargetVoice = TargetVoice;
	Raw.DialogueSound = DialogueSound;
	return Raw;
}