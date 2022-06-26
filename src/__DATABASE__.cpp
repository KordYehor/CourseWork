#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include "List.h"
#include "Functions.h"
#include "DepartmentList.h"


int main()
{
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, (((1 << 4) | 7)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Choice ch1;
    Data data;
    Node* node1;
    DepartmentList Departmentlist;
    std::string str;
    int choice, ID, dep,day,month;
    double percent;
    bool mode = false;
    std::vector<std::string> vec;
    do {
        system("cls");
        Departmentlist.PrintInfo();
        vec = Departmentlist.ListOfDepartments();
        std::cout << "\tМеню\n"
            "\t1 - Новый отдел\n"
            "\t2 - Удалить отдел\n"
            "\t3 - Очистить всю базу данных\n"
            "\t4 - Сменить название отдела\n"
            "\t5 - Показать списки(найти данные)\n"
            "\t6 - Открыть меню отдела\n"
            "\t7 - Инструкция\n"
            "\t0 - Выход\n";
        std::cout << "\nДействие :";
        choice = GetNum();
        switch (choice) {
        case 1:
            std::cout << "Введите название отдела :";
            std::getline(std::cin, str);
            std::getline(std::cin, str);
            Departmentlist.AddDepartment(str);
            vec = Departmentlist.ListOfDepartments();
            break;
        case 2:
            for (int i = 1; i < vec.size() + 1; i++) {
                std::cout << i << " - " << vec[i - 1] << "\n";
            }
            std::cout << "Введите номер отдела(чтобы выйти, введите любое другое число) :";
            std::cin >> dep;
            if (dep < 1 || dep > vec.size()) {
                system("cls");
                continue;
            }
            std::cout << " Вы уверены что хотите удалить" << stringRightAlign(vec[dep-1].length() + 1,vec[dep - 1]) << "? Чтобы продолжить введите ПОДТВЕРДИТЬ\n";
            std::cin >> str;
            if (str == "ПОДТВЕРДИТЬ")
                Departmentlist.DeleteDepartment(vec[dep-1]);
            break;
        case 3:
            std::cout << " Вы уверены что хотите удалить все записи? Чтобы продолжить введите ПОДТВЕРДИТЬ\n";
            std::cin >> str;
            if(str == "ПОДТВЕРДИТЬ")
                Departmentlist.Clear();
            break;
        case 4:
            for (int i = 1; i < vec.size() + 1; i++) {
                std::cout << i << " - " << vec[i - 1] << "\n";
            }
            std::cout << "Введите номер отдела(чтобы выйти, введите любое другое число) :";
            std::cin >> dep;
            if (dep < 1 || dep > vec.size()) continue;
            Departmentlist.Change(vec[dep - 1]);
            vec = Departmentlist.ListOfDepartments();
            break;
        case 5:
            system("cls");
            Departmentlist.Print();
            std::cout << "Нажмите \"Enter\" чтобы продолжить\n";
            _getch();
            break;
        case 6:
            system("cls");
            for (int i = 1; i < vec.size()+1; i++) {
                std::cout << i << " - " << vec[i - 1] << "\n";
            }
            std::cout << "Введите номер отдела(чтобы выйти, введите любое другое число) :";
            std::cin >> dep;
            system("cls");
            if (dep < 1 || dep > vec.size()) continue;
            DepartmentNodes* node;
            if(node = Departmentlist.findDepartmentByName(vec[dep - 1]))
                do {
                    system("cls");
                    node->list.Print(ch1.getChoice(),ch1.getIntParam1(), ch1.getIntParam2(),ch1.getStringParam1(),mode);
                    std::cout << "\n\tМеню\n"
                        << stringCenterAlign(40,"Редактирование",'-') <<
                        "\n\t1 - Новый сотрудник"
                        "\n\t2 - Добавить место работы"
                        "\n\t3 - Уволить сотрудника"
                        "\n\t4 - Удалить местро предыдущей работы"
                        "\n\t5 - Удалить весь список"
                        "\n\t6 - Увеличить/уменьшить зарплату на %"
                        "\n\t7 - Изменить запись"
                        "\n\t8 - Изменить список предыдущих мест работы"
                        "\n\t9 - Отметить присутсвие"
                        "\n\t10 - Отправить в отпуск / Закончить отпуск"
                        "\n\t11 - Сделать бекап записи"
                        "\n\t12 - Показывать записи с опытом/без опыта\n"
                        << stringCenterAlign(40, "Сортировка", '-') <<
                        "\n\t13 - Развернуть лист"
                        "\n\t14 - Отсортировать лист\n"
                        << stringCenterAlign(40, "Поиск", '-') <<
                        "\n\t15 - Найти по параметру"
                        "\n\t16 - Показать журнал присутствия\n"
                        << stringCenterAlign(40, "Сохранение", '-') <<
                        "\n\t17 - Сохранить данные в резервный файл"
                        "\n\t18 - Загрузить данные с резервного файла"
                        "\n\t19 - Сохранить журнал присутствия в резервный файл"
                        "\n\t20 - Загрузить журнал присутствия с резервного файла"
                        "\n\t21 - Выйти";
                    std::cout << "\nДействие :";
                    choice = GetNum();
                    switch (choice) {
//               -------------------Редактирование--------------------------
                    case 1:
                        data.InputData();
                        node->list.Append(data);
                        break;
                    case 2:
                        std::cout << "Введите ID работника :";
                        std::cin >> ID;
                        node1 = node->list.FindByID(ID);
                        if (!node1) {
                            std::cout << " Запись не найдена!\n Нажмите \"Enter\" чтобы продолжить";
                            _getch();
                            break;
                        }
                        node1->data.InputExp();
                        break;
                    case 3:
                        std::cout << "Введите ID работника для удаления :";
                        std::cin >> ID;
                        if (!(node1 = node->list.FindByID(ID))) {
                            std::cout << " Запись не найдена!\n Нажмите \"Enter\" чтобы продолжить";
                            _getch();
                            break;
                        }
                        std::cout << " Вы уверены что хотите удалить " << stringRightAlign(node1->data.getName().length() + 1, node1->data.getName()) << "? Чтобы продолжить введите ПОДТВЕРДИТЬ\n";
                        std::cin >> str;
                        if (str == "ПОДТВЕРДИТЬ")
                            node->list.Delete(ID);
                        break;
                    case 4:
                        std::cout << "Введите ID работника для удаления записи из списка предыдущих работ :";
                        std::cin >> ID;
                        if ((node1 = node->list.FindByID(ID))) {
                            std::cout << " Запись не найдена!\n Нажмите \"Enter\" чтобы продолжить";
                            _getch();
                            break;
                        }
                        node1->data.DeleteExp();
                        break;
                    case 5:
                        std::cout << " Вы уверены что хотите удалить все записи? Чтобы продолжить введите ПОДТВЕРДИТЬ\n";
                        std::cin >> str;
                        if (str == "ПОДТВЕРДИТЬ")
                            node->list.Clear();
                        break;
                    case 6:
                        std::cout << "Введите ID работника :";
                        std::cin >> ID;
                        node1 = node->list.FindByID(ID);
                        if (!node1) {
                            std::cout << " Запись не найдена!\n Нажмите \"Enter\" чтобы продолжить";
                            _getch();
                            break;
                        }
                        std::cout << " Введите +/-число чтобы увеличить/уменьшить з/п на число%";
                        percent = GetNum();
                        node1->data.setSalary(node1->data.getSalary() * (1 + percent / 100));
                        break;
                    case 7:
                        std::cout << "Введите ID работника для редактирования данных :";
                        std::cin >> ID;
                        node->list.Change(ID);
                        break;
                    case 8:
                        std::cout << "Введите ID работника для редактирования списка предыдущих работ :";
                        std::cin >> ID;
                        if (!(node1 = node->list.FindByID(ID))) {
                            std::cout << " Запись не найдена!\n Нажмите \"Enter\" чтобы продолжить";
                            _getch();
                            break;
                        }
                        node1->data.ChangeExp();
                        break;
                    case 9:
                        std::cout << " ID работника :";
                        std::cin >> ID;
                        if (!(node1 = node->list.FindByID(ID))) {
                            std::cout << " Запись не найдена!\n Нажмите \"Enter\" чтобы продолжить";
                            _getch();
                            break;
                        }
                        std::cout << " День :";
                        std::cin >> day;
                        std::cout << " Месяц :";
                        std::cin >> month;
                        node1->data.setDayPresence(day, month);
                        break;
                    case 10:
                        std::cout << " ID работника :";
                        std::cin >> ID;
                        if (!(node1 = node->list.FindByID(ID))) {
                            std::cout << " Запись не найдена!\n Нажмите \"Enter\" чтобы продолжить";
                            _getch();
                            break;
                        }
                        node1->data.setVacation(!node1->data.getVacation());
                        break;
                    case 11:
                        std::cout << " ID работника :";
                        std::cin >> ID;
                        if (!(node1 = node->list.FindByID(ID))) {
                            std::cout << " Запись не найдена!\n Нажмите \"Enter\" чтобы продолжить";
                            _getch();
                            break;
                        }
                        node1->data.BackUp_();
                        break;
                    case 12:
                        mode = !mode;
                        break;
//               -------------------Сортировка--------------------------
                    case 13:
                        node->list.Reverse();
                        break;
                    case 14:
                        node->list.sort();
                        break;
//               -------------------Поиск--------------------------
                    case 15:
                        system("cls");
                        ch1 = node->list.ChooseFind();
                        break;
                    case 16:
                        std::cout << " ID работника :";
                        std::cin >> ID;
                        if (!(node1 = node->list.FindByID(ID))) {
                            std::cout << " Запись не найдена!\n Нажмите \"Enter\" чтобы продолжить";
                            _getch();
                            break;
                        }
                        node1->data.showPresence();
                        std::cout << "Нажмите \"Enter\" чтобы продолжить\n";
                        _getch();
                        break;
//               -------------------Другое--------------------------
                    case 17:
                        node->list.UploadIntoFile();
                        std::cout << "Нажмите \"Enter\" чтобы продолжить\n";
                        _getch();
                        break;
                    case 18:
                        node->list.DownloadFromFile();
                        std::cout << "Нажмите \"Enter\" чтобы продолжить\n";
                        _getch();
                        break;
                    case 19:
                        std::cout << " ID работника :";
                        std::cin >> ID;
                        if (!(node1 = node->list.FindByID(ID))) {
                            std::cout << " Запись не найдена!\n Нажмите \"Enter\" чтобы продолжить";
                            _getch();
                            break;
                        }
                        node1->data.DownloadPresenceIntoFile();
                        break;
                    case 20:
                        std::cout << " ID работника :";
                        std::cin >> ID;
                        if (!(node1 = node->list.FindByID(ID))) {
                            std::cout << " Запись не найдена!\n Нажмите \"Enter\" чтобы продолжить";
                            _getch();
                            break;
                        }
                        node1->data.DownloadPresenceFromFile();
                        break;
                    }
                } while (choice != 21);
                break;
        case 7:
            instruction();
            _getch();
            break;
        }
        system("cls");
    } while (choice != 0);
    return 0;
}
