#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DeathVolume.generated.h"
#include "Components/BoxComponent.h"

UCLASS()
class YOURPROJECT_API ADeathVolume : public AActor
{
	GENERATED_BODY()

public:
	ADeathVolume();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* DeathBox;

	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
};