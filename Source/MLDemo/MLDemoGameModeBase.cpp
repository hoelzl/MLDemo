// Copyright Epic Games, Inc. All Rights Reserved.


#include "MLDemoGameModeBase.h"

AMLDemoGameModeBase::AMLDemoGameModeBase(const FObjectInitializer& ObjectInitializer)
    : AGameModeBase(ObjectInitializer)
{
    ConstructorHelpers::FClassFinder<APawn> PawnClassFinder{TEXT("/Game/Blueprints/Player_BP")};
    if (PawnClassFinder.Succeeded())
    {
        DefaultPawnClass = PawnClassFinder.Class;
    }
    else
    {
        DefaultPawnClass = ADefaultPawn::StaticClass();
    }
}
