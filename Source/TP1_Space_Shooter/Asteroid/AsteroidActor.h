// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperFlipbookComponent.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "TP1_Space_Shooter/PlayerPawn.h"
#include "TP1_Space_Shooter/Components/Health/HealthComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AsteroidActor.generated.h"

UCLASS()
class TP1_SPACE_SHOOTER_API AAsteroidActor : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BoxCollision;
	UPROPERTY(VisibleAnywhere)
	class UPaperSpriteComponent* SpriteComponent;
	UPROPERTY(VisibleAnywhere)
	class UProjectileMovementComponent* ProjectileMovementComponent;
	UPROPERTY(VisibleAnywhere)
	class UHealthComponent* HealthComponent;
	UPROPERTY(VisibleAnywhere)
	class UPaperFlipbookComponent* FlipbookComponent;
	
	
	UPROPERTY(EditAnywhere, Category="AsteroidActor|Sprite")
	class UPaperFlipbook* ExplosionFlipbook;
	
	UPROPERTY(EditAnywhere, Category="AsteroidActor|Parameters")
	int Damage = 1;
	
	UPROPERTY(EditAnywhere, Category="AsteroidActor|Parameters")
	float MaxScale = 2.0f;
	UPROPERTY(EditAnywhere, Category="AsteroidActor|Parameters")
	float MinScale = 1.0f;
	
	UPROPERTY(EditAnywhere, Category="AsteroidActor|Parameters")
	float MaxZVelocity = 0.5f;
	UPROPERTY(EditAnywhere, Category="AsteroidActor|Parameters")
	float MinZVelocity = 0.0f;
	
	UPROPERTY(EditAnywhere, Category="AsteroidActor|Parameters")
	float MaxRandomSpeed = 250.0f;
	UPROPERTY(EditAnywhere, Category="AsteroidActor|Parameters")
	float MinRandomSpeed = 150.0f;
	
	bool IsDead = false;
public:	
	// Sets default values for this actor's properties
	AAsteroidActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	UFUNCTION()
	void HandleDeath();
	
	UFUNCTION()
	void OnFlipbookFinished();
	
	UFUNCTION()
	void OnOverlap(AActor* MyActor, AActor* OtherActor) const;
	
	void InitializeRandomVelocity() const;
	void InitializeRandomScale();
	void InitializeRandomSpeed() const;
};
