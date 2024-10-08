// ItemMaster.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SurvivalGame/Data/PDA_WeaponInfo.h"
#include "SurvivalGame/Data/PDA_ArmorInfo.h"
// Include other Data Assets as needed
#include "ItemMaster.generated.h"

UCLASS()
class SURVIVALGAME_API AItemMaster : public AActor
{
	GENERATED_BODY()

public:
	/** Sets default values for this actor's properties */
	AItemMaster();

protected:
	/** Called when the game starts or when spawned */
	virtual void BeginPlay() override;

public:
	/** Called every frame */
	virtual void Tick(float DeltaTime) override;

	/** Reference to the Weapon Data Asset */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|Weapon")
	UPDA_WeaponInfo* WeaponInfo;

	/** Reference to the Armor Data Asset */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|Armor")
	UPDA_ArmorInfo* ArmorInfo;

	/** Function to initialize item properties */
	UFUNCTION(BlueprintCallable, Category = "Item|Initialization")
	void InitializeItem();

	/** Example function to display item info */
	UFUNCTION(BlueprintCallable, Category = "Item|Display")
	void DisplayItemInfo();
};
