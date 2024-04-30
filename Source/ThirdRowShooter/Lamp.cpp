// Fill out your copyright notice in the Description page of Project Settings.


#include "Lamp.h"

// Sets default values
ALamp::ALamp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
	Light->SetIntensity(0);
	turnedOn = false;
}

void ALamp::toggleLight()
{
	turnedOn = !turnedOn;
}

// Called when the game starts or when spawned
void ALamp::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALamp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (turnedOn && Light -> Intensity < 500)
	{
		Light->SetIntensity(Light->Intensity + (DeltaTime * 100));
	}
	else if (Light->Intensity > 0)
	{
		if (Light -> Intensity - (DeltaTime * 100) > 0)
		{
			Light->SetIntensity(Light->Intensity - (DeltaTime * 100));
		}
		else {
			Light->SetIntensity(0);
		}
	}
}

