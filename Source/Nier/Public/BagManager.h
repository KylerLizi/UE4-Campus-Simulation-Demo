// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BagItem.h"
#include "BagManager.generated.h"

UCLASS()
class NIER_API ABagManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABagManager();
	// 已获得背包列表 TArray<ABagItem*>
	UPROPERTY(EditAnywhere)
		TArray<ABagItem*> BagIemArray;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/**
	 * @description: 获取物品，将物品添加进物品背包栏中
	 * @param {ABagItem* item} 
	 * @return: void
	 */
	void AcquireItem(ABagItem* item);

	/**
	 * @description: 删除物品,如果成功则返回true，否则返回false
	 * @param {ABagItem* item} 
	 * @return: bool（待修改）
	 */
	void DeleteItem(ABagItem* item);

	/**
	 * @description: 使用物品函数，如果拥有物品则返回true，否则返回false
	 * @param {ABagItem *item} 
	 * @return: bool（待修改）
	 */
	void UseItem(ABagItem* item);

	/**
	 * @description: 显示物品信息，返回一个物品类
	 * @param {ABagItem *item} 
	 * @return: ABagItem （待修改）
	 */
	void ShowItem(ABagItem* item);

	// 待添加函数： @存档 @独档 @物品数量合并
};
