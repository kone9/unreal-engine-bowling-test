// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn_Bola.h"
#include "Components/StaticMeshComponent.h"
#include <Engine/World.h>

// Sets default values
APawn_Bola::APawn_Bola()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	bola = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("bola"));
	bola->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	bola->SetupAttachment(RootComponent);//sino agregas esto no vas a ver las propiedades de transform position scale



}

// Called when the game starts or when spawned
void APawn_Bola::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawn_Bola::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (arroje_bola == true) return;
}

// Called to bind functionality to input
void APawn_Bola::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	PlayerInputComponent->BindAction("tirar_bola", IE_Pressed, this, &APawn_Bola::arrojar_bola);
	PlayerInputComponent->BindAxis("press_izqeruida", this, &APawn_Bola::mover_izquierda);
	PlayerInputComponent->BindAxis("press_derecha", this, &APawn_Bola::mover_derecha);
}

void APawn_Bola::mover_izquierda(float value)
{
	if (arroje_bola == true) return;
	if (GetWorld() == nullptr) return;
	desplazar_bola = value;

	FVector new_location{ GetActorLocation() };
	new_location.X -= desplazar_bola * fuerza_movimiento * GetWorld()->GetDeltaSeconds();

	SetActorLocation(new_location);

	const float float_to_print = desplazar_bola;
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Yellow, FString::Printf(TEXT("izquierda: %f"), float_to_print));
}

void APawn_Bola::mover_derecha(float value)
{
	if (arroje_bola == true) return;
	if (GetWorld() == nullptr) return;

	desplazar_bola = value;

	FVector new_location{ GetActorLocation() };
	new_location.X += desplazar_bola * fuerza_movimiento * GetWorld()->GetDeltaSeconds();

	SetActorLocation(new_location);

	const float float_to_print = desplazar_bola;
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Yellow, FString::Printf(TEXT("izquierda: %f"), float_to_print));
}

void APawn_Bola::arrojar_bola()
{
	if (bola == nullptr) return;
	bola->SetSimulatePhysics(true);

	FVector fuerza = FVector::ZeroVector;
	fuerza.Y = fuerza_impulso;
	bola->AddImpulse(fuerza,NAME_None,true);
}

