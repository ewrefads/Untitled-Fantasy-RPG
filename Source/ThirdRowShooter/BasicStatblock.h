// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BasicStatblock.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THIRDROWSHOOTER_API UBasicStatblock : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBasicStatblock();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int maxHealth;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int health;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int numberOfHitDice;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int hitDiceSize;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int Strength;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int StrengthModifier;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int StrengthSave;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int Dexterity;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int DexterityModifier;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int DexteritySave;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int Constitution;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int ConstitutionModifier;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int ConstitutionSave;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int Intelligence;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int IntelligenceModifier;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int IntelligenceSave;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int Wisdom;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int WisdomModifier;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int WisdomSave;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int Charisma;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int CharismaModifier;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int CharismaSave;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int SpellAttack;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int SpellDC;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int StrengthAttack;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int DexterityAttack;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int ProficiencyModifier;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int ArmorClass;


	UFUNCTION(BlueprintCallable)
	void CalculateDerivedStats();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
