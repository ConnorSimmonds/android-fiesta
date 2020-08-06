// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawnShip.h"

// Sets default values
AEnemySpawnShip::AEnemySpawnShip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (CubeVisualAsset.Succeeded()) {
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh -> SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

// Called when the game starts or when spawned
void AEnemySpawnShip::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemySpawnShip::SpawnEnemy(FVector Loc, FRotator rot) {
	// 

	UClass* EnemyFollow = StaticLoadClass(UObject::StaticClass(), NULL, TEXT("/Game/Content/ThirdPersonBP/Blueprints/EnemyFollow.EnemyFollowActor_C"), NULL, LOAD_None, NULL);
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	AActor* SpawnedActorRef = GetWorld()->SpawnActor<AActor>(EnemyFollow, Loc, rot, SpawnParams);
}

// Called every frame
void AEnemySpawnShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();

	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));

	NewLocation.Z += DeltaHeight * 20.0f;
	float DeltaRotation = DeltaTime * 20.0f;
	NewRotation.Yaw += DeltaRotation;

	SetActorLocationAndRotation(NewLocation, NewRotation);

	spawnTimer++;

	if (spawnTimer >= maxSpawnTimer) {
		spawnTimer = 0;
		//spawn an enemy who follows the player
		//The file path for this is 
		NewLocation.X += DeltaHeight * 20.0f;
		NewLocation.Y += DeltaHeight * 20.0f;
		SpawnEnemy(NewLocation, NewRotation);
	}

}

