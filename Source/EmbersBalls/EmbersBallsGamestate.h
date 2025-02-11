// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "EmbersBallsGamestate.generated.h"

class AEmbersBallsCharacter;
/**
 * 
 */
UCLASS()
class EMBERSBALLS_API AEmbersBallsGamestate : public AGameStateBase
{
	GENERATED_BODY()

public:

	AEmbersBallsGamestate();

	UFUNCTION(BlueprintCallable)
	void register_player(AEmbersBallsCharacter* NewPlayer);

	UFUNCTION(BlueprintCallable)
	void unregister_player(AEmbersBallsCharacter* OldPlayer);


	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

	UFUNCTION(BlueprintPure)
	TArray<AEmbersBallsCharacter*> GetPlayerList() const
	{
		return PlayerList;
	}

private:

	TSet<FName> AvailableNames;

	UPROPERTY(Replicated)
	TArray<TObjectPtr<AEmbersBallsCharacter>> PlayerList;
};
