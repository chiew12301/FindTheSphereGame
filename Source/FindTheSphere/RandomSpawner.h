// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomSpawner.generated.h"

UCLASS()
class FINDTHESPHERE_API ARandomSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARandomSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void StartGame();

	void OnCompletedSpawn();

public:	

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AActor> CubeClass;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AActor> SphereClass;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	int32 NumberOfCubes;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	FVector SpawnArea;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
