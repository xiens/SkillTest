// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"

void UMainMenuWidget::SetMapScoresWidgets(TArray<UMapScoresWidget*> WidgetsToSet)
{
	MapScoresWidgets.Empty();
	for(auto &Widget : WidgetsToSet)
	{
		MapScoresWidgets.Add(Widget);
	}
}

UMapScoresWidget* UMainMenuWidget::GetMapScoreWidgetByLevelName(FString LevelName)
{
	for(auto& Widget : MapScoresWidgets)
	{
		if(Widget->GetLevelName() == LevelName)
		{
			return Widget;
		}
	}
	return nullptr;
}
