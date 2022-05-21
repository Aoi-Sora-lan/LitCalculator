#include<iostream>
#include"StrategyPattern.h"
#include"Toolkit.h"
#include"Inputer.h"
using namespace std;
int main()
{
	Inputer inputer;
	Division a;
	DataPack* b;
	b=inputer.InputPack(a.GetInputInfo());
	a.Calulate(b);
	a.Show();
}