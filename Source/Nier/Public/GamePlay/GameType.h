// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameType.generated.h"

// 人物属性枚举类型，逻辑、体育、社交、魅力、幸运
UENUM(BlueprintType)
enum class EPlayerAttributeType : uint8 {
	Logic,
	PE,
	Social,
	Charm,
	Luck,
};