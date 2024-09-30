// MainUILayoutBase.cpp

#include "SurvivalGame/UI/Widgets/MainUILayoutBase.h"
#include "GameHUDWidgetBase.h"
#include "CommonUI/Public/Widgets/CommonActivatableWidgetContainer.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

UMainUILayoutBase::UMainUILayoutBase(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

void UMainUILayoutBase::NativeConstruct()
{
    Super::NativeConstruct();

    // Additional initialization if necessary
    // For example, you can call PushGameHUDWidget here if appropriate
    // PushGameHUDWidget();
}

void UMainUILayoutBase::PushGameHUDWidget()
{
    if (GameHUDStack)
    {
        if (GameHUDWidgetClass)
        {
            // Use BP_AddWidget to add the widget to the stack
            UCommonActivatableWidget* GameHUDWidget = GameHUDStack->AddWidget(GameHUDWidgetClass);
            if (GameHUDWidget)
            {
                // Optionally, store a reference if needed
                GameHUDLayout = GameHUDWidget;
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("PushGameHUDWidget: Failed to create GameHUDWidget."));
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("PushGameHUDWidget: GameHUDWidgetClass is null."));
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("PushGameHUDWidget: GameHUDStack is null."));
    }
}