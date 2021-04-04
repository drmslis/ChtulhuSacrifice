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
            //FString m = TEXT("你");
            //FString str = FString(L"Русский текстs");
            Element.NPCText = FText::FromString(TEXT("Как ты посмел задержаться с очередной жертвой?"));
            Element.PlayerText = FText::FromString(TEXT("Мой Повелитель, я нашёл медальон и меня посетило видение, \nв котором прекрасная девушка целовала меня. Но, мой Повелитель, \nвы говорили, что я всю жизнь был вашим рабом!"));
            Quest.Dialogues.Add(Element);
        }
        {
            FDialougueElement Element;
            Element.NPCText = FText::FromString(TEXT("Ты знаешь столько сколько тебе положено. \nПринесёшь больше жертв и получишь ответы. Убей человека"));
            Element.PlayerText = FText::FromString(TEXT("Конечно.."));
            Quest.Dialogues.Add(Element);
        }

        // Conditional for quest finish
        Quest.Conditional.ItemType = EItemType::HumanItem;
        Quest.Conditional.ItemsCount = 1;
        
        // Reward for this Quest
        Quest.Reward.CthulhuFeedPercent = 0.3; // increase this part from init maximum
        Quest.Reward.CthulhuFeedMaxPercent = -0.25; // increase maximum on this percent
        Quest.Reward.LevelUp = true;


        Quests.Add(Quest);
    }

    
    {
        FQuest Quest;
        
        // Dialogue from this NPC for this Quest
        {
            FDialougueElement Element;
            Element.NPCText = FText::FromString(TEXT("Слушаю.."));
            Element.PlayerText = FText::FromString(TEXT("Мой Повелитель, я принёс обещанную жертву. Прошу вас, выполните своё обещание, \nскажите кто эта девушка на медальоне?"));
            Quest.Dialogues.Add(Element);
        }
        {
            FDialougueElement Element;
            Element.NPCText = FText::FromString(TEXT("Кто эта девушка? Ха-ха-ха. Она жена короля Эльтоса"));
            Element.PlayerText = FText::FromString(TEXT("Но.."));
            Quest.Dialogues.Add(Element);
        }

        // Conditional for quest finish
        Quest.Conditional.ItemType = EItemType::HumanItem;
        Quest.Conditional.ItemsCount = 2;
        
        // Reward for this Quest
        Quest.Reward.CthulhuFeedPercent = 0.3; // increase this part from init maximum
        Quest.Reward.CthulhuFeedMaxPercent = -0.3; // increase maximum on this percent
        Quest.Reward.LevelUp = true;


        Quests.Add(Quest);
    }

}

