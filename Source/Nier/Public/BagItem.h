// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BagItem.generated.h"

UCLASS()
class NIER_API ABagItem : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	// 背包物品名称
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName BagItemName;

	// 背包物品描述
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString BagItemDescription;

	// 背包物品2D图片
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		UTexture2D* BagItemPic;
	
	// 背包物品三维形态StaticMesh
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		UStaticMesh* BagItemMesh;

	ABagItem();

	/**
	 * @description: ABgTtem重载构造函数
	 * @param {Name name, FString des, UTexture2D* pic} 
	 * @return: 无
	 */
	ABagItem(FName name, FString des, UTexture2D* pic);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/**
	 * @description: 物品的使用函数，需要蓝图实现
	 * @param {} 
	 * @return: bool（待修改）如果使用成功返回true，否则返回false
	 */
	UFUNCTION(BlueprintImplementableEvent)
		void Use();
};
