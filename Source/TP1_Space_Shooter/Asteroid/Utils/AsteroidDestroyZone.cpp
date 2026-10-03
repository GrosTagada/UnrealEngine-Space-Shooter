// Fill out your copyright notice in the Description page of Project Settings.


#include "AsteroidDestroyZone.h"

#include "TP1_Space_Shooter/Asteroid/AsteroidActor.h"

// Sets default values
AAsteroidDestroyZone::AAsteroidDestroyZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
}

// Called when the game starts or when spawned
void AAsteroidDestroyZone::BeginPlay()
{
	Super::BeginPlay();
	
	this->OnActorBeginOverlap.AddDynamic(this, &AAsteroidDestroyZone::DestroyAsteroid);
}

// Called every frame
void AAsteroidDestroyZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAsteroidDestroyZone::DestroyAsteroid(AActor* MyActor, AActor* OtherActor)
{
	if (AAsteroidActor* AsteroidActor = Cast<AAsteroidActor>(OtherActor))
	{
		AsteroidActor->Destroy();
	}
}

