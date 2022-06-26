#include <iostream>
#include <string>
#include "Data.h"
#include "Functions.h"

std::string stringRightAlign(int newlength, std::string str,char char_) {
	if (str.length() >= newlength)
		return str;
	
	std::string newstr(newlength - str.length(), char_);

	return newstr + str;
}

std::string stringLeftAlign(int newlength, std::string str, char char_) {
	if (str.length() >= newlength)
		return str;

	std::string newstr(newlength - str.length(), char_);

	return  str + newstr;
}

std::string stringCenterAlign(int newlength, std::string str, char char_) {
	if (str.length() >= newlength)
		return str;

	std::string newstr((newlength - str.length())/2, char_);

	return newstr + str + newstr;
}

void instruction() {
	std::cout << stringCenterAlign(36, "����������", '-') <<
		"\n ����� ���������� � ���� ������ ���������� It ��������\n"
		" ����� ������� �������� ������ ������� ��� ����� � ������� \"Enter\" ��� �������������\n"
		" ��� �������,�� ������ ��������� ����� � ��������� ���� �������� � ������������ �������� ������ ������� ����\n"
		" ����� ����� ������������� ������ �� ���������� ����� ������ � ���� ������ �������� � ������ ���� � �����\n"
		" ��������� �������� ���� �������� � ������ ������,� ����� ������� ��������� ����� ������� �������������\n"
		" �������� ��������� �������� � ������ ������������� ������,��� ��� ������������ ����������� ��������� ������ � ��������� ����\n";
		" �� �������� ������ �� ������ ���� ���������� ��������,����� ������� � ���� ������������� ������ �������� �������� '6' � �������� ���������� �����������\n"
		" ��� ������� �� ������ ������� ����� ������(� �������� ������ ������� ���������,����� �������� ��������� ����������� ������ ���������)\n";
}

int GetNum() {
	int num;
	std::cin >> num;
	
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		return -1;
	}
	else {
		return num;
	}
}

