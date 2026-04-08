// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	Super::Init();

	// 로그 출력.
	UE_LOG(LogTemp, Log, TEXT("%s"), TEXT("Hello Unreal"));
}
