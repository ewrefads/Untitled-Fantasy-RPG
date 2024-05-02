// Fill out your copyright notice in the Description page of Project Settings.


#include "RangedAbility.h"
#include "BasicStatblock.h"
#include "Math/UnrealMathUtility.h"

void ARangedAbility::spawnProjectile(int damage)
{
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo; 
	GetWorld()->SpawnActor<ASpellProjectile>(Location, Rotation, SpawnInfo)->setTargetAndDamage(Abilitytarget, damage);
}

void ARangedAbility::Cast()
{
	if(Abilitytarget != NULL){
		UBasicStatblock* enemyStatBloc = Abilitytarget->GetComponentByClass<UBasicStatblock>();
		int ac = enemyStatBloc ->ArmorClass;
		int diceRoll = FMath::RandRange(1, 20);
		int total = diceRoll + hitModifier;
		int damage = 0;
		if (total >= ac)
		{
			for (size_t i = 0; i < numDamageDice; i++)
			{
				damage+= FMath::RandRange(1, damagedie);
			}
			damage += damageModifier;
		}
		spawnProjectile(damage);
	}
	
}
