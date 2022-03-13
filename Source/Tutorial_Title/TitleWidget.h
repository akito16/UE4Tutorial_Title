// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleWidget.generated.h"

/**
 * 
 */
UCLASS()
class TUTORIAL_TITLE_API UTitleWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativeConstruct() override;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* StartGameBtn;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* QuitGameBtn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		FName LevelName;

	UPROPERTY(EditAnywhere)
		UWorld* World;

	UPROPERTY(EditAnywhere)
		APlayerController* PC;

protected:
	UFUNCTION()
		void StartGame();

	UFUNCTION()
		void QuitGame();
};
