#include<iostream>
#include"StrategyPattern.h"
#include"Manager.h"
#include"Toolkit.h"
#include"Inputer.h"
using namespace std;

int main()
{
	int n;
	Manager manager;
	while (1)
	{
		cin >> n;
		if (n == 24) break;
		manager.DealStrategy(n);
	}
}