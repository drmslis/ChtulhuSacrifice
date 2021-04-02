// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpping.h"


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
        PickUpObject = Cast<APickUpObject>(HitResult.Actor);
    }

    if(PickUpObject != OldPickUpObject)
    {
        ChangedPickUpEvent.Broadcast(PickUpObject);
    }
}

void UPickUpping::PickUp()
{
    if(PickUpObject)
    {
        //TODO: add increasing pickUps here

        PickUpObject->Destroy();
    }
}
