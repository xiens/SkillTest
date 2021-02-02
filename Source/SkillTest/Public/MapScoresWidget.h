// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MapScoresWidget.generated.h"

/**
 * 
 */
UCLASS()
class SKILLTEST_API UMapScoresWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	FString LevelName;

	UFUNCTION(BlueprintCallable)
    void SetLevelName(FString LevelNameToSet){ LevelName = LevelNameToSet; }
	
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateTimeToComplete(float Time);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdatePoints(int Points);

	FORCEINLINE FString GetLevelName() const { return LevelName; }
};
