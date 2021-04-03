// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PickUpObject.h"
#include "QuestGiver.h"
#include "InGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class CTHULHUSACRIFICE_API AInGameHUD : public AHUD
{
	GENERATED_BODY()
	
public:
    UFUNCTION()
    void UpdatePickupText(APickUpObject* PickUpObject);
    
    UFUNCTION()
    void UpdateQuestGiverText(UQuestGiver* QuestGiver);
    
    UFUNCTION()
    void OnQuestGiverTalk(UQuestGiver* QuestGiver);
    
    UFUNCTION(BlueprintCallable, Category = "Actions")
    void BindEvents();
    
    UFUNCTION(BlueprintCallable, Category = "Actions")
    void UpdateCthulhuFeed(float CurrFeed, float MaxFeed);
    
    UFUNCTION(BlueprintCallable, Category = "Actions")
    void NextQuestGiverTalkButtonClicked();
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Actions")
    void ShowPickupText(bool Show);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Actions")
    void ShowQuestGiverToTalkText(bool Show);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Actions")
    void UpdateInventory(UInventory* Inventory);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Actions")
    void UpdateCthulhuFeedPercent(float Percent);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Actions")
    void ShowQuestGiverTalkWidget(bool Show);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Actions")
    void SetQuestGiverTalkWidgetText(const FText& Text);

    UPROPERTY()
    int DialogueIdx;

    UPROPERTY()
    UQuestGiver* QuestGiver_C;
};
