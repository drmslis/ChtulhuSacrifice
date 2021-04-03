// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Patrolling.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPatrolling : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CTHULHUSACRIFICE_API IPatrolling
{
	GENERATED_BODY()
public:
    
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Actions")
    AActor* FindEnemy();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Actions")
    bool IsNextPatrolLocationExist();
    
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Actions")
    FVector GetNextPatrolLocation();
    
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Actions")
    void IncrementPatrolLocation();
    
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Actions")
    void SetPatrolToClosestPatrolLocation();
};
