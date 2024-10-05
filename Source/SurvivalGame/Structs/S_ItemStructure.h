// S_ItemStructure.h

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "SurvivalGame/Enums/ItemEnums.h"
#include "S_ItemStructure.generated.h"


/**
 * @brief Structure representing a modifier or enchantment applied to an item.
 */
USTRUCT(BlueprintType)
struct FItemModifier
{
    GENERATED_BODY()

public:
    /** Name of the modifier */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Modifier")
    FName ModifierName;

    /** Description of the modifier */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Modifier")
    FText ModifierDescription;

    /** Effect magnitude (e.g., +10 Damage) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Modifier")
    float EffectMagnitude;

    /** Type of effect (e.g., Damage, Defense, Durability) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Modifier")
    E_ItemEffectType EffectType;

    /** Constructor for default initialization */
    FItemModifier()
        : ModifierName(NAME_None)
        , ModifierDescription(FText::FromString("No Description"))
        , EffectMagnitude(0.0f)
        , EffectType(E_ItemEffectType::Invalid)
    {}
};

/**
 * @brief Structure representing the effect triggered when the item is used.
 */
USTRUCT(BlueprintType)
struct FItemEffectOnUse
{
    GENERATED_BODY()

public:
    /** Type of effect triggered */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Effect")
    E_ItemEffect EffectType;

    /** Magnitude or duration of the effect */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Effect")
    float EffectMagnitude;

    /** Constructor for default initialization */
    FItemEffectOnUse()
        : EffectType(E_ItemEffect::None)
        , EffectMagnitude(0.0f)
    {}
};

/**
 * @brief Structure representing an item within the game.
 */
USTRUCT(BlueprintType)
struct FItemStructure : public FTableRowBase
{
    GENERATED_BODY()

public:
    //////////////////////////////////////////
    /// Basic Item Properties
    //////////////////////////////////////////

    /** Unique identifier for the item (Registry Key) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    FName RegistryKey;

    /** Name of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    FText ItemName;

    /** Quantity of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (ClampMin = "1"))
    int32 ItemQuantity;

    /** Maximum stack size for stackable items */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (EditCondition = "bIsStackable", ClampMin = "1"))
    int32 MaxStackSize;

    /** Indicates if the item is stackable */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    bool bIsStackable;

    /** Unique instance identifier for the item */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item")
    FGuid UniqueInstanceID;

    /** Category of the item for sorting and management */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    E_ItemCategory ItemCategory;

    /** Item Rarity */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    E_ItemRarity ItemRarity;

    /** Gameplay Tags associated with the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Tags")
    FGameplayTagContainer ItemTags;

    //////////////////////////////////////////
    /// Durability and Health
    //////////////////////////////////////////

    /** Current health or durability of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Durability", meta = (ClampMin = "0"))
    int32 CurrentDurability;

    /** Maximum health or durability of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Durability", meta = (ClampMin = "1"))
    int32 MaxDurability;

    /** Durability decay rate determining how quickly durability decreases */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Durability", meta = (ClampMin = "0.0"))
    float DurabilityDecayRate;

    /** Indicates if the item is breakable */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Durability")
    bool bIsDestroyable;

    //////////////////////////////////////////
    /// Ammunition (if applicable)
    //////////////////////////////////////////

    /** Indicates if the item uses ammunition */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammunition")
    bool bUsesAmmo;

    /** Current ammunition count */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammunition", meta = (EditCondition = "bUsesAmmo", ClampMin = "0"))
    int32 CurrentAmmo;

    /** Maximum ammunition capacity */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammunition", meta = (EditCondition = "bUsesAmmo", ClampMin = "1"))
    int32 MaxAmmo;

    //////////////////////////////////////////
    /// Consumable Properties
    //////////////////////////////////////////

    /** Indicates if the item is consumable */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Consumable")
    bool bIsConsumable;

    /** Nutrition value provided when the item is consumed */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Consumable", meta = (EditCondition = "bIsConsumable", ClampMin = "0"))
    int32 NutritionValue;

    /** Toxicity level of the item affecting player health or stamina */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Consumable", meta = (ClampMin = "0"))
    int32 Toxicity;

    /** Effect triggered when the item is used */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Consumable", meta = (EditCondition = "bIsConsumable"))
    FItemEffectOnUse EffectOnUse;

    /** Decay time after which the item starts to spoil or degrade */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Consumable", meta = (EditCondition = "bIsConsumable", ClampMin = "0.0"))
    float DecayTime;

    //////////////////////////////////////////
    /// Physical and Special Properties
    //////////////////////////////////////////

    /** Weight class of the item affecting movement or stamina */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physical")
    E_WeightClass WeightClass;

    /** Indicates if the item can act as a fire source */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physical")
    bool bIsFireSource;

    /** Temperature effect on the player when using or wearing the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physical", meta = (ClampMin = "-100.0", ClampMax = "100.0"))
    float TemperatureEffect;

    /** Warmth rating determining protection against cold environments */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physical", meta = (ClampMin = "0.0"))
    float WarmthRating;

    /** Indicates if the item is flammable */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physical")
    bool bIsFlammable;

    /** Burn time defining how long the item can burn */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physical", meta = (EditCondition = "bIsFlammable", ClampMin = "0.0"))
    float BurnTime;

    //////////////////////////////////////////
    /// Special Properties
    //////////////////////////////////////////

    /** Special ability or effect granted when the item is used or equipped */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special")
    FString SpecialAbility;

    //////////////////////////////////////////
    /// Additional Properties
    //////////////////////////////////////////

    /** Monetary value of the item used for trading or bartering */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Additional", meta = (ClampMin = "0"))
    int32 ItemValue;

    /** Indicates if the item is a quest item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Additional")
    bool bIsQuestItem;

    /** Indicates if the item is unique in the game world */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Additional")
    bool bIsUnique;

    /** Indicates if the item is a container */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Container")
    bool bIsContainer;

    /** Container size specifying how many items it can hold */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Container", meta = (EditCondition = "bIsContainer", ClampMin = "1"))
    int32 ContainerSize;

    //////////////////////////////////////////
    /// Modifiers and States
    //////////////////////////////////////////

    /** Default modifiers/enchantments applied to the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifiers")
    TArray<FItemModifier> DefaultModifiers;

    /** Item Modifiers */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifiers")
    TArray<FItemModifier> ItemModifiers;

    /** Initial state of the item (e.g., Raw, Processed, Broken) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
    E_ItemState InitialItemState;

    /** Current state of the item */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State")
    E_ItemState ItemState;

    //////////////////////////////////////////
    /// Constructor and Functions
    //////////////////////////////////////////

    /** Constructor for default initialization */
    FItemStructure();

    /**
     * @brief Initializes dynamic properties based on the Data Registry data.
     * @param LoadedItem The item data retrieved from the Data Registry.
     */
    void InitializeFromData(const FItemStructure& LoadedItem);

    /** Equality operator overload */
    bool operator==(const FItemStructure& Other) const;
};
