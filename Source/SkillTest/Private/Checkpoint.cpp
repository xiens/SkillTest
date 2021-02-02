// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillTest/Public/Checkpoint.h"
#include "Components/SphereComponent.h"
#include "SkillTest/SkillTestCharacter.h"

// Sets default values
ACheckpoint::ACheckpoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereCollision->SetupAttachment(RootComponent);
	SphereCollision->SetRelativeLocation(FVector(0, 0, 0));
	SphereCollision->InitSphereRadius(30.0f);
	SphereCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	SphereCollision->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void ACheckpoint::BeginPlay()
{
	Super::BeginPlay();

	SphereCollision->OnComponentBeginOverlap.AddUniqueDynamic(this, &ACheckpoint::OnComponentBeginOverlap);
	
}

void ACheckpoint::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(Cast<ASkillTestCharacter>(OtherActor))
	{
		bIsChecked = true;
		UE_LOG(LogTemp, Warning, TEXT("checkbox checked "))
	}
}

void ACheckpoint::MovePlayerToCheckpoint()
{
	UE_LOG(LogTemp, Warning, TEXT("moving player back to checkpoint "))
	GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 50.0f), false, 0, ETeleportType::TeleportPhysics);
}