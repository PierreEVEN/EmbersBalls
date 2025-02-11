// Fill out your copyright notice in the Description page of Project Settings.


#include "EmbersBallsGamestate.h"

#include "EmbersBallsCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Net/UnrealNetwork.h"

AEmbersBallsGamestate::AEmbersBallsGamestate()
{
	AvailableNames = {FName("B1"), FName("B2"), FName("B3"), FName("B4")};
}

void AEmbersBallsGamestate::register_player(AEmbersBallsCharacter* NewPlayer)
{
	if (NewPlayer->HasAuthority() && !PlayerList.Contains(NewPlayer)) {
		PlayerList.Add(NewPlayer);

		for (const auto& BallIndex : AvailableNames)
		{
			NewPlayer->BallIndex = BallIndex.ToString();
			AvailableNames.Remove(BallIndex);
			break;
		}
	}
}

void AEmbersBallsGamestate::unregister_player(AEmbersBallsCharacter* OldPlayer)
{
	if (OldPlayer->HasAuthority() && PlayerList.Contains(OldPlayer)) {
		PlayerList.Remove(OldPlayer);
		AvailableNames.Add(FName(OldPlayer->BallIndex));
	}
}

void AEmbersBallsGamestate::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AEmbersBallsGamestate, PlayerList);
}
