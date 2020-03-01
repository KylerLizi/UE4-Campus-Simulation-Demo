// Fill out your copyright notice in the Description page of Project Settings.


#include "NpcFactory.h"
#include "Engine/DataTable.h"
#include "NpcCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/Public/UnrealEngine.h"
//#include "Engine/World.h"
#include "NpcDataAsset.h"
#include "NierAssetManager.h"

const FString UNpcFactory::DefaultNpcPath = "/Game/DataDriven/Npc/";

UNpcFactory::UNpcFactory()
{
	NpcTableRaw = FNpcInfoRaw::StaticStruct();
}

FString UNpcFactory::GetNpcAssetPath(FName NpcId)
{
	return UNpcFactory::DefaultNpcPath + NpcId.ToString() + "." + NpcId.ToString();
}

ANpcCharacter * UNpcFactory::SpawnNpcCharacter(FName NpcId)
{
	ANpcCharacter* ProducedNpc = nullptr;
	UNpcDataAsset* NpcDataAsset = Cast<UNpcDataAsset>(UNierAssetManager::Get().LoadObjectByStaticPath(GetNpcAssetPath(NpcId)));
	if (NpcDataAsset) {
		//initialize spawn parameters
		FVector Location = NpcDataAsset->NpcInitLocation;
		FRotator Rotator = FRotator(0.f, 0.f, 0.f);
		FActorSpawnParameters NpcSpawnParameters;
		NpcSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		
		//spawn Npc
		ProducedNpc = GetWorld()->SpawnActor<ANpcCharacter>(ANpcCharacter::StaticClass(), Location, Rotator,NpcSpawnParameters);
		ProducedNpc->NpcAsset = NpcDataAsset;
		ProducedNpc->InitNpc();

		UE_LOG(LogTemp, Warning, TEXT("Successed Produce NPC:%s"), *NpcDataAsset->NpcName.ToString());
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Not Find NpcData in %s!"), *(UNpcFactory::DefaultNpcPath));

	return ProducedNpc;
}
