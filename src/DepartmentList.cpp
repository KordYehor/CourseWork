#include <string>
#include <conio.h>
#include "Functions.h"
#include "DepartmentList.h"
#include "List.h"

DepartmentList::DepartmentList() {
	head = nullptr;
	tail = nullptr;
}

void DepartmentList::AddDepartment(std::string name) {
	DepartmentNodes* node = new DepartmentNodes;
	node->setDeprtmentName(name);
	if (!head) {
		head = tail = node;
		return;
	}
	tail->next = node;
	tail = node;
	ML.check(name.length(), NULL, NULL, NULL, NULL);
}

void DepartmentList::DeleteFirst() {
	if (!head) {
		std::cout << "\t##############\n";
		std::cout << "\t# Лист пуст! #\n";
		std::cout << "\t##############\n";
		return;
	}
	DepartmentNodes* buffer = head;
	head = head->next;
	buffer->list.Clear();
	delete buffer;
	FindMaxLength();
}

void DepartmentList::DeleteDepartment(std::string name) {
	if (!head) {
		std::cout << "\t##############\n";
		std::cout << "\t# Лист пуст! #\n";
		std::cout << "\t##############\n";
		return;
	}
	if (head->getDepartmentName() == name) {
		DeleteFirst();
		return;
	}
	DepartmentNodes* p = head;
	while (p->next && !(p->next->getDepartmentName() == name))
		p = p->next;
	if (!p->next) {
		std::cout << "\t##############\n";
		std::cout << "\t# Нет данных #\n";
		std::cout << "\t##############\n";
		return;
	}
	DepartmentNodes* temp = p->next;
	p->next = temp->next;
	temp->list.Clear();
	delete temp;
	if (!p->next) tail = p;
	FindMaxLength();
}

void DepartmentList::Clear() {
	while (head)
		DeleteFirst();
	head = tail = nullptr;
}

DepartmentNodes* DepartmentList::findDepartmentByName(std::string name) {
	DepartmentNodes* p = head;
	while (p && p->getDepartmentName() != name) {
		p = p->next;
	}
	if (p)
		return p;
	std::cout << "\n Ошибка!(Нет данных)\n";
	return nullptr;
}

void DepartmentList::Change(std::string name) {
	std::string newname = "NoN";
	DepartmentNodes* data = findDepartmentByName(name);
	if (!data) return;
	std::cout << "\nВведите новое название : ";
	std::getline(std::cin, newname);
	std::getline(std::cin, newname);
	data->setDeprtmentName(newname);
	FindMaxLength();
}

void DepartmentList::Print() {
	if (!head) {
		std::cout << "\t##############\n";
		std::cout << "\t# Лист пуст! #\n";
		std::cout << "\t##############\n";
		return;
	}
	DepartmentNodes* p;
	Choice ch1;
	List list;
	do {
		system("cls");
		p = head;
		ch1 = list.ChooseFind();
		if (ch1.getChoice() == -1) return;
		while (p) {
			std::cout << stringLeftAlign(p->getDepartmentName().length() + 5, "\t#", '#');
			std::cout << "\n\t# " << p->getDepartmentName() << " #\n";
			std::cout << stringLeftAlign(p->getDepartmentName().length() + 5, "\t#", '#');
			std::cout << "\n";
			p->list.Print(ch1.getChoice(), ch1.getIntParam1(), ch1.getIntParam2(), ch1.getStringParam1());
			p = p->next;
		}
		std::cout << "Нажмите \"Enter\" чтобы продолжить\n";
		_getch();
	} while (true);
}

void DepartmentList::PrintInfo() {
	DepartmentNodes* p = head;
	if (!p) {
		std::cout << " ##############\n";
		std::cout << " # Лист пуст! #\n";
		std::cout << " ##############\n";
		return;
	}
	std::cout << stringLeftAlign(ML.MaxNameL, "Название отдела") << "|" << stringLeftAlign(20, "Кол-во сотрудников") << "|" << stringLeftAlign(32, "Сумарная з/п") << "|" << stringLeftAlign(20, "Средняя з/п") << "\n";
	std::cout << stringLeftAlign(70 + ML.MaxNameL, "-", '-') << "\n";
	while (p) {
		if (p->list.getSize() != 0) {
			std::cout << stringLeftAlign(ML.MaxNameL, p->getDepartmentName()) << "|" << stringLeftAlign(20, std::to_string(p->list.getSize())) << "|" << stringLeftAlign(32, std::to_string((int)p->list.getSalarySumm()) + " Грн.") << "|" << stringLeftAlign(20, std::to_string((int)p->list.getSalarySumm()/p->list.getSize()) + " Грн.") << "\n";
			std::cout << stringLeftAlign(70 + ML.MaxNameL, "-", '-') << "\n";
		}
		else {
			std::cout << stringLeftAlign(ML.MaxNameL, p->getDepartmentName()) << "|" << stringLeftAlign(20, std::to_string(p->list.getSize())) << "|" << stringLeftAlign(32, std::to_string((int)p->list.getSalarySumm()) + " Грн.") << "|" << stringLeftAlign(20, std::to_string((int)p->list.getSalarySumm()) + " Грн.") << "\n";
			std::cout << stringLeftAlign(70 + ML.MaxNameL, "-", '-') << "\n";
		}
		
		p = p->next;
	}
}

std::vector<std::string> DepartmentList::ListOfDepartments() {
	std::vector<std::string> vec;
	DepartmentNodes* p = head;
	while (p) {
		vec.push_back(p->getDepartmentName());
		p = p->next;
	}
	return vec;
}

void DepartmentList::FindMaxLength() {
	DepartmentNodes* p = head;
	ML.ReMax();
	while (p) {
		ML.check(p->getDepartmentName().length(), NULL, NULL, NULL, NULL);
		p = p->next;
	}
}