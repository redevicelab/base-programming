// Пользователь вводит с клавиатуры размер одного фильма в гигабайтах и скорость интернет-соединения в Мегабитах в секунду. 
// Посчитать, за сколько часов, минут и секунд скачается фильм. 
// ПОМНИТЕ. В одном гигабайте 1020 мегабайт, одном мегабайте 8 мегабит. 
// Не забывайте про использование КОНСТАНТ, магические числа ЗАПРЕЩЕНЫ и будут караться снижением баллов!

#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	const float QUANTITY_MEGA_IN_GIGA = 1024;
	const float QUANTITY_BYTE_IN_BIT = 8;
	const int QUANTITY_TIME_SYSTEM = 60;
	float fileSize;
	float bandwidth;
	int hour;
	int minute;
	int second;
	int totalSecond;
	cout << "-------------------------------------------------------------------------\n"
"Узнайте, за сколько времени можно скачать или закачать файл.\n"
"Рассчет проводится по весу файла в Gigabate и скорости интернет соединения в Mbps.\n"
"Числовые значение можно вводить дробные\n"
"------------------------------------------------------------------------------------\n\n"
"Введите размер файла: ";
	cin >> fileSize;
	cout << "Введите скорость приема данных: ";
	cin >> bandwidth;
	totalSecond = fileSize * QUANTITY_MEGA_IN_GIGA * QUANTITY_BYTE_IN_BIT / bandwidth;
	hour = totalSecond / (QUANTITY_TIME_SYSTEM * QUANTITY_TIME_SYSTEM);
	minute = (totalSecond / QUANTITY_TIME_SYSTEM) % QUANTITY_TIME_SYSTEM;
	second = totalSecond % QUANTITY_TIME_SYSTEM;
	cout << "\n\nВремя: " << hour << "ч " << minute << "мин " << second << "сек \n\n";
