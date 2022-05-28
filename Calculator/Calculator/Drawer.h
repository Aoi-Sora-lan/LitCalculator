#pragma once
#include"Toolkit.h"
#include<iostream>
#include<cstring>
#include<string>
#include<string.h>
using namespace std;
class UIDraw
{
protected:
	string preOut;
public:
	virtual void Draw(int) {};
	virtual void Draw(int, int) {};
	void Draws(int);
	void PreOutStart(int);
};
class MenuDraw :public UIDraw
{
public:
	void Draw(int Length);
protected:
private:
	const int FUNC_NUM = 24;
	static UIDraw* mInstance;
	string* Funcs = new string[FUNC_NUM]();
	void MenuSystem(int);
	void LoadFunction();
	void MenuSetLine(int,bool);
	void MenuSetPreContent(int, int, string);
	void SetPreContent(int,string);
	int CalTextLong(int, string);
	int CalCenter(int, int);
};
