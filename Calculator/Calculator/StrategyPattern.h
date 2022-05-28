#pragma once
#include"Toolkit.h"
#include"Inputer.h"
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<iomanip>
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
	DataPack* ramDataPack = new DataPack[25565];
	InputInfo inputInfo = { 0};
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

/// <summary>
/// 计算奇数和策略
/// </summary>
class OddAddition : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		UniData data;
		int end = datapack->Data.Integer;
		int sum = 0;
		for (int i = 1; i <= end; i++)
		{
			if (i % 2 == 1) sum += i;
		}
		int packInt = sum;
		data.Integer = packInt;
		ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Integer);
	}
	void Show()
	{
		int num = ramDataPack[0].Data.Integer;
		printf("1到该数之间所有奇数和为%d\n",num);
	}
	OddAddition()
	{
		inputInfo = { 1,TypeOfData::Integer };
	}
};

/// <summary>
/// 计算偶数和策略
/// </summary>
class EvenAddition : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		UniData data;
		int end = datapack->Data.Integer;
		int i=0,sum = 0;
		while(++i<=end)
		{
			if (i % 2 == 0) sum += i;
		}
		int packInt = sum;
		data.Integer = packInt;
		ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Integer);
	}
	void Show()
	{
		int num = ramDataPack[0].Data.Integer;
		printf("1到该数之间所有偶数和为%d\n", num);
	}
	EvenAddition()
	{
		inputInfo = { 1,TypeOfData::Integer };
	}
};

/// <summary>
/// 计算偶数和策略
/// </summary>
class TriCount : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		UniData data;
		int cnt = 1;
		int end = datapack->Data.Integer;
		int i = 1;
		do
		{
			if (i % 3 == 0)
			{
				data.Integer = i;
				ramDataPack[cnt++] = Toolkit::GenPack(data, TypeOfData::Integer);
			}
			i++;
		} while (i <= end);
		data.Integer = cnt-1;
		ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Integer);
		
	}
	void Show()
	{
		int cnt = ramDataPack[0].Data.Integer;
		if (cnt > 0)
		{
			printf("1到输入数之间所有3的倍数有：");
			for (int i = 0; i < cnt; i++)
			{
				cout << ramDataPack[i + 1].Data.Integer << " ";
			}
			cout << endl;
		}
		else
		{
			printf("1到输入数之间没有3的倍数\n");
		}
	}
	TriCount()
	{
		inputInfo = { 1,TypeOfData::Integer };
	}
};

/// <summary>
/// 计算Mod15策略
/// </summary>
class Mod15Is0 : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		UniData data;
		data.Integer = 1;
		int start = datapack[0].Data.Integer;
		int end = datapack[1].Data.Integer;
		for (int i = start; i <= end; i++)
		{
			if (i % 15 == 0)
			{
				data.Integer = i; break;
			}
		}
		ramDataPack[0]=Toolkit::GenPack(data,TypeOfData::Integer);
	}
	void Show()
	{
		if (ramDataPack->Data.Integer == 1) cout << "两个数之间没有既被3整除又被5整除的数";
		else cout << "两个数之间第一个既被3整除又被5整除的数是：" << ramDataPack->Data.Integer;
		cout << endl;
	}
	Mod15Is0()
	{
		inputInfo = { 2,TypeOfData::Integer };
	}
};

/// <summary>
/// 计算水仙花策略
/// </summary>
class WaterFlower : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		UniData data;
		data.Error = ErrorType::NULLERROR;
		int cnt = 1,jg;
		for (int i = 100; i < 1000; i++)
		{
			string numstr = to_string(i);
			jg = (int)pow(numstr[0] - '0', 3) + (int)pow(numstr[1] - '0', 3) + (int)pow(numstr[2] - '0', 3);
			if (i == jg)
			{
				data.Integer = i;
				ramDataPack[cnt++]=Toolkit::GenPack(data,TypeOfData::Integer);
			}
		}
		data.Integer = cnt;
		ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Integer);
	}
	void Show()
	{
		int cnt = ramDataPack[0].Data.Integer - 1;
		if (cnt > 0)
		{
			printf("水仙花数有：");
			for (int i = 0; i < cnt; i++)
			{
				cout << ramDataPack[i + 1].Data.Integer << " ";
			}
		}
		cout << endl;
	}
	WaterFlower()
	{
		inputInfo = { 0,TypeOfData::Integer };
	}
};

/// <summary>
/// 计算最大值策略
/// </summary>
class GetMax : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		UniData data;
		if (datapack[0].Data.Integer == datapack[1].Data.Integer)
		{
			data.Boolean = false;
			ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Boolean);
		}
		else
		{
			data.Boolean = true;
			ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Boolean);
			if (datapack[0].Data.Integer > datapack[1].Data.Integer) data.Integer = datapack[0].Data.Integer;
			else data.Integer = datapack[1].Data.Integer;
			ramDataPack[1] = Toolkit::GenPack(data, TypeOfData::Integer);
		}
		
	}
	void Show()
	{
		if (ramDataPack[0].Data.Boolean)
		{
			cout<<"两个数较大的是"<<ramDataPack[1].Data.Integer<<endl;
		}
		else 
		{
			cout << "两个数相等" << endl;
		}
	}
	GetMax()
	{
		inputInfo = { 2,TypeOfData::Integer };
	}
};

/// <summary>
/// 计算最大最小值策略
/// </summary>
class GetMaxMin : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		UniData data;
		int a = datapack[0].Data.Integer;
		int b = datapack[1].Data.Integer;
		if (!Toolkit::SetMaxmin(&a, &b))
		{
			data.Boolean = false;
			ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Boolean);
		}
		else
		{
			data.Boolean = true;
			ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Boolean);
			data.Integer = a;
			ramDataPack[1] = Toolkit::GenPack(data, TypeOfData::Integer);
			data.Integer = b;
			ramDataPack[2] = Toolkit::GenPack(data, TypeOfData::Integer);
		}

	}
	void Show()
	{
		if (ramDataPack[0].Data.Boolean)
		{
			cout << "两个数较大的是" << ramDataPack[1].Data.Integer;
			cout << endl;
			cout << "两个数较小的是" << ramDataPack[2].Data.Integer;
			cout << endl;
		}
		else
		{
			cout << "两个数相等" << endl;
		}
	}
	GetMaxMin()
	{
		inputInfo = { 2,TypeOfData::Integer };
	}
};

/// <summary>
/// 冒泡排序策略
/// </summary>
class BubbleSort : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		UniData data;
		int nums[10],temp;
		for (int i = 0; i <10 ; i++)
		{
			nums[i] = datapack[i].Data.Integer;
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = i + 1; j < 10; j++)
			{
				if (nums[i] < nums[j])
				{
					temp = nums[i];
					nums[i] = nums[j];
					nums[j] = temp;
				}
			}
		}
		for (int i = 0; i < 10; i++)
		{
			data.Integer = nums[i];
			ramDataPack[i] = Toolkit::GenPack(data, TypeOfData::Integer);
		}
	}
	void Show()
	{
		cout << "排序结果为：" << endl;
		for (int i = 0; i < 10; i++)
		{
			cout<<ramDataPack[i].Data.Integer << " ";
		}
		cout << endl;
	}
	BubbleSort()
	{
		inputInfo = { 10,TypeOfData::Integer };
	}
};

/// <summary>
/// 矩阵转置策略
/// </summary>
class MatrixTrans : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		UniData data;
		int nums[12],aftnums[12], cnt=0;
		for (int i = 0; i < 12; i++)
		{
			nums[i] = datapack[i].Data.Integer;
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				aftnums[cnt++] = nums[i + 3 * j];
			}
		}
		for (int i = 0; i < 12; i++)
		{
			data.Integer = aftnums[i];
			ramDataPack[i] = Toolkit::GenPack(data, TypeOfData::Integer);
		}
	}
	void Show()
	{
		cout << "转置后矩阵为：" << endl;
		for (int i = 0; i < 12; i++)
		{
			cout << ramDataPack[i].Data.Integer << " ";
			if(i%4==3) cout << endl;
		}
	}
	MatrixTrans()
	{
		inputInfo = { 12,TypeOfData::Integer };
	}
};

/// <summary>
/// 矩阵对角线求和策略
/// </summary>
class MatrixAdd : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		UniData data;
		int cnt = 0;
		for (int i = 0; i < 9; i++)
		{
			if (i % 4 == 0) cnt += datapack[i].Data.Integer;
		}
		data.Integer = cnt;
		ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Integer);
	}
	void Show()
	{
		cout << "矩阵的迹为："<<ramDataPack[0].Data.Integer << endl;
	}
	MatrixAdd()
	{
		inputInfo = { 9,TypeOfData::Integer };
	}
};

/// <summary>
/// 统计单词个数策略
/// </summary>
class WordCount : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		int cnt = 0;
		bool before = false;
		for (int i = 0; datapack[0].Data.Characters[i] != '\0'; i++)
		{
			if (!before&&datapack[0].Data.Characters[i] != ' ')
			{
				cnt++;
				before = true;
			}
			if (before && datapack[0].Data.Characters[i] == ' ')
			{
				before = false;
			}
		}
		UniData data;
		data.Integer = cnt;
		ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Integer);
	}
	void Show()
	{
		cout << "单词个数为：" << ramDataPack[0].Data.Integer << endl;
	}
	WordCount()
	{
		inputInfo = { 0,TypeOfData::Characters };
	}
};

/// <summary>
/// 建立静态链表策略
/// </summary>
class StaticChain : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		Node* node = new Node[4]{1,2,3,4};
		for (int i = 0; i < 3; i++)
		{
			node[i].NextNode = node+i+1;
		}
		UniData data;
		data.Address = node;
		ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Address);
	}
	void Show()
	{
		Node* StartNode = (Node*)ramDataPack[0].Data.Address;
		Node* NextNode = StartNode;
		cout << "链表有：" << endl;
		for (int i = 0; i < 4; i++)
		{
			cout<< NextNode->Data<<" ";
			NextNode = NextNode->NextNode;
		}
		cout << endl;
	}
	StaticChain()
	{
		inputInfo = { 0,TypeOfData::Empty };
	}
};


/// <summary>
/// 建立动态链表策略
/// </summary>
class DynamicChain : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		Node* StartNode = new Node(-1);
		Node* NowNode = StartNode;
		for (int i = 0; datapack[i].Data.Integer!= -1; i++)
		{
			NowNode->NextNode = new Node(datapack[i].Data.Integer);
			NowNode = NowNode->NextNode;
		}
		UniData data;
		data.Address = StartNode;
		ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Address);
	}
	void Show()
	{
		Node* StartNode = (Node*)ramDataPack[0].Data.Address;
		Node* NextNode = StartNode->NextNode;
		cout << "链表有：" << endl;
		for (int i = 0;NextNode->Data!=-1; i++)
		{
			cout << NextNode->Data << " ";
			if (NextNode->NextNode == NULL) break;
			NextNode = NextNode->NextNode;
		}
		cout << endl;
	}
	DynamicChain()
	{
		inputInfo = { -1,TypeOfData::Integer };
	}
};


/// <summary>
/// 学生排序策略
/// </summary>
class StudentSort : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		int n = 10;
		int sum = 0;
		double avg;
		Student* students = (Student*)(datapack->Data.Address);
		Student temp;
		for (int i = 0; i < n; i++)
		{
			sum += students[i].Score;
		}
		for (int i = 0; i < n; i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(students[i].Score>students[j].Score)
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
		UniData data;
		data.Address = students;
		ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Address);
		data.Integer = sum;
		ramDataPack[1] = Toolkit::GenPack(data, TypeOfData::Integer);
		avg = (double)sum / 10.0;
		data.Double = avg;
		ramDataPack[2] = Toolkit::GenPack(data, TypeOfData::Double);
	}
	void Show()
	{
		int n = 10;
		Student* students = (Student*)(ramDataPack->Data.Address);
		int maxlenn = strlen("学生姓名");
		int maxleno = strlen("学生学号");
		int maxlens = strlen("学生分数");
		for (int i = 0; i < n; i++)
		{
			maxlenn = max(maxlenn,(int)strlen(students[i].Name));
		}
		for (int i = 0; i < n; i++)
		{
			maxleno = max(maxleno, (int)to_string(students[i].No).length());
		}
		for (int i = 0; i < n; i++)
		{
			maxlens = max(maxlens, (int)to_string(students[i].Score).length());
		}
		cout << endl;
		cout << setiosflags(ios::left);
		cout << setw((long long)maxleno + 1) << "学生学号" << "| "
			<< setw((long long)maxlenn + 1) << "学生姓名" << "| "
			<< setw((long long)maxlens + 1) << "学生分数" << endl;
		string Not="", Nat="", Sct="";
		for (int i = 0; i <= maxleno; i++) Not += "-";
		for (int i = 0; i <= maxlenn+1; i++) Nat += "-";
		for (int i = 0; i <= maxlens; i++) Sct += "-";
		cout << Not<< "+"
			<< Nat << "+"
			<< Sct << endl;
		for (int i = 0; i < n; i++)
		{
			cout <<setw((long long)maxleno+1)<< students[i].No<<"| "
				 <<setw((long long)maxlenn+1)<<students[i].Name<<"| "
				 <<setw((long long)maxlens+1)<< students[i].Score << endl;
		}
		cout << endl;
		cout << "学生总分为：" << ramDataPack[1].Data.Integer << endl;
		cout << "学生平均分为：" << ramDataPack[2].Data.Double << endl;
	}
	StudentSort()
	{
		inputInfo = { 10,TypeOfData::Address };
	}
};

/// <summary>
/// 学生分数增长策略
/// </summary>
class StudentUp : public AStrategyPattern
{
public:
	void Calulate(DataPack* datapack)
	{
		FILE* fp;
		errno_t err;
		UniData data;
		if((err=fopen_s(&fp,"d:\\my.txt", "r+")!=0))
		{
			data.Error = ErrorType::NULLERROR;
			ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::ERROR);
		}
		else
		{
			int nums[10];
			//for(int i=0;i<)
			int ram;
			for(int i=0;i<10;i++)
			{
				fscanf_s(fp, "%d", (nums+i));
				if(i!=9) ram=getc(fp);//吃掉0D0A
			}
			fseek(fp, 0, SEEK_SET);
			for (int i = 0; i < 10; i++)
			{
				nums[i] += 10;
				fprintf_s(fp, "%d\n", nums[i]);
			}
			fclose(fp);
			data.Boolean = true;
			ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Boolean);
		}
	}
	void Show()
	{
		if (ramDataPack[0].Type == TypeOfData::ERROR)
		{
			if (ramDataPack[0].Data.Error == ErrorType::NULLERROR)
			{
				cout << "未找到文件" << endl;
			}
		}
		else
		{
			if (ramDataPack->Data.Boolean)
			{
				cout << "成功！" << endl;
			}
		}
	}
	StudentUp()
	{
		inputInfo = { 0,TypeOfData::Empty };
	}
};