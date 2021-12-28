// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyBoat.generated.h"

UCLASS()
class UNREALPROJECT_API AMyBoat : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyBoat();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boat Speed");
	float RotationSpeed; //ȸ���Ҷ��� �ӵ�

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator RotationRate; //ī�޶� ȸ���ϰ� �ִ� ����

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator InitialRotation; //ó�� ������ ȸ������

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bTrue; //MoveForwar�� �ش��ϴ� Ű���� �Է��� ������ true

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int isForward; 

	FRotator NowLocation; //������ ������ġ�� ������ ������ ����
	FRotator LaterLocation; // ������ ���� ��ġ�� ������ ������ ����

	UPROPERTY(EditAnywhere)
	class UCameraComponent* FrontCamera;  //ī�޶� ������Ʈ ����

	//UPROPERTY(EditAnywhere)
	//class UCameraComponent* RightCamera;

	//UPROPERTY(EditAnywhere)
	//class UCameraComponent* LeftCamera;
	
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class USpringArmComponent* FrontSpringArm; //ī�޶� ������ �������� ����

	//UPROPERTY(VisibleAnywhere, Category = "Mesh")
	//class USpringArmComponent* RightSpringArm;

	//UPROPERTY(VisibleAnywhere, Category = "Mesh")
	//class USpringArmComponent* LeftSpringArm;

	FVector2D MouseInput; //MouseYaw, Pitch�� ���� ���� ���� ������ ���� ����

	//FORCEINLINE USpringArmComponent* GetSpringArmComponent()
	//{
	//	return FrontSpringArm; 
	//}
	//
	//FORCEINLINE void SetSpringArmComponent(USpringArmComponent* InSpringArm)
	//{ 
	//	FrontSpringArm = InSpringArm;
	//}

private:

	UFUNCTION(BlueprintCallable) //bTrue ������ ���� true�� �ٲٴ� �Լ�
	void IsTrue();

	UFUNCTION(BlueprintCallable) //bTrue ������ ���� fasle�� �ٲٴ� �Լ�
	void IsFalse();

	UFUNCTION(BlueprintCallable)
	bool bIsOne(float Value); //Value���� 1���� Ȯ���ϴ� �Լ�, 1�̸� LaterLocation �� ���� ����, �ƴϸ� NowLocation �� ����


	void MoveRight(float Value); // �¿� Ű���� �Է� �޴� �Լ�

	void MouseYaw(float axis); //���콺 �Է� �Լ� (ī�޶� ��ȯ)
	void MousePitch(float axis); //���콺 �Է� �Լ� (ī�޶� ��ȯ)

	//void RightCameraChange(float Value);
	//void LeftCameraChange(float Value);
	//void FrontCameravChange(float Value);

};
