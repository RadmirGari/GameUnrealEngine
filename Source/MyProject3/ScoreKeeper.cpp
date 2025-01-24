// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreKeeper.h"
#include "Kismet/GameplayStatics.h"  // For getting player controllers
#include "GameFramework/PlayerController.h"

AScoreKeeper::AScoreKeeper(){
    score = 0;
}

void AScoreKeeper::addScore(){
    score++;
    updateDisplay();
    if(score >= AScoreKeeper::MAX_SCORE){
        win();
    }
}

void AScoreKeeper::win(){
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("You won!"));
}

void AScoreKeeper::updateDisplay(){
    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
    if(!PlayerController){
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Failed to load player controller"));
    }
    scoreHUD = Cast<AScoreHUD>(PlayerController->GetHUD());
    if(!scoreHUD){
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Failed to load scorehud"));
    }
    
    scoreHUD->updateDisplay(score, AScoreKeeper::MAX_SCORE);
}

int AScoreKeeper::getScore(){
    return score;
}

