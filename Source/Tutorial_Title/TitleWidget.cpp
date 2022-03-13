// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

void UTitleWidget::NativeConstruct()
{
	if (StartGameBtn)
	{
		StartGameBtn->OnClicked.AddDynamic(this, &UTitleWidget::StartGame);
	}
	if (QuitGameBtn)
	{
		QuitGameBtn->OnClicked.AddDynamic(this, &UTitleWidget::QuitGame);
	}

	World = GetWorld();
	PC = World->GetFirstPlayerController();
}

void UTitleWidget::StartGame()
{
	UGameplayStatics::OpenLevel(this, FName(TEXT("ThirdPersonExampleMap")));
	RemoveFromParent();
}

void UTitleWidget::QuitGame()
{
	PC->ConsoleCommand("quit");
}