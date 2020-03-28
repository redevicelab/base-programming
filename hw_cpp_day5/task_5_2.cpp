// Написать программу, которая принимает одно число и определяет является ли это число положительным или отрицательным;

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int userVariable;
	cout << "Учебная программа\n"
		"Принимает одно число и определяет является ли это число положительным или отрицательным\n\n"
		"Введите число: ";
	cin >> userVariable;
	if (userVariable >= 0) {
		cout << "Число: " << userVariable << " - Положительное\n";
	}
	else cout << "Число: " << userVariable << " - Отрицательное\n";
	cout << "Программа завершена\n";
	return 0;
}
