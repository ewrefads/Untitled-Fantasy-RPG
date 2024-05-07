// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ability.generated.h"

UCLASS()
class THIRDROWSHOOTER_API AAbility : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAbility();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float castTime;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	float remainingCastTime = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float cooldown = 1;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	float remainingCooldown = 0;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float channelTime = 0;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	float remainingchannelTime = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float channelTickTime = 0;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	float remainingchannelTickTime = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool movementCancelsAbility = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ACharacter* Abilitytarget;

	UFUNCTION(BlueprintCallable)
	void BeginCast();

	UFUNCTION(BlueprintCallable)
	void CancelCast();

	UFUNCTION(BlueprintCallable)
	void CancelCooldown();

	UFUNCTION(BlueprintCallable)
	void BeginChannel();

	UFUNCTION(BlueprintCallable)
	void CancelChannel();

	UFUNCTION(BlueprintCallable)
	virtual void Cast();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
