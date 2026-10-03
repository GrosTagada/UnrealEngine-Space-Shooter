// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "AsteroidDestroyZone.generated.h"

UCLASS()
class TP1_SPACE_SHOOTER_API AAsteroidDestroyZone : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> BoxComponent;
	
	
public:	
	// Sets default values for this actor's properties
	AAsteroidDestroyZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void DestroyAsteroid(AActor* MyActor, AActor* OtherActor);
};
