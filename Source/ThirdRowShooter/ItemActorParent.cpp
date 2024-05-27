// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemActorParent.h"

// Sets default values
AItemActorParent::AItemActorParent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItemActorParent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemActorParent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemActorParent::TurnOffPhysics() {
	
}

