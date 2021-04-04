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
        Quest.Reward.CthulhuFeedMaxPercent = -0.2; // increase maximum on this percent
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

        {
            FDialougueElement Element;
            Element.NPCText = FText::FromString(TEXT("Ты просил правду - я сказал. ВОН и не зли меня\n Больше жертв - больше ответов"));
            Element.PlayerText = FText::FromString(TEXT(".."));
            Quest.Dialogues.Add(Element);
        }


        // Conditional for quest finish
        Quest.Conditional.ItemType = EItemType::HumanItem;
        Quest.Conditional.ItemsCount = 1;
        
        // Reward for this Quest
        Quest.Reward.CthulhuFeedPercent = 0.2; // increase this part from init maximum
        Quest.Reward.CthulhuFeedMaxPercent = -0.2; // increase maximum on this percent
        Quest.Reward.LevelUp = true;


        Quests.Add(Quest);
    }

    {
        FQuest Quest;

        // Dialogue from this NPC for this Quest
        {
            FDialougueElement Element;
            Element.NPCText = FText::FromString(TEXT(".."));
            Element.PlayerText = FText::FromString(TEXT("Мой Повелитель, я принес новую жертву. \nПо дороге назад я нашел эту карту и меня посетило видение,\n в котором я снова видел эту девушку. Что это за карта?"));
            Quest.Dialogues.Add(Element);
        }
        {
            FDialougueElement Element;
            Element.NPCText = FText::FromString(TEXT("Её купили, чтобы найти сокровища"));
            Element.PlayerText = FText::FromString(TEXT("ой повелитель, но это не тот ответ на который я расчитывал"));
            Quest.Dialogues.Add(Element);
        }

        {
            FDialougueElement Element;
            Element.NPCText = FText::FromString(TEXT("Ты смеешь мне уазывать? Какой вопрос такой и ответ. Убирайся"));
            Element.PlayerText = FText::FromString(TEXT(".."));
            Quest.Dialogues.Add(Element);
        }




        // Conditional for quest finish
        Quest.Conditional.ItemType = EItemType::HumanItem;
        Quest.Conditional.ItemsCount = 1;

        // Reward for this Quest
        Quest.Reward.CthulhuFeedPercent = 0.2; // increase this part from init maximum
        Quest.Reward.CthulhuFeedMaxPercent = -0.2; // increase maximum on this percent
        Quest.Reward.LevelUp = true;


        Quests.Add(Quest);
    }

    {
        FQuest Quest;

        // Dialogue from this NPC for this Quest
        {
            FDialougueElement Element;
            Element.NPCText = FText::FromString(TEXT(".."));
            Element.PlayerText = FText::FromString(TEXT("Мой повелитель, новая жертва уже отправилась на алтарь.\n Как я связан с русалкой, которая сидит на рифах?"));
            Quest.Dialogues.Add(Element);
        }
        {
            FDialougueElement Element;
            Element.NPCText = FText::FromString(TEXT("Она тоже хотела найти сокровища. \nТы так и не научился задавать правильные вопросы, червь. \nИди за новой жертвой и не трать моё время"));
            Element.PlayerText = FText::FromString(TEXT(".."));
            Quest.Dialogues.Add(Element);
        }

        // Conditional for quest finish
        Quest.Conditional.ItemType = EItemType::HumanItem;
        Quest.Conditional.ItemsCount = 1;

        // Reward for this Quest
        Quest.Reward.CthulhuFeedPercent = 1.0; // increase this part from init maximum
        Quest.Reward.CthulhuFeedMaxPercent = -0.2; // increase maximum on this percent
        Quest.Reward.LevelUp = true;


        Quests.Add(Quest);
    }


}

