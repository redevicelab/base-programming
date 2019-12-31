// Используя функции, написать программу с нижеследующей функциональностью. 
// Пользователь вводит с клавиатуры диаметр окружности. Посчитать площадь и периметр окружности. 
// Вывести на экран. Для расчёта периметра и площади окружности использовать отдельные функции.

#include <iostream>

using namespace std;

float getPerimeter(float diameter)
{
	const float NUMBER_PI = 3.1415;
	return NUMBER_PI * diameter;
}

float getSquare(float diameter)
{
	const float NUMBER_PI = 3.1415;
	const int NUMBER_FOR_CALCULATION_SQUARE = 4;
	diameter *= diameter;
	return (NUMBER_PI * diameter) / NUMBER_FOR_CALCULATION_SQUARE;
}

int main()
{
	setlocale (LC_ALL, "ru");
	float userNumber;
	cout << "Программа для расчета площади и периметра круга по его диаметру\n"
			"Данная программа работает и с веществеными числами\n"
			"---------------------------------------------------------------\n\n"
			"Введите диаметр круга: ";
	cin >> userNumber;
	cout << "\nПериметр круга равен: " << getPerimeter(userNumber) << "\n";
	cout << "Площадь круга равен: " << getSquare(userNumber) << "\n";
	return 0;
}