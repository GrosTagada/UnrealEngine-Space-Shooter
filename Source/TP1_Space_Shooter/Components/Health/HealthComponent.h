// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged,int,Health);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TP1_SPACE_SHOOTER_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()
	
	int Health = 1;
	
	UPROPERTY(VisibleAnywhere, Category= "HealthComponent|Debug")
	bool IsDead = false;

public:	
	// Sets default values for this component's properties
	UHealthComponent();
	
	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;
	UPROPERTY(BlueprintAssignable)
	FOnDeath OnDeath;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category= "HealthComponent|Parameters")
	int MaxHealth = 1;
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	void TakeDamage(int damage);
	
	UFUNCTION(BlueprintCallable)
	int GetHealth();

		
};
