// Fill out your copyright notice in the Description page of Project Settings.


#include "AsteroidSpawner.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AAsteroidSpawner::AAsteroidSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAsteroidSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	RestartSpawnTimer();
}

// Called every frame
void AAsteroidSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAsteroidSpawner::SpawnAsteroid()
{
	if (!AsteroidsToSpawn)
		return;
	
	float SpawnPosZ = FMath::RandRange(DownMaxSpawnPos.Z,UpMaxSpawnPos.Z);
	
	float SpawPosY = FMath::RandRange(49.0f,51.0f); // For Overlap purpose
	
	FVector SpawnLocation = {DownMaxSpawnPos.X,SpawPosY, SpawnPosZ};
	
	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(AsteroidsToSpawn,SpawnLocation , FRotator(0, 0, 0));
	
	RestartSpawnTimer();
}

void AAsteroidSpawner::RestartSpawnTimer()
{
	float TimeBeforeNextSpawn = FMath::RandRange(MinSpawnInterval,MaxSpawnInterval);
	FTimerManager& WorldTimer = GetWorld()->GetTimerManager();
	WorldTimer.SetTimer(SpawnTimer,this,&AAsteroidSpawner::SpawnAsteroid,TimeBeforeNextSpawn);
}

