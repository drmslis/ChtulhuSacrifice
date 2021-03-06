// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestGiver.h"

// Sets default values for this component's properties
UQuestGiver::UQuestGiver()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
    
    QuestIdx = 0;
    RadialDistanceToTalk = 700;
	// ...
}


// Called when the game starts
void UQuestGiver::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UQuestGiver::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


bool UQuestGiver::IsNextDialogue()
{
    return QuestIdx < Quests.Num();
}

