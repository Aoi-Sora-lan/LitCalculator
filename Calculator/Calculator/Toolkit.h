#pragma once
using namespace std;
union UniData
{
	int Integer;
	char Characters[50];
	double Double;
	int Error;
};
enum class TypeOfData
{
	Integer,
	Characters,
	Double,
	ERROR
};
static class ErrorType
{
public:
	 const static int NULLERROR = 0;
	 const static int TOMUCHINPUT = 1;
	 const static int NOTPOSTIVE = 2;
	 const static int MATHERROR = 3;
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

