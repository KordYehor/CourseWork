#pragma once
#include "Data.h"
#include "Functions.h"
#include <iostream>
#include <string>
#include <fstream>

bool operator == (Data d1, Data d2) {
	return d1.getID() == d2.getID() && d1.getName() == d2.getName() && d1.getNumber() == d2.getNumber() && d1.getPosition() == d2.getPosition();
}

Data::Data() {
	this->ID = NULL;
	this->salary =NULL;
	this->name = "NoN";
	this->position = "NoN";
	this->vacation = 0;
	for (int i = 0; i < 365; i++)
		this->presence[i] = false;
}

void Data::setData(int salary,bool vacation,int weekdays,int day_offs, std::string name,std::string position,std::string number ,std::vector<background> l1,int ID) {
	this->ID = ID;
	this->salary = salary;
	this->weekdays = weekdays;
	this->day_offs = day_offs;
	this->name = name;
	this->exp = l1;
	this->position = position;
	this->number = number;
	this->vacation = vacation;
}

Data Data::InputData() {
	std::cout << " ������� ��� :";
	std::getline(std::cin, this->name);
	std::getline(std::cin, this->name);
	std::cout << " ������� ��������� :";
	std::getline(std::cin, this->position);
	std::cout << " ������� ����� ������� :";
	std::getline(std::cin, this->number);
	std::cout << " ������� �������� :";
	this->salary = GetNum();
	std::cout << " ������� ������ ������ (������� ���):";
	this->weekdays = GetNum();
	std::cout << " ������� ������ ������ (�������� ���):";
	this->day_offs = GetNum();
	exp.clear();
	BackUp.push_back(*this);
	return *this;
}

void Data::InputExp() {
	std::string company;
	int years;
	std::cout << " ������� ��������� �������� :";
	std::getline(std::cin, company);
	std::getline(std::cin, company);
	std::cout << " ������� ���������� ��� ����� :";
	years = GetNum();
	background back(company,years);
	this->exp.push_back(back);
}

void Data::PrintExp(int spaces) {
	if (exp.empty()) {
		std::cout << "\n";
		return;
	}
	std::cout << exp[0].getCompany() << " - " << exp[0].getExpYears() << " year/s \n";
	for (int i = 1; i < exp.size();i++) {
		std::cout << stringRightAlign(spaces +  (exp[i].getCompany() + " - " + std::to_string(exp[i].getExpYears()) + " year/s").length(), exp[i].getCompany() + " - " + std::to_string(exp[i].getExpYears()) + " year/s") << "\n";
	}
}

void Data::ChangeExp() {
	int choice,years;
	std::string str;
	for (int i = 0; i < exp.size(); i++) {
		std::cout << i + 1 << "-" << exp[i].getCompany() << "\n";
	}
	std::cout << " �������� ����� ������ ��� ��������� :";
	choice = GetNum();
	if (choice < 1 && choice > exp.size())
		return;
	std::cout << " �� ������� ��� ������ �������� ������ ��" << stringRightAlign(exp[choice - 1].getCompany().length() + 1, exp[choice - 1].getCompany()) << "? ����� ���������� ������� �����������\n";
	std::cin >> str;
	if (str != "�����������") return;
	std::cout << " �������� �������� �������� :";
	std::getline(std::cin, str);
	std::getline(std::cin, str);
	std::cout << " �������� ���������� ��� ����� :";
	std::cin >> years;
	exp[choice - 1].SetData(str, years);
}

void Data::DeleteExp() {
	int choice;
	std::string str;
	for (int i = 0; i < exp.size(); i++) {
		std::cout << i + 1 << "-" << exp[i].getCompany() << "\n";
	}
	std::cout << " �������� ����� ������ ��� �������� :";
	choice = GetNum();
	if(choice < 1 && choice > exp.size())
		return;
	std::cout << " �� ������� ��� ������ ������� ������ ��" << stringRightAlign(exp[choice - 1].getCompany().length() + 1, exp[choice - 1].getCompany()) << "? ����� ���������� ������� �����������\n";
	std::cin >> str;
	if (str != "�����������")
		return;
	for (; choice < exp.size() && choice > 0; choice++) {
		exp[choice - 1] = exp[choice];
	}
	exp.pop_back();
	
}

void Data::setDayPresence(int day, int month) {
	if (month < 1 || month > 12 || day < 1 || day > 31) return;
	switch (month) {
	case 1:
		presence[JANUARY - 1 + day] = true;
		break;
	case 2:
		presence[FEBRUARY - 1 + day] = true;
		break;
	case 3:
		presence[MARCH - 1 + day] = true;
		break;
	case 4:
		presence[APRIL - 1 + day] = true;
		break;
	case 5:
		presence[MAY - 1 + day] = true;
		break;
	case 6:
		presence[JUNE - 1 + day] = true;
		break;
	case 7:
		presence[JULY - 1 + day] = true;
		break;
	case 8:
		presence[AUGUST - 1 + day] = true;
		break;
	case 9:
		presence[SEPTEMBER - 1 + day] = true;
		break;
	case 10:
		presence[OCTOBER - 1 + day] = true;
		break;
	case 11:
		presence[NOVEMBER - 1 + day] = true;
		break;
	case 12:
		presence[DECEMBER - 1 + day] = true;
		break;
	}
}

void Data::showPresence() {
	for (int i = 364; i >= 0; i--) {
		if (i >= DECEMBER && presence[i] == true) {
			std::cout << this->name << " ������������� �� ������ " << i + 1 - DECEMBER << " �������\n";
		}
		else if (i >= NOVEMBER && presence[i] == true) {
			std::cout << this->name << " ������������� �� ������ " << i + 1 - NOVEMBER << " ������\n";
		}
		else if (i >= OCTOBER && presence[i] == true) {
			std::cout << this->name << " ������������� �� ������ " << i + 1 - OCTOBER << " �������\n";
		}
		else if (i >= SEPTEMBER && presence[i] == true) {
			std::cout << this->name << " ������������� �� ������ " << i + 1 - SEPTEMBER << " ��������\n";
		}
		else if (i >= AUGUST && presence[i] == true) {
			std::cout << this->name << " ������������� �� ������ " << i + 1 - AUGUST << " �������\n";
		}
		else if (i >= JULY && presence[i] == true) {
			std::cout << this->name << " ������������� �� ������ " << i + 1 - JULY << " ����\n";
		}
		else if (i >= JUNE && presence[i] == true) {
			std::cout << this->name << " ������������� �� ������ " << i + 1 - JUNE << " ����\n";
		}
		else if (i >= MAY && presence[i] == true) {
			std::cout << this->name << " ������������� �� ������ " << i + 1 - MAY << " ���\n";
		}
		else if (i >= APRIL && presence[i] == true) {
			std::cout << this->name << " ������������� �� ������ " << i + 1 - APRIL << " ������\n";
		}
		else if (i >= MARCH && presence[i] == true) {
			std::cout << this->name << " ������������� �� ������ " << i + 1 - MARCH << " �����\n";
		}
		else if (i >= FEBRUARY && presence[i] == true) {
			std::cout << this->name << " ������������� �� ������ " << i + 1 - FEBRUARY << " �������\n";
		}
		else if (i >= JANUARY && presence[i] == true) {
			std::cout << this->name << " ������������� �� ������ " << i + 1 - JANUARY << " ������\n";
		}
	}
}

void Data::BackUp_() {
	std::string str;
	std::getline(std::cin, str);
	std::cout << " �������� ������ ��� ������ :\n";
	for (auto& n : BackUp) {
		std::cout << " ��� - " << n.name << " ��������� - " << n.position << " ����� �������� - " << n.number << " �������� - " << n.salary << "\n";
		std::cout << "������� ����������� ����� ������� ��� ������ :";
		std::getline(std::cin, str);
		if (str == "�����������") {
			this->setData(n.salary,n.vacation, n.weekdays, n.day_offs, n.name, n.position, n.number, n.exp, n.ID);
			return;
		}
	}
}

void Data::setBackUp(Data data) {
	for (auto& n : BackUp) {
		if (n == data) return;
	}
	BackUp.push_back(data);
}

void Data::DownloadPresenceIntoFile() {
	std::ofstream datafile;
	std::string file, str;
	std::cout << " ������� ��� ����� ��� ���� � ����(��� ���������� �����.���� �� ������� ���� � �����,����� '\\' ����� �����������) : ";
	std::cin >> file;
	std::cout << " ��� �������� ����� �������� � ������ ������ � ������ ���� ����� ���� ����������! ����� ���������� ������� ����������� :";
	std::getline(std::cin, str);
	std::getline(std::cin, str);
	if (str != "�����������") return;
	datafile.open(file + ".bin", std::ios::out | std::ios::binary);
	if (!datafile.is_open()) {
		std::cout << " ������ ��� �������� �����!\n";
		return;
	}
	for (int i = 0; i < 365; i++) {
		datafile.write((char*)& presence[i], 1);
	}
	datafile.close();
}

void Data::DownloadPresenceFromFile() {
	std::ifstream datafile;
	std::string file;
	std::cout << " ������� ��� ����� ��� ���� � ����(��� ���������� �����.���� �� ������� ���� � �����,����� '\\' ����� �����������) : ";
	std::cin >> file;
	datafile.open(file + ".bin", std::ios::in | std::ios::binary);
	if (!datafile.is_open()) {
		std::cout << " ������ ��� �������� �����!\n";
		return;
	}
	for (int i = 0; i < 365; i++) {
		datafile.read((char*)&presence[i], 1);
	}
	datafile.close();
}