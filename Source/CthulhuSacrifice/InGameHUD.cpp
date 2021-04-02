// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameHUD.h"

#include "GameFramework/Character.h"
#include "Kismet/GamePlayStatics.h"
#include "PickUpping.h"
#include "Inventory.h"

void AInGameHUD::UpdatePickupText(APickUpObject* PickUpObject)
{
    ShowPickupText(IsValid(PickUpObject));
}

void AInGameHUD::BindEvents()
{
    ACharacter* Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

    if(IsValid(Character))
    {
        UPickUpping* PickUpping = Cast<UPickUpping>(Character->GetComponentByClass(UPickUpping::StaticClass()));
        UInventory* Inventory = Cast<UInventory>(Character->GetComponentByClass(UInventory::StaticClass()));
        
        if(IsValid(PickUpping))
        {
            PickUpping->ChangedPickUpEvent.AddDynamic(this, &AInGameHUD::UpdatePickupText);
        }
        
        if(IsValid(Inventory))
        {
            Inventory->InventoryChanged.AddDynamic(this, &AInGameHUD::UpdateInventory);
        }
    }
}