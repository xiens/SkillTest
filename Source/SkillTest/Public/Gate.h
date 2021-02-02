// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gate.generated.h"

UCLASS()
class SKILLTEST_API AGate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGate();

	UPROPERTY(EditAnywhere)
	float TimeToOpen = 1.0f;

	UPROPERTY(EditAnywhere)
	float MaxGateRotation = 90.0f;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "0.1", ClampMax = "2.0", UIMin = "0.1", UIMax = "2.0"))
	float OpeningSpeed = 1.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* Mesh;

public:	
	void StartMoving(bool IsOpening);

private:
	FTimerHandle GateTimerHandle;
	float CurrentTime = 0;
	float TimeDiff = 0.01f;
	
	void Move(float Speed);

};
