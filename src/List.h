#pragma once
#include "Data.h"
#include "Node.h"
#include "Functions.h"
#include <iostream>
#include <string>

#define PRINT_ALL 0
#define PRINT_BY_NAME 1
#define PRINT_BY_ID 2
#define PRINT_BY_POSITION 3
#define PRINT_BY_NUMBER 4
#define PRINT_BY_SALARY 5
#define PRINT_BETWEEN_SALARY 6
#define PRINT_BY_DAYOFFS 7
#define PRINT_BETWEEN_DAYOFFS 8
#define PRINT_BY_WEEKDAYS 9
#define PRINT_BETWEEN_WEEKDAYS 10
#define PRINT_BY_VACATION 11

struct MaxLength {
private:
	int MaxNameL = 16;
	int MaxPosL = 14;
	int MaxNumL = 14;
	int MaxSalaryL = 8;
	int MaxIdL = 4;
public:
	void ReMax() {
		MaxNameL = 16;
		MaxPosL = 14;
		MaxNumL = 14;
		MaxSalaryL = 8;
		MaxIdL = 4;
	}
	void check(int NameL, int PosL, int NumL, int SalL, int IdL) {
		if (NameL > MaxNameL) MaxNameL = NameL;
		if (PosL > MaxPosL) MaxPosL = PosL;
		if (NumL > MaxNumL) MaxNumL = NumL;
		if (SalL > MaxSalaryL) MaxSalaryL = SalL;
		if (IdL > MaxIdL) MaxIdL = IdL;
	}
	int getMaxNameL()		{ return MaxNameL;   }
	int getMaxPosL()		{ return MaxPosL;    }
	int getMaxNumL()		{ return MaxNumL;    }
	int getMaxSalaryL()		{ return MaxSalaryL; }
	int getMaxIdL()			{ return MaxIdL;     }
};

struct Choice {
private:
	int choice = PRINT_ALL;
	std::string strParam1 = "NoN";
	int intParam1 = NULL;
	int intParam2 = NULL;
public:
	void setChoice(int choice)		{ this->choice = choice;                                                }
	void setStringParam1()			{ std::getline(std::cin, strParam1); std::getline(std::cin, strParam1); }
	void setIntParam1()				{ intParam1 = GetNum();												    }
	void setIntParam2()             { intParam2 = GetNum();                                                 }
	int getChoice()					{ return choice;													    }
	std::string getStringParam1()	{ return strParam1;													    }
	int getIntParam1()				{ return intParam1;                                                     }
	int getIntParam2()              { return intParam2;                                                     }
};

class List
{
private:
	MaxLength ML;
	Node* head;
	Node* tail;
	int count;
public:
	List();
	void Append(Data data);
	void Print(int tumblr, int param1, int param2, std::string strParam1, bool mode = false);
	void PrintOne(Node* p,bool mode);
	Node* FindByID(int ID);
	void DeleteFirst();
	void Delete(int ID);
	void Clear();
	void Change(int ID);
	void Reverse();
	void UploadIntoFile();
	void DownloadFromFile();
	void sort();
	bool isEmpty();
	float getSalarySumm();
	int getSize() { return count; }
	Choice ChooseFind();
	void FindMaxLength();
};

