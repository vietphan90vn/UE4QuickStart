// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4QuickStart.h"
#include "FloatingActor.h"


// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ZScaleSpeed = 30.0f;
	XScaleSpeed = 30.0f;
	YScaleSpeed = 30.0f;
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime)) - FMath::Sin(RunningTime);
	NewLocation.Z += DeltaHeight * ZScaleSpeed;
	NewLocation.X += DeltaHeight * XScaleSpeed;
	NewLocation.Y += DeltaHeight * YScaleSpeed;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);
}

