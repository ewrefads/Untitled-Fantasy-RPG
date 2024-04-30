// Fill out your copyright notice in the Description page of Project Settings.


#include "AIStatblock.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <typeinfo>
#include "CaptureZone.h"

// Sets default values for this component's properties
UAIStatblock::UAIStatblock()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UAIStatblock::TakeDamage(int dmg)
{
	health -= dmg;
	if (health <= 0)
	{
		GetOwner()->GetComponentByClass<USkeletalMeshComponent>()->SetSimulatePhysics(true);
		GetOwner()->GetComponentByClass<UCharacterMovementComponent>()->DisableMovement();
		alive = false;
		if (currentCaptureZone != NULL) {
			currentCaptureZone->DeadAI();
		}
		
	}
}

// Called when the game starts
void UAIStatblock::BeginPlay()
{
	Super::BeginPlay();

	maxHealth = health;
	// ...
	
}

void UAIStatblock::OnOverlapBegin(ACaptureZone* capureZone)
{
	currentCaptureZone = capureZone;
	currentCaptureZone->AIENTER();
}

void UAIStatblock::OnOverlapEnd(ACaptureZone* capureZone)
{
	capureZone->AILEAVE();
	currentCaptureZone = NULL;
}



// Called every frame
void UAIStatblock::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

