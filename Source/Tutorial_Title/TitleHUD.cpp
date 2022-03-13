// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleHUD.h"
#include "Blueprint/UserWidget.h"

ATitleHUD::ATitleHUD()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> TitleHUDObj(TEXT("/Game/Blueprints/BP_TitleWidget"));
	TitleHUDWidgetClass = TitleHUDObj.Class;
}

void ATitleHUD::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	APlayerController* PC = World->GetFirstPlayerController();
	PC->bShowMouseCursor = true;

	if (TitleHUDWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), TitleHUDWidgetClass);
		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}
}