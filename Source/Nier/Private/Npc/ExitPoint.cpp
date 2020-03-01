// Fill out your copyright notice in the Description page of Project Settings.


#include "ExitPoint.h"
/*#include "Components/BoxComponent.h"
#include "NpcCharacter.h"

AExitPoint::AExitPoint()
{
	DestroyNpcBox = CreateDefaultSubobject<UBoxComponent>(TEXT("DestroyNpcBox"));
	DestroyNpcBox->SetupAttachment(RootComponent);
	DestroyNpcBox->SetCollisionObjectType(ECC_OverlapAll_Deprecated);
	FVector BoxSize = FVector(100, 100, 100);
	DestroyNpcBox->SetBoxExtent(BoxSize);

	DestroyNpcBox->OnComponentBeginOverlap.AddDynamic(this, &AExitPoint::DestroyNpc);
}

void AExitPoint::DestroyNpc(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (Cast<ANpcCharacter>(OtherActor))
	{
		Destroy(OtherActor);
	}
}*/