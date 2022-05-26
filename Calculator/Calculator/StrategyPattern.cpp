#include "StrategyPattern.h"

InputInfo AStrategyPattern::GetInputInfo()
{
	return inputInfo;
}

void AStrategyPattern::QuickDeal()
{
	Inputer inputer;
	DataPack* b;
	b = inputer.InputPack(this->GetInputInfo());
	this->Calulate(b);
	this->Show();
}
