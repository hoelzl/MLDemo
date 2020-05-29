// Copyright 2020 Dr. Matthias Hölzl

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "PlayerPawn.generated.h"

/**
 * 
 */
UCLASS()
class MLDEMO_API APlayerPawn : public ADefaultPawn
{
public:
    explicit APlayerPawn(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadOnly, Category="Camera")
    TArray<ACameraActor *> Cameras;

    UPROPERTY(BlueprintReadOnly, Category="Camera")
    UChildActorComponent* ChildCameraActor;

    void SwitchToCamera(ACameraActor* Camera, float BlendTime) const;
    ACameraActor* GetCameraByTag(FName DesiredCameraName);
    void SwitchToCameraByName(FName DesiredCameraName, float BlendTime);

    
};
