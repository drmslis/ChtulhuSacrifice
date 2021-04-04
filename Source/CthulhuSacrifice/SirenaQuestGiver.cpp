// Fill out your copyright notice in the Description page of Project Settings.


#include "SirenaQuestGiver.h"

USirenaQuestGiver::USirenaQuestGiver()
{
    Name = TEXT("Sirena");
    
    {
        FQuest Quest;
        
        // Dialogues from this NPC for this Quest
        {
            FDialougueElement Element;
            Element.NPCText = FText::FromString(TEXT("I am Sirena\nHello"));
            Element.PlayerText = FText::FromString(TEXT("Hello Sirena"));
            Quest.Dialogues.Add(Element);
        }
        {
            FDialougueElement Element;
            Element.NPCText = FText::FromString(TEXT("Give me Corall"));
            Element.PlayerText = FText::FromString(TEXT("Okay, no problem"));
            Quest.Dialogues.Add(Element);
        }

        // Conditional for quest finish
        Quest.Conditional.ItemType = EItemType::CoralItem;
        Quest.Conditional.ItemsCount = 1;
        
        // Reward for this Quest
        Quest.Reward.CthulhuFeedPercent = 0;
        Quest.Reward.LevelUp = false;


        Quests.Add(Quest);
    }

    
    {
        FQuest Quest;
        
        // Dialogues from this NPC for this Quest
        {
            FDialougueElement Element;
            Element.NPCText = FText::FromString(TEXT("Thanks for coral"));
            Element.PlayerText = FText::FromString(TEXT("No problem"));
            Quest.Dialogues.Add(Element);
        }
        {
            FDialougueElement Element;
            Element.NPCText = FText::FromString(TEXT("Give another two"));
            Element.PlayerText = FText::FromString(TEXT("Are you kidding me?\n Okay"));
            Quest.Dialogues.Add(Element);
        }

        // Conditional for quest finish
        Quest.Conditional.ItemType = EItemType::CoralItem;
        Quest.Conditional.ItemsCount = 2;
        
        // Reward for this Quest
        Quest.Reward.CthulhuFeedPercent = 0;
        Quest.Reward.LevelUp = false;


        Quests.Add(Quest);
    }

}
