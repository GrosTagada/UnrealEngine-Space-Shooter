// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

#include "InputMappingContext.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/Health/HealthComponent.h"

#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class TP1_SPACE_SHOOTER_API APlayerPawn : public APawn
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere);
	class UBoxComponent* BoxCollision;
	
	UPROPERTY(VisibleAnywhere);
	TObjectPtr<UPaperSpriteComponent> SpriteComponent;
	
	UPROPERTY(VisibleAnywhere);
	TObjectPtr<UFloatingPawnMovement> PawnMovementComponent;
	
	UPROPERTY(VisibleAnywhere);
	TObjectPtr<UHealthComponent> HealthComponent;
	
	UPROPERTY(EditAnywhere, Category = "Player|Input");
	TObjectPtr<UInputMappingContext> DefaultMappingContext;
	
	UPROPERTY(EditAnywhere, Category = "Player|Projectile");
	TSubclassOf<AActor> ObjectToSpawn;

	UPROPERTY(EditAnywhere,Category="Player|Projectile")
	float SpawnDistance = 100.0f;
	
	UPROPERTY(EditAnywhere, Category="Player|Movement|Bounds")
	float MinX = -800.0f;
	UPROPERTY(EditAnywhere, Category="Player|Movement|Bounds")
	float MaxX = 800.0f;
	UPROPERTY(EditAnywhere, Category="Player|Movement|Bounds")
	float MinZ = -800.0f;
	UPROPERTY(EditAnywhere, Category="Player|Movement|Bounds")
	float MaxZ = 800.0f;
	
public :
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player|Movement");
	float MoveSpeed = 500.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player|Input");
	class UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Player|Input")
	class UInputAction* ShootAction;

public:
	// Sets default values for this pawn's properties
	APlayerPawn();
	
	UFUNCTION()
	void Move(const FInputActionValue& Value);
	
	UFUNCTION()
	void Shoot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
private : 
	
	UFUNCTION()
	void HandleDeath();
	void ClampPlayerPosition();

};
