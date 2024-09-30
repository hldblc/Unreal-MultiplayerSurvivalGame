// GameHUDWidgetBase.h

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "GameHUDWidgetBase.generated.h"

/**
 * @brief Base class for the Game HUD Widget, derived from UCommonActivatableWidget.
 */
UCLASS(Blueprintable, BlueprintType)
class SURVIVALGAME_API UGameHUDWidgetBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UGameHUDWidgetBase(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativeConstruct() override;

	// Add any C++ functions or properties needed for the HUD

public:
	// Expose any functions or variables to Blueprints if necessary
};
