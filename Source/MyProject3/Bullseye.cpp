// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullseye.h"
#include "Projectile.h"
#include "ScoreKeeper.h"

ABullseye::ABullseye()
{
    StaticBullsEyeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticBullsEyeMesh"));
    RootComponent = StaticBullsEyeMesh;
    
    StaticBullsEyeMesh->SetEnableGravity(false);
    StaticBullsEyeMesh->SetMobility(EComponentMobility::Static);
    StaticBullsEyeMesh->SetNotifyRigidBodyCollision(true);
    StaticBullsEyeMesh->BodyInstance.SetCollisionProfileName(TEXT("BlockAll"));
    StaticBullsEyeMesh->OnComponentHit.AddDynamic(this, &ABullseye::OnComponentHit);
    
    ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Target/SM_Target.SM_Target"));
    StaticBullsEyeMesh->SetStaticMesh(MeshAsset.Object);

    
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABullseye::BeginPlay()
{
	Super::BeginPlay();
    GEngine->AddOnScreenDebugMessage(
     -1,
     5.0f,
     FColor::Green,
     TEXT("Bullseye successfully loaded!")
     );
}

// Called every frame
void ABullseye::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullseye::OnComponentHit(UPrimitiveComponent* HitComponent,
       AActor* OtherActor,
       UPrimitiveComponent* OtherComp,
       FVector NormalImpulse,
       const FHitResult& Hit){
    
    if(!OtherActor || !OtherActor->GetClass()->ImplementsInterface(UProjectile::StaticClass())) return;
    
    
    AScoreKeeper* scoreKeeper = Cast<AScoreKeeper>(GetWorld()->GetAuthGameMode());
    if(!scoreKeeper){
        return;
    }
    scoreKeeper->addScore();
    
    Destroy();
}

