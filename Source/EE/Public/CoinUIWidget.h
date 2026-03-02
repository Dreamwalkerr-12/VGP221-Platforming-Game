#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CoinUIWidget.generated.h"

class UTextBlock;

UCLASS()
class YOURGAME_API UCoinUIWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void UpdateCoinText(int32 NewCoinCount);

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* CoinText;
};