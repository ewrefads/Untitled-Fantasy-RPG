// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellProjectile.h"

// Sets default values
ASpellProjectile::ASpellProjectile()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASpellProjectile::setTargetAndDamage(ACharacter* tar, int dmg)
{
	target = tar;
	damage = dmg;
}



// Called when the game starts or when spawned
void ASpellProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpellProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector targetLoc = target ->GetActorLocation();
	FVector currentLoc = GetActorLocation();
	FVector direction = FVector(targetLoc.X - currentLoc.X, targetLoc.Y - currentLoc.Y, targetLoc.Z - currentLoc.Z);
	FVector Velocity = direction.GetSafeNormal() * speed * DeltaTime;
	SetActorLocation(GetActorLocation() + Velocity);
}

// Called to bind functionality to input
void ASpellProjectile::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

