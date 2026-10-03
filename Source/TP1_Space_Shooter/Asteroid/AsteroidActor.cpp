// Fill out your copyright notice in the Description page of Project Settings.


#include "AsteroidActor.h"

#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
AAsteroidActor::AAsteroidActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	FlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("FlipbookComponent"));
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Component"));
	
	RootComponent = BoxCollision;
	SpriteComponent->SetupAttachment(RootComponent);
	FlipbookComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AAsteroidActor::BeginPlay()
{
	Super::BeginPlay();
	
	HealthComponent->OnDeath.AddDynamic(this,&AAsteroidActor::HandleDeath);
	
	this->OnActorBeginOverlap.AddDynamic(this,&AAsteroidActor::OnOverlap);
	
	InitializeRandomScale();
	InitializeRandomVelocity();
	InitializeRandomSpeed();
}

// Called every frame
void AAsteroidActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAsteroidActor::HandleDeath()
{
	IsDead = true;
	
	ProjectileMovementComponent->Velocity= {0,0,0}; //Stop the mouvement
	
	if (!ExplosionFlipbook)
		return;
	
	SpriteComponent->SetSprite(nullptr);
	
	FlipbookComponent->SetFlipbook(ExplosionFlipbook);
	FlipbookComponent->SetLooping(false);
	FlipbookComponent->PlayFromStart();
	
	FlipbookComponent->OnFinishedPlaying.AddDynamic(this,&AAsteroidActor::OnFlipbookFinished);
}

void AAsteroidActor::OnFlipbookFinished()
{
	this->Destroy();
}

void AAsteroidActor::OnOverlap(AActor* MyActor, AActor* OtherActor) const
{
	if (IsDead)
		return;
	
	if (APlayerPawn* player = Cast<APlayerPawn>(OtherActor))
	{
		UHealthComponent* playerHealthComponent = player->GetComponentByClass<UHealthComponent>();
		
		if (!playerHealthComponent)
			return; 
		
		playerHealthComponent->TakeDamage(Damage);
	}
}

void AAsteroidActor::InitializeRandomVelocity() const
{
	float ZDirection = FMath::RandRange(MinZVelocity, MaxZVelocity);
	
	if (GetActorLocation().Z >= 50)
		ZDirection = -ZDirection;

	FVector Direction = FVector(-1.0f, 0.0f, ZDirection).GetSafeNormal();

	ProjectileMovementComponent->Velocity = Direction * ProjectileMovementComponent->InitialSpeed;
}

void AAsteroidActor::InitializeRandomScale()
{
	float scale =  FMath::RandRange(MinScale,MaxScale);
	
	SetActorRelativeScale3D({scale,scale,scale});
}

void AAsteroidActor::InitializeRandomSpeed() const
{
	float MaxSpeed = FMath::RandRange(MinRandomSpeed,MaxRandomSpeed);
	ProjectileMovementComponent->MaxSpeed = MaxSpeed;
}





