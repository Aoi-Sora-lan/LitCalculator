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
/// 策略模板
/// <para>~构造函数中：初始化输入信息</para>
/// </summary>
class AStrategyPattern
{
public:
	/// <summary>
	/// 获取输入信息
	/// </summary>
	/// <returns><see cref="InputInfo"/></returns>
	InputInfo GetInputInfo();
	virtual void Calulate(DataPack*)=0;
	virtual void Show() = 0;
	void QuickDeal();
protected:
	DataPack* ramDataPack = new DataPack[10];
	InputInfo inputInfo;
};

/// <summary>
/// 加法策略
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
		printf("加法结果的十进制形式是：%d\n加法结果的八进制形式是：%o\n加法结果的十六进制形式是：%x\n",num,num,num); 
	}
	Addition()
	{
		inputInfo = { 2,TypeOfData::Integer };
	}
};

/// <summary>
/// 减法策略
/// </summary>
class Subtraction : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		UniData data;
		int packInt = (datapack->Data.Integer) - ((datapack + 1)->Data.Integer);
		data.Integer = packInt;
		ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Integer);
	}
	void Show()
	{
		int num = ramDataPack[0].Data.Integer;
		printf("减法结果的十进制形式是：%d\n减法结果的八进制形式是：%o\n减法结果的十六进制形式是：%x\n", num, num, num);
	}
	Subtraction()
	{
		inputInfo = { 2,TypeOfData::Integer };
	}
};

/// <summary>
/// 乘法策略
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
		printf("乘法结果的小数形式是：%0.5f\n乘法结果的指数形式是：%e\n", ramDataPack[0].Data.Double,ramDataPack[0].Data.Double);
	}
	Multiplication()
	{
		inputInfo = { 2,TypeOfData::Double };
	}
};

/// <summary>
/// 除法策略
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
				printf("除数为0，无法进行除法运算\n");
			}
		}
		else
		{
			printf("除法结果是：%0.6f\n", ramDataPack[0].Data.Double);
		}
	}
	Division()
	{
		inputInfo = { 2,TypeOfData::Double };
	}
};

/// <summary>
/// 求位数策略
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
			string str = "该数为"+to_string(length)+"位数";
			for (int i = 0; i < length; i++)
			{
				str += "，";
				if (i == length-3) { str += "百"; }
				if (i == length-2) { str += "十"; }
				if (i == length-1) { str += "个"; }
				str += "位是"+to_string(ramDataPack[i+1].Data.Integer);
			}
			cout << str<<endl;
		}
		else if(ramDataPack->Type==TypeOfData::ERROR)
		{
			if (ramDataPack->Data.Error == ErrorType::TOMUCHINPUT)
			{
				printf("要求输入的数为3位以内的正整数\n");
			}
			else if (ramDataPack->Data.Error == ErrorType::NOTPOSTIVE)
			{
				printf("要求输入的数为正数\n");
			}
		}
	}
	GetDigits()
	{
		inputInfo = { 1,TypeOfData::Integer };
	}
};
/// <summary>
/// 求圆面积策略
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
		printf("该圆面积是%0.6f\n该圆面积保留两位小数的结果是%0.2f\n", num,num);
	}
	GetRound()
	{
		inputInfo = { 1,TypeOfData::Double };
	}
};
/// <summary>
/// 判断闰年策略
/// </summary>
class JudgeYear : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		UniData data[2];
		int packInt = datapack->Data.Integer;
		bool packBool;
		data[0].Integer = packInt;
		packBool = ((packInt % 400 == 0) || (packInt % 4 == 0 && packInt % 100 != 0));
		data[1].Boolean = packBool;
		ramDataPack[0] = Toolkit::GenPack(data[0], TypeOfData::Integer);
		ramDataPack[1] = Toolkit::GenPack(data[1], TypeOfData::Boolean);
	}
	void Show()
	{
		cout<<ramDataPack[0].Data.Integer<< "年是";
		if (ramDataPack[1].Data.Boolean) cout << "闰年";
		else cout << "平年";
		cout << endl;
	}
	JudgeYear()
	{
		inputInfo = { 1,TypeOfData::Integer };
	}
};
/// <summary>
/// 成绩转换策略
/// </summary>
class ScoreTrans : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		bool isError = false;
		UniData data;
		data.Characters[0] = ' ';
		int score = datapack->Data.Integer;
		if (score<0||score > 100) 
		{
			isError = true;
			data.Error = ErrorType::UNMEANINGFUL; 
		}
		else if (score >= 90) { strcpy_s(data.Characters, "优秀"); }
		else if (score >= 80) { strcpy_s(data.Characters, "良"); }
		else if (score >= 70) { strcpy_s(data.Characters, "中"); }
		else if (score >= 60) { strcpy_s(data.Characters, "及格"); }
		else if (score >= 0) { strcpy_s(data.Characters, "不及格"); }
		if(!isError) ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Characters);
		else  ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::ERROR);
	}
	void Show()
	{
		if (ramDataPack[0].Type == TypeOfData::ERROR)
		{
			if (ramDataPack[0].Data.Error == ErrorType::UNMEANINGFUL) cout << "输入的成绩无意义"<<endl;
		}
		else
		{
			string str = ramDataPack[0].Data.Characters;
			cout << str << endl;
		}
	}
	ScoreTrans()
	{
		inputInfo = { 1,TypeOfData::Integer };
	}
};