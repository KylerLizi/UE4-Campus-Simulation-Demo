// Fill out your copyright notice in the Description page of Project Settings.


#include "NpcManager.h"
#include "Engine/DataTable.h"
#include "NpcFactory.h"
#include "NpcCharacter.h"
#include "NormalSaveGame.h"
#include "RecorderInstance.h"
#include "Engine/World.h"
#include "HAL/FileManager.h"

//get default npc asset directory path
FString str(FPaths::ProjectContentDir() + "DataDriven/Npc/");
const TCHAR* ANpcManager::DefaultNpcPath = str.GetCharArray().GetData(); 

ANpcManager::ANpcManager()
{
	NpcFactory = NewObject<UNpcFactory>(this, TEXT("NpcFactory"));
}

void ANpcManager::LoadNpcFromSlot()
{
	auto SaveSlot = Cast<URecorderInstance>(GetWorld()->GetGameInstance())->GetCurrentSaveGame();
	for (TPair<FName, FNpcInfoRaw> Info : SaveSlot->GetNpc())
	{
		UE_LOG(LogTemp, Warning, TEXT("Npc %s is load by Info"), *Info.Value.NpcName.ToString());
		ANpcCharacter* NpcCharacter = NpcFactory->SpawnNpcCharacter(Info.Value.NpcId);
		NpcList.Add(Info.Value.NpcId,NpcCharacter);
	}
}

//void ANpcManager::SaveNpcSlot(ANpcCharacter* Npc)
//{
//	auto SaveSlot = Cast<URecorderInstance>(GetWorld()->GetGameInstance())->GetCurrentSaveGame();
//	SaveSlot->SaveNpc(Npc->GetNpcInfo());
//}

void ANpcManager::SpawnAllNpcCharacter()
{
	//load saved Npc
	LoadNpcFromSlot();
	
	IFileManager& NpcFileManager = IFileManager::Get();
	if (NpcFileManager.DirectoryExists(DefaultNpcPath))
	{
		TArray<FString> NpcAssetName;
		//get all file name(NpcId) from default directory
		NpcFileManager.FindFiles(NpcAssetName, DefaultNpcPath);

		for(FString T : NpcAssetName)
		{
			FString NpcIdStr;
			FString SuffixStr;
			//split the NpcId from file name
			T.Split(".", &NpcIdStr, &SuffixStr);
			//if not exist in NpcList, produce&add new Npc
			if (!NpcList.Find(FName(*NpcIdStr)))
			{
				ANpcCharacter* NpcCharacter = NpcFactory->SpawnNpcCharacter(FName(*NpcIdStr));
				NpcList.Add(FName(*NpcIdStr), NpcCharacter);
				//SaveNpcSlot(NpcCharacter);
				NpcCharacter->SaveNpcSlot();
			}
		}
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("lxb:Npc Directory isn't Exist!"));
}
