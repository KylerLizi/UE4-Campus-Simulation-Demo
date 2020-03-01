// Fill out your copyright notice in the Description page of Project Settings.


#include "FContainerInfo.h"

FContainerInfo::FContainerInfo()
{
	this->AdvInfo = nullptr;
}

FContainerInfo::FContainerInfo(FName ContainerNumber, FAdventureInfo* AdvInfo)
{
	this->ContainerNumber = ContainerNumber;
	this->AdvInfo = AdvInfo;
}

FContainerInfo::~FContainerInfo()
{
	delete this->AdvInfo;
}
