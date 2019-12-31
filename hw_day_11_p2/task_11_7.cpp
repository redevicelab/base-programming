// Пользователь вводит целое число. Необходимо вывести все целые числа, на которое заданное число делиться без остатка;

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Пользователь вводит целое число. Необходимо вывести все целые числа,\nна которое заданное число делиться без остатка\nВведите число: ";
	int userValue;
	cin >> userValue;
	cout << "Числа на которые число делятся без остатка: " << endl;
	if (userValue < 0) {
		userValue = -userValue;
	}
	for (int i = -userValue; i <= userValue; i++) {
		if (i == 0) continue;
		if (userValue % i == 0) {
			cout << i << ' ';
		}
	}
	cout << endl;
	return 0;
}
