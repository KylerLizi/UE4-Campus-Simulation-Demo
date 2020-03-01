#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FNpcInfo.generated.h"

UENUM(BlueprintType)
enum class ENpcState : uint8 {
	Idle,
	Walk,
	Run
};

USTRUCT(BlueprintType)
struct NIER_API FNpcInfoRaw : public FTableRowBase {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		FName NpcId;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		FName NpcName;//名称
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		TSoftObjectPtr<class USkeletalMesh> NpcMesh;//模型
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		TSubclassOf<class UAnimInstance> NpcAnimClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		ENpcState NpcState;//运动状态
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		FName NpcTaskNumber;//该Npc相关任务编号
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable)
		FVector NpcInitLocation;//初始位置
};