#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FTaskInfo.generated.h"

UENUM(BlueprintType)
enum class ETaskState :uint8 {
	NeverTrigger,
	NotReceive,
	Received,
	Finished,
	AlreadyEnd
};

USTRUCT(BlueprintType)
struct NIER_API FTaskInfoRaw :public FTableRowBase {

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, SaveGame)
		ETaskState TaskState;
	UPROPERTY(EditAnywhere, SaveGame)
		FName TaskNumber;
	UPROPERTY(EditAnywhere, SaveGame)
		int32 CurrentProgress;
	UPROPERTY(EditAnywhere, SaveGame)
		int32 MaxProgress;
	UPROPERTY(EditAnywhere, SaveGame)
		FName Name;
	UPROPERTY(EditAnywhere, SaveGame)
		FName Description;
	UPROPERTY(EditAnywhere, SaveGame)
		TArray<FName> PreviousTaskNumber;
	UPROPERTY(EditAnywhere, SaveGame)
		TArray<FName> NextTaskNumber;
	UPROPERTY(EditAnywhere, SaveGame)
		TSoftClassPtr<class UTask> TaskClass;
	UPROPERTY(EditAnywhere, SaveGame)
		FName StartTaskNpc;
	UPROPERTY(EditAnywhere, SaveGame)
		FName EndTaskNpc;
};
