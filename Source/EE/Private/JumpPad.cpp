#include "JumpPad.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"

AJumpPad::AJumpPad()
{
    PrimaryActorTick.bCanEverTick = false;

    // Root
    PadMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PadMesh"));
    RootComponent = PadMesh;

    // Trigger Box
    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    TriggerBox->SetupAttachment(RootComponent);
    TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    TriggerBox->SetCollisionResponseToAllChannels(ECR_Ignore);
    TriggerBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AJumpPad::OnOverlapBegin);
}

void AJumpPad::BeginPlay()
{
    Super::BeginPlay();
}

void AJumpPad::OnOverlapBegin(
    UPrimitiveComponent* OverlappedComponent,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    ACharacter* Character = Cast<ACharacter>(OtherActor);
    if (Character)
    {
        FVector LaunchVelocity = FVector(0.f, 0.f, LaunchStrength);
        Character->LaunchCharacter(LaunchVelocity, bOverrideXYVelocity, bOverrideZVelocity);
    }
}