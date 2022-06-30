#pragma once
#include <iostream>
#include <vector>
#include "DepartmentNodes.h"

class DepartmentList
{
private:
	
	MaxLength ML;
	DepartmentNodes* head = nullptr;
	DepartmentNodes* tail = nullptr;
public:
	DepartmentList();
	void AddDepartment(std::string name);
	void PrintInfo();
	void DeleteDepartment(std::string name);
	void DeleteFirst();
	void Clear();
	DepartmentNodes* findDepartmentByName(std::string name);
	void Change(std::string name);
	void Print();
	std::vector<std::string> ListOfDepartments();
	void FindMaxLength();
};

