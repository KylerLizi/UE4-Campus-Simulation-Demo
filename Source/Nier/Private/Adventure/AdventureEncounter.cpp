// Fill out your copyright notice in the Description page of Project Settings.


#include "AdventureEncounter.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "FContainerInfo.h"
#include "FAdventureInfo.h"
#include "NierGameMode.h"

// Sets default values
AAdventureEncounter::AAdventureEncounter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Encounter = CreateDefaultSubobject<UBoxComponent>(TEXT("Encounter"));
	RootComponent = Encounter;
	Encounter->OnComponentBeginOverlap.AddDynamic(this, &AAdventureEncounter::OpenAdventure);
	ContainerInfo = TSharedPtr<FContainerInfo>(new FContainerInfo("12",new FTaskAdvInfo("12","1")));

}

// Called when the game starts or when spawned
void AAdventureEncounter::BeginPlay()
{
	Super::BeginPlay();
}

void AAdventureEncounter::OpenAdventure(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult)
{
	ANierGameMode* Mode = Cast<ANierGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	AAdventureManager* Manager= Mode->GetAdventureManager();
	
	UAdventureObject* Adv = nullptr;
	Adv = ContainerInfo.Get()->GetAdvInfo()->GetAdventureByInfo(Mode);
	Manager->StartAdventure(Adv);
}

void AAdventureEncounter::PlayAdventure()
{
}

TSharedRef<FContainerInfo> AAdventureEncounter::GetContainerInfo() const
{
	return ContainerInfo.ToSharedRef();
}

// Called every frame
void AAdventureEncounter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

