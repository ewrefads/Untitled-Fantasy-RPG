// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CaptureZone.h"
#include "AIStatblock.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THIRDROWSHOOTER_API UAIStatblock : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAIStatblock();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ACaptureZone* currentCaptureZone;

	UPROPERTY(BlueprintReadOnly)
	bool alive = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float accuracy = 0.5;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float health = 40;

	UPROPERTY(BlueprintReadOnly)
	float maxHealth;

	UFUNCTION(BlueprintCallable)
	void TakeDamage(int dmg);

	UFUNCTION(BlueprintCallable)
	void OnOverlapBegin(ACaptureZone* capureZone);

	/** called when something leaves the sphere component */
	UFUNCTION(BlueprintCallable)
	void OnOverlapEnd(ACaptureZone* capureZone);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	

		
};
