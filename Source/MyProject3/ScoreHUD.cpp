// Fill out your copyright notice in the Description page of Project Settings.

#include "ScoreHUD.h"
#include "UObject/ConstructorHelpers.h"

AScoreHUD::AScoreHUD(){
    
}

void AScoreHUD::BeginPlay(){
    Super::BeginPlay();
}

void AScoreHUD::updateDisplay(int score, int maxScore){
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Nice!"));
}

