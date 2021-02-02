// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "FinishLine.generated.h"

UCLASS()
class SKILLTEST_API AFinishLine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFinishLine();

protected:
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UMainMenuWidget> MainMenuWidgetClass;

	UPROPERTY(VisibleDefaultsOnly)
	class USphereComponent* SphereCollision;

	UPROPERTY()
	UMainMenuWidget * MainMenuWidget;
	
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void MeasureTimeToFinish();

	UFUNCTION()
	void OnComponentBeginOverlap(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	bool IsLevelFinished = false;
	class USTGameInstance * STGameInstance;
	class UMapScoresWidget * MapScoresWidget;
	FTimerHandle FinishLevelTimerHandle;
	float TimeToFinish = 0;
	float TimeDiff = 0.01f;
};
