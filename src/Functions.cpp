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
	std::cout << stringCenterAlign(36, "Инструкция", '-') <<
		"\n Добро пожаловать в базу данных работников It компании\n"
		" Чтобы выбрать действие просто введите его номер и нажмите \"Enter\" для подтверждения\n"
		" При желании,Вы можете сохранить отдел в резервный файл название и расположение которого можете выбрать сами\n"
		" Также можно импортировать данные из резервного файла выбрав в меню нужное дейсвтие и указав путь к файлу\n"
		" Некоторые действия могу привести к потере данных,в таких случаях программа будет просить подтверждения\n"
		" Закрытие программы приведет к потере несохраненных данных,так что настоятельно рекомендуем сохранять данные в резервный файл\n";
		" На основном экране вы видите меню управления отделами,чтобы перейти в меню определенного отдела выберите действие '6' и следуйте дальнейшим инструкциям\n"
		" При желании вы можете сделать бекап записи(в пределах одного запуска программы,после закрытия программы сохраненные бекапы удаляются)\n";
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

