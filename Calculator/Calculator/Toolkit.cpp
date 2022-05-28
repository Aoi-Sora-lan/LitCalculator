#include "Toolkit.h"

DataPack Toolkit::GenPack(UniData data, TypeOfData type)
{
	DataPack datapack = { data,type };
	return datapack;

}

const int ErrorType::NULLERROR = 0;
const int ErrorType::TOMUCHINPUT=1;
const int ErrorType::NOTPOSTIVE=2;
const int ErrorType::MATHERROR=3;
const int ErrorType::UNMEANINGFUL=4;
bool Toolkit::SetMaxmin(int* a, int* b)
{
	if (*a == *b) return false;
	int temp;
	if (*a < *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
	return true;
}
