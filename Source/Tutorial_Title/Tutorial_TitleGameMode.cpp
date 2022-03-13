// Copyright Epic Games, Inc. All Rights Reserved.

#include "Tutorial_TitleGameMode.h"
#include "Tutorial_TitleCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATutorial_TitleGameMode::ATutorial_TitleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
