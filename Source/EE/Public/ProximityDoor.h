#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "ProximityDoor.generated.h"

UCLASS()
class YOURPROJECT_API AProximityDoor : public AActor
{
	GENERATED_BODY()

public:
	AProximityDoor();

protected:
	virtual void BeginPlay() override;

	/* Components */
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DoorMesh;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* TriggerBox;

	/* Timeline */
	UPROPERTY()
	UTimelineComponent* DoorTimeline;

	UPROPERTY(EditAnywhere)
	UCurveFloat* DoorCurve;

	FOnTimelineFloat TimelineProgress;

	UFUNCTION()
	void HandleProgress(float Value);

	/* Overlap */
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	/* Settings */
	UPROPERTY(EditAnywhere)
	float OpenAngle = 90.f;

	FRotator ClosedRotation;
};