#pragma once
#include <iostream>
#include <vector>

#define JANUARY 0
#define FEBRUARY 31
#define MARCH 60
#define APRIL 91
#define MAY 121
#define JUNE 152
#define JULY 182
#define AUGUST 213
#define SEPTEMBER 244
#define OCTOBER 274
#define NOVEMBER 305
#define DECEMBER 335

class background {
private:
	std::string company;
	int exp_years;
public:
	background() {
		company = "";
		exp_years = 0;
	}
	background(std::string company, int years) {
		this->company = company;
		exp_years = years;
	}
	void SetData(std::string company, int years) {
		this->company = company;
		exp_years = years;
	}
	std::string getCompany() { return company; }
	int getExpYears() { return exp_years; }
};

class Data
{
private:
	int ID;
	int salary;
	int weekdays;
	int day_offs;
	bool vacation;
	std::string name;
	std::string position;
	std::string number;
	bool presence[365];
	std::vector<background> exp;
	std::vector<Data> BackUp;
public:
	Data();
	void setData(int salary,bool vacation, int weekdays, int day_offs, std::string name ,std::string position,std::string number, std::vector<background> vec ,int ID = NULL);

	int getID()							   { return ID;                 }
	bool getVacation()                     { return vacation;           }
	int getWeekdays()				       { return weekdays;           }
	int getDayOffs()					   { return day_offs;           }
	int getSalary()					       { return salary;             }
	std::string getName()				   { return name;               }
	std::string getPosition()              { return position;           }
	std::string getNumber()                { return number;             }
	std::vector<background> getExp()       { return exp;                }
	void setID(int id)					   { this->ID = id;             }
	void setVacation(bool vacation)        { this->vacation = vacation; }
	void setWeekdays(int weekdays)	       { this->weekdays = weekdays; }
	void setDayOffs(int dayOffs)		   { this->day_offs = dayOffs;  }
	void setSalary(int salary)			   { this->salary = salary;     }
	void setName(std::string name)		   { this->name = name;         }
	void setPosition(std::string position) { this->position = position; }
	void setNumber(std::string number)     { this->number = number;     }
	void setBackUp(Data data);
	void InputExp();
	void PrintExp(int spaces);
	void BackUp_();
	void ChangeExp();
	void DeleteExp();
	Data InputData();
	void setDayPresence(int day, int month);
	void showPresence();
	void DownloadPresenceFromFile();
	void DownloadPresenceIntoFile();
};

