// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Project_3_372GameMode.h"
#include "Project_3_372HUD.h"
#include "Project_3_372Character.h"
#include "UObject/ConstructorHelpers.h"

AProject_3_372GameMode::AProject_3_372GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AProject_3_372HUD::StaticClass();
}
