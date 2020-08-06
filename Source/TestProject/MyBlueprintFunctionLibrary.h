// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameFramework/Actor.h"
#include "MyBlueprintFunctionLibrary.generated.h"


/**
 * 
 */
UCLASS()
class TESTPROJECT_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static void SpinActor(AActor *ac, float DeltaTime, float RunningTime);
};
