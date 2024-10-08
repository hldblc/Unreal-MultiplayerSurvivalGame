// PDA_ToolInfo.cpp

#include "SurvivalGame/Data/PDA_ToolInfo.h"
#include "Engine/Engine.h"

UPDA_ToolInfo::UPDA_ToolInfo()
    : RegistryKey(NAME_None)
    , ToolID(0)
    , ToolName(FText::FromString("Tool Name"))
    , ToolDescription(FText::FromString("Tool Description"))
    , ToolType(E_ToolType::None)
    , BaseDurability(100)
    , CurrentDurability(100)
    , DurabilityDecayRate(0.0f) // Example decay rate
    , Weight(0.0f)
    , Rarity(E_ItemRarity::Common)
    , RequiredCraftingSkill(E_CraftingSkill::None)
    , CraftingStation(E_CraftingStation::None)
    , ToolEffects(TArray<FToolEffect>())
    , ResourceEfficiencyMap(TMap<E_ResourceType, float>())
    , ToolIcon(nullptr)
    , ToolMesh(nullptr)
    , ToolSound(nullptr)
    , ToolParticle(nullptr)
    , ConditionMaterial(nullptr)
    , RepairCostMap(TMap<FName, int32>())
    , bIsBroken(false)
    , CachedEfficiencyBoost(0.0f)
{
    // Initialize default values or perform setup if necessary
}

void UPDA_ToolInfo::DegradeTool(float UsageFactor)
{
    if (bIsBroken)
    {
        // Tool is already broken; no further degradation
        return;
    }

    // Calculate durability loss based on usage factor
    float DurabilityLoss = DurabilityDecayRate * UsageFactor;
    CurrentDurability = FMath::Max(CurrentDurability - FMath::RoundToInt(DurabilityLoss), 0);

    // Check if tool is broken
    if (CurrentDurability == 0)
    {
        bIsBroken = true;
        // Optionally, trigger events or notifications about the broken tool
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Your tool has broken!"));
        }
    }

    // Update efficiency based on current durability
    UpdateEfficiency(E_ResourceType::None); // Replace with actual resource type as needed
}

bool UPDA_ToolInfo::RepairTool(const TMap<FName, int32>& AvailableResources)
{
    // Check if required resources are available
    for (const auto& Cost : RepairCostMap)
    {
        if (!AvailableResources.Contains(Cost.Key) || AvailableResources[Cost.Key] < Cost.Value)
        {
            // Missing required resource or insufficient quantity
            return false;
        }
    }

    // Deduct the required resources (this should be handled in the calling function)
    // ...

    // Restore durability
    CurrentDurability = BaseDurability;
    bIsBroken = false;

    // Update efficiency
    UpdateEfficiency(E_ResourceType::None); // Replace with actual resource type as needed

    // Optionally, trigger events or notifications about the repaired tool
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Your tool has been repaired."));
    }

    return true;
}

void UPDA_ToolInfo::UpdateEfficiency(E_ResourceType ResourceType)
{
    // Reset cached efficiency
    CachedEfficiencyBoost = 0.0f;

    if (ResourceEfficiencyMap.Contains(ResourceType))
    {
        CachedEfficiencyBoost = ResourceEfficiencyMap[ResourceType];
    }

    // Adjust efficiency based on current durability
    float DurabilityFactor = static_cast<float>(CurrentDurability) / static_cast<float>(BaseDurability);
    CachedEfficiencyBoost *= DurabilityFactor;

    // You can use CachedEfficiencyBoost in your gameplay logic to affect tool performance
}
