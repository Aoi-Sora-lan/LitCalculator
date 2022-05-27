#include "Inputer.h"
#include <string>
/// <summary>
/// 输入包
/// </summary>
/// <param name="length">输入包长度</param>
/// <param name="type">输入包类型</param>
/// <returns></returns>
DataPack* Inputer::InputPack(int length, TypeOfData type)
{
	if (type == TypeOfData::Integer || type == TypeOfData::Double)
	{
		if(type==TypeOfData::Integer)
		{
			if (length == -1)
			{
				int num=0,cnt=0;
				UniData data;
				while (num >= 0)
				{
					cin >> num;
					data.Integer = num;
					inputerRam[cnt++] = Toolkit::GenPack(data, TypeOfData::Integer);
				}
			}
			else
			{
				int temp;
				for (int i = 0; i < length; i++)
				{
					UniData data;
					cin >> data.Integer;
					inputerRam[i] = Toolkit::GenPack(data, TypeOfData::Integer);
				}
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
	else if(type==TypeOfData::Characters)
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
