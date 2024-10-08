// PDA_ConsumableInfo.h

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SurvivalGame/Enums/ItemEnums.h"
#include "PDA_ConsumableInfo.generated.h"

//////////////////////////////////////////
/// Consumable Effect Structure
//////////////////////////////////////////

/**
 * @brief Structure defining effects that consumables can have when used.
 */
USTRUCT(BlueprintType)
struct FConsumableEffect
{
    GENERATED_BODY()

public:
    /** Type of effect (e.g., Healing, Buff) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect")
    E_ItemEffectType EffectType;

    /** Magnitude of the effect */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect", meta = (ClampMin = "0.0"))
    float EffectMagnitude;

    /** Duration of the effect in seconds (0 for instant) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect", meta = (ClampMin = "0.0"))
    float EffectDuration;
};

//////////////////////////////////////////
/// UPDA_ConsumableInfo Class
//////////////////////////////////////////

/**
 * @brief Data Asset for Consumable Items containing specific properties.
 */
UCLASS(BlueprintType)
class SURVIVALGAME_API UPDA_ConsumableInfo : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    /** Constructor */
    UPDA_ConsumableInfo();

    /** Unique identifier for the consumable (Used by Data Registry) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable")
    FName RegistryKey;

    /** Unique identifier for the consumable */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable")
    int32 ConsumableID;

    /** Name of the consumable */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable")
    FText ConsumableName;

    /** Description of the consumable */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable")
    FText ConsumableDescription;

    /** Effect type when consumed */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable")
    E_ItemEffectType EffectType;

    /** Effect strength */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable", meta = (ClampMin = "0.0"))
    float EffectStrength;

    /** Duration of the effect in seconds (0 for instant) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable", meta = (ClampMin = "0.0"))
    float EffectDuration;

    /** Nutrition value provided */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable", meta = (ClampMin = "0"))
    int32 NutritionValue;

    /** Toxicity level affecting player health or stamina */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable", meta = (ClampMin = "0"))
    int32 Toxicity;

    /** Decay time after which the consumable spoils */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable", meta = (ClampMin = "0.0"))
    float DecayTime;

    /** Rarity of the consumable */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable")
    E_ItemRarity Rarity;

    /** Required crafting skill to create the consumable */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable")
    E_CraftingSkill RequiredCraftingSkill;

    /** Crafting station needed to create the consumable */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable")
    E_CraftingStation CraftingStation;

    /** Effects applied when the consumable is used */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable|Effects")
    TArray<FConsumableEffect> ConsumableEffects;

    /** Icon representing the consumable in the inventory */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable|Visuals")
    UTexture2D* ConsumableIcon;

    /** Mesh representing the consumable in the world */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable|Visuals")
    UStaticMesh* ConsumableMesh;

    /** Sound played when the consumable is consumed */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable|Audio")
    USoundBase* ConsumableSound;

    /** Particle effect displayed when the consumable is consumed */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable|Effects")
    UParticleSystem* ConsumableParticle;

private:
    /** Cached effect application value for performance optimization */
    UPROPERTY(Transient)
    float CachedEffectValue;

public:
    /**
     * @brief Retrieves the cached effect value.
     * @return Cached effect value.
     */
    float GetCachedEffectValue() const;
    
    /**
     * @brief Updates the cached effect value.
     */
    void UpdateEffectValue();
};
