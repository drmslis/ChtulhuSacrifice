﻿// Fill out your copyright notice in the Description page of Project Settings.


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
            Element.NPCText = FText::FromString(TEXT("Кхтулху проснулся"));
            Element.PlayerText = FText::FromString(TEXT("Дальше"));
            Quest.Dialogues.Add(Element);
        }
        {
            FDialougueElement Element;
            Element.NPCText = FText::FromString(TEXT("Кхтулху проснулся2"));
            Element.PlayerText = FText::FromString(TEXT("Окей"));
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