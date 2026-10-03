// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperSpriteComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"

#include "TP1_Space_Shooter/Asteroid/AsteroidActor.h"
#include "TP1_Space_Shooter/Components/Health/HealthComponent.h"

#include "Projectile.generated.h"

UCLASS()
class TP1_SPACE_SHOOTER_API AProjectile : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BoxComponent;
	
	UPROPERTY(VisibleAnywhere)
	class UPaperSpriteComponent* SpriteComponent;
	
	UPROPERTY(VisibleAnywhere)
	class UProjectileMovementComponent* ProjectileMovementComponent;
	
	UPROPERTY(EditAnywhere, Category="Projectile|Parameters")
	int Damage = 1;
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private : 
	
	UFUNCTION()
	void OnOverlap(AActor* MyActor, AActor* OtherActor);
	
	void HandleDeath();
};
