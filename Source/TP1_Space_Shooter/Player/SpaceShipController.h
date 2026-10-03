// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"

#include "../GameModes/SpaceShooterGameMode.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SpaceShipController.generated.h"



UCLASS()
class TP1_SPACE_SHOOTER_API ASpaceShipController : public APlayerController
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, Category = "SpaceShipController|Input")
	TObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "SpaceShipController|Input")
	TObjectPtr<UInputAction> PauseAction;
	
protected:
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
	void TogglePause();
};
