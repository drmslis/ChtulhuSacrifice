// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PickUpObject.h"
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
    
    UFUNCTION(BlueprintCallable, Category = "Actions")
    void BindEvents();
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Actions")
    void ShowPickupText(bool Show);
};
