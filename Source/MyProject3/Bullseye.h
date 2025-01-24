// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Hittable.h"
#include "GameFramework/Actor.h"
#include "Bullseye.generated.h"

UCLASS()
class MYPROJECT3_API ABullseye : public AActor, public IHittable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullseye();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
    UFUNCTION()
    void OnComponentHit(
            UPrimitiveComponent* HitComponent,  // The component that was hit
            AActor* OtherActor,                 // The actor that hit this component
            UPrimitiveComponent* OtherComp,     // The other component involved
            FVector NormalImpulse,              // Impulse from the hit
            const FHitResult& Hit               // Detailed hit result info
        );
    
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* StaticBullsEyeMesh;
};
