// Fill out your copyright notice in the Description page of Project Settings.


#include "CthulhuFeedProgress.h"

// Sets default values
ACthulhuFeedProgress::ACthulhuFeedProgress()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


    MaxFeedLevel = 100;
    CurrFeedLevel = 50;
    DecreaseFeedLevelPerSec = 0.005f;
    DecreaseFeedLevelPerKill = 0; // TODO: Implement decreasing
    IncreaseFeedLevelPerQuestDefault = 0.07f; // TODO: Implement quest
    DecreaseFeedLevelMaxPerQuestDefault = 0.1f;
}

// Called when the game starts or when spawned
void ACthulhuFeedProgress::BeginPlay()
{
	Super::BeginPlay();
	
    
    FTimerHandle UnusedHandle;

    GetWorldTimerManager().SetTimer(UnusedHandle, this, &ACthulhuFeedProgress::UpdateFeedLevelPerSecond, 1, true, 0.01f);

    InitMaxFeedLevel = MaxFeedLevel;
}

// Called every frame
void ACthulhuFeedProgress::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACthulhuFeedProgress::ChangeFeedLevel(float DeltaPercent)
{
    CurrFeedLevel += InitMaxFeedLevel * DeltaPercent;

    CthulhuFeedChanged.Broadcast(CurrFeedLevel, MaxFeedLevel);

    if(CurrFeedLevel < 0)
        CthulhuWokeUp.Broadcast(true);
    else if(CurrFeedLevel >= MaxFeedLevel)
        CthulhuWokeUp.Broadcast(false);
}

void ACthulhuFeedProgress::ChangeMaxFeedLevel(float DeltaPercent)
{
    CurrFeedLevel += CurrFeedLevel * DeltaPercent;
    MaxFeedLevel += InitMaxFeedLevel * DeltaPercent;
}

void ACthulhuFeedProgress::UpdateFeedLevelPerSecond()
{
    ChangeFeedLevel(-DecreaseFeedLevelPerSec);
}

