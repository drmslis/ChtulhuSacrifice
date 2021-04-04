// Fill out your copyright notice in the Description page of Project Settings.


#include "AfterFirstPickQuestGiver.h"

//("你");
UAfterFirstPickQuestGiver::UAfterFirstPickQuestGiver()
{
    Name = TEXT("AfterFirstPick");
    
    {
        FQuest Quest;
        
        // Dialogues from this NPC for this Quest
        {
            FDialougueElement Element;
            //FString str = FString(L"Русский текстs");
            Element.NPCText = FText::FromString(TEXT("Подожди! Я видела ты нашёл медальон"));
            Element.PlayerText = FText::FromString(TEXT("Что ты о нём знаешь? Говори немедленно!"));
            Quest.Dialogues.Add(Element);
        }
        {
            FDialougueElement Element;
            Element.NPCText = FText::FromString(TEXT("Я не могу тебе ничего рассказать, но могу помочь тебе стать сильнее.\n Возможно это также поможет тебе что-то вспомнить. Добудь мне 2 коралла"));
            Element.PlayerText = FText::FromString(TEXT("В любом случае я узнаю всё у Повелителя.."));
            Quest.Dialogues.Add(Element);
        }

        // Conditional for quest finish
        Quest.Conditional.ItemType = EItemType::CoralItem;
        Quest.Conditional.ItemsCount = 2;
        
        // Reward for this Quest
        Quest.Reward.CthulhuFeedPercent = 0; // increase this part from init maximum
        Quest.Reward.CthulhuFeedMaxPercent = 0; // increase maximum on this percent
        Quest.Reward.LevelUp = false;


        Quests.Add(Quest);
    }
}