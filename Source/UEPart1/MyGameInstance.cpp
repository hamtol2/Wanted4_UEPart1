// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "StudentData.h"

UMyGameInstance::UMyGameInstance()
{
}

void UMyGameInstance::Init()
{
	Super::Init();

	// 구조체 객체 생성.
	FStudentData RawDataSource(23, TEXT("장세윤"));

	// 파일로 저장하기 위한 경로 생성.
	const FString SavePath = FPaths::Combine(
		FPlatformMisc::ProjectDir(), TEXT("Saved")
	);

	// 파일 저장 테스트를 위한 구간.
	{
		// 파일 이름.
		const FString RawDataFileName(TEXT("RawData.bin"));

		// 저장 경로 + 파일 이름.
		FString RawDataAbsolutePath
			= FPaths::Combine(SavePath, RawDataFileName);

		// 경로 출력.
		UE_LOG(
			LogTemp,
			Log,
			TEXT("저장할 파일 전체 경로: %s"),
			*RawDataAbsolutePath
		);

		// 경로 정리.
		FPaths::MakeStandardFilename(RawDataAbsolutePath);

		UE_LOG(
			LogTemp,
			Log,
			TEXT("변경할 파일 전체 경로: %s"),
			*RawDataAbsolutePath
		);

		// 직렬화 사용해서 저장.
		// 파일 열기(쓰기 모드로).
		FArchive* RawFileWriteAr
			= IFileManager::Get().CreateFileWriter(
				*RawDataAbsolutePath);
		if (RawFileWriteAr)
		{
			// 파일에 기록.
			*RawFileWriteAr << RawDataSource.Order;
			*RawFileWriteAr << RawDataSource.Name;

			// 파일 닫기.
			RawFileWriteAr->Close();
			
			// 메모리 해제.
			delete RawFileWriteAr;
			RawFileWriteAr = nullptr;
		}
	}
}