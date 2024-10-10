// SurvivalGameCharacter.cpp

#include "SurvivalGameCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Engine/LocalPlayer.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ASurvivalGameCharacter

ASurvivalGameCharacter::ASurvivalGameCharacter()
{
    // Set size for collision capsule
    GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

    // ---------------------------------- First Person Setup ----------------------------------

    // Create a Spring Arm Component for First Person
    FirstPersonSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("FirstPersonSpringArm"));
    FirstPersonSpringArmComponent->SetupAttachment(GetMesh(), TEXT("head"));
    FirstPersonSpringArmComponent->TargetArmLength = 0.0f; // Camera at the character's head
    FirstPersonSpringArmComponent->bUsePawnControlRotation = true; // Enables camera rotation based on controller
    FirstPersonSpringArmComponent->bDoCollisionTest = false; // Disable collision testing for first-person

    // Create a Camera Component for First Person
    FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
    FirstPersonCameraComponent->SetupAttachment(FirstPersonSpringArmComponent, USpringArmComponent::SocketName);
    FirstPersonCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f)); // Camera positioned at the end of the spring arm
    FirstPersonCameraComponent->bUsePawnControlRotation = false; // Camera rotation is handled by the spring arm

    // ---------------------------------- Third Person Setup ----------------------------------

    // Create a Spring Arm Component for Third Person
    ThirdPersonSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("ThirdPersonSpringArm"));
    ThirdPersonSpringArmComponent->SetupAttachment(GetMesh()); // Attach to the main mesh (CharacterMesh0)
    ThirdPersonSpringArmComponent->TargetArmLength = 300.0f; // Distance behind the character
    ThirdPersonSpringArmComponent->bUsePawnControlRotation = true; // Enables camera rotation based on controller
    ThirdPersonSpringArmComponent->bDoCollisionTest = true; // Enables collision testing

    // Create a Camera Component for Third Person
    ThirdPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
    ThirdPersonCameraComponent->SetupAttachment(ThirdPersonSpringArmComponent, USpringArmComponent::SocketName);
    ThirdPersonCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f)); // Camera positioned at the end of the spring arm
    ThirdPersonCameraComponent->bUsePawnControlRotation = false; // Camera rotation is handled by the spring arm

    // Optional: Hide the main mesh when in first-person view to prevent clipping
    // GetMesh()->SetOwnerNoSee(true);
}

void ASurvivalGameCharacter::BeginPlay()
{
    // Call the base class
    Super::BeginPlay();
}



void ASurvivalGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    // Set up action bindings
    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        // Jumping
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

        // Moving
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASurvivalGameCharacter::Move);

        // Looking
        EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASurvivalGameCharacter::Look);
    }
    else
    {
        UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
    }
}

void ASurvivalGameCharacter::Move(const FInputActionValue& Value)
{
    // Input is a Vector2D
    FVector2D MovementVector = Value.Get<FVector2D>();

    if (Controller != nullptr)
    {
        // Add movement in the forward and right directions
        AddMovementInput(GetActorForwardVector(), MovementVector.Y);
        AddMovementInput(GetActorRightVector(), MovementVector.X);
    }
}

void ASurvivalGameCharacter::Look(const FInputActionValue& Value)
{
    // Input is a Vector2D
    FVector2D LookAxisVector = Value.Get<FVector2D>();

    if (Controller != nullptr)
    {
        // Add yaw and pitch input to controller
        AddControllerYawInput(LookAxisVector.X);
        AddControllerPitchInput(LookAxisVector.Y);
    }
}
