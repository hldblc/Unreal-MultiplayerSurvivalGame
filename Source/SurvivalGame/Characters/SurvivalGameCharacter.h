// SurvivalGameCharacter.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "GameFramework/SpringArmComponent.h" // Include for USpringArmComponent
#include "Camera/CameraComponent.h"        // Include for UCameraComponent
#include "SurvivalGameCharacter.generated.h"

// Forward declarations
class UInputAction;
struct FInputActionValue;

// Declare the log category
DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

/**
 * @brief The main character class for the Survival Game.
 *        Handles movement, camera setup, and input bindings.
 */
UCLASS(config=Game)
class ASurvivalGameCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    /** Constructor */
    ASurvivalGameCharacter();

    /** Returns FirstPersonCameraComponent subobject **/
    UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

    /** Returns FirstPersonSpringArmComponent subobject **/
    USpringArmComponent* GetFirstPersonSpringArmComponent() const { return FirstPersonSpringArmComponent; }

    /** Returns ThirdPersonCameraComponent subobject **/
    UCameraComponent* GetThirdPersonCameraComponent() const { return ThirdPersonCameraComponent; }

    /** Returns ThirdPersonSpringArmComponent subobject **/
    USpringArmComponent* GetThirdPersonSpringArmComponent() const { return ThirdPersonSpringArmComponent; }

    /////////////////////////////////////// First Person ////////////////////////////////////////////////

    /** Spring Arm for First Person Camera */
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera|FirstPerson", meta = (AllowPrivateAccess = "true"))
    USpringArmComponent* FirstPersonSpringArmComponent;

    /** First Person Camera */
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera|FirstPerson", meta = (AllowPrivateAccess = "true"))
    UCameraComponent* FirstPersonCameraComponent;

    /////////////////////////////////////// Third Person ////////////////////////////////////////////////

    /** Spring Arm for Third Person Camera */
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera|ThirdPerson", meta = (AllowPrivateAccess = "true"))
    USpringArmComponent* ThirdPersonSpringArmComponent;

    /** Third Person Camera */
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera|ThirdPerson", meta = (AllowPrivateAccess = "true"))
    UCameraComponent* ThirdPersonCameraComponent;

    /////////////////////////////////////// Enhanced Input System //////////////////////////////////////

    /** Jump Input Action */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta=(AllowPrivateAccess = "true"))
    UInputAction* JumpAction;

    /** Move Input Action */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta=(AllowPrivateAccess = "true"))
    UInputAction* MoveAction;

    /** Look Input Action */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (AllowPrivateAccess = "true"))
    UInputAction* LookAction;

protected:
    /** Called when the game starts or when spawned */
    virtual void BeginPlay() override;

    /** Called for movement input */
    void Move(const FInputActionValue& Value);

    /** Called for looking input */
    void Look(const FInputActionValue& Value);

    // APawn interface
    virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
    // End of APawn interface
};
