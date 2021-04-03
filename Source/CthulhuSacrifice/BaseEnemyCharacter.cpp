// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemyCharacter.h"

#include "Math/NumericLimits.h"
#include "Kismet/GamePlayStatics.h"

// Sets default values
ABaseEnemyCharacter::ABaseEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    PatrolLocationIdx = 0;
}

// Called when the game starts or when spawned
void ABaseEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool ABaseEnemyCharacter::IsNextPatrolLocationExist_Implementation()
{
    return PatrolLocations.Num() > 0;
}

FVector ABaseEnemyCharacter::GetNextPatrolLocation_Implementation()
{
    if(PatrolLocations.Num() > 0)
        return PatrolLocations[PatrolLocationIdx];
    return FVector();
}

void ABaseEnemyCharacter::IncrementPatrolLocation_Implementation()
{
    if(PatrolLocations.Num() > 0)
        PatrolLocationIdx = (PatrolLocationIdx + 1) % PatrolLocations.Num();
}

void ABaseEnemyCharacter::SetPatrolToClosestPatrolLocation_Implementation()
{
    float MaxSqrDist = TNumericLimits<float>::Max();
    FVector CurrLocation = GetActorLocation();
    for(int i = 0; i < PatrolLocations.Num(); ++i)
    {
        float CurrSqrDist = FVector::DistSquared(CurrLocation, PatrolLocations[i]);
        if(CurrSqrDist < MaxSqrDist)
            PatrolLocationIdx = i;
    }
}

AActor* ABaseEnemyCharacter::FindEnemy_Implementation()
{
    TArray<AActor*> Actors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawn::StaticClass(), Actors);

    FVector StartLocation = GetActorLocation();
    ACharacter* myCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

    for(auto Actor : Actors)
    {
        //TODO: add actor visibility if need
        FVector ActorLoc = Actor->GetActorLocation();

        FHitResult HitResult;
        if(!GetWorld()->LineTraceSingleByChannel(
            HitResult,
            StartLocation,
            ActorLoc,
            ECollisionChannel::ECC_Visibility))
        {
            if(Actor == myCharacter)    //TODO: check other variants, not only character. Include different teams
                return Actor;
        }
    }
    return nullptr;
}
