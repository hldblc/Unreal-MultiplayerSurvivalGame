// PDA_ResourceInfo.cpp

#include "SurvivalGame/Data/PDA_ResourceInfo.h"

UPDA_ResourceInfo::UPDA_ResourceInfo()
	: RegistryKey(NAME_None)
	, ResourceID(0)
	, ResourceName(FText::FromString("Resource Name"))
	, ResourceDescription(FText::FromString("Resource Description"))
	, ResourceType(E_ResourceType::None)
	, Quantity(0)
	, Rarity(E_ItemRarity::Common)
	, RequiredCraftingSkill(E_CraftingSkill::None)
	, CraftingStation(E_CraftingStation::None)
	, Durability(100)
	, ResourceEffects()
	, ResourceIcon(nullptr)
	, ResourceMesh(nullptr)
	, ResourceSound(nullptr)
	, ResourceParticle(nullptr)
	, CachedDurabilityDecay(0.0f)
{
	// Optionally, pre-reserve space if you know the typical number of effects
	ResourceEffects.Reserve(4);
}

float UPDA_ResourceInfo::GetCachedDurabilityDecay() const
{
	return CachedDurabilityDecay;
}

void UPDA_ResourceInfo::UpdateDurabilityDecay(float DeltaTime)
{
	// Example calculation: decay rate multiplied by delta time
	// Assume DurabilityDecayRate is a property you define elsewhere or calculate based on other factors
	float DurabilityDecayRate = 0.1f; // Example value

	CachedDurabilityDecay = DurabilityDecayRate * DeltaTime;

	// Ensure durability doesn't drop below zero
	Durability = FMath::Max(Durability - static_cast<int32>(CachedDurabilityDecay), 0);
}
