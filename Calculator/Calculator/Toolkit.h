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
	/// �Ӽ���������һ�������������1������֮�����������͡�Ҫ����forѭ�����ʵ�֡�
	/// </summary>
	OddAddition,
	/// <summary>
	/// �Ӽ���������һ�������������1������֮������ż���͡�Ҫ����while���ʵ�֡�
	/// </summary>
	EvenAddition,
	/// <summary>
	/// �Ӽ���������һ�������������1������֮������3�ı�����Ҫ����do-whileʵ�֡�
	/// </summary>
	TriCount,
	/// <summary>
	/// �Ӽ��������������������������֮���һ������3�����ֱ�5����������
	/// </summary>
	Mod15Is0,
	/// <summary>
	/// �������ˮ�ɻ�����ˮ�ɻ�����һ��3λ������λ���ֵ�����֮�͵������������磺153= 1^3+5^3+3^3��
	/// </summary>
	WaterFlower,
	/// <summary>
	/// ��дһ�������������ĺ������ú����������������������ֵ����������������������ǵ����ֵ��
	/// </summary>
	GetMax,
	/// <summary>
	/// ��дһ�������������ĺ������ú���������������������ֵ����Сֵ��ʹ�õ�һ������������ֵ���ڶ������������Сֵ��Ҫ����ϰ���ݵ�ַ�Ĳ�����
	/// </summary>
	GetMaxMin,
	/// <summary>
	///   �Ӽ���������10����������ð�����������������
	/// </summary>
	BubbleSort,
	/// <summary>
	/// �Ӽ�������һ��3X4���������󣬽���ת�ò���������ת�ý������Ļ�������
	/// </summary>
	MatrixTrans,
	/// <summary>
	/// �Ӽ�������һ��3*3�������������Խ���Ԫ�غͣ�
	/// </summary>
	MatrixAdd,
	/// <summary>
	/// �Ӽ�������һ���ַ�������֮���ÿո�ָ�����ͳ�������ж��ٸ����ʣ� ����������
	/// </summary>
	WordCount,
	/// <summary>
	/// ��̬����һ��������4���ڵ�ĵ�����������������������ݡ��ڵ����������������int�ͣ���ָ����
	/// </summary>
	StaticChain,
	/// <summary>
	/// ��̬����һ���������δӼ�������������������������������뵽�������У�ֱ������һ������Ϊֹ����󽫸������е���������Ļ�������
	/// </summary>
	DynamicChain,
	/// <summary>
	///   ����ѧ���ṹ�����飬����Ϊ10������������ʮ��ѧ����ѧ�š��������ɼ�������ð�����򣬶���10��ѧ�����򣬴�С���������10��ѧ������Ϣ��Ȼ�����10��ѧ�����ܳɼ���ƽʱ�ɼ�
	/// </summary>
	StudentSort,
	/// <summary>
	/// d�̸�Ŀ¼�´���һ���ı��ļ�my.txt����������10��ѧ���ĳɼ���һ��һ���ɼ������ļ��ж�ȡѧ���ĳɼ���ÿ���ɼ�����10�ֺ󣬱��浽ԭ�ļ��С�
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

