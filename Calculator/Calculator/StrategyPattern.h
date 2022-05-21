#pragma once
#include"Toolkit.h"
#include"Inputer.h"
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

/// <summary>
/// ����ģ��
/// <para>~���캯���У���ʼ��������Ϣ</para>
/// </summary>
class AStrategyPattern
{
public:
	/// <summary>
	/// ��ȡ������Ϣ
	/// </summary>
	/// <returns><see cref="InputInfo"/></returns>
	InputInfo GetInputInfo();
	virtual void Calulate(DataPack*)=0;
	virtual void Show() = 0;
protected:
	DataPack* ramDataPack = new DataPack[10];
	InputInfo inputInfo;
};

/// <summary>
/// �ӷ�����
/// </summary>
class Addition : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		UniData data;
		int packInt = (datapack->Data.Integer) + ((datapack + 1)->Data.Integer);
		data.Integer = packInt;
		ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Integer);
	}
	void Show()
	{
		int num = ramDataPack[0].Data.Integer;
		printf("�ӷ������ʮ������ʽ�ǣ�%d\n�ӷ�����İ˽�����ʽ�ǣ�%o\n�ӷ������ʮ��������ʽ�ǣ�%x\n",num,num,num); 
	}
	Addition()
	{
		inputInfo = { 2,TypeOfData::Integer };
	}
};

/// <summary>
/// ��������
/// </summary>
class Subtraction : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		UniData data;
		int packInt = (datapack->Data.Integer) + ((datapack + 1)->Data.Integer);
		data.Integer = packInt;
		ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Integer);
	}
	void Show()
	{
		int num = ramDataPack[0].Data.Integer;
		printf("���������ʮ������ʽ�ǣ�%d\n��������İ˽�����ʽ�ǣ�%o\n���������ʮ��������ʽ�ǣ�%x\n", num, num, num);
	}
	Subtraction()
	{
		inputInfo = { 2,TypeOfData::Integer };
	}
};

/// <summary>
/// �˷�����
/// </summary>
class Multiplication : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		UniData data;
		double packDouble = (datapack->Data.Double) * ((datapack + 1)->Data.Double);
		data.Double = packDouble;
		ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Double);
	}
	void Show()
	{
		printf("%0.5f", ramDataPack[0].Data.Double);
	}
	Multiplication()
	{
		inputInfo = { 2,TypeOfData::Double };
	}
};

/// <summary>
/// ��������
/// </summary>
class Division : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		UniData data;
		if ((datapack + 1)->Data.Double == 0) 
		{
			data.Error = ErrorType::MATHERROR;
			ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::ERROR);
		}
		else
		{
			double packDouble = (datapack->Data.Double) / ((datapack + 1)->Data.Double);
			data.Double = packDouble;
			ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Double);
		}
	}
	void Show()
	{
		if (ramDataPack->Type == TypeOfData::ERROR)
		{
			if (ramDataPack->Data.Error == ErrorType::MATHERROR)
			{
				printf("����Ϊ0���޷����г�������");
			}
		}
		else
		{
			printf("��������ǣ�%0.6f", ramDataPack[0].Data.Double);
		}
	}
	Division()
	{
		inputInfo = { 2,TypeOfData::Double };
	}
};

/// <summary>
/// ��λ������
/// </summary>
class GetDigits : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		UniData data;
		int num = datapack->Data.Integer;
		string numstr = to_string(num);
		int length = numstr.length();
		if (num <= 0) 
		{
			data.Error = ErrorType::NOTPOSTIVE;
			ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::ERROR);
		}
		else if (length > 3)
		{
			data.Error = ErrorType::TOMUCHINPUT;
			ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::ERROR);
		}
		else
		{
			data.Integer = length;
			ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Integer);
			for (int i = 1; i < length+1; i++)
			{
				data.Integer = (int)(numstr[i-1] - '0');
				ramDataPack[i] = Toolkit::GenPack(data, TypeOfData::Integer);
			}
		}
	}
	void Show()
	{
		if(ramDataPack->Type==TypeOfData::Integer)
		{
			int length = ramDataPack[0].Data.Integer;
			string str = "����Ϊ"+to_string(length)+"λ��";
			for (int i = 0; i < length; i++)
			{
				str += "��";
				if (i == length-3) { str += "��"; }
				if (i == length-2) { str += "ʮ"; }
				if (i == length-1) { str += "��"; }
				str += "λ��"+to_string(ramDataPack[i+1].Data.Integer);
			}
			cout << str;
		}
		else if(ramDataPack->Type==TypeOfData::ERROR)
		{
			if (ramDataPack->Data.Error == ErrorType::TOMUCHINPUT)
			{
				printf("Ҫ���������Ϊ3λ���ڵ�������");
			}
			else if (ramDataPack->Data.Error == ErrorType::NOTPOSTIVE)
			{
				printf("Ҫ���������Ϊ����");
			}
		}
	}
	GetDigits()
	{
		inputInfo = { 1,TypeOfData::Integer };
	}
};
/// <summary>
/// ��Բ�������
/// </summary>
class GetRound : public AStrategyPattern
{
private:
	const double PI = 3.14;
public:
	void Calulate(DataPack* datapack)
	{
		UniData data;
		double packDouble = pow((datapack->Data.Double),2)*PI;
		data.Double = packDouble;
		ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Double);
	}
	void Show()
	{
		double num = ramDataPack[0].Data.Double;
		printf("��Բ�����%0.6f\n��Բ���������λС���Ľ����%0.2f", num,num);
	}
	GetRound()
	{
		inputInfo = { 1,TypeOfData::Double };
	}
};