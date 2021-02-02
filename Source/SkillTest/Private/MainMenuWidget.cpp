// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"

#include "STGameInstance.h"

void UMainMenuWidget::SetMapScoresWidgets(TArray<UMapScoresWidget*> WidgetsToSet)
{
	for(UMapScoresWidget * Widget : WidgetsToSet)
	{
		MapScoresWidgets.AddUnique(Widget);
		USTGameInstance * GameInstance = Cast<USTGameInstance>(GetGameInstance());
		if(GameInstance)
		{
			GameInstance->MapScoresWidgets.AddUnique(Widget);
		}
	}
}

UMapScoresWidget* UMainMenuWidget::GetMapScoreWidgetByLevelName(FString LevelName)
{
	USTGameInstance * GameInstance = Cast<USTGameInstance>(GetGameInstance());
	
	if(GameInstance)
	{
		if(GameInstance->MapScoresWidgets.Num() > 0)
		{
			for(auto& Widget : GameInstance->MapScoresWidgets)
			{
				if(Widget->GetLevelName() == LevelName)
				{
					return Widget;
				}
			}
		}
		
	}
	return nullptr;
}
