// Fill out your copyright notice in the Description page of Project Settings.


#include "LightSwitch.h"

// Sets default values
ALightSwitch::ALightSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	ButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Button"));
	RootComponent = CollisionComponent;
	ButtonMesh->SetupAttachment(RootComponent);
}		

// Called when the game starts or when spawned
void ALightSwitch::BeginPlay()
{
	Super::BeginPlay();
	

	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ALightSwitch::OnOverlapBegin);
	CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &ALightSwitch::OnOverlapEnd);
}

void ALightSwitch::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	/*if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, .5f, FColor::Yellow, TEXT("Colliding"));
		capturing = true;
	}*/
}

void ALightSwitch::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	/*if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, .5f, FColor::Yellow, TEXT("Not Colliding"));
		capturing = false;
	}*/
}

// Called every frame
void ALightSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void ALightSwitch::Use_Implementation()
{
	if (Lamp != NULL) {
		Lamp -> toggleLight();
	}
}

