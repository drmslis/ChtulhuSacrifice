// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Camera/CameraComponent.h"
#include "PickUpObject.h"
#include "QuestGiver.h"
#include "PickUpping.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangedPickUpEvent, APickUpObject*, PickUpObject);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangedQuestGiverToTalkEvent, UQuestGiver*, QuestGiver);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestGiverTalkEvent, UQuestGiver*, QuestGiver);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CTHULHUSACRIFICE_API UPickUpping : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPickUpping();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
    UFUNCTION()
    void UpdatePickUpObject();
    UFUNCTION(BlueprintCallable, Category = "Actions")
    void PickUp();
    UFUNCTION(BlueprintCallable, Category = "Actions")
    bool Talk();

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
    APickUpObject* PickUpObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
    UQuestGiver* QuestGiver;
    
    UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
    FOnChangedPickUpEvent ChangedPickUpEvent;
    
    UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
    FOnChangedQuestGiverToTalkEvent ChangedQuestGiverToTalkEvent;

    UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
    FOnQuestGiverTalkEvent QuestGiverTalkEvent;
    
    UPROPERTY()
    UCameraComponent* Camera;
    
    UPROPERTY()
    class UInventory* Inventory;

    UPROPERTY(BluePrintReadWrite, EditAnywhere, Category = "Variables")
    float PickUpDistance;
};
