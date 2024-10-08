// PDA_ToolInfo.h

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SurvivalGame/Enums/ItemEnums.h"
#include "PDA_ToolInfo.generated.h"

//////////////////////////////////////////
/// Tool Effect Structure
//////////////////////////////////////////

/**
 * @brief Structure defining effects that tools can have when used.
 */
USTRUCT(BlueprintType)
struct FToolEffect
{
    GENERATED_BODY()

public:
    /** Type of effect (e.g., Efficiency, Durability) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect")
    E_ItemEffectType EffectType;

    /** Magnitude of the effect */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect", meta = (ClampMin = "0.0"))
    float EffectMagnitude;

    /** Duration of the effect in seconds (0 for permanent) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect", meta = (ClampMin = "0.0"))
    float EffectDuration;
};

//////////////////////////////////////////
/// PDA_ToolInfo Class
//////////////////////////////////////////

/**
 * @brief Data Asset for Tool Items containing specific properties.
 */
UCLASS(BlueprintType)
class SURVIVALGAME_API UPDA_ToolInfo : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    /** Constructor */
    UPDA_ToolInfo();

    /** Unique identifier for the tool (Used by Data Registry) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool")
    FName RegistryKey;

    /** Unique identifier for the tool */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool")
    int32 ToolID;

    /** Name of the tool */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool")
    FText ToolName;

    /** Description of the tool */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool")
    FText ToolDescription;

    /** Type of the tool (e.g., Pickaxe, Shovel) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool")
    E_ToolType ToolType;

    /** Base durability of the tool */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool")
    int32 BaseDurability;

    /** Current durability of the tool */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool", meta = (ClampMin = "0"))
    int32 CurrentDurability;

    /** Durability decay rate per second */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool")
    float DurabilityDecayRate;

    /** Weight of the tool affecting player stamina and movement */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool", meta = (ClampMin = "0.0"))
    float Weight;

    /** Rarity of the tool */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool")
    E_ItemRarity Rarity;

    /** Required crafting skill to create the tool */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool")
    E_CraftingSkill RequiredCraftingSkill;

    /** Crafting station needed to create the tool */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool")
    E_CraftingStation CraftingStation;

    /** Effects applied when the tool is used */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool|Effects")
    TArray<FToolEffect> ToolEffects;

    /** Map defining tool's efficiency on different resource types */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool|Efficiency")
    TMap<E_ResourceType, float> ResourceEfficiencyMap;

    /** Icon representing the tool in the inventory */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool|Visuals")
    UTexture2D* ToolIcon;

    /** Mesh representing the tool in the world */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool|Visuals")
    UStaticMesh* ToolMesh;

    /** Sound played when the tool is used */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool|Audio")
    USoundBase* ToolSound;

    /** Particle effect displayed when the tool is used */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool|Effects")
    UParticleSystem* ToolParticle;

    /** Visual indicators for tool condition (e.g., cracks, rust) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool|Visuals")
    UMaterialInterface* ConditionMaterial;

    /** Repair cost in terms of resources or currency */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tool|Repair")
    TMap<FName, int32> RepairCostMap;

    /** Indicates if the tool is broken */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tool|State")
    bool bIsBroken;

    /** Function to handle tool degradation based on usage */
    void DegradeTool(float UsageFactor);

    /** Function to repair the tool */
    bool RepairTool(const TMap<FName, int32>& AvailableResources);

private:
    /** Cached efficiency boost value for performance optimization */
    UPROPERTY(Transient)
    float CachedEfficiencyBoost;

    /** Function to update cached efficiency based on resource type */
    void UpdateEfficiency(E_ResourceType ResourceType);
};
