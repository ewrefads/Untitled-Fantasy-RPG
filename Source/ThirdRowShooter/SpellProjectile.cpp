// Fill out your copyright notice in the Description page of Project Settings.

#include "SpellProjectile.h"

// Sets default values
ASpellProjectile::ASpellProjectile()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));
	}

	if (!CollisionComponent)
	{
		// Use a sphere as a simple collision representation.
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
		// Set the sphere's collision radius.
		CollisionComponent->InitSphereRadius(15.0f);
		// Set the root component to be the collision component.
		RootComponent = CollisionComponent;
	}

	if (!ProjectileMovementComponent)
	{
		// Use this component to drive this projectile's movement.
		ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
		ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
		ProjectileMovementComponent->InitialSpeed = 3000.0f;
		ProjectileMovementComponent->MaxSpeed = 3000.0f;
		ProjectileMovementComponent->bRotationFollowsVelocity = true;
		ProjectileMovementComponent->bShouldBounce = true;
		ProjectileMovementComponent->Bounciness = 0.3f;
		ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
	}

}

void ASpellProjectile::setTargetAndDamage(ACharacter* tar, int dmg, float spd)
{
	target = tar;
	damage = dmg;
	speed = spd;
}


// Called when the game starts or when spawned

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

// Called to bind functionality to inpu

