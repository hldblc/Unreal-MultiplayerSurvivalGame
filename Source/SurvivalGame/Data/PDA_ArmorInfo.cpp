// PDA_ArmorInfo.cpp

#include "SurvivalGame/Data/PDA_ArmorInfo.h"

UPDA_ArmorInfo::UPDA_ArmorInfo()
	: RegistryKey(NAME_None)
	, ArmorID(0)
	, ArmorName(FText::FromString("Armor Name"))
	, ArmorDescription(FText::FromString("Armor Description"))
	, ArmorType(E_ArmorType::None)
	, Defense(15)
	, Weight(10.0f)
	, Rarity(E_ItemRarity::Common)
	, RequiredCraftingSkill(E_CraftingSkill::None)
	, CraftingStation(E_CraftingStation::None)
	, Durability(100)
	, ArmorEffects(TArray<FArmorEffect>())
	, ArmorIcon(nullptr)
	, ArmorMesh(nullptr)
	, ArmorSound(nullptr)
	, ArmorParticle(nullptr)
	, CachedTotalDefense(0.0f)
{
	// Initialize ArmorEffects with default values if necessary
}

float UPDA_ArmorInfo::GetCachedTotalDefense() const
{
	return CachedTotalDefense;
}

void UPDA_ArmorInfo::UpdateTotalDefense()
{
	// Example calculation: base defense plus sum of effect magnitudes
	CachedTotalDefense = static_cast<float>(Defense);
	for (const FArmorEffect& Effect : ArmorEffects)
	{
		CachedTotalDefense += Effect.EffectMagnitude;
	}

	// Ensure total defense doesn't fall below base defense
	CachedTotalDefense = FMath::Max(CachedTotalDefense, static_cast<float>(Defense));
}
