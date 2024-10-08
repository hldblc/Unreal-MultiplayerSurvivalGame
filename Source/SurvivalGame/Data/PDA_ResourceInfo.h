// PDA_ResourceInfo.h

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SurvivalGame/Enums/ItemEnums.h"
#include "PDA_ResourceInfo.generated.h"

//////////////////////////////////////////
/// Resource Effect Structure
//////////////////////////////////////////

/**
 * @brief Structure defining effects that resources can have when used or processed.
 */
USTRUCT(BlueprintType)
struct FResourceEffect
{
    GENERATED_BODY()

public:
    /** Type of effect (e.g., Healing, Buff) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect")
    E_ItemEffectType EffectType;

    /** Magnitude of the effect */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect", meta = (ClampMin = "0.0"))
    float EffectMagnitude;

    /** Duration of the effect in seconds */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect", meta = (ClampMin = "0.0"))
    float EffectDuration;
};

//////////////////////////////////////////
/// UPDA_ResourceInfo Class
//////////////////////////////////////////

/**
 * @brief Data Asset for Resource Items containing specific properties.
 */
UCLASS(BlueprintType)
class SURVIVALGAME_API UPDA_ResourceInfo : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    /** Constructor */
    UPDA_ResourceInfo();

    /** Unique identifier for the resource (Used by Data Registry) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource")
    FName RegistryKey;

    /** Unique identifier for the resource */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource")
    int32 ResourceID;

    /** Name of the resource */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource")
    FText ResourceName;

    /** Description of the resource */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource")
    FText ResourceDescription;

    /** Type of the resource (e.g., Wood, Stone) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource")
    E_ResourceType ResourceType;

    /** Quantity available for harvesting */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource", meta = (ClampMin = "0"))
    int32 Quantity;

    /** Rarity of the resource */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource")
    E_ItemRarity Rarity;

    /** Required crafting skill to harvest or process the resource */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource")
    E_CraftingSkill RequiredCraftingSkill;

    /** Crafting station needed to process the resource */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource")
    E_CraftingStation CraftingStation;

    /** Durability of the resource if applicable */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource", meta = (ClampMin = "0"))
    int32 Durability;

    /** Effects applied when the resource is used */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource|Effects")
    TArray<FResourceEffect> ResourceEffects;

    /** Icon representing the resource in the inventory */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource|Visuals")
    UTexture2D* ResourceIcon;

    /** Mesh representing the resource in the world */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource|Visuals")
    UStaticMesh* ResourceMesh;

    /** Sound played when the resource is harvested or used */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource|Audio")
    USoundBase* ResourceSound;

    /** Particle effect displayed when the resource is used */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource|Effects")
    UParticleSystem* ResourceParticle;

private:
    /** Cached durability decay value to optimize performance */
    UPROPERTY(Transient)
    float CachedDurabilityDecay;

public:
    /**
     * @brief Retrieves the cached durability decay value.
     * @return Cached durability decay.
     */
    float GetCachedDurabilityDecay() const;
    
    /**
     * @brief Updates the cached durability decay value.
     * @param DeltaTime Time elapsed since the last update.
     */
    void UpdateDurabilityDecay(float DeltaTime);
};
