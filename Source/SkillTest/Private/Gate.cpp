// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillTest/Public/Gate.h"

// Sets default values
AGate::AGate()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void AGate::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGate::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GetWorldTimerManager().ClearTimer(GateTimerHandle);
}

void AGate::StartMoving(bool IsOpening)
{
	float Speed;
	IsOpening ? Speed = OpeningSpeed : Speed = OpeningSpeed * -1;
	const FTimerDelegate OpenGateDelegate = FTimerDelegate::CreateUObject( this, &AGate::Move, Speed );
	GetWorldTimerManager().SetTimer( GateTimerHandle, OpenGateDelegate, TimeDiff, true );
}

void AGate::Move(float Speed)
{
	CurrentTime += TimeDiff;

	SetActorRotation(FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw  + MaxGateRotation*(TimeDiff/TimeToOpen) * Speed, GetActorRotation().Roll), ETeleportType::None);

	if(CurrentTime > TimeToOpen)
	{
		CurrentTime = 0;
		GetWorldTimerManager().ClearTimer(GateTimerHandle);
	}
}