// Fill out your copyright notice in the Description page of Project Settings.


#include "TressureChest.h"
#include "Kismet/KismetMathLibrary.h"


#include "GameFramework/Actor.h"


// Sets default values
ATressureChest::ATressureChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	open = false;

	//laver collision boxen
	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	//laver bunden af kiste static meshen
	BaseChestMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseChest"));
	//laver topdelen af kisten
	TopChestMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TopChest"));

	RootComponent = CollisionComponent;

	BaseChestMesh->SetupAttachment(RootComponent);
	TopChestMesh->SetupAttachment(BaseChestMesh);

	
}

// Called when the game starts or when spawned
void ATressureChest::BeginPlay()
{
	Super::BeginPlay();
	//sætter item spawntimeren til en tilfældig værdi i starten af spillet
	timeToSpawn = FMath::RandRange(minSpawnTime, maxSpawnTime);
}

// Called every frame
void ATressureChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

	//hvis kisten er åben så spawner den periodisk items
	if (open) {
		currentTimer += DeltaTime;
		
		if (currentTimer>=timeToSpawn && currentItemsSpawned < itemsToSpawn) {
			//vi vil gerne spawne et item nu
			SpawnRandomItem();

			//reseter timer
			currentTimer = 0;
			//finder en ny tilfældig mængde tid det tager at spawne
			timeToSpawn = FMath::RandRange(minSpawnTime, maxSpawnTime);
		}

	}

}

void ATressureChest::Use_Implementation()
{
	
	if (!open) {
		open = true;

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hello, Unreal Engine!"));
		}
		//flytter kistens top til 0,0,0 localspace
		FVector NewLocation = OpenLocation;
		TopChestMesh->SetRelativeLocation(NewLocation);

		//rotere top delen af kisten når der interactes
		FRotator NewRotation = OpenRotation;
		FQuat QuatRotation = FQuat(NewRotation);
		TopChestMesh->SetRelativeRotation(QuatRotation, false, 0, ETeleportType::None);
	}
}
/*
void ATressureChest::SpawnRandomItem() {
	
	//laver et tilfældigt index tal
	int32 RandomIndex = FMath::RandRange(0, ItemActorsToSpawn.Num() - 1);
	//får fat i en actor med givne tilfældigt index
	TSubclassOf<AActor> ItemActor = ItemActorsToSpawn[RandomIndex];

	//checker om at det er en valid class at som kan spawnes
	if (ItemActor)
	{
		//opsætter spawn parameter for den itemActor som skal spawnes (ændre ikke på nogen parametre)
		FActorSpawnParameters SpawnParams;

		//location for actorens spawn
		FVector spawnLocation = BaseChestMesh->GetComponentLocation();
		//lægger lidt til højden for at spawne itemet over kiste meshen
		spawnLocation.Z += itemSpawnHeight;

		//rotation for actorens spawn
		FRotator spawnRotation = FRotator(0, 0, 0);

		// Spawner itemActoren med de variabler der er angivet tidligere
		AActor* spawnedItem = (GetWorld()->SpawnActor<AActor>(ItemActor, spawnLocation, spawnRotation, SpawnParams));

		if(spawnedItem)
		{

			//enable physics på itemets static mesh collider
			//
			TArray<USceneComponent*> SceneComponents;
			spawnedItem->GetComponents(SceneComponents);
			//TArray<UActorComponent*> ActorComponents = (spawnedItem->GetComponents(SceneComponents));

			//kode fra chatgpt til at loope igennem scenecomponents og checke om de er staticmeshcomponents
			for (USceneComponent* SceneComponent : SceneComponents)
			{
				UStaticMeshComponent* StaticMeshComponent = Cast<UStaticMeshComponent>(SceneComponent);
				//checker om komponentet er valid
				if (StaticMeshComponent)
				{
					// Found the UStaticMeshComponent, do something with it
					// For example, you can apply forces or manipulate its properties
					// StaticMeshComponent->AddForce(...);
				
				
					//kode til at enable physics på static mesh component og giver den fart i en retning
					StaticMeshComponent->SetSimulatePhysics(true);
				
					FVector RandomDirection = UKismetMathLibrary::RandomUnitVector();
					FVector ForceToAdd = RandomDirection * SpawnForce;
					//sørger for at den altid flyver op af
					ForceToAdd.Z = 1000;

				
					StaticMeshComponent->AddForce(ForceToAdd);

					break; // Exit loop since we found the component
				

				}
			}
		}
	}
}*/

void ATressureChest::SpawnRandomItem() {
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("spawner item"));
	}

    int32 RandomIndex = FMath::RandRange(0, ItemActorsToSpawn.Num() - 1);
    TSubclassOf<AActor> ItemActor = ItemActorsToSpawn[RandomIndex];

    if (ItemActor)
    {
        FActorSpawnParameters SpawnParams;
        FVector SpawnLocation = BaseChestMesh->GetComponentLocation();
        SpawnLocation.Z += itemSpawnHeight;
        FRotator SpawnRotation = FRotator(0, 0, 0);

        AActor* SpawnedItem = GetWorld()->SpawnActor<AActor>(ItemActor, SpawnLocation, SpawnRotation, SpawnParams);
        
        if (SpawnedItem)
        {
            TArray<USceneComponent*> SceneComponents;
            SpawnedItem->GetComponents(SceneComponents);

            for (USceneComponent* SceneComponent : SceneComponents)
            {
				UStaticMeshComponent* StaticMesh = Cast<UStaticMeshComponent>(SceneComponent);
                
                if (StaticMesh)
                {
                    StaticMesh->SetSimulatePhysics(true);
                    FVector RandomDirection = UKismetMathLibrary::RandomUnitVector();
                    FVector ForceToAdd = RandomDirection * SpawnForce;
                    ForceToAdd.Z = 1000;

                    StaticMesh->AddImpulse(ForceToAdd);
					
					/*if (GEngine)
					{
						FString Message = FString::Printf(TEXT("Force being added: %s"), *ForceToAdd.ToString());
						GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, Message);

						FVector FinalVelocity = StaticMesh->GetComponentVelocity();
						
						FString FinalVelocityStr = FinalVelocity.ToString();
						FString Message2 = FString::Printf(TEXT("Final Velocity: %s"), *FinalVelocityStr);
						GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, Message2);
					}*/
                    break;
                }
            }

			//ItemActor

			/*
			UFunction* const func = SpawnedItem->FindFunction("TurnOffPhysicsAfterWait");
			if (func) {
				FTimerDelegate Delegate;
				Delegate.BindUFunction(SpawnedItem, "TurnOffPhysicsAfterWait");
				Delegate.Execute();
			}*/
			/*
			AInventoryItem* InventoryItemComponent = SpawnedItem->FindComponentByClass<AInventoryItem>();

			// Check if the component is valid
			if (InventoryItemComponent)
			{
				// Call the function on the component
				InventoryItemComponent->TurnOffPhysicsAfterWait();
			}*/





			currentItemsSpawned += 1;
        }
    }
}

