// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpping.h"

#include "Inventory.h"

// Sets default values for this component's properties
UPickUpping::UPickUpping()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

    PickUpDistance = 800;
	// ...
}


// Called when the game starts
void UPickUpping::BeginPlay()
{
	Super::BeginPlay();

	// ...
    FTimerHandle UnusedHandle;
    GetOwner()->GetWorldTimerManager().SetTimer(UnusedHandle, this, &UPickUpping::UpdatePickUpObject, 0.1, true);

    Camera = Cast<UCameraComponent>(GetOwner()->GetComponentByClass(UCameraComponent::StaticClass()));
    
    Inventory = Cast<UInventory>(GetOwner()->GetComponentByClass(UInventory::StaticClass()));
}


// Called every frame
void UPickUpping::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPickUpping::UpdatePickUpObject()
{
    auto OldPickUpObject = PickUpObject;
    PickUpObject = nullptr;

    FVector StartLocation = Camera->GetComponentLocation();
    FVector Direction = Camera->GetForwardVector();
    FVector EndLocation = StartLocation + Direction * PickUpDistance;

    FHitResult HitResult;
    if(GetWorld()->LineTraceSingleByChannel(
        HitResult,
        StartLocation,
        EndLocation,
        ECollisionChannel::ECC_Visibility))
    {
        //UE_LOG(LogTemp, Warning, TEXT("Hit %s"), *HitResult.Actor->GetName())
        PickUpObject = Cast<APickUpObject>(HitResult.Actor);
    }

    if(PickUpObject != OldPickUpObject)
    {
        ChangedPickUpEvent.Broadcast(PickUpObject);
    }
}

void UPickUpping::PickUp()
{
    if(IsValid(PickUpObject))
    {
        if(IsValid(Inventory))
            Inventory->AddItems(PickUpObject->ItemType, PickUpObject->ItemsCount);

        PickUpObject->Destroy();
    }
}
