


#include "Character/AuraEnemy.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Aura/Aura.h"

AAuraEnemy::AAuraEnemy()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AAuraEnemy::HighlightActor()
{
	SetHighlighProperties(true, CUSTOM_DEPTH_RED);
}

void AAuraEnemy::UnHighlightActor()
{
	SetHighlighProperties(false, 0.f);
}

void AAuraEnemy::SetHighlighProperties(bool bRenderCustomDepth, int StencilValue)
{
	GetMesh()->SetRenderCustomDepth(bRenderCustomDepth);
	GetMesh()->SetCustomDepthStencilValue(StencilValue);
	
	Weapon->SetRenderCustomDepth(bRenderCustomDepth);
	Weapon->SetCustomDepthStencilValue(StencilValue);
}
