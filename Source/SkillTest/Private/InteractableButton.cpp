// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillTest/Public/InteractableButton.h"
#include "Components/BoxComponent.h"
#include "SkillTest/Public/Gate.h"
#include "SkillTest/Public/MovingPlatform.h"
#include "SkillTest/Public/Obstacle.h"


// Sets default values
AInteractableButton::AInteractableButton()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(RootComponent);
	BoxCollision->InitBoxExtent(FVector(32.0f,32.0f,32.0f));
	BoxCollision->SetRelativeLocation(FVector(0, 0, 35.0f));
	BoxCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	BoxCollision->SetGenerateOverlapEvents(true);
	
}

// Called when the game starts or when spawned
void AInteractableButton::BeginPlay()
{
	Super::BeginPlay();
	
	BoxCollision->OnComponentBeginOverlap.AddUniqueDynamic(this, &AInteractableButton::OnComponentBeginOverlap);
	BoxCollision->OnComponentEndOverlap.AddUniqueDynamic(this, &AInteractableButton::OnComponentEndOverlap);
}

void AInteractableButton::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AObstacle * Obstacle = Cast<AObstacle>(OtherActor);

	if(Obstacle && !IsButtonPressed)
	{
		IsButtonPressed = true;

		if(Gate)
		{
			if(!Gate->GetIsMoving())
			{
				Gate->StartMoving(!Gate->GetIsOpened());
			}
		}

		if(MovingPlatform)
		{
			MovingPlatform->MovePlatform(true);
		}
	}

}

void AInteractableButton::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AObstacle * Obstacle = Cast<AObstacle>(OtherActor);

	if(Obstacle && IsButtonPressed)
	{
		IsButtonPressed = false;

		if(Gate)
		{
			if(!Gate->GetIsMoving())
			{
				Gate->StartMoving(!Gate->GetIsOpened());
			}
		}
		
		if(MovingPlatform)
		{
			MovingPlatform->MovePlatform(false);
		}
	}
}


