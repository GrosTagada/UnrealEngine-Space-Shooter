// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceShipController.h"

#include "TP1_Space_Shooter/GameModes/SpaceShooterGameMode.h"

void ASpaceShipController::BeginPlay()
{
	Super::BeginPlay();

	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem =
			LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (InputMappingContext)
			{
				InputSubsystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}
}

void ASpaceShipController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		if (PauseAction)
		{
			EnhancedInputComponent->BindAction(PauseAction,ETriggerEvent::Started,this,&ASpaceShipController::TogglePause);
		}
	}
}

void ASpaceShipController::TogglePause()
{
	ASpaceShooterGameMode* GameMode = Cast<ASpaceShooterGameMode>(GetWorld()->GetAuthGameMode());

	if (!GameMode)
		return;

	if (GameMode->IsPaused())
	{
		GameMode->Resume();
	}
	else
	{
		GameMode->Pause();
	}
}