// ItemMaster.cpp

#include "SurvivalGame/Actors/ItemMaster.h"
#include "Engine/Engine.h"

AItemMaster::AItemMaster()
{
    // Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

void AItemMaster::BeginPlay()
{
    Super::BeginPlay();
}

void AItemMaster::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AItemMaster::InitializeItem()
{
    // Initialize Weapon Info
    if (WeaponInfo)
    {
        int32 WeaponID = WeaponInfo->WeaponID;
        FString WeaponName = WeaponInfo->WeaponName.ToString();
        FString WeaponDescription = WeaponInfo->WeaponDescription.ToString();
        float TotalDamage = WeaponInfo->GetCachedTotalDamage();

        // Example: Log Weapon Info
        FString WeaponInfoString = FString::Printf(TEXT("Weapon ID: %d\nName: %s\nDescription: %s\nTotal Damage: %.2f"),
                                                  WeaponID,
                                                  *WeaponName,
                                                  *WeaponDescription,
                                                  TotalDamage);
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, WeaponInfoString);
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("WeaponInfo is nullptr!"));
    }

    // Initialize Armor Info
    if (ArmorInfo)
    {
        int32 ArmorID = ArmorInfo->ArmorID;
        FString ArmorName = ArmorInfo->ArmorName.ToString();
        FString ArmorDescription = ArmorInfo->ArmorDescription.ToString();
        float TotalDefense = ArmorInfo->GetCachedTotalDefense();

        // Example: Log Armor Info
        FString ArmorInfoString = FString::Printf(TEXT("Armor ID: %d\nName: %s\nDescription: %s\nTotal Defense: %.2f"),
                                                 ArmorID,
                                                 *ArmorName,
                                                 *ArmorDescription,
                                                 TotalDefense);
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, ArmorInfoString);
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("ArmorInfo is nullptr!"));
    }

    // Repeat similarly for other item types like Consumables, Tools, Resources
}

void AItemMaster::DisplayItemInfo()
{
    // This function can be expanded to display item information in the UI or other systems
    InitializeItem();
}
