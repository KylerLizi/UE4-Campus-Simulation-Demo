// Fill out your copyright notice in the Description page of Project Settings.


#include "NpcDataAsset.h"

FNpcInfoRaw UNpcDataAsset::GetNpcInfo()
{
	FNpcInfoRaw Raw = FNpcInfoRaw();
	Raw.NpcId = NpcId;
	Raw.NpcName = NpcName;
	Raw.NpcMesh = NpcMesh;
	Raw.NpcState = NpcState;
	Raw.NpcAnimClass = NpcAnimClass;
	Raw.NpcTaskNumber = NpcTaskNumber;
	Raw.NpcInitLocation = NpcInitLocation;
	return Raw;
}
