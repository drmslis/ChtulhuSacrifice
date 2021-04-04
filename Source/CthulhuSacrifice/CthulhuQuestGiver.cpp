// Fill out your copyright notice in the Description page of Project Settings.


#include "CthulhuQuestGiver.h"


UCthulhuQuestGiver::UCthulhuQuestGiver()
{
    Name = TEXT("Cthulhu");
    
    {
        FQuest Quest;
        
        // Dialogue from this NPC for this Quest
        // Dialogues from this NPC for this Quest
        {
            FDialougueElement Element;
            Element.NPCText = FText::FromString(TEXT("I AM CHTULHU\nWUHAHAHA"));
            Element.PlayerText = FText::FromString(TEXT("Wakeup!"));
            Quest.Dialogues.Add(Element);
        }
        {
            FDialougueElement Element;
            Element.NPCText = FText::FromString(TEXT("GIVE ME CORALL\nNOW!"));
            Element.PlayerText = FText::FromString(TEXT("Will do it ASAP"));
            Quest.Dialogues.Add(Element);
        }

        // Conditional for quest finish
        Quest.Conditional.ItemType = EItemType::CoralItem;
        Quest.Conditional.ItemsCount = 1;
        
        // Reward for this Quest
        Quest.Reward.CthulhuFeedPercent = 20;
        Quest.Reward.LevelUp = true;


        Quests.Add(Quest);
    }

    
    {
        FQuest Quest;
        
        // Dialogue from this NPC for this Quest
        {
            FDialougueElement Element;
            Element.NPCText = FText::FromString(TEXT("KILL 2 HUMANS"));
            Element.PlayerText = FText::FromString(TEXT("Serve you with pleasure"));
            Quest.Dialogues.Add(Element);
        }
        {
            FDialougueElement Element;
            Element.NPCText = FText::FromString(TEXT("GIVE ME THEIR BLOOD TO FEED\nNOW!"));
            Element.PlayerText = FText::FromString(TEXT("ok"));
            Quest.Dialogues.Add(Element);
        }

        // Conditional for quest finish
        Quest.Conditional.ItemType = EItemType::HumanItem;
        Quest.Conditional.ItemsCount = 2;
        
        // Reward for this Quest
        Quest.Reward.CthulhuFeedPercent = 30;
        Quest.Reward.LevelUp = true;


        Quests.Add(Quest);
    }

}

