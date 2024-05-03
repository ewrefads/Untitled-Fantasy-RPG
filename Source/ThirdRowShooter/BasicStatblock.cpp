// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicStatblock.h"

// Sets default values for this component's properties
UBasicStatblock::UBasicStatblock()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UBasicStatblock::CalculateDerivedStats()
{
	StrengthModifier = Strength / 2 - 5;
	DexterityModifier = Dexterity / 2 - 5;
	ConstitutionModifier = Constitution / 2 - 5;
	IntelligenceModifier = Intelligence / 2 - 5;
	WisdomModifier = Wisdom / 2 - 5;
	CharismaModifier = Charisma / 2 - 5;
	StrengthAttack = StrengthModifier + ProficiencyModifier;
	DexterityAttack = DexterityModifier + ProficiencyModifier;
	SpellAttack = IntelligenceModifier + ProficiencyModifier;
	SpellDC = 8 + SpellAttack + ProficiencyModifier;
	int healthPrHitDice = 0;
	switch (hitDiceSize)
	{
	case 4:
		healthPrHitDice = 2;
		break;
	case 6:
		healthPrHitDice = 3;
	case 8:
		healthPrHitDice = 4;
	case 10:
		healthPrHitDice = 5;
	case 12:
		healthPrHitDice = 6;
	default:
		healthPrHitDice = 4;
		break;
	}
	maxHealth = healthPrHitDice * numberOfHitDice + ConstitutionModifier * numberOfHitDice;
	health = maxHealth;

	ArmorClass = 10 + DexterityModifier;
}

// Called when the game starts
void UBasicStatblock::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBasicStatblock::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

