#include "BPC_ItemsContainerMaster.h"
#include "Net/UnrealNetwork.h"
#include "DataRegistrySubsystem.h"
#include "DataRegistry.h"
#include "Engine/Engine.h"


// Sets default values for this component's properties
UItemsContainerMaster::UItemsContainerMaster()
{
    // Enable replication
    SetIsReplicatedByDefault(true);

    // Initialize default values
    ContainerType = E_ContainerType::None;
    // Initialize Items array with desired size if needed
}

// Called when the game starts
void UItemsContainerMaster::BeginPlay()
{
    Super::BeginPlay();

    // Initialization logic here (if any)
}

// Called every frame
void UItemsContainerMaster::TickComponent(float DeltaTime, ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // Per-frame logic here (if any)
}

// Ensure properties are replicated
void UItemsContainerMaster::GetLifetimeReplicatedProps(
    TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(UItemsContainerMaster, Items);
}

// Replication callback for Items array
void UItemsContainerMaster::OnRep_Items()
{
    // Handle client-side logic when Items array is updated
    UE_LOG(LogTemp, Log, TEXT("OnRep_Items: Items array replicated"));
    // Broadcast an event or call a function here if needed
}

// Function to find an empty slot
bool UItemsContainerMaster::FindEmptySlot(int32& OutEmptySlotIndex) const
{
    for (int32 Index = 0; Index < Items.Num(); ++Index)
    {
        if (Items[Index].RegistryKey == NAME_None)
        {
            OutEmptySlotIndex = Index;
            return true;
        }
    }
    return false;
}

// Function to find a slot where the item can be stacked
bool UItemsContainerMaster::FindStackableSlot(const FName& ItemRegistryKey,
    int32& OutSlotIndex) const
{
    for (int32 Index = 0; Index < Items.Num(); ++Index)
    {
        if (Items[Index].RegistryKey == ItemRegistryKey &&
            Items[Index].ItemQuantity < Items[Index].MaxStackSize)
        {
            OutSlotIndex = Index;
            return true;
        }
    }
    return false;
}

// Function to load item data from the Data Registry
bool UItemsContainerMaster::LoadItemData(const FDataRegistryId& ItemRegistryId, FItemStructure& OutItemData)
{
    UDataRegistrySubsystem* DataRegistrySubsystem = UDataRegistrySubsystem::Get();
    if (!DataRegistrySubsystem)
    {
        UE_LOG(LogTemp, Error, TEXT("LoadItemData: DataRegistrySubsystem not found."));
        return false;
    }

    const uint8* ItemMemory = nullptr;
    const UScriptStruct* ItemStruct = nullptr;

    FDataRegistryCacheGetResult GetResult = DataRegistrySubsystem->GetCachedItemRaw(ItemMemory, ItemStruct, ItemRegistryId);
    if (GetResult)
    {
        if (ItemStruct && ItemStruct->IsChildOf(FItemStructure::StaticStruct()))
        {
            OutItemData = *reinterpret_cast<const FItemStructure*>(ItemMemory);
            return true;
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("LoadItemData: ItemStruct is not of type FItemStructure."));
            return false;
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("LoadItemData: Item data not found for ID %s."), *ItemRegistryId.ToString());
        return false;
    }
}

// Function to add an item to the inventory
bool UItemsContainerMaster::AddItem(const FItemStructure& NewItem)
{
    if (!GetOwner()->HasAuthority())
    {
        // If called on client, request the server to add the item
        Server_AddItem(NewItem);
        return false; // Client cannot add the item directly
    }

    int32 SlotIndex;

    // Try to find a stackable slot first
    if (NewItem.bIsStackable &&
        FindStackableSlot(NewItem.RegistryKey, SlotIndex))
    {
        // Add to existing stack
        int32 AvailableSpace = Items[SlotIndex].MaxStackSize -
                               Items[SlotIndex].ItemQuantity;
        int32 QuantityToAdd = FMath::Min(NewItem.ItemQuantity, AvailableSpace);
        Items[SlotIndex].ItemQuantity += QuantityToAdd;

        UpdateTagMapOnItemAdd(Items[SlotIndex]);
        OnItemAdded.Broadcast(Items[SlotIndex], SlotIndex);

        UE_LOG(LogTemp, Log,
            TEXT("AddItem: Stacked item '%s' in slot %d. Quantity: %d"),
            *Items[SlotIndex].ItemName.ToString(), SlotIndex,
            Items[SlotIndex].ItemQuantity);

        // If there's remaining quantity, try to add it to a new slot
        if (NewItem.ItemQuantity > QuantityToAdd)
        {
            FItemStructure RemainingItem = NewItem;
            RemainingItem.ItemQuantity -= QuantityToAdd;
            return AddItem(RemainingItem);
        }
        return true;
    }
    // If stacking is not possible, find an empty slot
    else if (FindEmptySlot(SlotIndex))
    {
        FDataRegistryId ItemRegistryId(FName("DR_ItemRegistry"), NewItem.RegistryKey);
        FItemStructure LoadedItem;

        // Attempt to retrieve the item data from the Data Registry
        if (LoadItemData(ItemRegistryId, LoadedItem))
        {
            // Initialize the item structure with data from Data Registry
            FItemStructure InitializedItem = LoadedItem;
            InitializedItem.ItemQuantity = NewItem.ItemQuantity;
            InitializedItem.UniqueInstanceID = FGuid::NewGuid();

            // Add the initialized item to the inventory
            Items[SlotIndex] = InitializedItem;

            UpdateTagMapOnItemAdd(Items[SlotIndex]);

            // Broadcast the item added event
            OnItemAdded.Broadcast(Items[SlotIndex], SlotIndex);

            UE_LOG(LogTemp, Log,
                TEXT("AddItem: Item '%s' added to slot %d"),
                *InitializedItem.ItemName.ToString(), SlotIndex);
            return true; // Item successfully added
        }
        else
        {
            UE_LOG(LogTemp, Warning,
                TEXT("AddItem: Failed to retrieve item data for "
                     "RegistryKey: %s"),
                *NewItem.RegistryKey.ToString());
            return false;
        }
    }

    // Inventory is full
    UE_LOG(LogTemp, Warning,
        TEXT("AddItem: Inventory is full, cannot add item with "
             "RegistryKey: %s"),
        *NewItem.RegistryKey.ToString());
    return false;
}

// Function to remove an item from the inventory
bool UItemsContainerMaster::RemoveItem(int32 SlotIndex)
{
    if (!GetOwner()->HasAuthority())
    {
        // If called on client, request the server to remove the item
        Server_RemoveItem(SlotIndex);
        return false; // Client cannot remove the item directly
    }

    if (Items.IsValidIndex(SlotIndex) &&
        Items[SlotIndex].RegistryKey != NAME_None)
    {
        FItemStructure RemovedItem = Items[SlotIndex];
        Items[SlotIndex] = FItemStructure(); // Reset the slot to default

        UpdateTagMapOnItemRemove(RemovedItem);

        // Broadcast the item removed event
        OnItemRemoved.Broadcast(RemovedItem, SlotIndex);

        UE_LOG(LogTemp, Log,
            TEXT("RemoveItem: Item '%s' removed from slot %d"),
            *RemovedItem.ItemName.ToString(), SlotIndex);
        return true; // Item successfully removed
    }

    // Invalid slot or already empty
    UE_LOG(LogTemp, Warning,
        TEXT("RemoveItem: Invalid slot index %d or slot already empty."),
        SlotIndex);
    return false;
}

// Server RPC implementations

bool UItemsContainerMaster::Server_AddItem_Validate(const FItemStructure& NewItem)
{
    UDataRegistrySubsystem* DataRegistrySubsystem = UDataRegistrySubsystem::Get();
    if (!DataRegistrySubsystem)
    {
        return false;
    }

    FDataRegistryId ItemRegistryId(FName("DR_ItemRegistry"), NewItem.RegistryKey);

    const uint8* ItemMemory = nullptr;
    const UScriptStruct* ItemStruct = nullptr;

    FDataRegistryCacheGetResult GetResult = DataRegistrySubsystem->GetCachedItemRaw(ItemMemory, ItemStruct, ItemRegistryId);
    if (GetResult)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void UItemsContainerMaster::Server_AddItem_Implementation(
    const FItemStructure& NewItem)
{
    AddItem(NewItem);
}

bool UItemsContainerMaster::Server_RemoveItem_Validate(int32 SlotIndex)
{
    // Add validation logic here
    return SlotIndex >= 0 && SlotIndex < Items.Num();
}

void UItemsContainerMaster::Server_RemoveItem_Implementation(int32 SlotIndex)
{
    RemoveItem(SlotIndex);
}

// Retrieves all items with a specific gameplay tag
TArray<FItemStructure> UItemsContainerMaster::GetItemsWithTag(
    const FGameplayTag& DesiredTag) const
{
    TArray<FItemStructure> ItemsWithTag;
    if (const TArray<FItemStructure>* FoundItems =
            TagToItemsMap.Find(DesiredTag))
    {
        ItemsWithTag = *FoundItems;
    }
    return ItemsWithTag;
}

// Checks if any item in the inventory has a specific tag
bool UItemsContainerMaster::HasItemWithTag(
    const FGameplayTag& DesiredTag) const
{
    return TagToItemsMap.Contains(DesiredTag);
}

// Checks if any item in the inventory has any tag from a set
bool UItemsContainerMaster::HasAnyItemWithTagFromSet(
    const FGameplayTagContainer& TagSet) const
{
    for (const FGameplayTag& Tag : TagSet)
    {
        if (TagToItemsMap.Contains(Tag))
        {
            return true;
        }
    }
    return false;
}

// Add a tag to an item
bool UItemsContainerMaster::AddTagToItem(int32 SlotIndex,
    const FGameplayTag& NewTag)
{
    if (Items.IsValidIndex(SlotIndex))
    {
        Items[SlotIndex].ItemTags.AddTag(NewTag);
        UpdateTagMapOnItemAdd(Items[SlotIndex]);
        return true;
    }
    return false;
}

// Update the tag map when adding an item
void UItemsContainerMaster::UpdateTagMapOnItemAdd(
    const FItemStructure& NewItem)
{
    for (const FGameplayTag& Tag : NewItem.ItemTags)
    {
        TagToItemsMap.FindOrAdd(Tag).Add(NewItem);
    }
}

// Update the tag map when removing an item
void UItemsContainerMaster::UpdateTagMapOnItemRemove(
    const FItemStructure& RemovedItem)
{
    for (const FGameplayTag& Tag : RemovedItem.ItemTags)
    {
        if (TArray<FItemStructure>* ItemsWithTag = TagToItemsMap.Find(Tag))
        {
            ItemsWithTag->RemoveAll([&RemovedItem](const FItemStructure& Item)
            {
                return Item.UniqueInstanceID == RemovedItem.UniqueInstanceID;
            });

            if (ItemsWithTag->Num() == 0)
            {
                TagToItemsMap.Remove(Tag);
            }
        }
    }
}
