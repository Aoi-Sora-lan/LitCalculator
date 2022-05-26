#include "Inputer.h"
/// <summary>
/// �����
/// </summary>
/// <param name="length">���������</param>
/// <param name="type">���������</param>
/// <returns></returns>
DataPack* Inputer::InputPack(int length, TypeOfData type)
{
	if (type == TypeOfData::Integer || type == TypeOfData::Double)
	{
		if(type==TypeOfData::Integer)
		{
			int temp;
			for (int i = 0; i < length; i++)
			{
				UniData data;
				cin >> data.Integer;
				inputerRam[i] = Toolkit::GenPack(data, TypeOfData::Integer);
			}
		}
		else
		{
			double temp;
			for (int i = 0; i < length; i++)
			{
				UniData data;
				cin >> data.Double;
				inputerRam[i]=Toolkit::GenPack(data, TypeOfData::Double);
			}
		}
	}
	return inputerRam;
}

DataPack* Inputer::InputPack(InputInfo info)
{
	return InputPack(info.length, info.type);
}
