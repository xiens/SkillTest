// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KillBox.generated.h"

UCLASS()
class SKILLTEST_API AKillBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKillBox();

	UPROPERTY(EditAnywhere)
	class ACheckpoint * Checkpoint;

	UPROPERTY(VisibleDefaultsOnly)
	class UBoxComponent* BoxCollision;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
    void OnComponentBeginOverlap(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
