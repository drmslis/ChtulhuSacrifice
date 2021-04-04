// Fill out your copyright notice in the Description page of Project Settings.


#include "SirenaQuestGiver.h"

USirenaQuestGiver::USirenaQuestGiver()
{
    Name = TEXT("Sirena");
    
    {
        FQuest Quest;
        
        // Dialogue from this NPC for this Quest
        Quest.Dialogues.Add(FText::FromString(TEXT("I am Sirena\nHello")));
        Quest.Dialogues.Add(FText::FromString(TEXT("Give me Corall")));

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
        
        // Dialogue from this NPC for this Quest
        Quest.Dialogues.Add(FText::FromString(TEXT("Thanks for coral.")));
        Quest.Dialogues.Add(FText::FromString(TEXT("Give another two")));

        // Conditional for quest finish
        Quest.Conditional.ItemType = EItemType::CoralItem;
        Quest.Conditional.ItemsCount = 2;
        
        // Reward for this Quest
        Quest.Reward.CthulhuFeedPercent = 0;
        Quest.Reward.LevelUp = false;


        Quests.Add(Quest);
    }

}
