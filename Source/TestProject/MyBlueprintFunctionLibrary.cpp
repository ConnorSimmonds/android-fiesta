// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

void UMyBlueprintFunctionLibrary::SpinActor(AActor *ac, float DeltaTime, float RunningTime)
{
	FVector NewLocation = ac->GetActorLocation();
	FRotator NewRotation = ac->GetActorRotation();

	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));

	NewLocation.Z += DeltaHeight * 20.0f;
	float DeltaRotation = DeltaTime * 20.0f;
	NewRotation.Yaw += DeltaRotation;

	ac->SetActorLocationAndRotation(NewLocation, NewRotation);
}
