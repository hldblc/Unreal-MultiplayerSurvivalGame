// BPC_ItemsContainerMaster.h

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SurvivalGame/Enums/ContainerType.h"
#include "SurvivalGame/Enums/ItemEnums.h"
#include "SurvivalGame/Structs/S_ItemStructure.h"
#include "GameplayTagContainer.h" // Include Gameplay Tags
#include "BPC_ItemsContainerMaster.generated.h"

// Forward declarations
class UPDA_ItemInfo;

// Delegate Declarations
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemAddedSignature, const FItemStructure&, AddedItem, int32, SlotIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemRemovedSignature, const FItemStructure&, RemovedItem, int32, SlotIndex);

/**
 * @brief Component managing a container of items.
 */
UCLASS(ClassGroup=(Custom), Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class SURVIVALGAME_API UItemsContainerMaster : public UActorComponent
{
    GENERATED_BODY()

public:    
    // Sets default values for this component's properties
    UItemsContainerMaster();

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:    
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    /** Array of items in the container */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", ReplicatedUsing=OnRep_Items)
    TArray<FItemStructure> Items;

    /** Type of the container */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    E_ContainerType ContainerType;

    /** Delegate to notify when an item is added */
    UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
    FOnItemAddedSignature OnItemAdded;

    /** Delegate to notify when an item is removed */
    UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
    FOnItemRemovedSignature OnItemRemoved;

    /** Map to store items categorized by their tags for fast lookup */
    // Removed UPROPERTY macro as TMap with TArray values is not supported with UPROPERTY
    TMap<FGameplayTag, TArray<FItemStructure>> TagToItemsMap;

    /**
     * @brief Finds an empty slot in the inventory.
     * @param OutEmptySlotIndex Index of the empty slot if found.
     * @return True if an empty slot is found; otherwise, false.
     */
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    bool FindEmptySlot(int32& OutEmptySlotIndex);

    /**
     * @brief Adds an item to the inventory.
     * @param NewItem The item to add.
     * @return True if the item was successfully added; otherwise, false.
     */
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    bool AddItem(const FItemStructure& NewItem);

    /**
     * @brief Removes an item from the inventory at the specified slot.
     * @param SlotIndex The index of the slot to remove the item from.
     * @return True if the item was successfully removed; otherwise, false.
     */
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    bool RemoveItem(int32 SlotIndex);

    /**
     * @brief Server RPC to add an item to the inventory.
     * @param NewItem The item to add.
     */
    UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category = "Inventory|Server")
    void Server_AddItem(const FItemStructure& NewItem);

    /**
     * @brief Server RPC to remove an item from the inventory.
     * @param SlotIndex The index of the slot to remove the item from.
     */
    UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category = "Inventory|Server")
    void Server_RemoveItem(int32 SlotIndex);

    /**
     * @brief Retrieves all items with a specific gameplay tag.
     * @param DesiredTag The gameplay tag to filter items by.
     * @return An array of items matching the tag.
     */
    UFUNCTION(BlueprintCallable, Category = "Inventory|Tags")
    TArray<FItemStructure> GetItemsWithTag(const FGameplayTag& DesiredTag) const;

    /**
     * @brief Checks if any item in the inventory has a specific tag.
     * @param DesiredTag The gameplay tag to check for.
     * @return True if any item has the tag; otherwise, false.
     */
    UFUNCTION(BlueprintCallable, Category = "Inventory|Tags")
    bool HasItemWithTag(const FGameplayTag& DesiredTag) const;

    /**
     * @brief Checks if any item in the inventory has any tag from a set.
     * @param TagSet The set of gameplay tags to check against.
     * @return True if any item has any of the tags; otherwise, false.
     */
    UFUNCTION(BlueprintCallable, Category = "Inventory|Tags")
    bool HasAnyItemWithTagFromSet(const FGameplayTagContainer& TagSet) const;

    /**
     * @brief Adds a gameplay tag to an item at a specified slot.
     * @param SlotIndex The index of the slot containing the item.
     * @param NewTag The gameplay tag to add.
     * @return True if the tag was successfully added; otherwise, false.
     */
    UFUNCTION(BlueprintCallable, Category = "Inventory|Tags")
    bool AddTagToItem(int32 SlotIndex, const FGameplayTag& NewTag);

private:
    /** Replication callback for Items array */
    UFUNCTION()
    void OnRep_Items();

    /** Updates the tag-to-item map when an item is added */
    void UpdateTagMapOnItemAdd(const FItemStructure& NewItem);

    /** Updates the tag-to-item map when an item is removed */
    void UpdateTagMapOnItemRemove(const FItemStructure& RemovedItem);
};
