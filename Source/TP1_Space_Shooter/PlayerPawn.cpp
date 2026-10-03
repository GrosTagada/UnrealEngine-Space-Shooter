// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

#include "GameModes/SpaceShooterGameMode.h"


// Sets default values
APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	PawnMovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("PawnMovementComponent"));
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
	
	RootComponent = BoxCollision;
	SpriteComponent->SetupAttachment(BoxCollision);
}

void APlayerPawn::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	
	AddMovementInput(GetActorUpVector(), MovementVector.Y);
	AddMovementInput(GetActorForwardVector(), MovementVector.X);
}

void APlayerPawn::Shoot()
{
	FVector Location = GetActorLocation() + (GetActorForwardVector() * SpawnDistance);

	// Check object to spawn is not null
	if (ObjectToSpawn)
		GetWorld()->SpawnActor<AActor>(ObjectToSpawn, Location, FRotator(0, 0, 0));
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
	HealthComponent->OnDeath.AddDynamic(this,&APlayerPawn::HandleDeath);
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	ClampPlayerPosition(); //Should be somewhere else for performance reasons

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	
	if (!GEngine)
		return;
	
	if (!Input)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Input problem");
		return;
	}

	if (!MoveAction)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "InputAction not set");
		return;
	}
	
	Input->BindAction(MoveAction,ETriggerEvent::Triggered,this,&APlayerPawn::Move);
	Input->BindAction(ShootAction,ETriggerEvent::Triggered,this,&APlayerPawn::Shoot);
}

void APlayerPawn::HandleDeath()
{
	PawnMovementComponent->Velocity = {0,0,0};
	
	ASpaceShooterGameMode* GameMode = Cast<ASpaceShooterGameMode>(GetWorld()->GetAuthGameMode());
	
	if (!GameMode)
		return;
	
	GameMode->GameOver();
}


void APlayerPawn::ClampPlayerPosition()
{
	FVector Location = GetActorLocation();

	Location.X = FMath::Clamp(Location.X, MinX, MaxX);
	Location.Z = FMath::Clamp(Location.Z, MinZ, MaxZ);

	SetActorLocation(Location);
}