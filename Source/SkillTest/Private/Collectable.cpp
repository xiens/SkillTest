// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillTest/Public/Collectable.h"

#include "STGameInstance.h"
#include "Components/SphereComponent.h"
#include "SkillTest/SkillTestCharacter.h"


// Sets default values
ACollectable::ACollectable()
{
	PrimaryActorTick.bCanEverTick = false;

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereCollision->SetupAttachment(RootComponent);
	SphereCollision->SetRelativeLocation(FVector(0, 0, 0));
	SphereCollision->InitSphereRadius(30.0f);
	SphereCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	SphereCollision->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void ACollectable::BeginPlay()
{
	Super::BeginPlay();

	SphereCollision->OnComponentBeginOverlap.AddUniqueDynamic(this, &ACollectable::OnComponentBeginOverlap);
}

void ACollectable::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(Cast<ASkillTestCharacter>(OtherActor))
	{
		USTGameInstance * STGameInstance = Cast<USTGameInstance>(GetGameInstance());
		if(STGameInstance)
		{
			UE_LOG(LogTemp, Warning, TEXT("point added "))
			STGameInstance->PointsCollected++;
		}
		Destroy();
	}
}


