// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FDialogueInfo.h"
#include "DialogueComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NIER_API UDialogueComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UDialogueComponent();

protected:
	//Dialogue Object
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
		class UDialogueWave* NpcDialogueWave;

	//DialogueInfoRaw
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
		FName TaskName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
		TMap<ETaskState, FString> DialogueText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
		class UDialogueVoice* SourceVoice;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
		class UDialogueVoice* TargetVoice;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
		class USoundWave* DialogueSound;

private:
	//dialogue data asset path
	static const FString DefaultDialoguePath;

	FString DefaultSpokenText;
	
public:	
	UFUNCTION()
		void UpdateDialogueWaveText(class UTask* Task);

	void SetDialogueInfoFromAsset(FName NpcId);

protected:
	virtual void BeginPlay() override;

	FString GetDialogueAssetPath(FName NpcId);

	void InitDialogue();
};
