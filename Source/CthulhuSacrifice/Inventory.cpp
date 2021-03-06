// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"

// Sets default values for this component's properties
UInventory::UInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UInventory::AddItems(EItemType Type, int Count)
{
    int* CountArrPtr = ItemsCounts.Find(Type);
    if(!CountArrPtr)
        ItemsCounts.Add(Type, Count);
    else
        *CountArrPtr = *CountArrPtr + Count;

    InventoryChanged.Broadcast(this);
}

bool UInventory::TryRemoveItems(EItemType Type, int Count)
{
    if(Count <= 0)
        return true;
    
    int* CountArrPtr = ItemsCounts.Find(Type);

    if(!CountArrPtr)
        return false;

    if(*CountArrPtr < Count)
        return false;

    *CountArrPtr = *CountArrPtr - Count;
    
    InventoryChanged.Broadcast(this);
    return true;
}