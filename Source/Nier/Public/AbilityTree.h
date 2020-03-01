// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameType.h"
#include "AbilityTree.generated.h"

UCLASS()
class NIER_API UAbilityTree : public UObject
{
	GENERATED_BODY()
	
public:	
	// 当前玩家的能力属性点TMap
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<EPlayerAttributeType, int32> PlayerAttribute;

protected:
	// 玩家已学习的技能TArray
	UPROPERTY()
		TArray<class UAbility*> LearnedAbility;

public:	

	/**
	 * @description: 学习技能
	 * @param {AAbility abi} 
	 * @return: 
	 */
	void AddAbility(UAbility* Ability);

	void PrintAbilityInfo();

	/**
	 * Change Player Attribute
	 * @param AttributeType 属性类型
	 * @param DeltaNumber 变化数值
	 */
	void UpdatePlayerAttribute(EPlayerAttributeType AttributeType, int32 DeltaNumber);

	/**
	 * @description: 更改玩家多种能力属性点
	 * @param {TMap<EAbilityType, int>} 
	 * @return: 
	 */
	void RefreshAbilities(TMap<EPlayerAttributeType, int32> Attributes);
};
