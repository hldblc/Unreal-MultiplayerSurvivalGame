// PDA_ItemInfo.h

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h" // Include Gameplay Tags
#include "SurvivalGame/Enums/ItemEnums.h"
#include "SurvivalGame/Structs/S_ItemStructure.h"
#include "PDA_ItemInfo.generated.h"

/**
 * @brief Primary Data Asset class containing static item properties.
 */
UCLASS(BlueprintType)
class SURVIVALGAME_API UPDA_ItemInfo : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    /** Constructor */
    UPDA_ItemInfo();

    /** Unique identifier for the item (Used by Data Registry) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item", meta = (DisplayName = "Registry Key"))
    FName RegistryKey;

    /** Unique identifier for the item */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
    int32 ItemID;

    /** Name of the item */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
    FText ItemName;

    /** Description of the item */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
    FText ItemDescription;

    /** Indicates if the item is stackable */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
    bool bIsStackable;

    /** Maximum stack size for stackable items */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item", meta = (EditCondition = "bIsStackable", ClampMin = "1"))
    int32 MaxStackSize;

    /** Category of the item for sorting and management */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
    E_ItemCategory ItemCategory;

    /** Item Rarity */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
    E_ItemRarity ItemRarity;

    /** Gameplay Tags associated with the item */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|Tags")
    FGameplayTagContainer ItemTags;

    /** Item icon displayed in the inventory */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|Visuals")
    UTexture2D* ItemIcon;

    /** Item mesh displayed in the world */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|Visuals")
    UStaticMesh* ItemMesh;

    /** Item sound played when used or equipped */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|Audio")
    USoundBase* ItemSound;

    /** Item particle effect displayed when used or equipped */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|Effects")
    UParticleSystem* ItemParticle;

    //////////////////////////////////////////
    /// Durability and Health
    //////////////////////////////////////////

    /** Maximum health or durability of the item */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Durability", meta = (ClampMin = "1"))
    int32 MaxDurability;

    /** Durability decay rate determining how quickly durability decreases */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Durability", meta = (ClampMin = "0.0"))
    float DurabilityDecayRate;

    /** Indicates if the item is breakable */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Durability")
    bool bIsDestroyable;

    //////////////////////////////////////////
    /// Ammunition (if applicable)
    //////////////////////////////////////////

    /** Indicates if the item uses ammunition */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ammunition")
    bool bUsesAmmo;

    /** Maximum ammunition capacity */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ammunition", meta = (EditCondition = "bUsesAmmo", ClampMin = "1"))
    int32 MaxAmmo;

    //////////////////////////////////////////
    /// Consumable Properties
    //////////////////////////////////////////

    /** Indicates if the item is consumable */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable")
    bool bIsConsumable;

    /** Nutrition value provided when the item is consumed */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable", meta = (EditCondition = "bIsConsumable", ClampMin = "0"))
    int32 NutritionValue;

    /** Toxicity level of the item affecting player health or stamina */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable", meta = (ClampMin = "0"))
    int32 Toxicity;

    /** Effect triggered when the item is used */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable", meta = (EditCondition = "bIsConsumable"))
    FItemEffectOnUse EffectOnUse;

    /** Decay time after which the item starts to spoil or degrade */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable", meta = (EditCondition = "bIsConsumable", ClampMin = "0.0"))
    float DecayTime;

    //////////////////////////////////////////
    /// Physical and Special Properties
    //////////////////////////////////////////

    /** Weight class of the item affecting movement or stamina */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physical")
    E_WeightClass WeightClass;

    /** Indicates if the item can act as a fire source */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physical")
    bool bIsFireSource;

    /** Temperature effect on the player when using or wearing the item */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physical", meta = (ClampMin = "-100.0", ClampMax = "100.0"))
    float TemperatureEffect;

    /** Warmth rating determining protection against cold environments */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physical", meta = (ClampMin = "0.0"))
    float WarmthRating;

    /** Indicates if the item is flammable */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physical")
    bool bIsFlammable;

    /** Burn time defining how long the item can burn */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physical", meta = (EditCondition = "bIsFlammable", ClampMin = "0.0"))
    float BurnTime;

    /** Special ability or effect granted when the item is used or equipped */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Special")
    FString SpecialAbility;

    //////////////////////////////////////////
    /// Additional Properties
    //////////////////////////////////////////

    /** Monetary value of the item used for trading or bartering */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Additional", meta = (ClampMin = "0"))
    int32 ItemValue;

    /** Indicates if the item is a quest item */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Additional")
    bool bIsQuestItem;

    /** Indicates if the item is unique in the game world */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Additional")
    bool bIsUnique;

    /** Indicates if the item is a container */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Container")
    bool bIsContainer;

    /** Container size specifying how many items it can hold */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Container", meta = (EditCondition = "bIsContainer", ClampMin = "1"))
    int32 ContainerSize;

    //////////////////////////////////////////
    /// Modifiers and States
    //////////////////////////////////////////

    /** Default modifiers/enchantments applied to the item */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Modifiers")
    TArray<FItemModifier> DefaultModifiers;

    /** Initial state of the item (e.g., Raw, Processed, Broken) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "State")
    E_ItemState InitialItemState;

    // Close the class definition
};
