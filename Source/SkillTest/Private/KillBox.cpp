// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillTest/Public/KillBox.h"

#include "Components/BoxComponent.h"
#include "SkillTest/SkillTestCharacter.h"
#include "SkillTest/Public/Checkpoint.h"

// Sets default values
AKillBox::AKillBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(RootComponent);
	BoxCollision->InitBoxExtent(FVector(8000.0f,8000.0f,100.0f));
	BoxCollision->SetRelativeLocation(FVector(0, 0, -200.0f));
	BoxCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	BoxCollision->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void AKillBox::BeginPlay()
{
	Super::BeginPlay();

	BoxCollision->OnComponentBeginOverlap.AddUniqueDynamic(this, &AKillBox::OnComponentBeginOverlap);
}

void AKillBox::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(Cast<ASkillTestCharacter>(OtherActor))
	{
		if(Checkpoint)
		{
			if(Checkpoint->IsChecked())
			{
				Checkpoint->MovePlayerToCheckpoint();
			}
		}
	}
}


