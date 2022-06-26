#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "List.h"
#include "Functions.h"


List::List() {
	head = nullptr;
	tail = nullptr;
	count = 0;
}

void List::Append(Data data) {
	Node* node = new Node;
	node->data = data;
	node->data.setBackUp(data);
	ML.check(data.getName().length(), data.getPosition().length(), data.getNumber().length(), std::to_string(data.getSalary()).length(), std::to_string(data.getID()).length());
	if (!head) {
		head = tail = node;
		if (data.getID() == NULL)
			head->data.setID(1);
		count++;
		return;
	}
	if (data.getID() == NULL)
		node->data.setID(tail->data.getID() + 1);
	tail->next = node;
	tail = node;
	count++;
	
}


Choice List::ChooseFind() {
	int choice;
	Choice ch1;
	std::cout << stringLeftAlign(20+10,stringCenterAlign(20, "���� ������ ������", '-'));
	std::cout << "\n\t1 - �������� ���� ������"
		"\n\t2 - ����� �� �����"
		"\n\t3 - ����� �� ID"
		"\n\t4 - ����� �� ���������"
		"\n\t5 - ����� �� ������"
		"\n\t6 - ����� �� ��������"
		"\n\t7 - ����� �� ��������� �������"
		"\n\t8 - ����� �� ���������� �������� ����"
		"\n\t9 - ����� �� ��������� �������� ����"
		"\n\t10 - ����� �� ���������� ������� ����"
		"\n\t11 - ����� �� ��������� ������� ����"
		"\n\t12 - ����� �� �������"
		"\n\t13 - �����";
	std::cout << "\n�������� :";
	choice = GetNum();
	switch (choice) {
	case 1:
		ch1.setChoice(PRINT_ALL);
		break;
	case 2:
		ch1.setChoice(PRINT_BY_NAME);
		std::cout << " ������� ��� :";
		ch1.setStringParam1();
		break;
	case 3:
		ch1.setChoice(PRINT_BY_ID);
		std::cout << " ������� ID :";
		ch1.setIntParam1();
		break;
	case 4:
		ch1.setChoice(PRINT_BY_POSITION);
		std::cout << " ������� ��������� :";
		ch1.setStringParam1();
		break;
	case 5:
		ch1.setChoice(PRINT_BY_NUMBER);
		std::cout << " ������� ����� :";
		ch1.setIntParam1();
		break;
	case 6:
		ch1.setChoice(PRINT_BY_SALARY);
		std::cout << " ������� �������� :";
		ch1.setIntParam1();
		break;
	case 7:
		ch1.setChoice(PRINT_BETWEEN_SALARY);
		std::cout << " ������� ������ ������� ��������� �������� :";
		ch1.setIntParam1();
		std::cout << " ������� ������� ������� ��������� �������� :";
		ch1.setIntParam2();
		break;
	case 8:
		ch1.setChoice(PRINT_BY_DAYOFFS);
		std::cout << " ������� ���������� �������� :";
		ch1.setIntParam1();
		break;
	case 9:
		ch1.setChoice(PRINT_BETWEEN_DAYOFFS);
		std::cout << " ������� ������ ������� ��������� �������� ���� :";
		ch1.setIntParam1();
		std::cout << " ������� ������� ������� ��������� �������� ���� :";
		ch1.setIntParam2();
		break;
	case 10:
		ch1.setChoice(PRINT_BY_WEEKDAYS);
		std::cout << " ������� ���������� ������� ���� :";
		ch1.setIntParam1();
		break;
	case 11:
		ch1.setChoice(PRINT_BETWEEN_WEEKDAYS);
		std::cout << " ������� ������ ������� ��������� ������� ���� :";
		ch1.setIntParam1();
		std::cout << " ������� ������� ������� ��������� ������� ���� :";
		ch1.setIntParam2();
		break;
	case 12:
		ch1.setChoice(PRINT_BY_VACATION);
		std::cout << " ������� '0' ����� ����� ���� ��� �� � �������.\n ������� '1' ����� ����� ���� ��� � �������.\n :";
		ch1.setIntParam1();
		break;
	case 13:
		ch1.setChoice(-1);
		break;
	}
	return ch1;
	
}

void List::PrintOne(Node* p,bool mode) {
	if (mode == false) {
		std::cout << stringLeftAlign(ML.MaxIdL, (std::string)std::to_string(p->data.getID())) << "|" << stringLeftAlign(ML.MaxNameL, p->data.getName()) << "|" << stringLeftAlign(ML.MaxPosL, p->data.getPosition()) << "|" << stringLeftAlign(12, std::to_string(p->data.getWeekdays()) + "/" + std::to_string(p->data.getDayOffs())) << "|" << stringLeftAlign(ML.MaxNumL, p->data.getNumber()) << "|" << stringLeftAlign(ML.MaxSalaryL + 5, std::to_string(p->data.getSalary()) + " ���. ") << "|" << stringLeftAlign(8, std::to_string(p->data.getVacation())) << "|"
			<< stringLeftAlign(18, "...") << "\n";
		std::cout << stringLeftAlign(18 + 8 + 5 + 12 + ML.MaxIdL + ML.MaxNameL + ML.MaxNumL + ML.MaxPosL + ML.MaxSalaryL, "-", '-') << "\n";
	}
	else if (mode == true) {
		std::cout << stringLeftAlign(ML.MaxIdL, std::to_string(p->data.getID())) << "|" << stringLeftAlign(ML.MaxNameL, p->data.getName()) << "|" << stringLeftAlign(ML.MaxPosL, p->data.getPosition()) << "|" << stringLeftAlign(12, std::to_string(p->data.getWeekdays()) + "/" + std::to_string(p->data.getDayOffs())) << "|" << stringLeftAlign(ML.MaxNumL, p->data.getNumber()) << "|" << stringLeftAlign(ML.MaxSalaryL + 5, std::to_string(p->data.getSalary()) + " ���. ") << "|" << stringLeftAlign(8, std::to_string(p->data.getVacation())) << "|";
		p->data.PrintExp(32 + ML.MaxIdL + ML.MaxNameL + ML.MaxNumL + ML.MaxPosL + ML.MaxSalaryL);
		std::cout << stringLeftAlign(18 + 8 + 5 + 12 + ML.MaxIdL + ML.MaxNameL + ML.MaxNumL + ML.MaxPosL + ML.MaxSalaryL, "-", '-') << "\n";
	}
}

void List::Print(int tumblr, int param1,int param2, std::string strParam1, bool mode) { // mode == false - ���������� ������ ��� �����; true - � ������
	if (!head) {
		std::cout << "\t##############\n";
		std::cout << "\t# ���� ���� !#\n";
		std::cout << "\t##############\n";
		return;
	}
	Node* p = head;
	std::cout << stringLeftAlign(ML.MaxIdL, "ID") << "|" << stringLeftAlign(ML.MaxNameL, "���") << "|" << stringLeftAlign(ML.MaxPosL, "���������") << "|" << stringLeftAlign(12, "������ �/�") << "|" << stringLeftAlign(ML.MaxNumL, "����� ��������") << "|" << stringLeftAlign(ML.MaxSalaryL + 5, "��������") << "|" << stringLeftAlign(8, "������") << "|" << stringLeftAlign(18, "����") << "\n" << stringLeftAlign(18+8+5+12+ML.MaxIdL+ML.MaxNameL+ML.MaxNumL+ML.MaxPosL+ML.MaxSalaryL, "-", '-') << "\n";
	switch (tumblr) {
	case PRINT_ALL:
		while (p) {
			PrintOne(p, mode);
			p = p->next;
		}
		break;
	case PRINT_BY_ID:
		while (p) {
			if (p->data.getID() == param1)
				PrintOne(p, mode);
			p = p->next;
		}
		break;
	case PRINT_BY_NAME:
		while (p) {
			if (p->data.getName() == strParam1)
				PrintOne(p, mode);
			p = p->next;
		}
		break;
	case PRINT_BY_POSITION:
		while (p) {
			if (p->data.getPosition() == strParam1)
				PrintOne(p, mode);
			p = p->next;
		}
		break;
	case PRINT_BY_NUMBER:
		while (p) {
			if (p->data.getName() == strParam1)
				PrintOne(p, mode);
			p = p->next;
		}
		break;
	case PRINT_BY_VACATION:
		while (p) {
			if (p->data.getVacation() == param1)
				PrintOne(p, mode);
			p = p->next;
		}
		break;
	case PRINT_BY_SALARY:
		while (p) {
			if (p->data.getSalary() == param1)
				PrintOne(p, mode);
			p = p->next;
		}
	case PRINT_BETWEEN_SALARY:
		while (p) {
			if (p->data.getSalary() >= param1 && p->data.getSalary() <= param2)
				PrintOne(p, mode);
			p = p->next;
		}
		break;
	case PRINT_BY_WEEKDAYS:
		while (p) {
			if (p->data.getWeekdays() == param1)
				PrintOne(p, mode);
			p = p->next;
		}
		break;
	case PRINT_BETWEEN_WEEKDAYS:
		while (p) {
			if (p->data.getWeekdays() >= param1 && p->data.getWeekdays() <= param2)
				PrintOne(p, mode);
			p = p->next;
		}
		break;
	case PRINT_BY_DAYOFFS:
		while (p) {
			if (p->data.getDayOffs() == param1)
				PrintOne(p, mode);
			p = p->next;
		}
		break;
	case PRINT_BETWEEN_DAYOFFS:
		while (p) {
			if (p->data.getDayOffs() >= param1 && p->data.getDayOffs() <= param2)
				PrintOne(p, mode);
			p = p->next;
		}
		break;
	}
}


Node* List::FindByID(int ID) {
	Node* p = head;
	while (p && p->data.getID() != ID) {
		p = p->next;
	}
	if (p)
		return p;
	std::cout << "\n ������!(��� ������)\n";
	return nullptr;
}



void List::DeleteFirst() {
	if (!head) {
		std::cout << " ##############\n";
		std::cout << " # ���� ����! #\n";
		std::cout << " ##############\n";
		return;
	}
	Node* buffer = head;
	head = head->next;
	delete buffer;
	count--;
	FindMaxLength();
}

void List::Delete(int ID) {
	if (!head) {
		std::cout << " ##############\n";
		std::cout << " # ���� ����! #\n";
		std::cout << " ##############\n";
		return;
	}
	if (head->data.getID() == ID) {
		DeleteFirst();
		return;
	}
	Node* p = head;
	while (p->next && !(p->next->data.getID() == ID))
		p = p->next;
	if (!p->next) {
		std::cout << "��� ������\n";
		return;
	}
	Node* temp = p->next;
	p->next = temp->next;
	delete temp;
	count--;
	if (!p->next) tail = p;
	FindMaxLength();
}

void List::Clear() {
	while (head)
		DeleteFirst();
	head = tail = nullptr;
	std::cout << " ������ ������� ������\n";
}

void List::Change(int ID) {
	Node* data = FindByID(ID);
	if (!data) {
		std::cout << " ������ �� �������!\n ������� \"Enter\" ����� ����������";
		_getch();
		return;
	}
	data->data.InputData();
	FindMaxLength();
}

void List::Reverse() {
	Node* pCurrent = head;
	Node* pNext = nullptr;
	Node* pPrev = nullptr;
	while (pCurrent) {
		pNext = pCurrent->next;
		pCurrent->next = pPrev;
		pPrev = pCurrent;
		pCurrent = pNext;
	}
	tail = head;
	head = pPrev;
}

void List::UploadIntoFile() {
	
	std::ofstream datafile;
	std::string file,str;
	std::cout << " ������� ��� ����� ��� ���� � ����(��� ���������� �����) : ";
	std::cin >> file;
	std::cout << " ��� �������� ����� �������� � ������ ������ � ������ ���� ����� ���� ����������! ����� ���������� ������� ����������� :";
	std::getline(std::cin, str);
	std::getline(std::cin, str);
	if (str != "�����������") return;
	datafile.open(file + ".txt", std::ios::out);
	if (!datafile.is_open()) {
		std::cout << " ������ ��� �������� �����!\n";
		return;
	}

	Node* p = head;
	while (p) {
		datafile << p->data.getID() << "\n" << p->data.getName() << "\n" << p->data.getSalary() << "\n" << p->data.getVacation() << "\n" << p->data.getWeekdays() << "\n" << p->data.getDayOffs() << "\n" << p->data.getPosition() << "\n" << p->data.getNumber() << "\n";
		for (background n : p->data.getExp()) {
			datafile << n.getCompany() << "\n" << n.getExpYears() << "\n";
		}
		datafile << "-\n";
		p = p->next;
	}
	datafile.close();
}



void List::DownloadFromFile() {
	if (!this->isEmpty()) {
		std::cout << " ���� �� ����\n";
		return;
	}
	std::string name,company,file,position,number,salary_str,ID_str,years_str,weekdays_str,day_offs_str,vacation_str;
	std::ifstream datafile;
	Data object;
	std::vector<background> vec;
	std::cout << " ������� �������� ����� ��� ���� � ����(��� ���������� �����) : ";
	std::cin >> file;
	datafile.open(file + ".txt", std::ios::in);
	
	if (!datafile.is_open()) {
		std::cout << " ���� �� ������/������ �������� �����!\n";
		return;
	}
	std::getline(datafile, ID_str);
	std::getline(datafile, name);
	std::getline(datafile, salary_str);
	std::getline(datafile, vacation_str);
	std::getline(datafile, weekdays_str);
	std::getline(datafile, day_offs_str);
	std::getline(datafile, position);
	std::getline(datafile, number);
	while (true) {
		std::getline(datafile, company);
		if (company == "-")
			break;
		std::getline(datafile, years_str);
		vec.push_back(background(company, std::atoi(years_str.c_str())));
	}
	
	object.setData(std::atoi(salary_str.c_str()), std::atoi(vacation_str.c_str()),std::atoi(weekdays_str.c_str()), std::atoi(day_offs_str.c_str()), name,position,number,vec, std::atoi(ID_str.c_str()));
	while (!datafile.eof()) {
		this->Append(object);
		std::getline(datafile, ID_str);
		std::getline(datafile, name);
		std::getline(datafile, salary_str);
		std::getline(datafile, vacation_str);
		std::getline(datafile, weekdays_str);
		std::getline(datafile, day_offs_str);
		std::getline(datafile, position);
		std::getline(datafile, number);
		vec.clear();
		while (true) {
			std::getline(datafile, company);
			if (company == "-")
				break;
			std::getline(datafile, years_str);
			vec.push_back(background(company, std::atoi(years_str.c_str())));
		}
		object.setData(std::atoi(salary_str.c_str()), std::atoi(vacation_str.c_str()), std::atoi(weekdays_str.c_str()), std::atoi(day_offs_str.c_str()), name, position, number, vec, std::atoi(ID_str.c_str()));
	}
	std::cout << " ������ ������� ���������\n";
	datafile.close();
}



void List::sort() {
	Node* p = head;
	int choice;
	bool check = false;
	std::cout <<"\t1 - ������������� �� ID\n"
				"\t2 - ������������� �� ���������\n"
				"\t3 - ������������� �� ���������\n"
				"\t4 - ������������� �� ����������\n"
				"\t5 - ������������� �� ������� ��������\n"
				"\t6 - ������������� �� ��������\n"
				"\t7 - ������������� �� ��������\n";
	std::cout << " ��������:";
	std::cin >> choice;
	switch (choice) {
	case 1:
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count - i - 1; j++) {
				if (p->data.getID() > p->next->data.getID()) {
					Data temp = p->data;
					p->data = p->next->data;
					p->next->data = temp;
					check = true;
				}
				p = p->next;
			}
			p = head;
		}
		break;
	case 2:
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count - i - 1; j++) {
				if (p->data.getName() > p->next->data.getName()) {
					Data temp = p->data;
					p->data = p->next->data;
					p->next->data = temp;
					check = true;
				}
				p = p->next;
			}
			p = head;
		}
		break;
	case 3:
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count - i - 1; j++) {
				if (p->data.getSalary() > p->next->data.getSalary()) {
					Data temp = p->data;
					p->data = p->next->data;
					p->next->data = temp;
					check = true;
				}
				p = p->next;
			}
			p = head;
		}
		break;
	case 4:
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count - i - 1; j++) {
				if (p->data.getPosition() > p->next->data.getPosition()) {
					Data temp = p->data;
					p->data = p->next->data;
					p->next->data = temp;
					check = true;
				}
				p = p->next;
			}
			p = head;
		}
		break;
	case 5:
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count - i - 1; j++) {
				if (p->data.getNumber() > p->next->data.getNumber()) {
					Data temp = p->data;
					p->data = p->next->data;
					p->next->data = temp;
					check = true;
				}
				p = p->next;
			}
			p = head;
		}
		break;
	case 6:
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count - i - 1; j++) {
				if (p->data.getWeekdays() > p->next->data.getWeekdays()) {
					Data temp = p->data;
					p->data = p->next->data;
					p->next->data = temp;
					check = true;
				}
				if(p->data.getWeekdays() == p->next->data.getWeekdays() && p->data.getDayOffs() > p->next->data.getDayOffs()) {
					Data temp = p->data;
					p->data = p->next->data;
					p->next->data = temp;
					check = true;
				}
				p = p->next;
			}
			p = head;
		}
		break;
	case 7:
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count - i - 1; j++) {
				if (p->data.getVacation() > p->next->data.getVacation()) {
					Data temp = p->data;
					p->data = p->next->data;
					p->next->data = temp;
					check = true;
				}
				p = p->next;
			}
			p = head;
		}
		break;
	}
	if (!check)
		Reverse();
}

bool List::isEmpty() {
	if (!head) return true;
	return false;
}

float List::getSalarySumm() {
	Node* p = head;
	float sum = 0;
	while (p) {
		sum += p->data.getSalary();
		p = p->next;
	}
	return sum;
}

void List::FindMaxLength() {
	Node* p = head;
	ML.ReMax();
	while (p) {
		ML.check(p->data.getName().length(), p->data.getPosition().length(), p->data.getNumber().length(), std::to_string(p->data.getSalary()).length(), std::to_string(p->data.getID()).length());
		p = p->next;
	}
}