// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SpaceShooterGameMode.generated.h"


UCLASS()
class TP1_SPACE_SHOOTER_API ASpaceShooterGameMode : public AGameModeBase
{
	UPROPERTY(EditDefaultsOnly, Category="SpaceShooterGameMode|UI")
	TSubclassOf<UUserWidget> PlayerOverlayWidgetClass;
	UPROPERTY(EditDefaultsOnly, Category="SpaceShooterGameMode|UI")
	TSubclassOf<UUserWidget> PauseMenuWidgetClass;
	UPROPERTY(EditDefaultsOnly, Category="SpaceShooterGameMode|UI")
	TSubclassOf<UUserWidget> GameOverWidgetClass;
	
	UPROPERTY()
	TObjectPtr<UUserWidget> PlayerOverlayWidget;
	UPROPERTY()
	TObjectPtr<UUserWidget> PauseMenuWidget;
	UPROPERTY()
	TObjectPtr<UUserWidget> GameOverWidget;
	
	TObjectPtr<APlayerController> PlayerController;
	
	GENERATED_BODY()
	
protected :
	virtual void BeginPlay() override;
	
public:
	UFUNCTION(BlueprintCallable)
	void Pause();
	UFUNCTION(BlueprintCallable)
	void Resume();
	
	UFUNCTION()
	void GameOver();
};
