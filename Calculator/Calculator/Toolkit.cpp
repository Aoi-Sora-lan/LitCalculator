#include "Toolkit.h"

DataPack Toolkit::GenPack(UniData data, TypeOfData type)
{
	DataPack datapack = { data,type };
	return datapack;

}

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
