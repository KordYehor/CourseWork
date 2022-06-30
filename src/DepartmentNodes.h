#pragma once
#include "List.h"

class DepartmentNodes
{
private:
	std::string Department_Name;
public:
	List list;
	DepartmentNodes* next;

	DepartmentNodes();
	std::string getDepartmentName() { return Department_Name; }
	void setDeprtmentName(std::string name) { this->Department_Name = name; }
};

