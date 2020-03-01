// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Task.h"
#include "DialogueDataAsset.h"
#include "NierAssetManager.h"
#include "Runtime/Engine/Classes/Sound/DialogueWave.h"
#include "Runtime/Engine/Classes/Sound/DialogueVoice.h"

const FString UDialogueComponent::DefaultDialoguePath = "/Game/DataDriven/Dialogue/";

UDialogueComponent::UDialogueComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	DefaultSpokenText = "Hi!";
}


void UDialogueComponent::BeginPlay()
{
	Super::BeginPlay();

}

FString UDialogueComponent::GetDialogueAssetPath(FName NpcId)
{
	return UDialogueComponent::DefaultDialoguePath + NpcId.ToString() + "." + NpcId.ToString();
}

void UDialogueComponent::InitDialogue()
{
	//new a dialogue wave object
	NpcDialogueWave = NewObject<UDialogueWave>(this, TEXT("NpcDialogueWave"));

	//set FDialogueContextMapping parameter
	const int DefaultArrayElementIndex = 0;
	FDialogueContextMapping DiaContextMap;
	DiaContextMap.Context.Speaker = SourceVoice;
	DiaContextMap.Context.Targets[DefaultArrayElementIndex] = TargetVoice;
	DiaContextMap.LocalizationKeyFormat = "{ContextHash}";
	DiaContextMap.SoundWave = DialogueSound;

	NpcDialogueWave->ContextMappings[DefaultArrayElementIndex] = DiaContextMap;
	NpcDialogueWave->bOverride_SubtitleOverride = 1;
	NpcDialogueWave->SpokenText = DefaultSpokenText;
	NpcDialogueWave->SubtitleOverride = NpcDialogueWave->SpokenText;
}

void UDialogueComponent::SetDialogueInfoFromAsset(FName NpcId)
{
	UDialogueDataAsset * DialogueAsset = Cast<UDialogueDataAsset>(UNierAssetManager::Get().LoadObjectByStaticPath(GetDialogueAssetPath(NpcId)));
	if (DialogueAsset)
	{
		//set part parameters
		TaskName = DialogueAsset->TaskName;
		DialogueText = DialogueAsset->DialogueText;
		SourceVoice = Cast<UDialogueVoice>(DialogueAsset->SourceVoice.Get());
		TargetVoice = Cast<UDialogueVoice>(DialogueAsset->TargetVoice.Get());
		DialogueSound = Cast<USoundWave>(DialogueAsset->DialogueSound.Get());
		//set left parameters
		InitDialogue();
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("lxb: Dialogue Asset %s isn't Exist!"), *NpcId.ToString());
}


void UDialogueComponent::UpdateDialogueWaveText(UTask* Task)
{
	if (Task->GetState() == ETaskState::NotReceive || Task->GetState() == ETaskState::Received || Task->GetState() == ETaskState::Finished)
	{//find text from map
		FString NpcSpokenText = DialogueText.FindRef(Task->GetState());
		NpcDialogueWave->SpokenText = NpcSpokenText;
		NpcDialogueWave->SubtitleOverride = NpcSpokenText;

		//update & play dialogue wave
		const int DefaultArrayElementIndex = 0;
		NpcDialogueWave->UpdateContext(NpcDialogueWave->ContextMappings[DefaultArrayElementIndex], DialogueSound
			, NpcDialogueWave->ContextMappings[DefaultArrayElementIndex].Context.Speaker
			, NpcDialogueWave->ContextMappings[DefaultArrayElementIndex].Context.Targets);
		if(!NpcSpokenText.Equals(""))
			UGameplayStatics::PlayDialogueAtLocation(GetOwner(), NpcDialogueWave, NpcDialogueWave->ContextMappings[DefaultArrayElementIndex].Context, GetOwner()->GetActorLocation());
	}
}