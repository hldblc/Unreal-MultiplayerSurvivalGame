// EnvironmentEnum.h

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentEnum.generated.h"

//////////////////////////////////////////
/// Environment Enumeration
//////////////////////////////////////////

/**
 * @brief Defines various environmental factors affecting resources.
 */
UENUM(BlueprintType, Blueprintable)
enum class E_EnvironmentType : uint8
{
    None            UMETA(DisplayName = "None"),
    Sunny           UMETA(DisplayName = "Sunny"),
    Rainy           UMETA(DisplayName = "Rainy"),
    Snowy           UMETA(DisplayName = "Snowy"),
    Windy           UMETA(DisplayName = "Windy"),
    Stormy          UMETA(DisplayName = "Stormy"),
    Foggy           UMETA(DisplayName = "Foggy"),
    Humid           UMETA(DisplayName = "Humid"),
    Dry             UMETA(DisplayName = "Dry"),
    Hot             UMETA(DisplayName = "Hot"),
    Cold            UMETA(DisplayName = "Cold"),

};

//////////////////////////////////////////
///// Biome Enumeration
//////////////////////////////////////////

/**
 * @brief Defines various biomes for resource spawning.
 */
UENUM(BlueprintType)
enum class E_BiomeType : uint8
{
	Forest      UMETA(DisplayName = "Forest"),
	Desert      UMETA(DisplayName = "Desert"),
	Mountain    UMETA(DisplayName = "Mountain"),
	Swamp       UMETA(DisplayName = "Swamp"),
	River       UMETA(DisplayName = "River"),
	Grassland   UMETA(DisplayName = "Grassland"),
	Coastal     UMETA(DisplayName = "Coastal"),
	Urban       UMETA(DisplayName = "Urban"),
	Cave        UMETA(DisplayName = "Cave"),
	Wetlands    UMETA(DisplayName = "Wetlands"),
    
	// Optionally, include a default or unknown biome
	Unknown     UMETA(DisplayName = "Unknown")
};
// Enable bitmask operations for E_BiomeType
ENUM_CLASS_FLAGS(E_BiomeType)
// Enable bitmask operations for E_EnvironmentType
ENUM_CLASS_FLAGS(E_EnvironmentType)
