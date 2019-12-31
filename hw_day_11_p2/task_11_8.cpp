// Пользователь вводит два целых числа. Необходимо вывести все целые числа, на которые оба введенных числа делятся без остатка.

#include <iostream>

using namespace std;

int checkNegativNum(int value) {
	if (value < 0) {
		value = -value;
	}
	return value;
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Пользователь вводит два целыx числа. Необходимо вывести все целые числа,\nна которое заданные числа делиться без остатка\nВведите первое число: ";
	int firstUserValue, secondUserValue, counter;
	cin >> firstUserValue;
	firstUserValue = checkNegativNum(firstUserValue);
	cout << "Введите второе число: ";
	cin >> secondUserValue;
	secondUserValue = checkNegativNum(secondUserValue);
	cout << "Числа на которые оба числа делятся без остатка: " << endl;
	if (firstUserValue > secondUserValue) {
		counter = firstUserValue;
	}
	else counter = secondUserValue;
	for (int i = -counter; i <= counter; i++) {
		if (i == 0) continue;
		if (firstUserValue % i == 0 && secondUserValue % i == 0) {
			cout << i << ' ';
		}
	}
	cout << endl;
	return 0;
}
