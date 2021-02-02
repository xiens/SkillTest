// Copyright Epic Games, Inc. All Rights Reserved.

#include "SkillTestGameMode.h"
#include "SkillTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASkillTestGameMode::ASkillTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
