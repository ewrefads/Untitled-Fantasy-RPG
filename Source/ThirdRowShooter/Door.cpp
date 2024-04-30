// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	open = false;
	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	RootComponent = CollisionComponent;
	DoorMesh->SetupAttachment(RootComponent);
	maxRotation = 90;
	currentRotation = 0;
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (open && currentRotation < 90)
	{
		float deltaRotation = DeltaTime * 100;
		if (currentRotation + deltaRotation < 90)
		{
			currentRotation += deltaRotation;
		}
		else
		{
			deltaRotation = 90 - currentRotation;
			currentRotation = 90;
		}
		FRotator NewRotation = FRotator(0, deltaRotation, 0);
		FQuat QuatRotation = FQuat(NewRotation);
		DoorMesh->AddLocalRotation(QuatRotation, false, 0, ETeleportType::None);

	}
	else if (currentRotation > 0 && !open)
	{
		float deltaRotation = DeltaTime * -100;
		if (currentRotation - deltaRotation > 0)
		{
			currentRotation += deltaRotation;
		}
		else
		{
			deltaRotation = currentRotation;
			currentRotation = 0;
		}
		FRotator NewRotation = FRotator(0, deltaRotation, 0);
		FQuat QuatRotation = FQuat(NewRotation);
		DoorMesh->AddLocalRotation(QuatRotation, false, 0, ETeleportType::None);
	}
}

void ADoor::Use_Implementation()
{
	open = !open;
}

