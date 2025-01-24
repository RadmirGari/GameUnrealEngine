// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ScoreHUD.generated.h"


/**
 * 
 */
UCLASS()
class MYPROJECT3_API AScoreHUD : public AHUD
{
	GENERATED_BODY()
    
public:
    AScoreHUD();
    
    virtual void BeginPlay() override;
    
    UFUNCTION(BlueprintCallable)
    void updateDisplay(int score, int maxScore);
};
