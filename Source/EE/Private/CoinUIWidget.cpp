#include "CoinUIWidget.h"
#include "Components/TextBlock.h"

void UCoinUIWidget::NativeConstruct()
{
	Super::NativeConstruct();
	UpdateCoinText(0);
}

void UCoinUIWidget::UpdateCoinText(int32 NewCoinCount)
{
	if (CoinText)
	{
		CoinText->SetText(FText::FromString(
			FString::Printf(TEXT("Coins: %d"), NewCoinCount)
		));
	}
}