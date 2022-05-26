#pragma once
using namespace std;

enum class CalculateType
{
	/// <summary>
	/// 
	/// </summary>
	Addition,
	Subtraction,
	Multiplication,
	Division,
	GetDigits,
	GetRound,
	JudgeYear,
	ScoreTrans,
	/// <summary>
	/// 从键盘上输入一个正整数，输出1到该数之间所有奇数和。要求用for循环语句实现。
	/// </summary>
	OddAddition,
	/// <summary>
	/// 从键盘上输入一个正整数，输出1到该数之间所有偶数和。要求用while语句实现。
	/// </summary>
	EvenAddition,
	/// <summary>
	/// 从键盘上输入一个正整数，输出1到该数之间所有3的倍数。要求用do-while实现。
	/// </summary>
	TriCount,
	/// <summary>
	/// 从键盘上输入两个数，输出两个数之间第一个即被3整除又被5整除的数。
	/// </summary>
	Mod15Is0,
	/// <summary>
	/// 输出所有水仙花数。水仙花数是一个3位数，各位数字的立方之和等于他本身，例如：153= 1^3+5^3+3^3。
	/// </summary>
	WaterFlower,
	/// <summary>
	/// 编写一个带两个参数的函数，该函数返回这两个参数的最大值。输入两个整数，输出他们的最大值。
	/// </summary>
	GetMax,
	/// <summary>
	/// 编写一个带两个参数的函数，该函数能求出这两个数的最大值和最小值，使得第一个参数存放最大值，第二个参数存放最小值。要求练习传递地址的参数。
	/// </summary>
	GetMaxMin,
	/// <summary>
	///   从键盘上输入10个数，进行冒泡排序，输出排序结果。
	/// </summary>
	BubbleSort,
	/// <summary>
	/// 从键盘输入一个3X4的整数矩阵，进行转置操作，并将转置结果在屏幕上输出；
	/// </summary>
	MatrixTrans,
	/// <summary>
	/// 从键盘输入一个3*3整数矩阵，求主对角线元素和；
	/// </summary>
	MatrixAdd,
	/// <summary>
	/// 从键盘输入一行字符，单词之间用空格分隔开，统计其中有多少个单词， 并输出结果。
	/// </summary>
	WordCount,
	/// <summary>
	/// 静态创建一个包含有4个节点的单链表，输出这个链表的所有数据。节点包含两个域：数据域（int型），指针域。
	/// </summary>
	StaticChain,
	/// <summary>
	/// 动态创建一个链表，依次从键盘上输入正整数，将输入的整数插入到该链表中，直到输入一个负数为止。最后将该链表中的数据在屏幕上输出。
	/// </summary>
	DynamicChain,
	/// <summary>
	///   定义学生结构体数组，长度为10，依次输入这十个学生的学号、姓名、成绩，利用冒泡排序，对这10个学生排序，从小到大输出这10个学生的信息，然后输出10个学生的总成绩和平时成绩
	/// </summary>
	StudentSort,
	/// <summary>
	/// d盘根目录下存在一个文本文件my.txt，里面存放了10个学生的成绩，一行一个成绩，从文件中读取学生的成绩，每个成绩都加10分后，保存到原文件中。
	/// </summary>
	StudentUp
};
union UniData
{
	int Integer;
	char Characters[50];
	double Double;
	int Error;
	bool Boolean;
};
enum class TypeOfData
{
	Integer,
	Characters,
	Double,
	ERROR,
	Boolean
};
static class ErrorType
{
public:
	 const static int NULLERROR = 0;
	 const static int TOMUCHINPUT = 1;
	 const static int NOTPOSTIVE = 2;
	 const static int MATHERROR = 3;
	 const static int UNMEANINGFUL = 4;
};
typedef struct
{
	UniData Data;
	TypeOfData Type;
}DataPack;
static class Toolkit
{
public:
	static DataPack GenPack(UniData,TypeOfData);
	static bool SetMaxmin(int*, int*);
};

