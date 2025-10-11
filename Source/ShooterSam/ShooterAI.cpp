// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAI.h"

#include "Kismet/GameplayStatics.h"

void AShooterAI::BeginPlay()
{
	Super::BeginPlay();
}

void AShooterAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// if (class APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
	// {
	// 	if (LineOfSightTo(PlayerPawn))
	// 	{
	// 		SetFocus(PlayerPawn);
	// 		MoveToActor(PlayerPawn, 200.0f);
	// 	}
	// 	else
	// 	{
	// 		ClearFocus(EAIFocusPriority::Gameplay);
	// 		StopMovement();
	// 	}
	// }
}

// ReSharper disable once CppMemberFunctionMayBeConst
void AShooterAI::StartBehaviorTree(AShooterSamCharacter* Player)
{
	if (EnemyAIBehaviorTree)
	{
		MyCharacter = Cast<AShooterSamCharacter>(GetPawn());
		
		if (Player)
		{
			PlayerCharacter = Player;
		}
		
		RunBehaviorTree(EnemyAIBehaviorTree);
	}	
}
