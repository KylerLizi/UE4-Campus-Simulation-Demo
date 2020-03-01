// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameType.h"
#include "Ability.generated.h"


//TODO:remove this enum class to a new file


UCLASS()
class NIER_API UAbility : public UObject{
	GENERATED_BODY()

public:	
	// 能力名称
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName AbilityName;

	// 能力使用的冷却事件
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CoolTime;

	// 能力2DUI图标
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UTexture2D *AbilityIcon;

	// 能力需要的能力属性点列表
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<EPlayerAttributeType, int> RequireAbilityType;

	// 能力需要的前序能力TArray
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UAbility*> ParentAbilites;


public:	
	
	/**
	 * @description: 使用能力函数
	 * @param {} 
	 * @return: bool(待修改) 使用成功返回true，否则返回false
	 */
	UFUNCTION(BlueprintImplementableEvent)
		void Use();

	/**
	 * @description: 改变能力的使用冷却时间
	 * @param {float time} 
	 * @return: void
	 */
	void ChangeCoolTime(float time);

	//待添加函数：@存档 @独档 
};
