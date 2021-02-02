// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MapScoresWidget.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class SKILLTEST_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

	TArray<UMapScoresWidget*>  MapScoresWidgets;

public:

	UFUNCTION(BlueprintCallable)
	void SetMapScoresWidgets(TArray<UMapScoresWidget*>  WidgetsToSet);

	UFUNCTION(BlueprintCallable)
	FORCEINLINE TArray<UMapScoresWidget*> GetMapScoresWidgets() const { return MapScoresWidgets; }

	UMapScoresWidget* GetMapScoreWidgetByLevelName(FString LevelName);
};
