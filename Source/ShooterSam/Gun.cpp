// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

// Sets default values
AGun::AGun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ScentRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	SetRootComponent(ScentRoot);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(ScentRoot);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// ReSharper disable once CppMemberFunctionMayBeConst
void AGun::PullTrigger()
{
	// UE_LOG(LogTemp, Warning, TEXT("Bang!"));
	if (OwnerController)
	{
		FVector ViewPointLocation;
		FRotator ViewPointRotation;
		OwnerController->GetPlayerViewPoint(ViewPointLocation, ViewPointRotation);

		// DrawDebugCamera(GetWorld(), ViewPointLocation, ViewPointRotation,
		// 	90.0f, 2.0f, FColor::Red, true);

		FVector EndLocation = ViewPointLocation + ViewPointRotation.Vector() * MaxRange;
		FHitResult HitResult;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);
		Params.AddIgnoredActor(GetOwner());
		bool IsHit = GetWorld()->LineTraceSingleByChannel(HitResult,
			ViewPointLocation, EndLocation, ECC_GameTraceChannel2, Params);
		if (IsHit)
		{
			DrawDebugSphere(GetWorld(), HitResult.ImpactPoint,
				5.0f, 16, FColor::Red, true);
		}
	}
}
