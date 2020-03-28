
#include <iostream>
#include <Windows.h>

using namespace std;




class Date {
	const int MIN_DAY = 1;
	const int MIN_MONTH = 1;
	const int MAX_MONTH = 12;
	const int MIN_YEAR = 1;
	const int LEAP_EACH = 4;
	const int NO_LEAP_EACH = 100;
	const int LEAP_EACH_400 = 400;
	const int monthDays[13] = { 0,31, 28, 31, 30, 31, 30,
						   31, 31, 30, 31, 30, 31 };
	int day;
	int month;
	int year;

	enum Month { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUS, SEP, OCT, NOV, DEC };

	bool checkLeapYear(int year)
	{
		if (year % LEAP_EACH == 0 && year % NO_LEAP_EACH != 0 || year % LEAP_EACH_400 == 0)
			return true;

		else
			return false;
	}

	int countDayInMonth(int month, int year)
	{
		if (month == JAN || month == MAR || month == MAY || month == JUL || month == AUS || month == OCT || month == DEC)
			return 31;

		if (month == APR || month == JUN || month == SEP || month == NOV)
			return 30;

		if (month == FEB)
		{
			if (checkLeapYear(year))
				return 29;
			else
				return 28;
		}
	}

	int countLeapYears(int year)
	{
		int years = year;
		years--;
		return years / 4 - years / 100 + years / 400;
	}

	void SetDay(int day, int maxDay) {
		if (day < MIN_DAY) {
			this->day = MIN_DAY;
		}
		else if (day > maxDay) {
			this->day = maxDay;
		}
		else this->day = day;
	}

	void SetMonth(int month) {
		if (month < MIN_MONTH) {
			this->month = MIN_MONTH;
		}
		else if (month > MAX_MONTH) {
			this->month = MAX_MONTH;
		}
		else this->month = month;
	}

	void SetYear(int year) {
		if (year < MIN_YEAR) {
			this->year = MIN_YEAR;
		}
		else this->year = year;
	}

	long int convertToDays(int year, int month, int day) {
		long int totalDays = year * 365 + day;
		for (int i = 1; i < month; i++)
			totalDays += monthDays[i];
		totalDays += countLeapYears(year);
		return totalDays;
	}

	int offsetDays(int year, int month, int day) {
		int offset = day;
		if (month == JAN) {
			return offset;
		}
		else {
			for (int i = 0; i < month - JAN; i++) {
				offset += monthDays[i - JAN];
			}
		}
		if (checkLeapYear(year) && month > FEB) {
			offset++;
		}
		return offset;
	}

public:
	Date() {
		day = 1;
		month = 1;
		year = 1970;
	}
	Date(int day, int month, int year) {
		SetYear(year);
		SetMonth(month);
		SetDay(day, countDayInMonth(month, year));
	}


	~Date() {

	}

	void EnterDate() {
		int day;
		int month;
		int year;
		int maxDay;
		cout << "День :";
		cin >> day;
		cout << "Месяц :";
		cin >> month;
		cout << "Год :";
		cin >> year;
		SetYear(year);
		SetMonth(month);
		SetDay(day, countDayInMonth(this->month, this->year));
	}

	void printDate() {
		cout << day << "-" << month << "-" << year << endl;
	}


	void operator=(Date obj) {
		this->day = obj.day;
		this->month = obj.month;
		this->year = obj.year;
	}

	int operator-(Date obj)
	{
		int firstDate = convertToDays(this->year, this->month, this->day);
		int secondDate = convertToDays(obj.year, obj.month, obj.day);
		return abs(firstDate - secondDate);
	}

	Date operator+(int days) {
		int nMaxDays(monthDays[this->month] + (this->month == FEB && checkLeapYear(this->year)));
		int nYear(this->year);
		int nMonth(this->month);
		int nDays(this->day + days);
		while (nDays > nMaxDays) {
			nDays -= nMaxDays;
			++nMonth;

			if (nMonth > MAX_MONTH) {
				nMonth = MIN_MONTH;
				++nYear;
			}
			nMaxDays = monthDays[nMonth] + (nMonth == FEB && checkLeapYear(nYear));
		}
		return Date(nDays, nMonth, nYear);
	}
};


class Menu
{
	const short int COUNT_MENU_POINT = 7;
	short int userChoice = 1;
public:

	void ShowWellcom()
	{
		cout << "==========================================================================";
		cout << endl << endl;
		cout << "\tКраткое описание\n"
			"Программа с помощью меню принимает значение двух дат\n"
			"Программа позволяет домавть дни к первой дате сохранив новое значение\n"
			"Программа позволяет вычислить количество дней между двумя датами\n"
			"Ну и программа позволяет вывести на экран обе даты\n";
		cout << "==========================================================================";
		cout << endl << endl;
	}

	void ShowMenu()
	{
		cout << endl;
		cout << "Меню программы" << endl;
		cout << "=============================================" << endl;
		cout << "1.  Введите первую дату;" << endl;
		cout << "2.  Введите вторую дату;" << endl;
		cout << "3.  Прибавить к дате дни;" << endl;
		cout << "4.  Подчитать разницу между датами;" << endl;
		cout << "5.  Вывести даты на экран;" << endl;
		cout << "6.  Очистить экран;" << endl;
		cout << "7.  Выход;" << endl;
		cout << "=============================================" << endl;
	}

	short int SetUserChoice(short int userChoice)
	{
		if (userChoice > 0 && userChoice <= COUNT_MENU_POINT)
		{
			this->userChoice = userChoice;
			return userChoice;
		}
		return 0;
	}
	void EnterUserChoice()
	{
		int userChoice;
		while (true)
		{
			cout << "Введите пункт меню: ";
			cin >> userChoice;
			if (SetUserChoice(userChoice)) break;
			cout << endl << "Вы ввели не корректный номер пункта меню." << endl;
			cout << "Допустимое значение должно быть в диапазоне от 1 до " << COUNT_MENU_POINT << ", пожалуйста, повторите ввод." << endl << endl;
		};
	}
	short int GetUserChoice()
	{
		return userChoice;
	}

	void waitAndClear() {
		system("pause");
		system("cls");
	}
};


enum MenuPoint {
	SET_FIRST_DATE = 1,
	SET_SECOND_DATE,
	ADDITION,
	SUBTRACTION,
	PRINTALL,
	CLEAR,
	EXIT
};

void loop() {
	Menu menu;
	Date firstDate;
	Date secondDate;
	int days;
	int daysAdd;
	menu.ShowWellcom();
	menu.waitAndClear();
	menu.ShowMenu();
	while (true) {
		menu.EnterUserChoice();
		switch (menu.GetUserChoice())
		{
		case SET_FIRST_DATE:
			cout << "----------" << endl;
			cout << "Введите дату\n";
			firstDate.EnterDate();
			cout << "Дата сохранена: ";
			firstDate.printDate();
			cout << "----------" << endl;
			break;
		case SET_SECOND_DATE:
			cout << "----------" << endl;
			cout << "Введите дату\n";
			secondDate.EnterDate();
			cout << "Дата сохранена: ";
			secondDate.printDate();
			cout << "----------" << endl;
			break;
		case ADDITION:
			cout << "----------" << endl;
			cout << "Текущая дата: ";
			firstDate.printDate();
			cout << "Введите кол-во дней: ";
			cin >> daysAdd;
			firstDate = firstDate + daysAdd;
			cout << "Дата изменилась: ";
			firstDate.printDate();
			cout << "----------" << endl;
			break;
		case SUBTRACTION:
			cout << "----------" << endl;
			days = firstDate - secondDate;
			cout << "Разность двух дат составляет: " << days << " дней\n";
			cout << "----------" << endl;
			break;
		case PRINTALL:
			cout << "----------" << endl;
			cout<< "Дата №1 : ";
			firstDate.printDate();
			cout << "Дата №2 : ";
			secondDate.printDate();
			cout << "----------" << endl;
			break;
		case CLEAR:
			menu.waitAndClear();
			menu.ShowMenu();
			break;
		case EXIT:
			exit(0);
			break;
		default:
			break;
		}
	}

}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	loop();
}
