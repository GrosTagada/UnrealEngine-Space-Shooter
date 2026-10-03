// Fill out your copyright notice in the Description page of Project Settings.
#include "SpaceShooterGameMode.h"

#include "Kismet/GameplayStatics.h"

void ASpaceShooterGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	
	PlayerController = GetWorld()->GetFirstPlayerController();
	
	if (PlayerController)
	{
		PlayerController->SetInputMode(FInputModeGameOnly());
	}
	
	if (PlayerOverlayWidgetClass)
	{
		PlayerOverlayWidget = CreateWidget(GetWorld(),PlayerOverlayWidgetClass);
	
		if (PlayerOverlayWidget)
		{
			PlayerOverlayWidget->AddToViewport();
		}
	}
	
	if (PauseMenuWidgetClass)
	{
		PauseMenuWidget = CreateWidget(GetWorld(),PauseMenuWidgetClass);
	
		if (PauseMenuWidget)
		{
			PauseMenuWidget->SetVisibility(ESlateVisibility::Collapsed);
			PauseMenuWidget->AddToViewport();
		}
	}
	
	if (GameOverWidgetClass)
	{
		GameOverWidget = CreateWidget(GetWorld(),GameOverWidgetClass);
		
		if (GameOverWidget)
		{
			GameOverWidget->SetVisibility(ESlateVisibility::Collapsed);
			GameOverWidget->AddToViewport();
		}
	}
	
}

void ASpaceShooterGameMode::Pause()
{
	if (IsPaused())
		return;
	
	if (!PauseMenuWidget || !PlayerController)
		return;
	
	PauseMenuWidget->SetVisibility(ESlateVisibility::Visible);
	
	PlayerController->SetShowMouseCursor(true);
	PlayerController->SetInputMode(FInputModeGameAndUI());
	
	UGameplayStatics::SetGamePaused(GetWorld(), true);
}

void ASpaceShooterGameMode::Resume()
{
	if (!IsPaused())
		return;
	
	if (!PauseMenuWidget && !PlayerController)
		return;
	
	PauseMenuWidget->SetVisibility(ESlateVisibility::Collapsed);
	
	PlayerController->SetShowMouseCursor(false);
	PlayerController->SetInputMode(FInputModeGameOnly());
	
	UGameplayStatics::SetGamePaused(GetWorld(), false);
}

void ASpaceShooterGameMode::GameOver()
{
	if (PauseMenuWidget)
		PauseMenuWidget->SetVisibility(ESlateVisibility::Collapsed);
	
	if (PlayerOverlayWidget)
		PlayerOverlayWidget->SetVisibility(ESlateVisibility::Collapsed);
	
	if (GameOverWidget)
	{
		GameOverWidget->SetVisibility(ESlateVisibility::Visible);
		
		PlayerController->SetShowMouseCursor(true);
		PlayerController->SetInputMode(FInputModeUIOnly());
	}
}

