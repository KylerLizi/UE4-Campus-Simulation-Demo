// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NpcFactory.generated.h"

/**
 *
 */
UCLASS()
class NIER_API UNpcFactory : public UObject
{
	GENERATED_BODY()

public:
	UNpcFactory();

	FString GetNpcAssetPath(FName NpcId);
	/**
	 * @description: 根据表格NpcId获取数据来生产Npc实例并返回
	 * @param {FName NpcId}
	 * @return: class ANpcCharacter*
	 */
	class ANpcCharacter* SpawnNpcCharacter(FName NpcId);

private:
	static const FString DefaultNpcPath;
	//判断表格结构正确的变量
	UStruct* NpcTableRaw;
};
