// PDA_WeaponInfo.h

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SurvivalGame/Enums/ItemEnums.h"
#include "PDA_WeaponInfo.generated.h"

//////////////////////////////////////////
/// Weapon Effect Structure
//////////////////////////////////////////

/**
 * @brief Structure defining effects that weapons can have when used or equipped.
 */
USTRUCT(BlueprintType)
struct FWeaponEffect
{
    GENERATED_BODY()

public:
    /** Type of effect (e.g., Fire, Ice) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect")
    E_SpecialEffectType EffectType;

    /** Magnitude of the effect */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect", meta = (ClampMin = "0.0"))
    float EffectMagnitude;

    /** Duration of the effect in seconds */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect", meta = (ClampMin = "0.0"))
    float EffectDuration;
};

//////////////////////////////////////////
/// UPDA_WeaponInfo Class
//////////////////////////////////////////

/**
 * @brief Data Asset for Weapon Items containing specific properties.
 */
UCLASS(BlueprintType)
class SURVIVALGAME_API UPDA_WeaponInfo : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    /** Constructor */
    UPDA_WeaponInfo();

    /** Unique identifier for the weapon (Used by Data Registry) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
    FName RegistryKey;

    /** Unique identifier for the weapon */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
    int32 WeaponID;

    /** Name of the weapon */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
    FText WeaponName;

    /** Description of the weapon */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
    FText WeaponDescription;

    /** Type of the weapon (e.g., Sword, Bow, Axe) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
    E_WeaponType WeaponType;

    /** Damage value of the weapon */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon", meta = (ClampMin = "0"))
    int32 Damage;

    /** Weight of the weapon affecting player stamina and movement */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon", meta = (ClampMin = "0.0"))
    float Weight;

    /** Rarity of the weapon */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
    E_ItemRarity Rarity;

    /** Required crafting skill to create the weapon */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
    E_CraftingSkill RequiredCraftingSkill;

    /** Crafting station needed to craft the weapon */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
    E_CraftingStation CraftingStation;

    /** Whether the weapon is two-handed */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
    bool bIsTwoHanded;

    /** Projectile type if the weapon is ranged */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Ranged", meta = (EditCondition = "WeaponType == E_WeaponType::Ranged"))
    E_ProjectileType ProjectileType;

    /** Effects applied when the weapon is used */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Effects")
    TArray<FWeaponEffect> WeaponEffects;

    /** Icon representing the weapon in the inventory */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Visuals")
    UTexture2D* WeaponIcon;

    /** Mesh representing the weapon in the world */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Visuals")
    UStaticMesh* WeaponMesh;

    /** Sound played when the weapon is swung or fired */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Audio")
    USoundBase* WeaponSound;

    /** Particle effect displayed when the weapon is used */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Effects")
    UParticleSystem* WeaponParticle;

private:
    /** Cached total damage for performance optimization */
    UPROPERTY(Transient)
    float CachedTotalDamage;

public:
    /** Retrieves the cached total damage */
    UFUNCTION(BlueprintCallable, Category = "Weapon|Damage")
    float GetCachedTotalDamage() const;

    /** Updates the cached total damage */
    UFUNCTION(BlueprintCallable, Category = "Weapon|Damage")
    void UpdateTotalDamage();
};
