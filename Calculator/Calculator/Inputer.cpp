#include "Inputer.h"
#include <string>
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
	else
	{
		string str;
		UniData data{};
		cin.ignore();
		getline(cin, str);
		int len = str.length();
		for (int i = 0; i < len; i++)
		{
			data.Characters[i] = str[i];
		}
		inputerRam[0] = Toolkit::GenPack(data, TypeOfData::Characters);
	}
	return inputerRam;
}

DataPack* Inputer::InputPack(InputInfo info)
{
	return InputPack(info.length, info.type);
}
