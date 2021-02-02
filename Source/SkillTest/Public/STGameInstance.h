// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"



#include "MainMenuWidget.h"
#include "MapScoresWidget.h"
#include "Engine/GameInstance.h"
#include "STGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SKILLTEST_API USTGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	
	int PointsCollected = 0;

private:
	
	UMainMenuWidget * MainMenuWidget;

public:
	
	UFUNCTION(BlueprintCallable)
	void SetMainMenuWidget(UMainMenuWidget * WidgetToSet) { MainMenuWidget = WidgetToSet; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE UMainMenuWidget * GetMainMenuWidget() const { return MainMenuWidget; }

};
