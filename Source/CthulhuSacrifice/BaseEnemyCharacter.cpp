// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemyCharacter.h"

#include "Math/NumericLimits.h"
#include "Kismet/GamePlayStatics.h"
#include "GameFramework/PhysicsVolume.h"

// Sets default values
ABaseEnemyCharacter::ABaseEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    PatrolLocationIdx = 0;
    EnemyVisionDistance = 1000;
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
    return PatrolPointActors.Num() > 0;
}

FVector ABaseEnemyCharacter::GetNextPatrolLocation_Implementation()
{
    if(PatrolPointActors.Num() > 0)
        return PatrolPointActors[PatrolLocationIdx]->GetActorLocation();
    return FVector();
}

void ABaseEnemyCharacter::IncrementPatrolLocation_Implementation()
{
    if(PatrolPointActors.Num() > 0)
        PatrolLocationIdx = (PatrolLocationIdx + 1) % PatrolPointActors.Num();
}

void ABaseEnemyCharacter::SetPatrolToClosestPatrolLocation_Implementation()
{
    float MaxSqrDist = TNumericLimits<float>::Max();
    FVector CurrLocation = GetActorLocation();
    for(int i = 0; i < PatrolPointActors.Num(); ++i)
    {
        float CurrSqrDist = FVector::DistSquared(CurrLocation, PatrolPointActors[i]->GetActorLocation());
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
    
    UE_LOG(LogTemp, Warning, TEXT("FindEnemy, Actors Count: %d"), Actors.Num())
    for(auto Actor : Actors)
    {
        if(Actor == this)
            continue;

        //TODO: add actor visibility if need
        FVector ActorLoc = Actor->GetActorLocation();

        if(FVector::Dist(StartLocation, ActorLoc) > EnemyVisionDistance)
            continue;

        FCollisionQueryParams CollisionParams;
        CollisionParams.AddIgnoredActor(this);
        CollisionParams.AddIgnoredActor(Actor);
        FHitResult HitResult;
        bool anyFound = GetWorld()->LineTraceSingleByChannel(
            HitResult,
            StartLocation,
            ActorLoc,
            ECollisionChannel::ECC_Visibility, CollisionParams);

        if(!anyFound)
        {
            UE_LOG(LogTemp, Warning, TEXT("FindEnemy %s"), *Actor->GetName())
            if(Actor == myCharacter)    //TODO: check other variants, not only character. Include different teams
                return Actor;
        }
    }
    return nullptr;
}
