// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillTest/Public/FinishLine.h"

#include "MapScoresWidget.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "SkillTest/SkillTestCharacter.h"
#include "STGameInstance.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AFinishLine::AFinishLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereCollision->SetupAttachment(RootComponent);
	SphereCollision->SetRelativeLocation(FVector(0, 0, 0));
	SphereCollision->InitSphereRadius(30.0f);
	SphereCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	SphereCollision->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void AFinishLine::BeginPlay()
{
	Super::BeginPlay();

	SphereCollision->OnComponentBeginOverlap.AddUniqueDynamic(this, &AFinishLine::OnComponentBeginOverlap);

	GetWorldTimerManager().SetTimer(FinishLevelTimerHandle, this, &AFinishLine::MeasureTimeToFinish, TimeDiff, true);

	STGameInstance = Cast<USTGameInstance>(GetGameInstance());
}

void AFinishLine::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GetWorldTimerManager().ClearTimer(FinishLevelTimerHandle);
}

void AFinishLine::MeasureTimeToFinish()
{
	TimeToFinish += TimeDiff;

	if(IsLevelFinished)
	{
		TimeToFinish = 0;
		GetWorldTimerManager().ClearTimer(FinishLevelTimerHandle);
	}
}

void AFinishLine::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(Cast<ASkillTestCharacter>(OtherActor))
	{
		if(STGameInstance && MainMenuWidgetClass)
		{
			MainMenuWidget = CreateWidget<UMainMenuWidget>(GetWorld(), MainMenuWidgetClass);
		
			if(MainMenuWidget)
			{
				// MapScoresWidget = MainMenuWidget->GetMapScoreWidgetByLevelName(UGameplayStatics::GetCurrentLevelName(GetWorld()));
				UE_LOG(LogTemp, Warning, TEXT(" current level name: %s"), *UGameplayStatics::GetCurrentLevelName(GetWorld()));
		
				// if(MapScoresWidget)
				// {
				// 	MapScoresWidget->UpdatePoints(STGameInstance->PointsCollected);
				// 	MapScoresWidget->UpdateTimeToComplete(TimeToFinish);
				// }
		
				MainMenuWidget->AddToViewport();
				if(GetWorld()->GetFirstPlayerController())
				{
					GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true; 
					GetWorld()->GetFirstPlayerController()->bEnableClickEvents = true; 
					GetWorld()->GetFirstPlayerController()->bEnableMouseOverEvents = true;
				}
			}
				

		}
		IsLevelFinished = true;

	}
}

// Called every frame
void AFinishLine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

