// Пользователь вводит любое целое число А. 
// Необходимо вывести все целые числа В, для которых А делиться без остатка на В*В и не делиться без остатка на В*В*В

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int userNumberA;
	int numberB = 1;

	cout << "Выводим все целые числа В, для которых А делиться без остатка на В*В и не делиться без остатка на В*В*В\n"
		"введите любое целое число А ";
	cin >> userNumberA;

	if (userNumberA > 3)
	{
		cout << "Числа соответствующие условиям = ";
	}
	else
	{
		cout << "Нет таких чисел";
		return 1;
	}

	for (userNumberA; userNumberA >= numberB * numberB; numberB++)
	{
		if (userNumberA % (numberB * numberB) == 0 && userNumberA % (numberB * numberB * numberB) != 0)
		{
			cout << numberB << " ";
		}
	}
	cout << endl;
	return 0;
}
