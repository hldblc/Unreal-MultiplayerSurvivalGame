// SurvivalGamePlayerController.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SurvivalGamePlayerController.generated.h"

class UInputMappingContext;
class UMainUILayoutBase;

/**
 * Survival Game Player Controller class.
 */
UCLASS()
class SURVIVALGAME_API ASurvivalGamePlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    ASurvivalGamePlayerController();

protected:
    /** Input Mapping Context to be used for player input */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    UInputMappingContext* InputMappingContext;

    /** Widget class to instantiate as the main UI layout */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
    TSubclassOf<UMainUILayoutBase> MainUILayoutClass;

    /** Reference to the main UI layout widget */
    UPROPERTY(BlueprintReadOnly, Category = "UI")
    UMainUILayoutBase* RootLayout;

protected:
    // Begin AActor interface
    virtual void BeginPlay() override;
    // End AActor interface

    /** Creates and sets up the UI */
    void CreateAndSetupUI();
};
