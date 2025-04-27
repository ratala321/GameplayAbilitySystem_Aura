


#include "Character/AuraCharacter.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "Player/AuraPlayerState.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerState.h"

AAuraCharacter::AAuraCharacter()
{
	UCharacterMovementComponent* AuraCharacterMovement = GetCharacterMovement();
	AuraCharacterMovement->bOrientRotationToMovement = true;
	AuraCharacterMovement->RotationRate = FRotator(0.f, 400.f, 0.f);
	AuraCharacterMovement->bConstrainToPlane = true;
	AuraCharacterMovement->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init for the Server.
	InitAbilityActor();
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init for Client.
	InitAbilityActor();
}

void AAuraCharacter::InitAbilityActor()
{
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState)

	AbilitySystemComponent = Cast<UAuraAbilitySystemComponent>(AuraPlayerState->GetAbilitySystemComponent());
	AttributeSet = Cast<UAuraAttributeSet>(AuraPlayerState->GetAttributeSet());
	
	AbilitySystemComponent->InitAbilityActorInfo(AuraPlayerState, this);
}


