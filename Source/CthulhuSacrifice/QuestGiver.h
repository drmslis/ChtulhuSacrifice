// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PickUpObject.h"
#include "QuestGiver.generated.h"

USTRUCT(BlueprintType)
struct FReward
{       
	GENERATED_BODY() 
    UPROPERTY()
    bool LevelUp;
    
    UPROPERTY()
    float CthulhuFeedPercent;
};

USTRUCT(BlueprintType)
struct FConditional
{    
	GENERATED_BODY()
    UPROPERTY()
    EItemType ItemType;
    
    UPROPERTY()
    int ItemsCount;
};

USTRUCT(BlueprintType)
struct FQuest
{
    GENERATED_BODY()

    UPROPERTY()
    TArray<FText> Dialogues;

    UPROPERTY()
    FConditional Conditional;
    
    UPROPERTY()
    FReward Reward;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CTHULHUSACRIFICE_API UQuestGiver : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UQuestGiver();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION()
    bool IsNextDialogue();

	UPROPERTY()
    int QuestIdx;
    
	UPROPERTY()
    FName Name;
    
    UPROPERTY()
    TArray<FQuest> Quests;
};
