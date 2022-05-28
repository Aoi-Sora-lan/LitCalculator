#include "Drawer.h"
#include<iostream>
#include<cstring>
#include<string>
#include<string.h>
void UIDraw::Draws(int Length)
{
	preOut[Length] = '\0';
	preOut[Length + 1] = '\0';
	for (int i = 0; i < Length; i++)
	{
		cout << preOut[i];
	}
	cout << endl;
}
void UIDraw::PreOutStart(int lineLength)
{
	for (int i = 0; i <= lineLength; i++)
	{
		preOut += '\0';
	}
}
void MenuDraw::Draw(int Length)
{
	PreOutStart(Length);
	MenuSystem(Length);
}
void MenuDraw::LoadFunction()
{
	Funcs[0] = "�ӷ�";
	Funcs[1] = "����";
	Funcs[2] = "�˷�";
	Funcs[3] = "����";
	Funcs[4] = "�ж�����λ��";
	Funcs[5] = "����Բ���";
	Funcs[6] = "�ж�����";
	Funcs[7] = "�ɼ�ת��";
	Funcs[8] = "�����1��������֮��������� (for)";
	Funcs[9] = "�����1��������֮���ż���� (while)";
	Funcs[10] = "�����1��������֮������3�ı��� (do-while)";
	Funcs[11] = "�󼴱�3�����ֱ�5��������";
	Funcs[12] = "��ˮ�ɻ���";
	Funcs[13] = "�����ֵ";
	Funcs[14] = "�������Сֵ";
	Funcs[15] = "ð������";
	Funcs[16] = "����ת��";
	Funcs[17] = "��Խ��ߺ�";
	Funcs[18] = "ͳ�Ƶ��ʸ���";
	Funcs[19] = "��̬��������";
	Funcs[20] = "��̬��������";
	Funcs[21] = "ѧ���ɼ�����";
	Funcs[22] = "ѧ���ɼ�����10��";
	Funcs[23] = "�˳�";
}
void MenuDraw::MenuSystem(int lineLength)
{
	LoadFunction();
	MenuSetLine(lineLength, false);
	Draws(lineLength);
	SetPreContent(lineLength, "СС������");
	Draws(lineLength);
	for (int i = 0; i < FUNC_NUM; i++)
	{
		MenuSetPreContent(lineLength, i + 1, Funcs[i]);
		Draws(lineLength);
	}
	MenuSetLine(lineLength, false);
	Draws(lineLength);
}
void MenuDraw::MenuSetLine(int lineLength, bool isSpace)
{
	for (int i = 0; i < lineLength; i++)
	{
		if (i == 0 || i == lineLength - 1) preOut[i] = '*';
		else
		{
			if (!isSpace) preOut[i] = '*';
			else preOut[i] = ' ';
		}
	}
}
void MenuDraw::MenuSetPreContent(int lineLength, int num, string Func)
{
	MenuSetLine(lineLength, true);
	string temp;
	int startNum;
	startNum = CalCenter(lineLength, CalTextLong(num, Func));
	temp = to_string(num) + " " + Func;
	preOut.replace(startNum + 1, temp.length(), temp);
}

void MenuDraw::SetPreContent(int lineLength, string strings)
{
	MenuSetLine(lineLength, true);
	int startNum;
	startNum = CalCenter(lineLength, strings.length());
	preOut.replace(startNum + 1, strings.length(), strings);
}

int MenuDraw::CalTextLong(int num, string Func)
{
	int numLength = 0;
	while (num > 0)
	{
		numLength++;
		num /= 10;
	}
	int stringLength = Func.length();
	return numLength + stringLength + 1;
}
int MenuDraw::CalCenter(int fullLength, int textLength)
{
	int start;
	start = (fullLength - textLength - 2) / 2;
	return start;
}