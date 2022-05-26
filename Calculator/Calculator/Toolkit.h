#pragma once
using namespace std;
enum class CalculateType
{
	Addition,
	Subtraction,
	Multiplication,
	Division,
	GetDigits,
	GetRound,
	JudgeYear,
	ScoreTrans,
	OddAddition,
	EvenAddition,
	TriCount,
	Mod15Is0,
	WaterFlower,
	GetMax,
	GetMaxMin,
	BubbleSort,
	MatrixTrans,
	MatrixAdd,
	WordCount,
	StaticChain,
	DynamicChain,
	StudentSort,
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
};

