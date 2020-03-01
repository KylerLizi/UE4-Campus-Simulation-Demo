// Fill out your copyright notice in the Description page of Project Settings.


#include "AdventureContainer.h"
#include "AdventureManager.h"

// Add default functionality here for any IAdventureContainer functions that are not pure virtual.

TSharedRef<FContainerInfo> IAdventureContainer::GetContainerInfo() const
{
	return TSharedRef<FContainerInfo>();
}
void IAdventureContainer::PlayAdventure() {

}
