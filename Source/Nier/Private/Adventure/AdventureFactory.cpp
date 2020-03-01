#include "AdventureFactory.h"
#include "Engine/DataTable.h"

UAdventureObject * UAdventureFactory::ProduceAdventure(FName AdventureNumber)
{
	
	return nullptr;
}

void UAdventureFactory::InitTable(UDataTable* AdvTable) {
	if (Table->GetRowStruct()->StaticClass() == TableRaw) {
		UE_LOG(LogTemp,Warning, TEXT("Struct Equal"));
	}
	this->Table = AdvTable;
}