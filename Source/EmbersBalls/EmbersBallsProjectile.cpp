// Copyright Epic Games, Inc. All Rights Reserved.

#include "EmbersBallsProjectile.h"

#include "EmbersBallsCharacter.h"
#include "EmbersBallsGamestate.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerState.h"
#include "Kismet/GameplayStatics.h"

AEmbersBallsProjectile::AEmbersBallsProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AEmbersBallsProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;
}

void AEmbersBallsProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		//Destroy();
	}
}

void AEmbersBallsProjectile::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AEmbersBallsGamestate* GameState = Cast<AEmbersBallsGamestate>(UGameplayStatics::GetGameState(this));

	LookRatio = 0;
	for (const auto& Player : GameState->GetPlayerList())
	{
		FVector BallToPlayer = (GetActorLocation() - Player->PlayerLookTransform.GetLocation());
		BallToPlayer.Normalize();

		float AngleRadian = FMath::Acos(Player->PlayerLookTransform.Rotator().Vector().Dot(BallToPlayer));

		constexpr float MaxAngleRadian = 30 * 0.0174533f; /* 30° * angle to radian constant */

		LookRatio += FMath::Pow(1 - FMath::Clamp(AngleRadian / MaxAngleRadian, 0, 1), 1 / LookSharpness) / GameState->GetPlayerList().Num();
	}
}
