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
    void UpdateHP(float CurrHP, float MaxHP);
    
    UFUNCTION(BlueprintCallable, Category = "Actions")
    void NextQuestGiverTalkButtonClicked();
    
    UFUNCTION(BlueprintCallable, Category = "Actions")
    void GameOver();

    // Implemented inside blueprints
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
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Actions")
    void SetPlayerTalkWidgetText(const FText& Text);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Actions")
    void SetQuestMainImage(UTexture2D* Image);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Actions")
    void SetQuestPlayerIcon(UTexture2D* Image);

    UFUNCTION(BlueprintImplementableEvent, Category = "Actions")
    void SetQuestNPCIcon(UTexture2D* Image);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Actions")
    void UpdateHPPercent(float Percent);

    UFUNCTION(BlueprintImplementableEvent, Category = "Actions")
    void LoadMainMenu();

    // private fields
    UPROPERTY()
    int DialogueIdx;

    UPROPERTY()
    bool IsGameOver = false;
    
    UPROPERTY()
    UQuestGiver* QuestGiver_C;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
    UQuestGiver* QuestGiver_GameOver;
};
