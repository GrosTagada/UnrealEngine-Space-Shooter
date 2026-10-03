// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"


#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TP1_SPACE_SHOOTER_API AMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	UPROPERTY()
	TObjectPtr<UUserWidget> MainMenuWidget;
	UPROPERTY()
	TObjectPtr<UUserWidget> CreditsWidget;
	
	UPROPERTY(EditDefaultsOnly, Category = "Menu Game Mode|UI")
	TSubclassOf<UUserWidget> MainMenuWidgetClass;
	UPROPERTY(EditDefaultsOnly, Category = "Menu Game Mode|UI")
	TSubclassOf<UUserWidget> CreditsWidgetClass;
	
protected:
	virtual void BeginPlay() override;
	
public:
	UFUNCTION(BlueprintCallable)
	void GoToCredits();
	UFUNCTION(BlueprintCallable)
	void GoToMainMenu();
};
