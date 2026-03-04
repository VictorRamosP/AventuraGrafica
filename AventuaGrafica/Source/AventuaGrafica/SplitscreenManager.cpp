#include "SplitscreenManager.h"
#include "Engine/GameViewportClient.h"

ASplitscreenManager::ASplitscreenManager()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ASplitscreenManager::BeginPlay()
{
    Super::BeginPlay();
    UGameViewportClient* l_Viewport = GetWorld()->GetGameViewport();
    if (!l_Viewport) return;

    FSplitscreenData l_ScreenLayout;
    FPerPlayerSplitscreenData Screen1;

    Screen1.SizeX = 1.0f;
    Screen1.SizeY = 0.725f;
    Screen1.OriginX = 0.0f;
    Screen1.OriginY = 0.0f; 

    l_ScreenLayout.PlayerData.Add(Screen1);

    l_Viewport->SplitscreenInfo.Empty();
    l_Viewport->SplitscreenInfo.Add(l_ScreenLayout);

    l_Viewport->UpdateActiveSplitscreenType();
}