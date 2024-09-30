// BPC_ItemsContainerMaster.cpp

#include "BPC_ItemsContainerMaster.h"
#include "Net/UnrealNetwork.h"
#include "SurvivalGame/Data/PDA_ItemInfo.h" // Adjust the path as necessary
#include "Engine/Engine.h" // For UE_LOG

// Sets default values for this component's properties
UItemsContainerMaster::UItemsContainerMaster()
{
    // Enable replication
    SetIsReplicatedByDefault(true);

    // Initialize default values
    ContainerType = E_ContainerType::None;
    Items = TArray<FItemStructure>();
}

// Called when the game starts
void UItemsContainerMaster::BeginPlay()
{
    Super::BeginPlay();
    
    // Initialization logic here (if any)
}

// Called every frame
void UItemsContainerMaster::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // Per-frame logic here (if any)
}

// Ensure properties are replicated
void UItemsContainerMaster::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(UItemsContainerMaster, Items);
}

// Replication callback for Items array
void UItemsContainerMaster::OnRep_Items()
{
    // Handle any client-side logic when Items array is updated
    // For example, update UI or notify other systems
}

// Function to find an empty slot
bool UItemsContainerMaster::FindEmptySlot(int32& OutEmptySlotIndex)
{
    for (int32 Index = 0; Index < Items.Num(); ++Index)
    {
        if (Items[Index].ItemID == 0 && !Items[Index].ItemAsset.IsValid())
        {
            OutEmptySlotIndex = Index;
            return true;
        }
    }
    return false;
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

    int32 EmptySlotIndex;
    if (FindEmptySlot(EmptySlotIndex))
    {
        // Initialize the item from its Data Asset
        FItemStructure InitializedItem = NewItem;
        InitializedItem.InitializeFromAsset();

        Items[EmptySlotIndex] = InitializedItem;
        UpdateTagMapOnItemAdd(InitializedItem);

        // Broadcast the item added event
        OnItemAdded.Broadcast(InitializedItem, EmptySlotIndex);

        UE_LOG(LogTemp, Log, TEXT("Item ID %d with Rarity %s added to slot %d"),
            InitializedItem.ItemID,
            *UEnum::GetValueAsString(InitializedItem.ItemRarity),
            EmptySlotIndex);
        return true; // Item successfully added
    }

    // Inventory is full
    UE_LOG(LogTemp, Warning, TEXT("AddItem: Inventory is full, cannot add item ID %d"), NewItem.ItemID);
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

    if (Items.IsValidIndex(SlotIndex) && Items[SlotIndex].ItemID != 0)
    {
        FItemStructure RemovedItem = Items[SlotIndex];
        Items[SlotIndex] = FItemStructure(); // Reset the slot to default

        UpdateTagMapOnItemRemove(RemovedItem);

        // Broadcast the item removed event
        OnItemRemoved.Broadcast(RemovedItem, SlotIndex);

        UE_LOG(LogTemp, Log, TEXT("Item ID %d removed from slot %d"), RemovedItem.ItemID, SlotIndex);
        return true; // Item successfully removed
    }

    // Invalid slot or already empty
    UE_LOG(LogTemp, Warning, TEXT("RemoveItem: Invalid slot index %d or slot already empty."), SlotIndex);
    return false;
}

// Server RPC implementations

bool UItemsContainerMaster::Server_AddItem_Validate(const FItemStructure& NewItem)
{
    // Add validation logic here to prevent cheating
    return NewItem.ItemID > 0 && NewItem.ItemAsset.IsValid();
}

void UItemsContainerMaster::Server_AddItem_Implementation(const FItemStructure& NewItem)
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
TArray<FItemStructure> UItemsContainerMaster::GetItemsWithTag(const FGameplayTag& DesiredTag) const
{
    if (const TArray<FItemStructure>* FilteredItems = TagToItemsMap.Find(DesiredTag))
    {
        return *FilteredItems;
    }
    return TArray<FItemStructure>(); // Return empty if no items with the tag
}

// Checks if any item in the inventory has a specific tag
bool UItemsContainerMaster::HasItemWithTag(const FGameplayTag& DesiredTag) const
{
    return TagToItemsMap.Contains(DesiredTag);
}

// Checks if any item in the inventory has any tag from a set
bool UItemsContainerMaster::HasAnyItemWithTagFromSet(const FGameplayTagContainer& TagSet) const
{
    for (const FItemStructure& Item : Items)
    {
        if (Item.ItemTags.HasAny(TagSet))
        {
            return true;
        }
    }
    return false;
}

// Add a tag to an item
bool UItemsContainerMaster::AddTagToItem(int32 SlotIndex, const FGameplayTag& NewTag)
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
void UItemsContainerMaster::UpdateTagMapOnItemAdd(const FItemStructure& NewItem)
{
    if (NewItem.ItemTags.Num() > 0)
    {
        for (const FGameplayTag& Tag : NewItem.ItemTags)
        {
            TArray<FItemStructure>& ItemsWithTag = TagToItemsMap.FindOrAdd(Tag);
            ItemsWithTag.Add(NewItem);
        }
    }
}

// Update the tag map when removing an item
void UItemsContainerMaster::UpdateTagMapOnItemRemove(const FItemStructure& RemovedItem)
{
    if (RemovedItem.ItemTags.Num() > 0)
    {
        for (const FGameplayTag& Tag : RemovedItem.ItemTags)
        {
            if (TArray<FItemStructure>* ItemsWithTag = TagToItemsMap.Find(Tag))
            {
                ItemsWithTag->Remove(RemovedItem);
                if (ItemsWithTag->Num() == 0)
                {
                    TagToItemsMap.Remove(Tag);
                }
            }
        }
    }
}
