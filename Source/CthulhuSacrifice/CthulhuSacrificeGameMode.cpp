// Copyright Epic Games, Inc. All Rights Reserved.

#include "CthulhuSacrificeGameMode.h"
#include "CthulhuSacrificeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACthulhuSacrificeGameMode::ACthulhuSacrificeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
