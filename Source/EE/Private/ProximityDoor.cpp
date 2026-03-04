#include "ProximityDoor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

AProximityDoor::AProximityDoor()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(Root);

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(Root);
	TriggerBox->SetBoxExtent(FVector(150.f));

	DoorTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("DoorTimeline"));
}

void AProximityDoor::BeginPlay()
{
	Super::BeginPlay();

	ClosedRotation = DoorMesh->GetRelativeRotation();

	if (DoorCurve)
	{
		TimelineProgress.BindUFunction(this, FName("HandleProgress"));
		DoorTimeline->AddInterpFloat(DoorCurve, TimelineProgress);
	}

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AProximityDoor::OnOverlapBegin);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &AProximityDoor::OnOverlapEnd);
}

void AProximityDoor::HandleProgress(float Value)
{
	FRotator NewRotation = ClosedRotation;
	NewRotation.Yaw += Value * OpenAngle;

	DoorMesh->SetRelativeRotation(NewRotation);
}

void AProximityDoor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);

	if (OtherActor == PlayerPawn)
	{
		DoorTimeline->Play();
	}
}

void AProximityDoor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);

	if (OtherActor == PlayerPawn)
	{
		DoorTimeline->Reverse();
	}
}