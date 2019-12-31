// Используя функции и операцию целочисленного деления, написать программу с нижеследующей функциональностью. 
// Пользователь вводит с клавиатуры время в секундах, прошедшее с начала дня. 
// Вывести на экран текущее время в часах, минутах и секундах. Посчитать, сколько часов, минут и секунд осталось до полуночи.

#include <iostream>

using namespace std;

void getCurrentTime(int totalSecond)
{
	const int BASE_TIME = 60;
	const int BASE_HOUR_IN_DAY = 24;
	int hour;
	int minute;
	int second;
	hour = totalSecond / (BASE_TIME * BASE_TIME) % BASE_HOUR_IN_DAY;
	minute = (totalSecond / BASE_TIME) % BASE_TIME;
	second = totalSecond % BASE_TIME;
	cout << "\nТекущее время:\t" << hour << "ч " << minute << "мин " << second << "сек \n\n";
}

void getMidnightTime(int totalSecond)
{
	const int BASE_TIME = 60;
	const int BASE_HOUR_IN_DAY = 24;
	const int QUATATY_SENCONDS_DAY = 86400;
	int hour;
	int minute;
	int second;
	totalSecond = totalSecond % QUATATY_SENCONDS_DAY;
	int midnightSecond = QUATATY_SENCONDS_DAY - totalSecond;
	hour = midnightSecond / (BASE_TIME * BASE_TIME) % BASE_HOUR_IN_DAY;
	minute = (midnightSecond / BASE_TIME) % BASE_TIME;
	second = midnightSecond % BASE_TIME;
	cout << "\nВремя до полуночи: " << hour << "ч " << minute << "мин " << second << "сек \n\n";
}

int main()
{
	setlocale(LC_ALL, "ru");
	int userTimeSecond;
	cout << "Введите кол-во секунд от начала дня и узнайте текущие время в часах минутах и секундах,\n"
		"а также узнайте сколько часов минут и секунд отсалось до полуночи\n"
		"-----------------------------------------------------------------------------------------\n"
		"Введите кол-во секунд от начала для: ";
	cin >> userTimeSecond;
	getCurrentTime(userTimeSecond);
	getMidnightTime(userTimeSecond);
	return 0;
}
