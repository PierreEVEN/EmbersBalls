// Copyright Epic Games, Inc. All Rights Reserved.

#include "EmbersBallsGameMode.h"
#include "EmbersBallsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEmbersBallsGameMode::AEmbersBallsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
