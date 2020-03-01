// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskPrimaryDataAsset.h"
#include "NierAssetManager.h"
UTaskPrimaryDataAsset::UTaskPrimaryDataAsset() {
	
}

FPrimaryAssetId UTaskPrimaryDataAsset::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(Type,FName(*GetName()));
}
