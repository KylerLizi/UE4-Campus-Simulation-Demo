// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MainController.h"
#include "NierCharacter.h"
#include "AbilityTree.h"

ANierCharacter* AMainController::GetPlayerCharacter() {
	return Cast<ANierCharacter>(GetCharacter());
}

TMap<EPlayerAttributeType, int32> AMainController::GetPlayerAttributeNumber()
{
	 return AbilityTree->PlayerAttribute; 
}

void AMainController::UpdatePlayerAttributeNumber(EPlayerAttributeType AttributeType, int32 DeltaNumber)
{
	AbilityTree->UpdatePlayerAttribute(AttributeType, DeltaNumber);
	OnAttributeChange.Broadcast(AttributeType, DeltaNumber);
}

void AMainController::RefreashPlayerAttributeNumber(TMap<EPlayerAttributeType, int32> Attributes)
{
	AbilityTree->RefreshAbilities(Attributes);
}
