// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CthulhuFeedProgress.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCthulhuWokeUp, bool, Angry);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCthulhuFeedChanged, float, CurrFeed, float, MaxFeed);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CTHULHUSACRIFICE_API ACthulhuFeedProgress : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACthulhuFeedProgress();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable, Category = "Actions")
    void ChangeFeedLevel(float DeltaPercent);
    
    UFUNCTION(BlueprintCallable, Category = "Actions")
    void ChangeMaxFeedLevel(float DeltaPercent);
    
    UFUNCTION(BlueprintCallable, Category = "Actions")
    void UpdateFeedLevelPerSecond();
    
    UPROPERTY(BluePrintReadWrite, EditAnywhere, Category = "Variables")
    float MaxFeedLevel;
    
    UPROPERTY(BluePrintReadWrite, EditAnywhere, Category = "Variables")
    float CurrFeedLevel;
    
    UPROPERTY(BluePrintReadWrite, EditAnywhere, Category = "Variables")
    float DecreaseFeedLevelPerSec;
    
    UPROPERTY(BluePrintReadWrite, EditAnywhere, Category = "Variables")
    float DecreaseFeedLevelPerKill;
    
    UPROPERTY(BluePrintReadWrite, EditAnywhere, Category = "Variables")
    float IncreaseFeedLevelPerQuestDefault;
    
    UPROPERTY(BluePrintReadWrite, EditAnywhere, Category = "Variables")
    float DecreaseFeedLevelMaxPerQuestDefault;
    
    UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
    FOnCthulhuWokeUp CthulhuWokeUp;    
    
    UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
    FOnCthulhuFeedChanged CthulhuFeedChanged;    
};
