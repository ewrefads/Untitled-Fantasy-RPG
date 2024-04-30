// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability.h"

// Sets default values
AAbility::AAbility()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AAbility::BeginCast()
{
	remainingCastTime = castTime;
}

void AAbility::CancelCast()
{
	remainingCastTime = 0;
}

void AAbility::CancelCooldown()
{
	remainingCooldown = 0;
}

void AAbility::Cast()
{
}

// Called when the game starts or when spawned
void AAbility::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAbility::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (remainingCastTime > 0)
	{
		remainingCastTime -= DeltaTime;
		if (remainingCastTime <= 0)
		{
			remainingCooldown = cooldown;
			Cast();
		}
	}
	if (remainingCooldown > 0)
	{
		remainingCooldown -= DeltaTime;
	}

}

