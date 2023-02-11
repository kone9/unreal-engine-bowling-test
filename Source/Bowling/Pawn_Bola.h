// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Pawn_Bola.generated.h"

UCLASS()
class BOWLING_API APawn_Bola : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawn_Bola();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	void mover_izquierda(float value);
	void mover_derecha(float value);
	void arrojar_bola();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fuerza_impulso{ 1 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fuerza_movimiento{ 2 };

	float desplazar_bola{ 0 };

	bool arroje_bola{ false };

public:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root {nullptr};
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* bola{ nullptr };



};
