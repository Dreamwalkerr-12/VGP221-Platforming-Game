#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JumpPad.generated.h"

UCLASS()
class YOURGAME_API AJumpPad : public AActor
{
    GENERATED_BODY()

public:
    AJumpPad();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    class UStaticMeshComponent* PadMesh;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    class UBoxComponent* TriggerBox;

    UPROPERTY(EditAnywhere, Category = "Jump Settings")
    float LaunchStrength = 1500.f;

    UPROPERTY(EditAnywhere, Category = "Jump Settings")
    bool bOverrideXYVelocity = false;

    UPROPERTY(EditAnywhere, Category = "Jump Settings")
    bool bOverrideZVelocity = true;

    UFUNCTION()
    void OnOverlapBegin(
        UPrimitiveComponent* OverlappedComponent,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex,
        bool bFromSweep,
        const FHitResult& SweepResult
    );
};