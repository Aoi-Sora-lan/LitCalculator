#pragma once
#include<iostream>
#include"Toolkit.h"
using namespace std;
struct InputInfo
{
	int length;
	TypeOfData type;
};
class Inputer
{
private:
	DataPack inputerRam[30];
public:
	DataPack* InputPack(int,TypeOfData);
	DataPack* InputPack(InputInfo);
};


