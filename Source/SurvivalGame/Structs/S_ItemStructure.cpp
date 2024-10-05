#include "S_ItemStructure.h"

FItemStructure::FItemStructure()
    : RegistryKey(NAME_None)
    , ItemName(FText::FromString("Unknown Item"))
    , ItemQuantity(1)
    , MaxStackSize(1)
    , bIsStackable(false)
    , UniqueInstanceID(FGuid::NewGuid())
    , ItemCategory(E_ItemCategory::None)
    , ItemRarity(E_ItemRarity::Common)
    , CurrentDurability(100)
    , MaxDurability(100)
    , DurabilityDecayRate(0.0f)
    , bIsDestroyable(true)
    , CurrentAmmo(0)
    , MaxAmmo(0)
    , bUsesAmmo(false)
    , bIsConsumable(false)
    , NutritionValue(0)
    , Toxicity(0)
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
    , InitialItemState(E_ItemState::None)
    , ItemState(E_ItemState::None)
{
    // Initialize arrays
    DefaultModifiers = TArray<FItemModifier>();
    ItemModifiers = TArray<FItemModifier>();
}

void FItemStructure::InitializeFromData(const FItemStructure& LoadedItem)
{
    // Copy properties from LoadedItem to this instance
    *this = LoadedItem;

    // Generate a new UniqueInstanceID
    UniqueInstanceID = FGuid::NewGuid();

    // Set any runtime-specific properties
    ItemState = LoadedItem.InitialItemState;
}

bool FItemStructure::operator==(const FItemStructure& Other) const
{
    // Compare the UniqueInstanceID for equality
    return UniqueInstanceID == Other.UniqueInstanceID;
}
