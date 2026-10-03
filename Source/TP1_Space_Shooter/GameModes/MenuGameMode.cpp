// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuGameMode.h"

void AMenuGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	MainMenuWidget = CreateWidget<UUserWidget>(GetWorld(),MainMenuWidgetClass);//Get World = owner of the new created class
	CreditsWidget = CreateWidget<UUserWidget>(GetWorld(),CreditsWidgetClass);
	
	if (MainMenuWidget )
	{
		MainMenuWidget->AddToViewport();
		
		APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
		
		if (PlayerController)
		{
			PlayerController->SetShowMouseCursor(true);
			PlayerController->SetInputMode(FInputModeUIOnly());
		}
	}
	
	if (CreditsWidget)
	{
		CreditsWidget->SetVisibility(ESlateVisibility::Collapsed);
		CreditsWidget->AddToViewport();
	}
}

void AMenuGameMode::GoToCredits()
{
	if (CreditsWidget && MainMenuWidget)
	{
		MainMenuWidget->SetVisibility(ESlateVisibility::Collapsed);
		CreditsWidget->SetVisibility(ESlateVisibility::Visible);
		
	}
}

void AMenuGameMode::GoToMainMenu()
{
	if (CreditsWidget && MainMenuWidget)
	{
		MainMenuWidget->SetVisibility(ESlateVisibility::Visible);
		CreditsWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}
