// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "SpellProjectile.generated.h"

UCLASS()
class THIRDROWSHOOTER_API ASpellProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASpellProjectile();

	void setTargetAndDamage(ACharacter* tar, int dmg, float spd);

	

protected:
	// Called when the game starts or when spawned

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ACharacter* target;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int damage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float speed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UNiagaraComponent* spellEffect;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input

	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	USphereComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, Category = Movement)
	UProjectileMovementComponent* ProjectileMovementComponent;

};
