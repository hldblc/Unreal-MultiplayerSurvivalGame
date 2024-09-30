// MainUILayoutBase.h

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "CommonUI/Public/CommonActivatableWidget.h"
#include "CommonUI/Public/Widgets/CommonActivatableWidgetContainer.h"
#include "MainUILayoutBase.generated.h"

UCLASS(Blueprintable, BlueprintType)
class SURVIVALGAME_API UMainUILayoutBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UMainUILayoutBase(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativeConstruct() override;

public:
	/** Reference to the GameHUDStack */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UCommonActivatableWidgetStack* GameHUDStack;

	/** Reference to the GameInventoryStack */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UCommonActivatableWidgetStack* GameInventoryStack;

	/** Reference to the GameMenuStack */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UCommonActivatableWidgetStack* GameMenuStack;

	/** Class of the Game HUD widget to instantiate */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UCommonActivatableWidget> GameHUDWidgetClass;

	/** Reference to the instantiated Game HUD widget */
	UPROPERTY(BlueprintReadOnly, Category = "UI")
	UCommonActivatableWidget* GameHUDLayout;

	/** Pushes the Game HUD widget onto the GameHUDStack */
	UFUNCTION(BlueprintCallable, Category = "UI")
	void PushGameHUDWidget();
};
