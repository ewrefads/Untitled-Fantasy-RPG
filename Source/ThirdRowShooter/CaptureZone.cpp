// Fill out your copyright notice in the Description page of Project Settings.


#include "CaptureZone.h"
#include "PlayerComponent.h"
#include "AIStatblock.h"

// Sets default values
ACaptureZone::ACaptureZone()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	FlagMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Flag"));
	PoleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pole"));
	RootComponent = CollisionComponent;
	PoleMesh->SetupAttachment(RootComponent);
	FlagMesh->SetupAttachment(RootComponent);
	flagState = EFlagState::DOWN;
}

void ACaptureZone::DeadAI()
{
	if (DefendingAIs > 0) {
		DefendingAIs--;
		GEngine->AddOnScreenDebugMessage(-1, .5f, FColor::Yellow, TEXT("decreased defendingAIs"));
	}
}

void ACaptureZone::AIENTER()
{
	DefendingAIs++;
}

void ACaptureZone::AILEAVE()
{
	if (DefendingAIs > 0) {
		DefendingAIs--;
		GEngine->AddOnScreenDebugMessage(-1, .5f, FColor::Yellow, TEXT("decreased defendingAIs"));
	}
}

// Called when the game starts or when spawned
void ACaptureZone::BeginPlay()
{
	Super::BeginPlay();


	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ACaptureZone::OnOverlapBegin);
	CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &ACaptureZone::OnOverlapEnd);
}

void ACaptureZone::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	/*if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, .5f, FColor::Yellow, TEXT("Colliding"));
		capturing = true;
	}*/

}

void ACaptureZone::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	/*if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, .5f, FColor::Yellow, TEXT("Not Colliding"));
		capturing = false;
	}*/
}

// Called every frame
void ACaptureZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (capturing && DefendingAIs == 0)
	{
		timeSinceTick += DeltaTime;

		percentage = FMath::Clamp(timeSinceTick / CaptureTime * 100.0f, 0.0f, 100.0f);
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Float value: %f"), percentage));

		float newZPosition;
		if (flagState == EFlagState::DOWN)
		{
			newZPosition = FMath::Lerp(-15.0f, 27.5f, percentage / 100.0f);
		}
		else if (flagState == EFlagState::UP)
		{
			newZPosition = FMath::Lerp(27.5f, -15.0f, percentage / 100.0f);
		}
		FVector newLocation = FlagMesh->GetRelativeLocation();

		newLocation.Z = newZPosition;
		FlagMesh->SetRelativeLocation(newLocation);

		if (percentage >= 100)
		{
			capturing = false;
			timeSinceTick = 0;

			flagState = (flagState == EFlagState::DOWN) ? EFlagState::UP : EFlagState::DOWN;
		}
	}

}

void ACaptureZone::Use_Implementation()
{
	capturing = true;
}