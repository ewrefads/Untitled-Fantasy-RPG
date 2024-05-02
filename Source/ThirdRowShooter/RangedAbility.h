// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "GameFramework/Character.h"
#include "SpellProjectile.h"
#include "RangedAbility.generated.h"


/**
 * 
 */
UCLASS()
class THIRDROWSHOOTER_API ARangedAbility : public AAbility
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int hitModifier;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int damagedie;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int numDamageDice;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int damageModifier;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ACharacter* Abilitytarget;

	virtual void spawnProjectile(int damage);

	void Cast() override;
};
