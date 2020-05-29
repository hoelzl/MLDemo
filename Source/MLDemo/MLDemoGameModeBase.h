// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "GameFramework/GameModeBase.h"
#include "MLDemoGameModeBase.generated.h"

UCLASS()
class MLDEMO_API AMLDemoGameModeBase : public AGameModeBase
{
public:
    explicit AMLDemoGameModeBase(
        const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
    GENERATED_BODY()
};
