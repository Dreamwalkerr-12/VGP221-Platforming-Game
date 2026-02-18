// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoinPickup.generated.h"

class UStaticMeshComponent;
class URotatingMovementComponent;
class USphereComponent;

UCLASS()
class EE_API ACoinPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoinPickup();

	UFUNCTION()
	void OnBeginOverlapComponentEvent(
		UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Coin Pickup")
	TObjectPtr<UStaticMeshComponent> MeshComponent;
	
	UPROPERTY(EditDefaultsOnly, Category = "Coin Pickup")
	TObjectPtr<URotatingMovementComponent> RotatingMovementComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Coin Pickup")
	TObjectPtr<USphereComponent> SphereComponent;
};
