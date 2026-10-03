// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AsteroidSpawner.generated.h"

UCLASS()
class TP1_SPACE_SHOOTER_API AAsteroidSpawner : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "Asteroid Spawner|Spawn Object")
	TSubclassOf<AActor> AsteroidsToSpawn;
	
	UPROPERTY(EditAnywhere, Category= "Asteroid Spawner|Spawn Zone")
	FVector UpMaxSpawnPos;
	UPROPERTY(EditAnywhere, Category= "Asteroid Spawner|Spawn Zone")
	FVector DownMaxSpawnPos;
	
	UPROPERTY(EditAnywhere, Category= "Asteroid Spawner|Spawn parameters")
	float MaxSpawnInterval = 2.0f;
	UPROPERTY(EditAnywhere, Category= "Asteroid Spawner|Spawn parameters")
	float MinSpawnInterval = 1.0f;
	
public:	
	// Sets default values for this actor's properties
	AAsteroidSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FTimerHandle SpawnTimer;
	void SpawnAsteroid();
	
	void RestartSpawnTimer();

};
