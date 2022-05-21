#pragma once
using namespace std;
typedef union
{
	int Integer;
	char Characters[50];
	double Double;
}UniData;
enum class TypeOfData
{
	Integer,
	Characters,
	Double
};
typedef struct s
{
	UniData Data;
	TypeOfData Type;
}DataPack;
static class Toolkit
{
public:
	static DataPack GenPack(UniData,TypeOfData);
};

