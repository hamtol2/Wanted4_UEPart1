// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"
#include "Card.h"
#include "CourseInfo.h"

UMyGameInstance::UMyGameInstance()
{
	// 기본 값은 CDO라는 특별한 템플릿 객체에 저장됨.
	SchoolName = TEXT("기본학교");
}

void UMyGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("====================="));

	// 학사 정보 객체 생성.
	CourseInfo = NewObject<UCourseInfo>(this);

	// 3명의 학생 추가.
	UStudent* Student1 = NewObject<UStudent>();
	Student1->SetName(TEXT("학생1"));

	UStudent* Student2 = NewObject<UStudent>();
	Student2->SetName(TEXT("학생2"));

	UStudent* Student3 = NewObject<UStudent>();
	Student3->SetName(TEXT("학생3"));

	// 알림에 구독.
	CourseInfo->OnChanged.AddUObject(
		Student1, &UStudent::GetNotification);
	CourseInfo->OnChanged.AddUObject(
		Student2, &UStudent::GetNotification);
	CourseInfo->OnChanged.AddUObject(
		Student3, &UStudent::GetNotification);

	// 변경된 학사 정보 발행.
	CourseInfo->ChangeCourseInfo(
		SchoolName, TEXT("변경된 학사 정보"));

	UE_LOG(LogTemp, Log, TEXT("====================="));
}
