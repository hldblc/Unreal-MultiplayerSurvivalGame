// SurvivalGamePlayerController.cpp

#include "SurvivalGamePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

#include "Blueprint/UserWidget.h"
#include "SurvivalGame/UI/Widgets//MainUILayoutBase.h"

ASurvivalGamePlayerController::ASurvivalGamePlayerController()
{
    // Optionally, set the MainUILayoutClass via ConstructorHelpers if not set in Blueprint
    // static ConstructorHelpers::FClassFinder<UMainUILayoutBase> MainUILayoutBP(TEXT("/Game/UI/Widgets/BP_MainUILayout"));
    // if (MainUILayoutBP.Succeeded())
    // {
    //     MainUILayoutClass = MainUILayoutBP.Class;
    // }
}

void ASurvivalGamePlayerController::BeginPlay()
{
    Super::BeginPlay();

    // Get the enhanced input subsystem
    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        // Add the mapping context so we get controls
        if (InputMappingContext)
        {
            Subsystem->AddMappingContext(InputMappingContext, 0);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("InputMappingContext is null in ASurvivalGamePlayerController::BeginPlay"));
        }
    }

    // Create and set up the UI
    CreateAndSetupUI();
}

void ASurvivalGamePlayerController::CreateAndSetupUI()
{
    // Authority check
    if (HasAuthority())
    {
        if (IsLocalPlayerController())
        {
            // Listen server: create UI
            if (MainUILayoutClass)
            {
                RootLayout = CreateWidget<UMainUILayoutBase>(this, MainUILayoutClass);
                if (RootLayout)
                {
                    RootLayout->AddToViewport();

                    // Call PushGameHUDWidget
                    RootLayout->PushGameHUDWidget();
                }
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("Failed to create RootLayout on listen server in ASurvivalGamePlayerController::CreateAndSetupUI"));
                }
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("MainUILayoutClass is null on listen server in ASurvivalGamePlayerController::CreateAndSetupUI"));
            }
        }
        // Else: Dedicated server, do not create UI
    }
    else
    {
        // Client: create UI
        if (MainUILayoutClass)
        {
            RootLayout = CreateWidget<UMainUILayoutBase>(this, MainUILayoutClass);
            if (RootLayout)
            {
                RootLayout->AddToViewport();

                // Call PushGameHUDWidget
                RootLayout->PushGameHUDWidget();
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("Failed to create RootLayout on client in ASurvivalGamePlayerController::CreateAndSetupUI"));
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("MainUILayoutClass is null on client in ASurvivalGamePlayerController::CreateAndSetupUI"));
        }
    }
}
