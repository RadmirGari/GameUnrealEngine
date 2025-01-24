// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ScoreHUD.h"
#include "GameFramework/GameModeBase.h"
#include "ScoreKeeper.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT3_API AScoreKeeper : public AGameModeBase
{
	GENERATED_BODY()
    
    
    static constexpr int MAX_SCORE = 7;
    
    UPROPERTY()
    int score;
    
    UPROPERTY()
    AScoreHUD* scoreHUD;
    
public:
    
    AScoreKeeper();
	
    UFUNCTION()
    void addScore();
    
    UFUNCTION()
    void win();
    
    UFUNCTION()
    int getScore();
    
    UFUNCTION()
    void updateDisplay();
};
