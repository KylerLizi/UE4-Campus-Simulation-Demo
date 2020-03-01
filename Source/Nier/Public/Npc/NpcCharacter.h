// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FNpcInfo.h"
#include "TaskObserver.h"
#include "NpcCharacter.generated.h"

UCLASS()
class NIER_API ANpcCharacter : public ACharacter, public ITaskObserver
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
		FNpcInfoRaw NpcInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		class UBoxComponent *TriggerBox; //respond to player collision

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
		class UTextRenderComponent *TaskSignComp;//show task state sign

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DialogueComp")
		class UDialogueComponent *DialogueComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TaskProcessComp")
		class UTaskProcessComponent *TaskProcessComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DialogueComp")
		class ALevelSequenceActor *AnimSeqActor;

private:
	USkeletalMesh *DefaultMesh;

public:
	ANpcCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
		class UNpcDataAsset *NpcAsset;

	/**
	 * description: 初始化Npc参数
	 * @param {}
	 * @return: void
	 */
	void InitNpc();

	/**
	 * description: 更新NpcInfo结构体内容
	 * @param {FNpcInfoRaw _NpcInfo}
	 * @return: void
	 */
	void SetNpcInfo(FNpcInfoRaw _NpcInfo) { this->NpcInfo = _NpcInfo; };

	/**
	 * description: 返回NpcInfo结构体内容
	 * @param {}
	 * @return: FNpcInfoRaw
	 */
	FNpcInfoRaw GetNpcInfo() { return NpcInfo; };

	/**
	 * description: 检测Npc与主角交互
	 * @param {UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult}
	 * @return: void
	 */
	UFUNCTION(BlueprintCallable)
	void BoxTriggerEvent(UPrimitiveComponent *OverlappedComponent,
						 AActor *OtherActor, UPrimitiveComponent *OtherComp,
						 int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	/**
	 * description: 保存Npc的信息，只需加载一次
	*/
	void SaveNpcSlot();

protected:

	virtual void BeginPlay() override;

	//UFUNCTION()
	//void UpdateNpcTaskState(bool OnlyIcon);

	/** broadcast to npc task the state is changed */
	void TaskStateChanged_Implementation(const class UTask *Task) override;
};
