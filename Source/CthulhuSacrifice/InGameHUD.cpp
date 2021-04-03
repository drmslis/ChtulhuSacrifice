// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameHUD.h"

#include "GameFramework/Character.h"
#include "Kismet/GamePlayStatics.h"
#include "CthulhuFeedProgress.h"
#include "PickUpping.h"
#include "Inventory.h"

void AInGameHUD::UpdatePickupText(APickUpObject* PickUpObject)
{
    ShowPickupText(IsValid(PickUpObject));
}

void AInGameHUD::UpdateQuestGiverText(UQuestGiver* QuestGiver)
{
    ShowQuestGiverToTalkText(IsValid(QuestGiver));
}

void AInGameHUD::BindEvents()
{
    ACharacter* Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

    if(IsValid(Character))
    {
        UPickUpping* PickUpping = Cast<UPickUpping>(Character->GetComponentByClass(UPickUpping::StaticClass()));
        UInventory* Inventory = Cast<UInventory>(Character->GetComponentByClass(UInventory::StaticClass()));
        
        if(IsValid(PickUpping))
        {
            PickUpping->ChangedPickUpEvent.AddDynamic(this, &AInGameHUD::UpdatePickupText);
            PickUpping->ChangedQuestGiverToTalkEvent.AddDynamic(this, &AInGameHUD::UpdateQuestGiverText);
            PickUpping->QuestGiverTalkEvent.AddDynamic(this, &AInGameHUD::OnQuestGiverTalk);
        }
        
        if(IsValid(Inventory))
        {
            Inventory->InventoryChanged.AddDynamic(this, &AInGameHUD::UpdateInventory);
        }
    }

    ACthulhuFeedProgress* FeedProgress = Cast<ACthulhuFeedProgress>(UGameplayStatics::GetActorOfClass(GetWorld(), ACthulhuFeedProgress::StaticClass()));

    if(IsValid(FeedProgress))
    {
        FeedProgress->CthulhuFeedChanged.AddDynamic(this, &AInGameHUD::UpdateCthulhuFeed);
    }
}

void AInGameHUD::UpdateCthulhuFeed(float CurrFeed, float MaxFeed)
{
    UpdateCthulhuFeedPercent(FMath::Clamp(CurrFeed / MaxFeed, 0.f, 1.f));
}

void AInGameHUD::OnQuestGiverTalk(UQuestGiver* QuestGiver)
{
    ShowQuestGiverToTalkText(false);
    QuestGiver_C = QuestGiver;
    FQuest Quest = QuestGiver->Quests[QuestGiver->QuestIdx];
    if(Quest.Dialogues.Num() > 0)
    {
        DialogueIdx = 0;
        // open dialoges HUD

        ShowQuestGiverTalkWidget(true);
        SetQuestGiverTalkWidgetText(Quest.Dialogues[DialogueIdx]);
    }
    else
    {
        QuestGiver_C->QuestIdx++;
    }
}

void AInGameHUD::NextQuestGiverTalkButtonClicked()
{
    FQuest Quest = QuestGiver_C->Quests[QuestGiver_C->QuestIdx];

    DialogueIdx++;
    if(DialogueIdx >= Quest.Dialogues.Num())
    {
        // close dialoges HUD
        QuestGiver_C->QuestIdx++;
        ShowQuestGiverTalkWidget(false);
    }
    else
    {
        SetQuestGiverTalkWidgetText(Quest.Dialogues[DialogueIdx]);
    }
}