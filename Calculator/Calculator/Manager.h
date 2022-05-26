#pragma once
#include"StrategyPattern.h"
class Manager
{
private:
	AStrategyPattern* strategy;
public:
	void DealStrategy(CalculateType);
	void DealStrategy(int);
};

