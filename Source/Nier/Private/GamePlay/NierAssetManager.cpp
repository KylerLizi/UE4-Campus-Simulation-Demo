// Fill out your copyright notice in the Description page of Project Settings.


#include "NierAssetManager.h"
#include "Engine.h"


UObject* UNierAssetManager::LoadObjectByStaticPath(FString Path) {
	return Cast<UObject>(StaticLoadObject(UObject::StaticClass(), nullptr, *Path));
}

void UNierAssetManager::AsyncLoadObjectByStaticPath(FString Path, TFunctionRef<void(FSoftObjectPtr)> Callback)
{
	FSoftObjectPath ObjPath= FSoftObjectPath(Path);
	FStreamableDelegate FinishDelegate;
	CommanStream.RequestAsyncLoad(ObjPath, [ObjPath, Callback]()->void{
		FSoftObjectPtr Ptr = FSoftObjectPtr(ObjPath);
		Callback(Ptr);
	});
}

UNierAssetManager& UNierAssetManager::Get() {
	UNierAssetManager* Singleton = Cast<UNierAssetManager>(GEngine->AssetManager);

	if (Singleton)
	{
		return *Singleton;
	}
	else
	{
		UE_LOG(LogTemp, Fatal, TEXT("Cannot use AssetManager if no AssetManagerClassName is defined!"));
		return *NewObject<UNierAssetManager>(); // never calls this
	}
}