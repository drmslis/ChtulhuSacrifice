// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpObject.h"

// Sets default values
APickUpObject::APickUpObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");

    Mesh->SetupAttachment(RootComponent);

    RadialDistanceToTake = 400;
}

// Called when the game starts or when spawned
void APickUpObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUpObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

