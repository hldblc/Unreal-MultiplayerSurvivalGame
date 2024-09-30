// S_ItemStructure.cpp

#include "S_ItemStructure.h"
#include "SurvivalGame/Data/PDA_ItemInfo.h" // Adjust the path as necessary
#include "Engine/Engine.h" // For UE_LOG

/**
 * @brief Constructor for FItemStructure. Initializes default values.
 */
FItemStructure::FItemStructure()
    : ItemID(0)
    , ItemAsset(nullptr)
    , ItemQuantity(1)
    , MaxStackSize(1)
    , bIsStackable(false)
    , UniqueInstanceID(FGuid::NewGuid())
    , ItemCategory(E_ItemCategory::Miscellaneous)
    , ItemRarity(E_ItemRarity::None)
    , ItemTags()
    , CurrentDurability(100)
    , MaxDurability(100)
    , DurabilityDecayRate(0.0f)
    , bIsDestroyable(false)
    , CurrentAmmo(0)
    , MaxAmmo(0)
    , bUsesAmmo(false)
    , bIsConsumable(false)
    , NutritionValue(0)
    , Toxicity(0)
    , EffectOnUse() // Moved EffectOnUse before ItemModifiers
    , DecayTime(0.0f)
    , WeightClass(E_WeightClass::Light)
    , bIsFireSource(false)
    , TemperatureEffect(0.0f)
    , WarmthRating(0.0f)
    , bIsFlammable(false)
    , BurnTime(0.0f)
    , SpecialAbility(TEXT(""))
    , ItemValue(0)
    , bIsQuestItem(false)
    , bIsUnique(false)
    , bIsContainer(false)
    , ContainerSize(0)
    , DefaultModifiers()
    , InitialItemState(E_ItemState::Normal)
    , ItemState(E_ItemState::Normal)
    , ItemModifiers()
{
    // Initialize arrays and containers
}

/**
 * @brief Initializes dynamic properties of the item based on its static data from ItemAsset.
 */
void FItemStructure::InitializeFromAsset()
{
    if (ItemAsset.IsValid())
    {
        // Load the ItemAsset synchronously
        UPDA_ItemInfo* LoadedItemAsset = ItemAsset.LoadSynchronous();
        if (!LoadedItemAsset)
        {
            UE_LOG(LogTemp, Error, TEXT("FItemStructure::InitializeFromAsset() - Failed to load ItemAsset for ItemID: %d"), ItemID);
            return;
        }

        // Initialize basic properties
        ItemID = LoadedItemAsset->ItemID;
        bIsStackable = LoadedItemAsset->bIsStackable;
        MaxStackSize = bIsStackable ? LoadedItemAsset->MaxStackSize : 1;
        ItemCategory = LoadedItemAsset->ItemCategory;
        ItemRarity = LoadedItemAsset->ItemRarity;
        ItemTags = LoadedItemAsset->ItemTags;

        // Initialize durability
        MaxDurability = LoadedItemAsset->MaxDurability;
        CurrentDurability = MaxDurability;
        DurabilityDecayRate = LoadedItemAsset->DurabilityDecayRate;
        bIsDestroyable = LoadedItemAsset->bIsDestroyable;

        // Initialize ammunition
        bUsesAmmo = LoadedItemAsset->bUsesAmmo;
        if (bUsesAmmo)
        {
            MaxAmmo = LoadedItemAsset->MaxAmmo;
            CurrentAmmo = MaxAmmo;
        }
        else
        {
            MaxAmmo = 0;
            CurrentAmmo = 0;
        }

        // Initialize consumable properties
        bIsConsumable = LoadedItemAsset->bIsConsumable;
        if (bIsConsumable)
        {
            NutritionValue = LoadedItemAsset->NutritionValue;
            Toxicity = LoadedItemAsset->Toxicity;
            EffectOnUse = LoadedItemAsset->EffectOnUse;
            DecayTime = LoadedItemAsset->DecayTime;
        }

        // Initialize physical properties
        WeightClass = LoadedItemAsset->WeightClass;
        bIsFireSource = LoadedItemAsset->bIsFireSource;
        TemperatureEffect = LoadedItemAsset->TemperatureEffect;
        WarmthRating = LoadedItemAsset->WarmthRating;
        bIsFlammable = LoadedItemAsset->bIsFlammable;
        BurnTime = bIsFlammable ? LoadedItemAsset->BurnTime : 0.0f;

        // Initialize additional properties
        SpecialAbility = LoadedItemAsset->SpecialAbility;
        ItemValue = LoadedItemAsset->ItemValue;
        bIsQuestItem = LoadedItemAsset->bIsQuestItem;
        bIsUnique = LoadedItemAsset->bIsUnique;

        // Initialize container properties
        bIsContainer = LoadedItemAsset->bIsContainer;
        ContainerSize = bIsContainer ? LoadedItemAsset->ContainerSize : 0;

        // Initialize modifiers and state
        DefaultModifiers = LoadedItemAsset->DefaultModifiers;
        ItemModifiers = DefaultModifiers;
        InitialItemState = LoadedItemAsset->InitialItemState;
        ItemState = InitialItemState;

        // Log successful initialization
        UE_LOG(LogTemp, Log, TEXT("FItemStructure::InitializeFromAsset() - Successfully initialized ItemID: %d with Rarity: %s"), ItemID, *UEnum::GetValueAsString(ItemRarity));
    }
    else
    {
        // Handle cases where ItemAsset is not assigned or invalid
        UE_LOG(LogTemp, Warning, TEXT("FItemStructure::InitializeFromAsset() - Invalid ItemAsset for ItemID: %d"), ItemID);
    }
}

/**
 * @brief Equality operator overload for FItemStructure.
 */
bool FItemStructure::operator==(const FItemStructure& Other) const
{
    // Define how to compare two FItemStructure instances
    // Adjust the comparison based on what uniquely identifies an item
    return UniqueInstanceID == Other.UniqueInstanceID;
}
