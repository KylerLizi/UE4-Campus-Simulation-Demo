// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityTree.h"
#include "Kismet/GameplayStatics.h"
#include "RecorderInstance.h"


void UAbilityTree::AddAbility(class UAbility* Ability)
{
}

void UAbilityTree::PrintAbilityInfo()
{
	for (TMap<EPlayerAttributeType, int>::TConstIterator iter(PlayerAttribute); iter; ++iter)
	{
		UE_LOG(LogTemp, Warning, TEXT("--- key:%d, value222:%s "), iter->Key, iter->Value);
	}
}

void UAbilityTree::UpdatePlayerAttribute(EPlayerAttributeType AttributeType, int32 DeltaNumber)
{
	PlayerAttribute[AttributeType] += DeltaNumber;
	Cast<URecorderInstance>(UGameplayStatics::GetGameInstance(GetOuter()));
}


void UAbilityTree::RefreshAbilities(TMap<EPlayerAttributeType, int32> Attributes)
{
	for (TMap<EPlayerAttributeType, int32>::TConstIterator iter(Attributes); iter; ++iter)
	{
		PlayerAttribute[iter->Key] += iter->Value;
	}
}
