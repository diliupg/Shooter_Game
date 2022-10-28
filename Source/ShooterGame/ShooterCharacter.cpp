 // Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"

// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

//void AShooterCharacter::AddMovementInput( FVector WorldDirection, float ScaleValue, bool bForce )
//{
//
//}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis( TEXT( "MoveForward" ), this, &AShooterCharacter::MoveForward );
	PlayerInputComponent->BindAxis( TEXT( "MoveRight" ), this, &AShooterCharacter::MoveRight );
	PlayerInputComponent->BindAxis( TEXT( "Lookup" ), this, &AShooterCharacter::LookUp );
}

void AShooterCharacter::MoveForward( float MoveValue )
{
	UE_LOG( LogTemp, Warning, TEXT( "Move Forward-Backward: %f" ), MoveValue );
	AddMovementInput( GetActorForwardVector( ), MoveValue, IsMoveInputIgnored( ) );
}

void AShooterCharacter::MoveRight( float MoveValue )
{
	UE_LOG( LogTemp, Warning, TEXT( "Move Left-Right: %f" ), MoveValue );
	AddMovementInput( GetActorRightVector( ), MoveValue, IsMoveInputIgnored( ) );
}

void AShooterCharacter::LookUp( float MoveValue )
{
	UE_LOG( LogTemp, Warning, TEXT( "Look Up-Down: %f" ), MoveValue );
	AddControllerPitchInput( MoveValue );
}

