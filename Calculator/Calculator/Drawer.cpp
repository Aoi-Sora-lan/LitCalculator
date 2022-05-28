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
	Funcs[0] = "加法";
	Funcs[1] = "减法";
	Funcs[2] = "乘法";
	Funcs[3] = "除法";
	Funcs[4] = "判断数字位数";
	Funcs[5] = "计算圆面积";
	Funcs[6] = "判断闰年";
	Funcs[7] = "成绩转换";
	Funcs[8] = "计算从1到输入数之间的奇数和 (for)";
	Funcs[9] = "计算从1到输入数之间的偶数和 (while)";
	Funcs[10] = "输出从1到输入数之间所有3的倍数 (do-while)";
	Funcs[11] = "求即被3整除又被5整除的数";
	Funcs[12] = "求水仙花数";
	Funcs[13] = "求最大值";
	Funcs[14] = "求最大最小值";
	Funcs[15] = "冒泡排序";
	Funcs[16] = "矩阵转置";
	Funcs[17] = "求对角线和";
	Funcs[18] = "统计单词个数";
	Funcs[19] = "静态创建链表";
	Funcs[20] = "动态创建链表";
	Funcs[21] = "学生成绩排序";
	Funcs[22] = "学生成绩普涨10分";
	Funcs[23] = "退出";
}
void MenuDraw::MenuSystem(int lineLength)
{
	LoadFunction();
	MenuSetLine(lineLength, false);
	Draws(lineLength);
	SetPreContent(lineLength, "小小计算器");
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