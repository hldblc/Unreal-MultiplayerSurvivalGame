// PDA_ArmorInfo.h

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SurvivalGame/Enums/ItemEnums.h"
#include "PDA_ArmorInfo.generated.h"

//////////////////////////////////////////
/// Armor Effect Structure
//////////////////////////////////////////

/**
 * @brief Structure defining effects that armor can have when equipped.
 */
USTRUCT(BlueprintType)
struct FArmorEffect
{
    GENERATED_BODY()

public:
    /** Type of effect (e.g., Fire Resistance) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect")
    E_SpecialEffectType EffectType;

    /** Magnitude of the effect */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect", meta = (ClampMin = "0.0"))
    float EffectMagnitude;

    /** Duration of the effect in seconds (0 for permanent) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect", meta = (ClampMin = "0.0"))
    float EffectDuration;
};

//////////////////////////////////////////
/// UPDA_ArmorInfo Class
//////////////////////////////////////////

/**
 * @brief Data Asset for Armor Items containing specific properties.
 */
UCLASS(BlueprintType)
class SURVIVALGAME_API UPDA_ArmorInfo : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    /** Constructor */
    UPDA_ArmorInfo();

    /** Unique identifier for the armor (Used by Data Registry) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Armor")
    FName RegistryKey;

    /** Unique identifier for the armor */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Armor")
    int32 ArmorID;

    /** Name of the armor */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Armor")
    FText ArmorName;

    /** Description of the armor */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Armor")
    FText ArmorDescription;

    /** Type of the armor (e.g., Helmet, Chestplate) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Armor")
    E_ArmorType ArmorType;

    /** Defense value provided by the armor */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Armor", meta = (ClampMin = "0"))
    int32 Defense;

    /** Weight of the armor affecting player stamina and movement */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Armor", meta = (ClampMin = "0.0"))
    float Weight;

    /** Rarity of the armor */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Armor")
    E_ItemRarity Rarity;

    /** Required crafting skill to create the armor */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Armor")
    E_CraftingSkill RequiredCraftingSkill;

    /** Crafting station needed to create the armor */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Armor")
    E_CraftingStation CraftingStation;

    /** Durability of the armor */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Armor", meta = (ClampMin = "0"))
    int32 Durability;

    /** Effects applied when the armor is equipped */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Armor|Effects")
    TArray<FArmorEffect> ArmorEffects;

    /** Icon representing the armor in the inventory */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Armor|Visuals")
    UTexture2D* ArmorIcon;

    /** Mesh representing the armor in the world */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Armor|Visuals")
    UStaticMesh* ArmorMesh;

    /** Sound played when the armor is equipped or unequipped */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Armor|Audio")
    USoundBase* ArmorSound;

    /** Particle effect displayed when the armor is equipped */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Armor|Effects")
    UParticleSystem* ArmorParticle;

private:
    /** Cached total defense value for performance optimization */
    UPROPERTY(Transient)
    float CachedTotalDefense;

public:
    /** Retrieves the cached total defense */
    UFUNCTION(BlueprintCallable, Category = "Armor|Defense")
    float GetCachedTotalDefense() const;

    /** Updates the cached total defense */
    UFUNCTION(BlueprintCallable, Category = "Armor|Defense")
    void UpdateTotalDefense();
};
