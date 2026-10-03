// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	
	RootComponent = BoxComponent;
	SpriteComponent->SetupAttachment(BoxComponent);
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	this->OnActorBeginOverlap.AddDynamic(this,&AProjectile::OnOverlap);
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectile::OnOverlap(AActor* MyActor, AActor* OtherActor)
{
	if (AAsteroidActor* Asteroid = Cast<AAsteroidActor>(OtherActor))
	{
		UHealthComponent* otherHealthComponent = Asteroid->GetComponentByClass<UHealthComponent>();
	
		if (!otherHealthComponent)
		{
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Asteroids has not an health component"));
			return;
		}
			
	
		otherHealthComponent->TakeDamage(Damage);
		
		HandleDeath();
	}
}

void AProjectile::HandleDeath()
{
	this->Destroy();
}

