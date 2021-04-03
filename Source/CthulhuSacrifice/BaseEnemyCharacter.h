// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Patrolling.h"
#include "BaseEnemyCharacter.generated.h"

UCLASS()
class CTHULHUSACRIFICE_API ABaseEnemyCharacter : public ACharacter, public IPatrolling
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    virtual bool IsNextPatrolLocationExist_Implementation() override;
    virtual FVector GetNextPatrolLocation_Implementation() override;
    virtual void IncrementPatrolLocation_Implementation() override;
    virtual void SetPatrolToClosestPatrolLocation_Implementation() override;
    virtual AActor* FindEnemy_Implementation() override;

    UPROPERTY(BlueprintReadWrite, Category = "Variables")
    TArray<FVector> PatrolLocations;
    
    UPROPERTY(BlueprintReadWrite, Category = "Variables")
    int PatrolLocationIdx;
};
