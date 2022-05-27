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
	void QuickDeal();
protected:
	DataPack* ramDataPack = new DataPack[25565];
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
		int packInt = (datapack->Data.Integer) - ((datapack + 1)->Data.Integer);
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
		printf("�˷������С����ʽ�ǣ�%0.5f\n�˷������ָ����ʽ�ǣ�%e\n", ramDataPack[0].Data.Double,ramDataPack[0].Data.Double);
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
				printf("����Ϊ0���޷����г�������\n");
			}
		}
		else
		{
			printf("��������ǣ�%0.6f\n", ramDataPack[0].Data.Double);
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
			cout << str<<endl;
		}
		else if(ramDataPack->Type==TypeOfData::ERROR)
		{
			if (ramDataPack->Data.Error == ErrorType::TOMUCHINPUT)
			{
				printf("Ҫ���������Ϊ3λ���ڵ�������\n");
			}
			else if (ramDataPack->Data.Error == ErrorType::NOTPOSTIVE)
			{
				printf("Ҫ���������Ϊ����\n");
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
		printf("��Բ�����%0.6f\n��Բ���������λС���Ľ����%0.2f\n", num,num);
	}
	GetRound()
	{
		inputInfo = { 1,TypeOfData::Double };
	}
};

/// <summary>
/// �ж��������
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
		cout<<ramDataPack[0].Data.Integer<< "����";
		if (ramDataPack[1].Data.Boolean) cout << "����";
		else cout << "ƽ��";
		cout << endl;
	}
	JudgeYear()
	{
		inputInfo = { 1,TypeOfData::Integer };
	}
};

/// <summary>
/// �ɼ�ת������
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
		else if (score >= 90) { strcpy_s(data.Characters, "����"); }
		else if (score >= 80) { strcpy_s(data.Characters, "��"); }
		else if (score >= 70) { strcpy_s(data.Characters, "��"); }
		else if (score >= 60) { strcpy_s(data.Characters, "����"); }
		else if (score >= 0) { strcpy_s(data.Characters, "������"); }
		if(!isError) ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Characters);
		else  ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::ERROR);
	}
	void Show()
	{
		if (ramDataPack[0].Type == TypeOfData::ERROR)
		{
			if (ramDataPack[0].Data.Error == ErrorType::UNMEANINGFUL) cout << "����ĳɼ�������"<<endl;
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
/// ���������Ͳ���
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
		printf("1������֮������������Ϊ%d\n",num);
	}
	OddAddition()
	{
		inputInfo = { 1,TypeOfData::Integer };
	}
};

/// <summary>
/// ����ż���Ͳ���
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
		printf("1������֮������ż����Ϊ%d\n", num);
	}
	EvenAddition()
	{
		inputInfo = { 1,TypeOfData::Integer };
	}
};

/// <summary>
/// ����ż���Ͳ���
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
			printf("1��������֮������3�ı����У�");
			for (int i = 0; i < cnt; i++)
			{
				cout << ramDataPack[i + 1].Data.Integer << " ";
			}
			cout << endl;
		}
		else
		{
			printf("1��������֮��û��3�ı���\n");
		}
	}
	TriCount()
	{
		inputInfo = { 1,TypeOfData::Integer };
	}
};

/// <summary>
/// ����Mod15����
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
		if (ramDataPack->Data.Integer == 1) cout << "������֮��û�мȱ�3�����ֱ�5��������";
		else cout << "������֮���һ���ȱ�3�����ֱ�5���������ǣ�" << ramDataPack->Data.Integer;
		cout << endl;
	}
	Mod15Is0()
	{
		inputInfo = { 2,TypeOfData::Integer };
	}
};

/// <summary>
/// ����ˮ�ɻ�����
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
			jg = pow(numstr[0] - '0', 3) + pow(numstr[1] - '0', 3) + pow(numstr[2] - '0', 3);
			if (i == jg)
			{
				data.Integer = i;
				ramDataPack[cnt++]=Toolkit::GenPack(data,TypeOfData::Integer);
			}
		}
		ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Integer);
	}
	void Show()
	{
		int cnt = ramDataPack[0].Data.Integer - 1;
		if (cnt > 0)
		{
			printf("ˮ�ɻ����У�");
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
/// �������ֵ����
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
			cout<<"�������ϴ����"<<ramDataPack[1].Data.Integer<<endl;
		}
		else 
		{
			cout << "���������" << endl;
		}
	}
	GetMax()
	{
		inputInfo = { 2,TypeOfData::Integer };
	}
};

/// <summary>
/// ���������Сֵ����
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
			cout << "�������ϴ����" << ramDataPack[1].Data.Integer;
			cout << endl;
			cout << "��������С����" << ramDataPack[2].Data.Integer;
			cout << endl;
		}
		else
		{
			cout << "���������" << endl;
		}
	}
	GetMaxMin()
	{
		inputInfo = { 2,TypeOfData::Integer };
	}
};

/// <summary>
/// ð���������
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
		cout << "������Ϊ��" << endl;
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
/// ����ת�ò���
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
		cout << "ת�ú����Ϊ��" << endl;
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
/// ����Խ�����Ͳ���
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
		cout << "����ļ�Ϊ��"<<ramDataPack[0].Data.Integer << endl;
	}
	MatrixAdd()
	{
		inputInfo = { 9,TypeOfData::Integer };
	}
};

/// <summary>
/// ͳ�Ƶ��ʸ�������
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
		cout << "���ʸ���Ϊ��" << ramDataPack[0].Data.Integer << endl;
	}
	WordCount()
	{
		inputInfo = { 0,TypeOfData::Characters };
	}
};

/// <summary>
/// ������̬�������
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
		data.StartNode = node;
		ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Addrress);
	}
	void Show()
	{
		Node* StartNode = (Node*)ramDataPack[0].Data.StartNode;
		Node* NextNode = StartNode;
		cout << "�����У�" << endl;
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
/// ������̬�������
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
		data.StartNode = StartNode;
		ramDataPack[0] = Toolkit::GenPack(data, TypeOfData::Addrress);
	}
	void Show()
	{
		Node* StartNode = (Node*)ramDataPack[0].Data.StartNode;
		Node* NextNode = StartNode->NextNode;
		cout << "�����У�" << endl;
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