// ItemMaster.cpp

#include "SurvivalGame/Actors/ItemMaster.h"
#include "SurvivalGame/Data//PDA_ItemInfo.h" // Include the full definition of UPDA_ItemInfo
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/Engine.h" // For GEngine

// Sets default values
AItemMaster::AItemMaster()
{
    // Set this actor to call Tick() every frame. You can turn this off to improve performance if not needed.
    PrimaryActorTick.bCanEverTick = true;

    // Initialize Collision Component
    CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
    CollisionComponent->InitSphereRadius(50.0f);
    CollisionComponent->SetCollisionProfileName(TEXT("Trigger"));
    RootComponent = CollisionComponent;

    // Initialize Static Mesh Component
    ItemMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
    ItemMeshComponent->SetupAttachment(RootComponent);
    ItemMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision); // Disable collision for mesh; handled by collision component
}

// Called when the game starts or when spawned
void AItemMaster::BeginPlay()
{
    Super::BeginPlay();
    
    // Initialize the item based on the Data Asset
    InitializeItem();
}

// Called every frame
void AItemMaster::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // You can implement any per-frame logic here if necessary
}

void AItemMaster::InitializeItem()
{
    if (ItemInfo)
    {
        // Set the static mesh if available
        if (ItemInfo->ItemMesh)
        {
            ItemMeshComponent->SetStaticMesh(ItemInfo->ItemMesh);
        }

        // Optionally set other properties like sounds, particles, etc.
        // Example: Display item information in the log
        FString Info = FString::Printf(TEXT(
            "Initializing Item:\nName: %s\nDescription: %s\nRarity: %s\nCategory: %s"),
            *ItemInfo->ItemName.ToString(),
            *ItemInfo->ItemDescription.ToString(),
            *UEnum::GetValueAsString(ItemInfo->ItemRarity),
            *UEnum::GetValueAsString(ItemInfo->ItemCategory));

        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Info);
        }

        // Additional initialization based on ItemInfo properties can be done here
    }
    else
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ItemInfo is not assigned to ItemMaster."));
        }
    }
}

void AItemMaster::OnPickedUp()
{
    if (ItemInfo)
    {
        FString PickupInfo = FString::Printf(TEXT("Picked Up: %s"), *ItemInfo->ItemName.ToString());

        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, PickupInfo);
        }

        // Implement additional pickup logic here (e.g., adding to inventory, playing sound)
    }
    else
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("ItemInfo is not assigned to ItemMaster."));
        }
    }

    // Destroy the item actor after pickup
    Destroy();
}

void AItemMaster::OnUsed()
{
    if (ItemInfo)
    {
        FString UseInfo = FString::Printf(TEXT("Used: %s"), *ItemInfo->ItemName.ToString());

        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, UseInfo);
        }

        // Implement item usage logic here based on ItemInfo properties
        // For example, apply effects, consume the item if it's consumable, etc.
    }
    else
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("ItemInfo is not assigned to ItemMaster."));
        }
    }
}

void AItemMaster::RepairItem()
{
    if (ItemInfo)
    {
        // Example: Restore durability to maximum
        // Note: Actual implementation depends on how durability is managed in your game
        FString RepairInfo = FString::Printf(TEXT("Repaired: %s to Max Durability (%d)"), *ItemInfo->ItemName.ToString(), ItemInfo->MaxDurability);

        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, RepairInfo);
        }

        // Implement actual repair logic here
    }
    else
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("ItemInfo is not assigned to ItemMaster."));
        }
    }
}

void AItemMaster::UpgradeItem()
{
    if (ItemInfo)
    {
        // Example: Upgrade item rarity
        // Note: Actual implementation depends on your game mechanics
        if (ItemInfo->ItemRarity != E_ItemRarity::Legendary)
        {
            // Promote to next rarity level
            int32 CurrentRarity = static_cast<int32>(ItemInfo->ItemRarity);
            int32 NewRarity = CurrentRarity + 1;

            // Ensure we don't exceed the maximum defined rarity
            if (NewRarity < static_cast<int32>(E_ItemRarity::Invalid))
            {
                ItemInfo->ItemRarity = static_cast<E_ItemRarity>(NewRarity);
                FString UpgradeInfo = FString::Printf(TEXT("Upgraded: %s to %s Rarity"), *ItemInfo->ItemName.ToString(), *UEnum::GetValueAsString(ItemInfo->ItemRarity));

                if (GEngine)
                {
                    GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Magenta, UpgradeInfo);
                }

                // Update mesh or other properties based on new rarity if needed
                if (ItemInfo->ItemMesh)
                {
                    ItemMeshComponent->SetStaticMesh(ItemInfo->ItemMesh);
                }
            }
            else
            {
                if (GEngine)
                {
                    GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("Item has reached maximum rarity."));
                }
            }
        }
        else
        {
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("Item is already Legendary."));
            }
        }
    }
    else
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("ItemInfo is not assigned to ItemMaster."));
        }
    }
}
