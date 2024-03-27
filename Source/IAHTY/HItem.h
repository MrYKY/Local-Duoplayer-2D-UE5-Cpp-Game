// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HItem.generated.h"

UENUM()
enum class ERarity : uint8
{
	Common,
	Uncommon,
	Rare,
	Epic,
	Legendary
};

USTRUCT(BlueprintType)
struct FHItemInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	FText ClerkRecommendation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	int32 Price;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	int32 STHappinessIncrease;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	int32 DecreaseRoundNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	ERarity ItemRarity;
};


/**
 * 
 */
UCLASS()
class IAHTY_API AHItem : public AActor
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item Info")
	FHItemInfo ItemBaseInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item Info")
	TArray<int32> HappinessStack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item Info")
	TSubclassOf<UDataTable> ItemDataTableClass;

	UFUNCTION(BlueprintCallable)
	void InitializeItem(FName ItemId);

protected:
	void CalculateHappinessStack();
	
	
};