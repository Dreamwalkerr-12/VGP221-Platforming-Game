// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinPickup.h"

#include "Components/SphereComponent.h"
#include "GameFramework/RotatingMovementComponent.h"

// Sets default values
ACoinPickup::ACoinPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SetRootComponent(SphereComponent);
	SphereComponent->SetGenerateOverlapEvents(true);
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	SphereComponent->OnComponentBeginOverlap.AddDynamic(
		this, &ACoinPickup::OnBeginOverlapComponentEvent
	);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(SphereComponent);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshComponent->SetGenerateOverlapEvents(false);

	RotatingMovementComponent = CreateDefaultSubobject<URotatingMovementComponent>("RotatingMovementComponent");
}

void ACoinPickup::OnBeginOverlapComponentEvent(
	UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult
)
{
	if(!Cast<ACharacter>(OtherActor))
	{
		return;
		Destroy();
	}
}

