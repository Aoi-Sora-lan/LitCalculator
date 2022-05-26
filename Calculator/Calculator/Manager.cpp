#include "Manager.h"

void Manager::DealStrategy(CalculateType kind)
{
	switch (kind)
	{
	case CalculateType::Addition: {
		strategy = new Addition();
		break;
	}
	case CalculateType::Subtraction: {
		strategy = new Subtraction();
		break;
	}
	case CalculateType::Multiplication: {
		strategy = new Multiplication();
		break;
	}
	case CalculateType::Division: {
		strategy = new Division();
		break;
	}
	case CalculateType::GetDigits: {
		strategy = new GetDigits();
		break;
	}
	case CalculateType::GetRound: {
		strategy = new GetRound();
		break;
	}
	case CalculateType::JudgeYear: {
		strategy = new JudgeYear();
		break;
	}
	case CalculateType::ScoreTrans: {
		strategy = new ScoreTrans();
		break;
	}
	default:
		break;
	}
	strategy->QuickDeal();
	delete strategy;
}

void Manager::DealStrategy(int num)
{
	DealStrategy((CalculateType)num);
}
