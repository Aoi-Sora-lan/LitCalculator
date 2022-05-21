#include "Toolkit.h"

DataPack Toolkit::GenPack(UniData data, TypeOfData type)
{
	DataPack datapack = { data,type };
	return datapack;
}
