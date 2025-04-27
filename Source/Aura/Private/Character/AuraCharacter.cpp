


#include "Character/AuraCharacter.h"
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
