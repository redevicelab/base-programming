// Напишите программу, которая принимает с клавиатуры число, а затем проверяет является ли введённое число кратным числу 3.

#include <iostream>

using namespace std;

const int MULTIPLE_NUMBER = 3;

int main()
{
	setlocale(LC_ALL, "ru");
	int userVariable;
	cout << "Учебная программа\n"
		"Принимает с клавиатуры число, а затем проверяет является ли введённое число кратным числу 3.\n\n"
		"Введите число: ";
	cin >> userVariable;
	if (userVariable % MULTIPLE_NUMBER) {
		cout << "Число НЕ кратное числу " << MULTIPLE_NUMBER <<"\n";
	}
	else cout << "Число КРАТНОЕ числу " << MULTIPLE_NUMBER << "\n";

	cout << "Программа выполнило свое предназначение\n";

	return 0;
}
