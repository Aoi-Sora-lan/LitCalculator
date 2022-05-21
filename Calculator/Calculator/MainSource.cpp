#include<iostream>
#include"StrategyPattern.h"
#include"Toolkit.h"
#include"Inputer.h"
using namespace std;
int main()
{
	Inputer inputer;
	Addition a;
	DataPack* b;
	b=inputer.InputPack(2, TypeOfData::Integer);
	a.Calulate(b);
	a.Show();
}