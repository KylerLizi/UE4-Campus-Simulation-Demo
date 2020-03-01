// Fill out your copyright notice in the Description page of Project Settings.


#include "HelperLibrary/DataTableLibrary.h"
#include "Engine/DataTable.h"


TMap<EPlayerAttributeType, int32> UDataTableLibrary::TransFormGradeToAttribute(int32 Math, int32 Chinese, int32 English, int32 Comprehension) {
	TMap<EPlayerAttributeType, int32> AttributeMap;
	AttributeMap.Add(EPlayerAttributeType::Logic, float(Math)/150);
	AttributeMap.Add(EPlayerAttributeType::Charm, float(Chinese) / 150);
	AttributeMap.Add(EPlayerAttributeType::Social, float(English) / 150);
	AttributeMap.Add(EPlayerAttributeType::PE, float(Comprehension) / 300);
	AttributeMap.Add(EPlayerAttributeType::Luck, 50);
	return AttributeMap;
}