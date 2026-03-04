#include "DeathVolume.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

ADeathVolume::ADeathVolume()
{
	PrimaryActorTick.bCanEverTick = false;

	DeathBox = CreateDefaultSubobject<UBoxComponent>(TEXT("DeathBox"));
	RootComponent = DeathBox;

	DeathBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	DeathBox->SetCollisionResponseToAllChannels(ECR_Overlap);
}

void ADeathVolume::BeginPlay()
{
	Super::BeginPlay();

	DeathBox->OnComponentBeginOverlap.AddDynamic(this, &ADeathVolume::OnOverlapBegin);
}

void ADeathVolume::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	ACharacter* Player = Cast<ACharacter>(OtherActor);

	if (Player)
	{
		FName CurrentLevel = *UGameplayStatics::GetCurrentLevelName(this, true);
		UGameplayStatics::OpenLevel(this, CurrentLevel);
	}
}