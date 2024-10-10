// CraftingEnums.h

#pragma once

#include "CoreMinimal.h"
#include "CraftingEnums.generated.h"

//////////////////////////////////////////
/// Crafting Skill Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing the primary crafting skills required for crafting items.
 */
UENUM(BlueprintType)
enum class E_CraftingSkill : uint8
{
    None            UMETA(DisplayName = "None"),
    Smithing        UMETA(DisplayName = "Smithing"),
    Woodworking     UMETA(DisplayName = "Woodworking"),
    Alchemy         UMETA(DisplayName = "Alchemy"),
    Tailoring       UMETA(DisplayName = "Tailoring"),
    Cooking         UMETA(DisplayName = "Cooking"),
    Leatherworking  UMETA(DisplayName = "Leatherworking"),
    Stonecutting    UMETA(DisplayName = "Stonecutting"),
    // Add additional skills as needed
    Invalid         UMETA(Hidden)
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
    None                UMETA(DisplayName = "None"),
    Forge               UMETA(DisplayName = "Forge"),
    CarpenterBench      UMETA(DisplayName = "Carpenter's Bench"),
    AlchemyLab          UMETA(DisplayName = "Alchemy Lab"),
    TailorStation       UMETA(DisplayName = "Tailor Station"),
    CookingFire         UMETA(DisplayName = "Cooking Fire"),
    LeatherworkBench    UMETA(DisplayName = "Leatherwork Bench"),
    MasonryKiln         UMETA(DisplayName = "Masonry Kiln"),
    // Add additional stations as needed
    Invalid             UMETA(Hidden)
};

//////////////////////////////////////////
/// Recipe Type Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing the different types of crafting recipes.
 */
UENUM(BlueprintType)
enum class E_RecipeType : uint8
{
    Weapon       UMETA(DisplayName = "Weapon"),
    Armor        UMETA(DisplayName = "Armor"),
    Consumable    UMETA(DisplayName = "Consumable"),
    Tool         UMETA(DisplayName = "Tool"),
    Potion       UMETA(DisplayName = "Potion"),
    Enchantment  UMETA(DisplayName = "Enchantment"),
    Structure    UMETA(DisplayName = "Structure"),
    Food         UMETA(DisplayName = "Food"),
    Utility      UMETA(DisplayName = "Utility"),
    Miscellaneous UMETA(DisplayName = "Miscellaneous")
};

//////////////////////////////////////////
/// Ingredient Type Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing the different types of ingredients used in crafting.
 */
UENUM(BlueprintType)
enum class E_IngredientType : uint8
{
    None             UMETA(DisplayName = "None"),
    Material         UMETA(DisplayName = "Material"),
    Component        UMETA(DisplayName = "Component"),
    Essence          UMETA(DisplayName = "Essence"),
    Herb             UMETA(DisplayName = "Herb"),
    Mineral          UMETA(DisplayName = "Mineral"),
    Cloth            UMETA(DisplayName = "Cloth"),
    Leather          UMETA(DisplayName = "Leather"),
    Enchanted        UMETA(DisplayName = "Enchanted"),
    Rare             UMETA(DisplayName = "Rare"),
    Unique           UMETA(DisplayName = "Unique")
};

//////////////////////////////////////////
/// Crafting Result Enumeration
//////////////////////////////////////////

/**
 * @brief Enum representing the possible results of a crafting process.
 */
UENUM(BlueprintType)
enum class E_CraftingResult : uint8
{
    Success          UMETA(DisplayName = "Success"),
    Failure          UMETA(DisplayName = "Failure"),
    Partial          UMETA(DisplayName = "Partial"),
    CriticalFailure  UMETA(DisplayName = "Critical Failure")
};
