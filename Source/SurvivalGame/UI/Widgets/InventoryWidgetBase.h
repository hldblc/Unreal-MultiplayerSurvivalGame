// InventoryWidgetBase.h

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidgetBase.generated.h"

/**
 * @brief Base class for the inventory widget.
 */
UCLASS()
class SURVIVALGAME_API UInventoryWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UInventoryWidgetBase(const FObjectInitializer& ObjectInitializer);

	// Add public members here if necessary

protected:
	// Add protected members here if necessary

private:
	// Add private members here if necessary
};
