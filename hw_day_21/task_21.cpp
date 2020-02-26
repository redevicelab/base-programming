#include <iostream>

using namespace std;

enum Menu
{
	EXIT,
	SETTIME,
	ADDMIN,
	ADDSEC,
	PRINTTIME,
};

class Time
{
private:
	unsigned int hour = 0;
	unsigned int minute = 0;
	unsigned int second = 0;
	const int QTY_HOUR_DAY = 24;
	const int QTY_TIME = 60;
	const int QTY_SEC_IN_HOUR = 3600;
	const int FOR_PRINT_ZERO = 10;

public:

	void setHour(unsigned int value) {
		hour = value % QTY_HOUR_DAY;
	}

	void setMinute(unsigned int value) {
		minute = value % QTY_TIME;
	}

	void setSecond(unsigned int value) {
		second = value % QTY_TIME;
	}

	void addMinute(unsigned int value) {
		unsigned totalSecond;
		totalSecond = hour * QTY_SEC_IN_HOUR + minute * QTY_TIME + second;
		totalSecond = value * QTY_TIME + totalSecond;
		hour = totalSecond / (QTY_SEC_IN_HOUR) % QTY_HOUR_DAY;
		minute = totalSecond / QTY_TIME % QTY_TIME;
		second = totalSecond % QTY_TIME;
	}

	void addSecond(unsigned int value) {
		unsigned totalSecond;
		totalSecond = hour * QTY_SEC_IN_HOUR + minute * QTY_TIME + second;
		totalSecond = value + totalSecond;
		hour = totalSecond / (QTY_SEC_IN_HOUR) % QTY_HOUR_DAY;
		minute = totalSecond / QTY_TIME % QTY_TIME;
		second = totalSecond % QTY_TIME;
	}

	void printTime() {
		if (hour < FOR_PRINT_ZERO) cout << "\nВремя: 0" << hour << ":";
		else cout << "\nВремя: " << hour << ":";
		
		if (minute < FOR_PRINT_ZERO) cout << "0" << minute << ":";
		else cout << minute << ":";

		if (second < FOR_PRINT_ZERO) cout << "0" << second << "\n\n";
		else cout << second << "\n\n";
	}
};

void printWellcome() {
	cout <<
		"Учебная программа для работы с классами\n"
		"В данной программе предлагается установить время\n"
		"провести некоторые манипуляции со временем\n\n";
}

void printMenu() {
	cout <<
		"1-Задать часы минуты секунды\n"
		"2-Добавить минуты к заданному времени\n"
		"3-Добавить секунды к заданному времени\n"
		"4-Вывети на экран время формата ЧЧ:ММ:СС\n"
		"0-Выход из программы\n\n"
		"Введите пункт меню: " ;
}

void loop() {
	int userMenu;
	unsigned int userHour, userMinute, userSecond, userAddVal;
	Time clock;
	printWellcome();
	while (true)
	{
		printMenu();
		cin >> userMenu;
		switch (Menu(userMenu))
		{
		case EXIT:
			exit(0);
			break;
		case SETTIME:
			cout << "Введите часы: ";
			cin >> userHour;
			cout << "Введите Минуты: ";
			cin >> userMinute;
			cout << "Введите Секунды: ";
			cin >> userSecond;
			clock.setHour(userHour);
			clock.setMinute(userMinute);
			clock.setSecond(userSecond);
			cout << "Отлично... Параметры времени установлены\n";
			clock.printTime();
			system("pause");
			system("cls");
			break;
		case ADDMIN:
			cout << "Добавте количество минут к заданному времяни: ";
			cin >> userAddVal;
			clock.addMinute(userAddVal);
			cout << "Минуты добавлены\n";
			clock.printTime();
			system("pause");
			system("cls");
			break;
		case ADDSEC:
			cout << "Добавте количество секунд к заданному времяни: ";
			cin >> userAddVal;
			clock.addSecond(userAddVal);
			cout << "Секунды добавлены\n";
			clock.printTime();
			system("pause");
			system("cls");
			break;
		case PRINTTIME:
			clock.printTime();
			system("pause");
			system("cls");
			break;
		default:
			system("cls");
			break;
		}
	}
}

int main() {
	setlocale(LC_ALL,"ru");
	loop();
	return 0;
}