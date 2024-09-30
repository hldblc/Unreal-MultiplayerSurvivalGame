// ItemEnums.h

#pragma once

#include "CoreMinimal.h"
#include "ItemEnums.generated.h"

//////////////////////////////////////////
/// Crafting Skill Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing the primary crafting skills required for crafting items.
 */
UENUM(BlueprintType)
enum class E_CraftingSkill : uint8
{
    None 		   UMETA(DisplayName = "None"),
    Smithing       UMETA(DisplayName = "Smithing"),
    Woodworking    UMETA(DisplayName = "Woodworking"),
    Alchemy        UMETA(DisplayName = "Alchemy"),
    Tailoring      UMETA(DisplayName = "Tailoring"),
    Cooking        UMETA(DisplayName = "Cooking"),
    // Add additional skills as needed
    Invalid        UMETA(Hidden)
};

//////////////////////////////////////////
/// Crafting Station Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing the crafting stations required for specific crafting recipes.
 */
UENUM(BlueprintType)
enum class E_CraftingStation : uint8
{
    None 			              UMETA(DisplayName = "None"),	
    Forge                 UMETA(DisplayName = "Forge"),
    CarpenterBench        UMETA(DisplayName = "Carpenter's Bench"),
    AlchemyLab            UMETA(DisplayName = "Alchemy Lab"),
    TailorStation         UMETA(DisplayName = "Tailor Station"),
    CookingFire           UMETA(DisplayName = "Cooking Fire"),
    // Add additional stations as needed
    Invalid               UMETA(Hidden)
};

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
    Buff              UMETA(DisplayName = "Buff"),
    Poison            UMETA(DisplayName = "Poison"),
    StaminaRecovery   UMETA(DisplayName = "Stamina Recovery"),
    DamageBoost       UMETA(DisplayName = "Damage Boost"),
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
   	None 			         UMETA(DisplayName = "None"),
    Damage           UMETA(DisplayName = "Damage"),
    Defense          UMETA(DisplayName = "Defense"),
    Durability       UMETA(DisplayName = "Durability"),
    Speed            UMETA(DisplayName = "Speed"),
    Health           UMETA(DisplayName = "Health"),
    Stamina          UMETA(DisplayName = "Stamina"),
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
	None 	UMETA(DisplayName = "None"),
    Light   UMETA(DisplayName = "Light"),
    Medium  UMETA(DisplayName = "Medium"),
    Heavy   UMETA(DisplayName = "Heavy"),
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
	None 		   UMETA(DisplayName = "None"),
    Weapon         UMETA(DisplayName = "Weapon"),
    Armor          UMETA(DisplayName = "Armor"),
    Consumable     UMETA(DisplayName = "Consumable"),
    Resource       UMETA(DisplayName = "Resource"),
    Tool           UMETA(DisplayName = "Tool"),
    QuestItem      UMETA(DisplayName = "Quest Item"),
    Miscellaneous  UMETA(DisplayName = "Miscellaneous"),
    // Add additional categories as needed
    Invalid        UMETA(Hidden)
};

//////////////////////////////////////////
/// Item State Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing the state of the item (e.g., Raw, Processed, Broken).
 */
UENUM(BlueprintType)
enum class E_ItemState : uint8
{
    None 		   UMETA(DisplayName = "None"),
    Normal         UMETA(DisplayName = "Normal"),
    Raw            UMETA(DisplayName = "Raw"),
    Processed      UMETA(DisplayName = "Processed"),
    Broken         UMETA(DisplayName = "Broken"),
    Spoiled        UMETA(DisplayName = "Spoiled"),
    // Add additional states as needed
    Invalid        UMETA(Hidden)
};


//////////////////////////////////////////
/// Item Rarity Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing the general categories of items for sorting and management.
 */
UENUM(BlueprintType)
enum class E_ItemRarity : uint8
{
	None 		   UMETA(DisplayName = "None"),
	Common         UMETA(DisplayName = "Common"),
	Uncommon       UMETA(DisplayName = "Uncommon"),
	Rare           UMETA(DisplayName = "Rare"),
	Epic           UMETA(DisplayName = "Epic"),
	Legendary      UMETA(DisplayName = "Legendary"),
	// Add additional rarities as needed
	Invalid        UMETA(Hidden)
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
	None 		   UMETA(DisplayName = "None"),
	Name           UMETA(DisplayName = "Name"),
	Quantity       UMETA(DisplayName = "Quantity"),
	Weight         UMETA(DisplayName = "Weight"),
	Value          UMETA(DisplayName = "Value"),
	Rarity         UMETA(DisplayName = "Rarity"),
	Category       UMETA(DisplayName = "Category"),
	// Add additional criteria as needed
	Invalid        UMETA(Hidden)
};	



