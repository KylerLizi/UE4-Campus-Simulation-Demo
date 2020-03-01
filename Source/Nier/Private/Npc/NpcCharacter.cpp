// Fill out your copyright notice in the Description page of Project Settings.

#include "NpcCharacter.h"
#include "NierCharacter.h"
#include "Engine/World.h"
//animation
#include "Animation/AnimInstance.h"

//save game
#include "NormalSaveGame.h"
#include "RecorderInstance.h"

//level sequence
#include "Runtime/LevelSequence/Public/LevelSequence.h"
#include "Runtime/LevelSequence/Public/LevelSequenceActor.h"
#include "Runtime/MovieScene/Public/MovieSceneSequencePlayer.h"

//Components
#include "DialogueComponent.h"
#include "TaskProcessComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/SkeletalMeshComponent.h"

//for GetCharacterMovement
#include "GameFramework/CharacterMovementComponent.h"

#include "NpcDataAsset.h"
ANpcCharacter::ANpcCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	//default mesh
	/*ConstructorHelpers::FObjectFinder<USkeletalMesh> DefaultMesh(TEXT("/Game/Mannequin/Character/Mesh/SK_Mannequin"));*/
	DefaultMesh = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("/Game/Mannequin/Character/Mesh/SK_Mannequin")));
	GetMesh()->SetSkeletalMesh(DefaultMesh);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -80));

	//new TriggerBox and set properties
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(GetCapsuleComponent());
	TriggerBox->SetBoxExtent(FVector(50.f, 50.f, 100.f));
	TriggerBox->SetHiddenInGame(false);
	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	TriggerBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ANpcCharacter::BoxTriggerEvent);

	//show task state sign in the top of Npc head
	TaskSignComp = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TaskSignComp"));
	TaskSignComp->SetupAttachment(GetCapsuleComponent());
	TaskSignComp->SetText("");
	TaskSignComp->WorldSize = 100.f;
	TaskSignComp->SetRelativeLocation(FVector(0, 0, 110));
	TaskSignComp->SetRelativeRotation(FRotator(0, 90, 0));

	DialogueComp = CreateDefaultSubobject<UDialogueComponent>(TEXT("DialogueComp"));

	TaskProcessComp = CreateDefaultSubobject<UTaskProcessComponent>(TEXT("TaskProcessComp"));

	//// TODO:for stranger C++
	////lxb:Make AI rotate smoothly(avoid snapping)
	//bUseControllerRotationYaw = false;//prepare for orient rotation to movement
	///** bOrientRotationToMovement
	// * If true, smoothly rotate the Character toward the Controller's desired rotation (typically Controller->ControlRotation), using RotationRate as the rate of rotation change. Overridden by OrientRotationToMovement.
	// * Normally you will want to make sure that other settings are cleared, such as bUseControllerRotationYaw on the Character.
	// */
	//GetCharacterMovement()->bOrientRotationToMovement = true;
	///** bUseControllerDesiredRotation
	// * If true, rotate the Character toward the direction of acceleration, using RotationRate as the rate of rotation change. Overrides UseControllerDesiredRotation.
	// * Normally you will want to make sure that other settings are cleared, such as bUseControllerRotationYaw on the Character.
	// */
	// //GetCharacterMovement()->bUseControllerDesiredRotation = true;//与bOrientRotationToMovement互斥，只能选其一为True
	//float YawRotateRate = 0.f;
	//GetCharacterMovement()->RotationRate = FRotator(0, 0, YawRotateRate);
	
}

void ANpcCharacter::BeginPlay()
{
	Super::BeginPlay();

	//for BP Npc
	if(NpcInfo.NpcId != "")
		InitNpc();
	/*FTimerHandle Test_TimeHandle;
	GetWorld()->GetTimerManager().SetTimer(Test_TimeHandle, this, &ANpcCharacter::TestInit, 2.f, false, 0);*/
}

void ANpcCharacter::InitNpc()
{
	//set info
	if (NpcAsset != NULL)
		SetNpcInfo(NpcAsset->GetNpcInfo());

	//set mesh
	if (NpcInfo.NpcMesh)
		GetMesh()->SetSkeletalMesh(Cast<USkeletalMesh>(NpcInfo.NpcMesh.Get()));

	//set init location
	SetActorLocation(NpcInfo.NpcInitLocation);

	//set animation class
	if (NpcInfo.NpcAnimClass)
	{
		//GetMesh()->SetAnimInstanceClass(LoadClass<UAnimInstance>(NULL, NpcInfo.NpcAnimClass->GetPathName(NULL).GetCharArray().GetData()));
		GetMesh()->SetAnimInstanceClass(NpcInfo.NpcAnimClass);
	}

	//set Dialogue
	DialogueComp->SetDialogueInfoFromAsset(NpcInfo.NpcId);

	//set Npc Task
	TaskProcessComp->SetNpcTask(NpcInfo.NpcTaskNumber);

	TaskSignComp->SetText(TaskProcessComp->GetTaskStateSign());
}

void ANpcCharacter::SaveNpcSlot()
{
	auto SaveSlot = Cast<URecorderInstance>(GetWorld()->GetGameInstance())->GetCurrentSaveGame();
	SaveSlot->SaveNpc(NpcInfo);
}

void ANpcCharacter::BoxTriggerEvent(UPrimitiveComponent *OverlappedComponent,
									AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex,
									bool bFromSweep, const FHitResult &SweepResult)
{
	if (Cast<ANierCharacter>(OtherActor))
	{
		TaskProcessComp->UpdateNpcTaskState(NpcInfo.NpcId);
		TaskSignComp->SetText(TaskProcessComp->GetTaskStateSign());
		DialogueComp->UpdateDialogueWaveText(TaskProcessComp->GetNpcTask());

		SaveNpcSlot();
		UE_LOG(LogTemp, Warning, TEXT("lxb: Overlapped %s!"), *OtherActor->GetName());
	}
}

void ANpcCharacter::TaskStateChanged_Implementation(const UTask *Task)
{
	if (Task == TaskProcessComp->GetNpcTask())
	{
		TaskProcessComp->UpdateNpcTaskState(NpcInfo.NpcId);
		TaskSignComp->SetText(TaskProcessComp->GetTaskStateSign());
	}
}