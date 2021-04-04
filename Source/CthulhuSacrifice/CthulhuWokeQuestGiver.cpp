// Fill out your copyright notice in the Description page of Project Settings.


#include "CthulhuWokeQuestGiver.h"

//("你");
UCthulhuWokeQuestGiver::UCthulhuWokeQuestGiver()
{
    Name = TEXT("CthulhuWoke");
    
    {
        FQuest Quest;
        
        // Dialogues from this NPC for this Quest
        {
            FDialougueElement Element;
            //FString str = FString(L"Русский текстs");
            Element.NPCText = FText::FromString(TEXT("Ха-ха-ха! Наконец-то я смогу позволить себе нового жреца!"));
            Element.PlayerText = FText::FromString(TEXT("Атаковать"));
            Quest.Dialogues.Add(Element);
        }

        // Conditional for quest finish
        Quest.Conditional.ItemType = EItemType::CoralItem;
        Quest.Conditional.ItemsCount = 0;
        
        // Reward for this Quest
        Quest.Reward.CthulhuFeedPercent = 0; // increase this part from init maximum
        Quest.Reward.CthulhuFeedMaxPercent = 0; // increase maximum on this percent
        Quest.Reward.LevelUp = false;


        Quests.Add(Quest);
    }
}