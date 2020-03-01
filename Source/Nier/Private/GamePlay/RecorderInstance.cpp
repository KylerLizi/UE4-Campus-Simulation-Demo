// Fill out your copyright notice in the Description page of Project Settings.


#include "RecorderInstance.h"
#include "Kismet/GameplayStatics.h"
#include "NormalSaveGame.h"
#include "Paths.h"
#include "FileHelper.h"
#include "PlatformFilemanager.h"
#include "Kismet/KismetSystemLibrary.h"


UDataTable * URecorderInstance::AsyncLoadDataTableByPath(UObject * WorldContext, FString Path)
{
	FStreamableDelegate Delegate;
	FSoftObjectPath ObjPath = FSoftObjectPath(Path);
	FSoftObjectPtr Ptr = FSoftObjectPtr(ObjPath);
	if (!Ptr.Get()) {
		UKismetSystemLibrary::PrintString(WorldContext, "not load");
	}
	Delegate.BindUObject(this, &URecorderInstance::LoadTestFinish,ObjPath,WorldContext);

	CommanStream.RequestAsyncLoad(FSoftObjectPath(Path), [ObjPath,WorldContext]()->void {
		TSoftObjectPtr<UDataTable> TablePtr = TSoftObjectPtr<UDataTable>(ObjPath);
		UDataTable* Table = TablePtr.Get();
		if (Table) {
			UKismetSystemLibrary::PrintString(WorldContext, "Load");
		}
	});
	return nullptr;
}

void URecorderInstance::LoadTestFinish(FSoftObjectPath Path,UObject* WorldContext)
{
	TSoftObjectPtr<UDataTable> TablePtr = TSoftObjectPtr<UDataTable>(Path);
	UDataTable* Table= TablePtr.Get();
	if (Table) {
		UKismetSystemLibrary::PrintString(WorldContext,"Load");
	}
}



void URecorderInstance::SaveAllGame(const FString& SlotName, const int32 UserIndex,FString LevelName)
{
	UE_LOG(LogTemp,Warning, TEXT("CurrentSaveGame TaskListInfo is %d before save"), CurrentSaveGame->GetTask().Num());
	UE_LOG(LogTemp, Warning, TEXT("CurrentSaveGame Npc is %d before save"), CurrentSaveGame->GetNpc().Num());
	if (CurrentSaveGame != nullptr) {
		CurrentSaveGame->SaveMapName(LevelName);
		WriteToDisk(SlotName,  UserIndex);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("CurrentSaveGame is null"));
	}
}

TArray<FString> URecorderInstance::GetAllSlotName()
{
	IPlatformFile& FileManager= FPlatformFileManager::Get().GetPlatformFile();
	TArray<FString> SlotNames;
	FileManager.FindFiles(SlotNames, *(FPaths::ProjectSavedDir()+"SaveGames/"), TEXT("sav"));
	const int32 DefaultLen = FString("SaveGames/").Len();
	for (FString& SlotName : SlotNames) {
		int32 Start= SlotName.Find("SaveGames/")+ DefaultLen;
		int32 End = SlotName.Len()-1;
		SlotName = SlotName.Mid(Start, End);
	}
	return SlotNames;
}

UNormalSaveGame * URecorderInstance::GetCurrentSaveGame()
{
	if (CurrentSaveGame==nullptr) {
		UE_LOG(LogTemp, Error, TEXT("CurrentSaveGame is null before get it!"));
		CurrentSaveGame = Cast<UNormalSaveGame>(UGameplayStatics::CreateSaveGameObject(UNormalSaveGame::StaticClass()));
	}
	return CurrentSaveGame;
}

bool URecorderInstance::LoadOrCreateSlot(const FString& SlotName,const int32 UserIndex, FOpenLevelDelegate Callback)
{
	CurrentSaveGame = nullptr;
	bool result = false;
	if (UGameplayStatics::DoesSaveGameExist(SlotName, UserIndex)) {
		USaveGame* SaveGameSlot = UGameplayStatics::LoadGameFromSlot(SlotName, UserIndex);
		CurrentSaveGame = Cast<UNormalSaveGame>(SaveGameSlot);
		UE_LOG(LogTemp, Warning, TEXT("CurrentSave TaskInfo number is %d"), CurrentSaveGame->GetTask().Num());
		UE_LOG(LogTemp, Warning, TEXT("CurrentSave Npc number is %d"), CurrentSaveGame->GetNpc().Num());
		return true;
	}
	else {
		CurrentSaveGame = Cast<UNormalSaveGame>(UGameplayStatics::CreateSaveGameObject(UNormalSaveGame::StaticClass()));
	}
	Callback.ExecuteIfBound();
	return result;
}

void URecorderInstance::SavePlayerAttribute(EPlayerAttributeType AttributeType, int32 Number)
{
	CurrentSaveGame->SavePlayerAttribute(AttributeType, Number);
}

void URecorderInstance::WriteToDisk(const FString& SlotName, const int32 UserIndex)
{
	UGameplayStatics::SaveGameToSlot(CurrentSaveGame, SlotName, UserIndex);
}

