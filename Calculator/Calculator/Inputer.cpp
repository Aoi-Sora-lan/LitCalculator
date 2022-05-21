#include "Inputer.h"

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
				cout << "-3-";
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
				cout << "o3o";
			}
		}
	}
	return inputerRam;
}
