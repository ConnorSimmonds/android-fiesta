// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawnShip.generated.h"

UCLASS()
class TESTPROJECT_API AEnemySpawnShip : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawnShip();
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* VisualMesh;

	int spawnTimer = 0;
	int maxSpawnTimer = 60;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> EnemyToSpawn;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void SpawnEnemy(FVector Loc, FRotator rot);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
