// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UseableInterface.h"
#include <Components/BoxComponent.h>
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"




#include "TressureChest.generated.h"


UCLASS()
class THIRDROWSHOOTER_API ATressureChest : public AActor, public IUseableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATressureChest();

protected:
	// Called when the game starts or when spawned
	bool open;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* CollisionComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BaseChestMesh;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* TopChestMesh;

	UPROPERTY(EditAnywhere)
	UNiagaraComponent* ParticleSystem;

	UPROPERTY(EditAnywhere)
	FRotator OpenRotation;

	UPROPERTY(EditAnywhere)
	FVector OpenLocation;

	UPROPERTY(EditAnywhere, Category = "Items Chest Can Spawn")
	TArray<TSubclassOf<AActor>> ItemActorsToSpawn;

	UPROPERTY(EditAnywhere, Category = "spawnOptions")
	float itemSpawnHeight;

	UPROPERTY(EditAnywhere, Category = "spawnOptions")
	float minSpawnTime;

	UPROPERTY(EditAnywhere, Category = "spawnOptions")
	float maxSpawnTime;

	float currentTimer=0;
	float timeToSpawn=0;

	UPROPERTY(EditAnywhere, Category = "spawnOptions")
	float SpawnForce;
	
	UPROPERTY(EditAnywhere, Category = "spawnOptions")
	int itemsToSpawn;

	int currentItemsSpawned=0;
	
	APawn* playerCharacter;

	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Use_Implementation() override;
	void SpawnRandomItem();
};
