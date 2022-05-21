#pragma once
#include<iostream>
#include"Toolkit.h"
using namespace std;
class Inputer
{
private:
	DataPack inputerRam[30];
public:
	DataPack* InputPack(int,TypeOfData);
};

