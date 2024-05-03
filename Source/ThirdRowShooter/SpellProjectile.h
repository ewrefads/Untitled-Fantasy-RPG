// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpellProjectile.generated.h"

UCLASS()
class THIRDROWSHOOTER_API ASpellProjectile : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASpellProjectile();

	void setTargetAndDamage(ACharacter* tar, int dmg);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ACharacter* target;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int damage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float speed;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
