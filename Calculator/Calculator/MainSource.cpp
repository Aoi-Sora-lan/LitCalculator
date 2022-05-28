#include<iostream>
#include"StrategyPattern.h"
#include"Manager.h"
#include"Toolkit.h"
#include"Drawer.h"
#include"Inputer.h"
#include<windows.h>
using namespace std;

int main()
{
	int n;
	Manager manager;
	UIDraw* Drawer = new MenuDraw();
	Drawer->Draw(60);
	while (1)
	{
		cin >> n;
		if (n == 24) break;
		manager.DealStrategy(n-1);
		system("pause");
		system("CLS");
		Drawer->Draw(60);
	}
}