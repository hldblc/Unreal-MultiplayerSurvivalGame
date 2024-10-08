// PDA_ConsumableInfo.cpp

#include "SurvivalGame/Data/PDA_ConsumableInfo.h"

UPDA_ConsumableInfo::UPDA_ConsumableInfo()
	: RegistryKey(NAME_None)
	, ConsumableID(0)
	, ConsumableName(FText::FromString("Consumable Name"))
	, ConsumableDescription(FText::FromString("Consumable Description"))
	, EffectType(E_ItemEffectType::None)
	, EffectStrength(0.0f)
	, EffectDuration(0.0f)
	, NutritionValue(0)
	, Toxicity(0)
	, DecayTime(0.0f)
	, Rarity(E_ItemRarity::Common)
	, RequiredCraftingSkill(E_CraftingSkill::None)
	, CraftingStation(E_CraftingStation::None)
	, ConsumableEffects()
	, ConsumableIcon(nullptr)
	, ConsumableMesh(nullptr)
	, ConsumableSound(nullptr)
	, ConsumableParticle(nullptr)
	, CachedEffectValue(0.0f)
{
	// Optionally, pre-reserve space if you know the typical number of effects
	ConsumableEffects.Reserve(4);
}

float UPDA_ConsumableInfo::GetCachedEffectValue() const
{
	return CachedEffectValue;
}

void UPDA_ConsumableInfo::UpdateEffectValue()
{
	// Example calculation: effect strength multiplied by duration
	CachedEffectValue = EffectStrength * EffectDuration;
}
