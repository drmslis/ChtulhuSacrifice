// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpping.h"

#include "Inventory.h"
#include "Kismet/GamePlayStatics.h"
#include "CthulhuFeedProgress.h"

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
    
    CthulhuFeedProgress = Cast<ACthulhuFeedProgress>(UGameplayStatics::GetActorOfClass(GetWorld(), ACthulhuFeedProgress::StaticClass()));
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
    
    auto OldQuestGiver = QuestGiver;
    QuestGiver = nullptr;

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
        auto CurrQuestGiver = Cast<UQuestGiver>(HitResult.Actor->GetComponentByClass(UQuestGiver::StaticClass()));

        if(CurrQuestGiver)
            QuestGiver = CurrQuestGiver;
        else
            PickUpObject = Cast<APickUpObject>(HitResult.Actor);
    }
    
    if(QuestGiver != OldQuestGiver)
    {
        ChangedQuestGiverToTalkEvent.Broadcast(QuestGiver);
    }

    if(PickUpObject != OldPickUpObject)
    {
        ChangedPickUpEvent.Broadcast(PickUpObject);
    }
}

void UPickUpping::PickUp()
{
    if(Talk())
        return;

    if(IsValid(PickUpObject))
    {
        if(IsValid(Inventory))
            Inventory->AddItems(PickUpObject->ItemType, PickUpObject->ItemsCount);

        PickUpObject->Destroy();
    }
}

bool UPickUpping::Talk()
{
    if(IsValid(QuestGiver) && QuestGiver->IsNextDialogue())
    {
        if(IsValid(Inventory))
        {
            if(QuestGiver->QuestIdx > 0) // Talk only if succed past quest
            {
                FConditional Conditional = QuestGiver->Quests[QuestGiver->QuestIdx - 1].Conditional;
                if(Inventory->TryRemoveItems(Conditional.ItemType, Conditional.ItemsCount))
                {
                    ApplyReward(QuestGiver->Quests[QuestGiver->QuestIdx - 1].Reward);
                    QuestGiverTalkEvent.Broadcast(QuestGiver);
                    return true;
                }
            }
            else
            {
                QuestGiverTalkEvent.Broadcast(QuestGiver);
                return true;
            }
        }
    }

    return false;
}

void UPickUpping::ApplyReward(FReward Reward)
{
    // TODO: AddReward here
    if(CthulhuFeedProgress)
    {
        CthulhuFeedProgress->ChangeFeedLevel(Reward.CthulhuFeedPercent);
        CthulhuFeedProgress->ChangeMaxFeedLevel(Reward.CthulhuFeedMaxPercent);
    }
}