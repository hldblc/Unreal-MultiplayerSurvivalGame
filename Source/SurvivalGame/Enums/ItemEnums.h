// ItemEnums.h

#pragma once

#include "CoreMinimal.h"
#include "ItemEnums.generated.h"


//////////////////////////////////////////
/// Item Effect Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing the effects triggered when an item is used.
 */
UENUM(BlueprintType)
enum class E_ItemEffect : uint8
{
    None              UMETA(DisplayName = "None"),
    Healing           UMETA(DisplayName = "Healing"),
    StaminaRecovery   UMETA(DisplayName = "Stamina Recovery"),
    Buff              UMETA(DisplayName = "Defense Boost"),
    DamageBoost       UMETA(DisplayName = "Damage Boost"),
    Poison            UMETA(DisplayName = "Poison"),
    // Add additional effects as needed
    Invalid           UMETA(Hidden)
};

//////////////////////////////////////////
/// Item Effect Type Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing the types of item effects for modifiers.
 */
UENUM(BlueprintType)
enum class E_ItemEffectType : uint8
{
    None             UMETA(DisplayName = "None"),
    Damage           UMETA(DisplayName = "Damage"),
    Defense          UMETA(DisplayName = "Defense"),
    Durability       UMETA(DisplayName = "Durability"),
    Speed            UMETA(DisplayName = "Speed"),
    Health           UMETA(DisplayName = "Health"),
    Stamina          UMETA(DisplayName = "Stamina"),
    ElementalDamage  UMETA(DisplayName = "Elemental Damage"),
    // Add additional effect types as needed
    Invalid          UMETA(Hidden)
};

//////////////////////////////////////////
/// Weight Class Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing the weight class of items, influencing player movement and stamina.
 */
UENUM(BlueprintType)
enum class E_WeightClass : uint8
{
    None    UMETA(DisplayName = "None"),
    Light   UMETA(DisplayName = "Light"),
    Medium  UMETA(DisplayName = "Medium"),
    Heavy   UMETA(DisplayName = "Heavy"),
    // Add additional weight classes as needed
    Invalid UMETA(Hidden)
};

//////////////////////////////////////////
/// Item Category Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing the general categories of items for sorting and management.
 */
UENUM(BlueprintType)
enum class E_ItemCategory : uint8
{
    None            UMETA(DisplayName = "None"),
    Weapon          UMETA(DisplayName = "Weapon"),
    Armor           UMETA(DisplayName = "Armor"),
    Consumable      UMETA(DisplayName = "Consumable"),
    Resource        UMETA(DisplayName = "Resource"),
    Tool            UMETA(DisplayName = "Tool"),
    QuestItem       UMETA(DisplayName = "Quest Item"),
    Miscellaneous   UMETA(DisplayName = "Miscellaneous"),
    // Add additional categories as needed
    Invalid         UMETA(Hidden)
};

//////////////////////////////////////////
/// Item State Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing the state of the item (e.g., Normal, Raw, Processed, Broken, Spoiled).
 */
UENUM(BlueprintType)
enum class E_ItemState : uint8
{
    None        UMETA(DisplayName = "None"),
    Normal      UMETA(DisplayName = "Normal"),
    Raw         UMETA(DisplayName = "Raw"),
    Processed   UMETA(DisplayName = "Processed"),
    Broken      UMETA(DisplayName = "Broken"),
    Spoiled     UMETA(DisplayName = "Spoiled"),
    // Add additional states as needed
    Invalid     UMETA(Hidden)
};

//////////////////////////////////////////
/// Resource State Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing the state of the resource (e.g., Raw, Processed, Refined).
 */
UENUM(BlueprintType)
enum class E_ResourceState : uint8
{
    None        UMETA(DisplayName = "None"),
    Raw         UMETA(DisplayName = "Raw"),
    Processed   UMETA(DisplayName = "Processed"),
    Refined     UMETA(DisplayName = "Refined"),
    // Add additional resource states as needed
    Invalid     UMETA(Hidden)
};

//////////////////////////////////////////
/// Item Rarity Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing the rarity levels of items.
 */
UENUM(BlueprintType)
enum class E_ItemRarity : uint8
{
    None        UMETA(DisplayName = "None"),
    Common      UMETA(DisplayName = "Common"),
    Uncommon    UMETA(DisplayName = "Uncommon"),
    Rare        UMETA(DisplayName = "Rare"),
    Epic        UMETA(DisplayName = "Epic"),
    Legendary   UMETA(DisplayName = "Legendary"),
    Mythic      UMETA(DisplayName = "Mythic"),
    // Add additional rarities as needed
    Invalid     UMETA(Hidden)
};

//////////////////////////////////////////
/// Sorting Criteria Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing the criteria for sorting items in the inventory.
 */
UENUM(BlueprintType)
enum class E_SortCriteria : uint8
{
    None        UMETA(DisplayName = "None"),
    Name        UMETA(DisplayName = "Name"),
    Quantity    UMETA(DisplayName = "Quantity"),
    Weight      UMETA(DisplayName = "Weight"),
    Value       UMETA(DisplayName = "Value"),
    Rarity      UMETA(DisplayName = "Rarity"),
    Category    UMETA(DisplayName = "Category"),
    // Add additional criteria as needed
    Invalid     UMETA(Hidden)
};

//////////////////////////////////////////
/// Weapon Type Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing different types of weapons.
 */
UENUM(BlueprintType)
enum class E_WeaponType : uint8
{
    None        UMETA(DisplayName = "None"),
    Melee       UMETA(DisplayName = "Melee"),
    Ranged      UMETA(DisplayName = "Ranged"),
    Magic       UMETA(DisplayName = "Magic"),
    DualWield   UMETA(DisplayName = "Dual Wield"),
    // Add additional weapon types as needed
    Invalid     UMETA(Hidden)
};

//////////////////////////////////////////
/// Tool Type Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing different types of tools.
 */
UENUM(BlueprintType)
enum class E_ToolType : uint8
{
    None        UMETA(DisplayName = "None"),
    Pickaxe     UMETA(DisplayName = "Pickaxe"),
    Shovel      UMETA(DisplayName = "Shovel"),
    Hatchet     UMETA(DisplayName = "Hatchet"),
    Hammer      UMETA(DisplayName = "Hammer"),
    FishingRod  UMETA(DisplayName = "Fishing Rod"),
    // Add additional tool types as needed
    Invalid     UMETA(Hidden)
};

//////////////////////////////////////////
/// Projectile Type Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing different types of projectiles for ranged weapons.
 */
UENUM(BlueprintType)
enum class E_ProjectileType : uint8
{
    None        UMETA(DisplayName = "None"),
    Arrow       UMETA(DisplayName = "Arrow"),
    Bolt        UMETA(DisplayName = "Bolt"),
    MagicBolt   UMETA(DisplayName = "Magic Bolt"),
    Fireball    UMETA(DisplayName = "Fireball"),
    IceShard    UMETA(DisplayName = "Ice Shard"),
    // Add additional projectile types as needed
    Invalid     UMETA(Hidden)
};

//////////////////////////////////////////
/// Armor Type Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing different types of armor.
 */
UENUM(BlueprintType)
enum class E_ArmorType : uint8
{
    None        UMETA(DisplayName = "None"),
    Helmet      UMETA(DisplayName = "Helmet"),
    Chestplate  UMETA(DisplayName = "Chestplate"),
    Leggings    UMETA(DisplayName = "Leggings"),
    Boots       UMETA(DisplayName = "Boots"),
    Gauntlets   UMETA(DisplayName = "Gauntlets"),
    Shield      UMETA(DisplayName = "Shield"),
    // Add additional armor types as needed
    Invalid     UMETA(Hidden)
};

//////////////////////////////////////////
/// Special Effect Type Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing different types of special effects or abilities granted by items.
 */
UENUM(BlueprintType)
enum class E_SpecialEffectType : uint8
{
    None            UMETA(DisplayName = "None"),
    Fire            UMETA(DisplayName = "Fire"),
    Ice             UMETA(DisplayName = "Ice"),
    Poison          UMETA(DisplayName = "Poison"),
    Lightning       UMETA(DisplayName = "Lightning"),
    Healing         UMETA(DisplayName = "Healing"),
    SpeedBoost      UMETA(DisplayName = "Speed Boost"),
    StrengthBoost   UMETA(DisplayName = "Strength Boost"),
    // Add additional special effect types as needed
    Invalid         UMETA(Hidden)
};

//////////////////////////////////////////
/// Socket Type Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing different types of sockets available for item customization.
 */
UENUM(BlueprintType)
enum class E_SocketType : uint8
{
    None        UMETA(DisplayName = "None"),
    Gem         UMETA(DisplayName = "Gem"),
    Enchantment UMETA(DisplayName = "Enchantment"),
    Accessory   UMETA(DisplayName = "Accessory"),
    // Add additional socket types as needed
    Invalid     UMETA(Hidden)
};

//////////////////////////////////////////
/// Enchantment Type Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing different types of enchantments that can be applied to items.
 */
UENUM(BlueprintType)
enum class E_EnchantmentType : uint8
{
    None            UMETA(DisplayName = "None"),
    FireResistance  UMETA(DisplayName = "Fire Resistance"),
    IceResistance   UMETA(DisplayName = "Ice Resistance"),
    PoisonResistance UMETA(DisplayName = "Poison Resistance"),
    HealthBoost     UMETA(DisplayName = "Health Boost"),
    ManaBoost       UMETA(DisplayName = "Mana Boost"),
    StaminaBoost    UMETA(DisplayName = "Stamina Boost"),
    // Add additional enchantment types as needed
    Invalid         UMETA(Hidden)
};

//////////////////////////////////////////
/// Resource Type Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing different types of resources.
 */
UENUM(BlueprintType)
enum class E_ResourceType : uint8
{
    None        UMETA(DisplayName = "None"),
    Wood        UMETA(DisplayName = "Wood"),
    Tree        UMETA(DisplayName = "Tree"),         // Added Tree
    Herbs       UMETA(DisplayName = "Herbs"),
    Stone       UMETA(DisplayName = "Stone"),
    Metal       UMETA(DisplayName = "Metal"),
    Leather     UMETA(DisplayName = "Leather"),
    // Add additional resource types as needed
    Invalid     UMETA(Hidden)
};

//////////////////////////////////////////
/// ItemType Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing the general types of items.
 */
UENUM(BlueprintType)
enum class E_ItemType : uint8
{
    Weapon     UMETA(DisplayName = "Weapon"),
    Armor      UMETA(DisplayName = "Armor"),
    Consumable UMETA(DisplayName = "Consumable"),
    Resource   UMETA(DisplayName = "Resource"),
    Tool       UMETA(DisplayName = "Tool"),
    // Add other item types as needed
};
