// Fill out your copyright notice in the Description page of Project Settings.
#include "RandomSpawner.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

// Sets default values
ARandomSpawner::ARandomSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARandomSpawner::BeginPlay()
{
	Super::BeginPlay();
	StartGame();
}

// Called every frame
void ARandomSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARandomSpawner::StartGame()
{
	FVector SpawnerLocation = GetActorLocation();

	for (int32 i = 0; i < NumberOfCubes; ++i)
	{
		FVector location = SpawnerLocation + FVector(
			FMath::FRandRange(-SpawnArea.X, SpawnArea.X),
			FMath::FRandRange(-SpawnArea.Y, SpawnArea.Y),
			SpawnArea.Z
		);
		GetWorld()->SpawnActor<AActor>(CubeClass, location, FRotator::ZeroRotator);
	}

	FVector SphereLocation = SpawnerLocation + FVector(
		FMath::FRandRange(-SpawnArea.X, SpawnArea.X),
		FMath::FRandRange(-SpawnArea.Y, SpawnArea.Y),
		SpawnArea.Z
	);
	GetWorld()->SpawnActor<AActor>(SphereClass, SphereLocation, FRotator::ZeroRotator);

	OnCompletedSpawn();
}

void ARandomSpawner::OnCompletedSpawn()
{

}