// Copyright 2020 Dr. Matthias Hölzl


#include "PlayerPawn.h"

#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

APlayerPawn::APlayerPawn(const FObjectInitializer& ObjectInitializer)
    : ADefaultPawn(ObjectInitializer)
{
    ChildCameraActor = CreateDefaultSubobject<UChildActorComponent>(TEXT("CameraComponent"));
    ChildCameraActor->SetChildActorClass(ACameraActor::StaticClass());

    TArray<AActor*> TmpCameras{};
    UGameplayStatics::GetAllActorsOfClass(this, ACameraActor::StaticClass(),
                                          TmpCameras);
    for (AActor* CameraActor : TmpCameras)
    {
        ACameraActor* Camera{Cast<ACameraActor>(CameraActor)};
        Cameras.Add(Camera);
    }
}

void APlayerPawn::SwitchToCamera(ACameraActor* Camera, float BlendTime) const
{
    APlayerController* PC{UGameplayStatics::GetPlayerController(this, 0)};
    if (ensure(PC))
    {
        ACameraActor* CurrentCamera{Cast<ACameraActor>(PC->GetViewTarget())};
        if (ensure(CurrentCamera))
        {
            PC->SetViewTargetWithBlend(Camera, BlendTime);
        }
    }
}

ACameraActor* APlayerPawn::GetCameraByTag(FName DesiredCameraName)
{
    for (ACameraActor* Camera : Cameras)
    {
        if (Camera->Tags.Contains(DesiredCameraName))
        {
            return Camera;
        }
    }
    return Cast<ACameraActor>(ChildCameraActor->GetChildActor());
}

void APlayerPawn::SwitchToCameraByName(FName DesiredCameraName, float BlendTime)
{
    return SwitchToCamera(GetCameraByTag(DesiredCameraName), BlendTime);
}
