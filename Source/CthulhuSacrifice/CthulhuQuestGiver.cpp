// Fill out your copyright notice in the Description page of Project Settings.


#include "CthulhuQuestGiver.h"


UCthulhuQuestGiver::UCthulhuQuestGiver()
{
    Name = TEXT("Cthulhu");
    
    {
        FQuest Quest;
        
        // Dialogue from this NPC for this Quest
        Quest.Dialogues.Add(FText::FromString(TEXT("I AM CHTULHU\nWUHAHAHA")));
        Quest.Dialogues.Add(FText::FromString(TEXT("GIVE ME CORALL\nNOW!")));

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
        Quest.Dialogues.Add(FText::FromString(TEXT("KILL 2 HUMANS")));
        Quest.Dialogues.Add(FText::FromString(TEXT("GIVE ME THEIR BLOOD TO FEED\nNOW!")));

        // Conditional for quest finish
        Quest.Conditional.ItemType = EItemType::HumanItem;
        Quest.Conditional.ItemsCount = 2;
        
        // Reward for this Quest
        Quest.Reward.CthulhuFeedPercent = 30;
        Quest.Reward.LevelUp = true;


        Quests.Add(Quest);
    }

}

