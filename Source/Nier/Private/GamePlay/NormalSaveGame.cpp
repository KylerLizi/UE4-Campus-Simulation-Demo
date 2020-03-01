// Fill out your copyright notice in the Description page of Project Settings.


#include "NormalSaveGame.h"

void UNormalSaveGame::SaveTask(FTaskInfoRaw Raw)
{
	PlayerTaskInfo.FindOrAdd(Raw.TaskNumber) = Raw;

}

void UNormalSaveGame::SaveNpc(FNpcInfoRaw Raw)
{
	NpcInfoMap.FindOrAdd(Raw.NpcName) = Raw;
}

void UNormalSaveGame::SavePlayerAttribute(EPlayerAttributeType AttributeType, int32 Number)
{
	PlayerAttribute.FindOrAdd(AttributeType) = Number;
}
