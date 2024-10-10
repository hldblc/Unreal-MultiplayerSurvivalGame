// ItemMaster.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Forward declarations to reduce dependencies
class UPDA_ItemInfo;
class UStaticMeshComponent;
class USphereComponent;

#include "ItemMaster.generated.h"

UCLASS()
class SURVIVALGAME_API AItemMaster : public AActor
{
    GENERATED_BODY()
    
public:	
    // Sets default values for this actor's properties
    AItemMaster();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:	
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    /**
     * @brief Reference to the primary Data Asset containing item properties.
     *        Assign this in the Editor or via Blueprint.
     */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
    UPDA_ItemInfo* ItemInfo;

    /**
     * @brief Static Mesh component representing the item's appearance in the world.
     *        Assign a mesh in the Editor or via Blueprint.
     */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
    UStaticMeshComponent* ItemMeshComponent;

    /**
     * @brief Sphere Collision component for item interactions (e.g., picking up).
     */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
    USphereComponent* CollisionComponent;

    /**
     * @brief Sets up the item based on the assigned Data Asset.
     *        This includes applying visuals, audio, and other properties.
     */
    UFUNCTION(BlueprintCallable, Category = "Item|Initialization")
    void InitializeItem();

    /**
     * @brief Handles the logic when the item is picked up by a player.
     *        You can extend this function to include more complex behaviors.
     */
    UFUNCTION(BlueprintCallable, Category = "Item|Actions")
    void OnPickedUp();

    /**
     * @brief Handles the logic when the item is used by a player.
     *        Implement item-specific usage behaviors here.
     */
    UFUNCTION(BlueprintCallable, Category = "Item|Actions")
    void OnUsed();

    /**
     * @brief Repairs the item, restoring its durability.
     */
    UFUNCTION(BlueprintCallable, Category = "Item|Maintenance")
    void RepairItem();

    /**
     * @brief Upgrades the item to a higher level or enhances its properties.
     */
    UFUNCTION(BlueprintCallable, Category = "Item|Upgrades")
    void UpgradeItem();
};
