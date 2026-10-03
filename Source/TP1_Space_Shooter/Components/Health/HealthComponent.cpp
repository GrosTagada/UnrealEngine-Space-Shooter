// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
	Health = MaxHealth;
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UHealthComponent::TakeDamage(int damage)
{
	if (IsDead)
		return;
	
	Health = Health - damage;
	OnHealthChanged.Broadcast(Health);
	
	if (Health <= 0)
	{
		IsDead = true;
		OnDeath.Broadcast();
	}
}

int UHealthComponent::GetHealth()
{
	return Health;
}

