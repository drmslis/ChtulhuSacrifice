// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpObject.generated.h"

UENUM(BluePrintType)
enum class EItemType : uint8
{
    CoralItem,
    HumanItem,
    SharkItem,
    AngryPlantItem,
    HenchManItem,
    QuestCountItem
};

UCLASS()
class CTHULHUSACRIFICE_API APickUpObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
    class UStaticMeshComponent* Mesh;

    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
    EItemType ItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
    int ItemsCount;    
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
    class UQuestGiver* QuestGiver;
    
    UPROPERTY(BluePrintReadWrite, EditAnywhere, Category = "Variables")
    float RadialDistanceToTake;
};
