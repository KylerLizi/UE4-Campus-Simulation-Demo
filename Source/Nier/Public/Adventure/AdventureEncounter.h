// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AdventureContainer.h"
#include "AdventureEncounter.generated.h"


/*
Collider Trigger of Adventure
*/

UCLASS()
class NIER_API AAdventureEncounter : public AActor,public IAdventureContainer
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAdventureEncounter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* Encounter;

	UFUNCTION(BlueprintCallable)
		void OpenAdventure(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void PlayAdventure() override;
	TSharedRef<FContainerInfo> GetContainerInfo() const override;

protected:
	//Infomation about this Container
	 TSharedPtr<class FContainerInfo> ContainerInfo;
};
