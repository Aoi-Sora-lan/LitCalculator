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
	case CalculateType::OddAddition: {
		strategy = new OddAddition();
		break;
	}
	case CalculateType::EvenAddition: {
		strategy = new EvenAddition();
		break;
	}
	case CalculateType::TriCount: {
		strategy = new TriCount();
		break;
	}
	case CalculateType::Mod15Is0: {
		strategy = new Mod15Is0();
		break;
	}
	case CalculateType::WaterFlower: {
		strategy = new WaterFlower();
		break;
	}
	case CalculateType::GetMax: {
		strategy = new GetMax();
		break;
	}
	case CalculateType::GetMaxMin: {
		strategy = new GetMaxMin();
		break;
	}
	case CalculateType::BubbleSort: {
		strategy = new BubbleSort();
		break;
	}
	case CalculateType::MatrixTrans: {
		strategy = new MatrixTrans();
		break;
	}
	case CalculateType::MatrixAdd: {
		strategy = new MatrixAdd();
		break;
	}
	case CalculateType::WordCount: {
		strategy = new WordCount();
		break;
	}
	case CalculateType::StaticChain: {
		strategy = new TriCount();
		break;
	}
	case CalculateType::DynamicChain: {
		strategy = new TriCount();
		break;
	}
	case CalculateType::StudentSort: {
		strategy = new TriCount();
		break;
	}
	case CalculateType::StudentUp: {
		strategy = new TriCount();
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
