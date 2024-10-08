// PDA_WeaponInfo.cpp

#include "SurvivalGame/Data/PDA_WeaponInfo.h"

UPDA_WeaponInfo::UPDA_WeaponInfo()
    : RegistryKey(NAME_None)
    , WeaponID(0)
    , WeaponName(FText::FromString("Weapon Name"))
    , WeaponDescription(FText::FromString("Weapon Description"))
    , WeaponType(E_WeaponType::None)
    , Damage(10)
    , Weight(5.0f)
    , Rarity(E_ItemRarity::Common)
    , RequiredCraftingSkill(E_CraftingSkill::None)
    , CraftingStation(E_CraftingStation::None)
    , bIsTwoHanded(false)
    , ProjectileType(E_ProjectileType::None)
    , WeaponEffects(TArray<FWeaponEffect>())
    , WeaponIcon(nullptr)
    , WeaponMesh(nullptr)
    , WeaponSound(nullptr)
    , WeaponParticle(nullptr)
    , CachedTotalDamage(0.0f)
{
    // Initialize WeaponEffects with default values if necessary
}

float UPDA_WeaponInfo::GetCachedTotalDamage() const
{
    return CachedTotalDamage;
}

void UPDA_WeaponInfo::UpdateTotalDamage()
{
    // Example calculation: base damage plus sum of effect magnitudes
    CachedTotalDamage = static_cast<float>(Damage);
    for (const FWeaponEffect& Effect : WeaponEffects)
    {
        CachedTotalDamage += Effect.EffectMagnitude;
    }
}
