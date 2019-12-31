// Пользователь вводит целое число А. Программа должна определить, что куб суммы цифр этого числа равен А*А;

#include <iostream>

using namespace std;

const int BASE_TENS = 10;

int getSumDigits(int value) {
	int sum = 0;
	if (value < 0) {
		value = -value;
	}
	while (value > 0) {
		sum += value % BASE_TENS;
		value /= BASE_TENS;
	}
	return sum;
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Учебная программа. Пользователь вводит любое целое число\nПрограмма оперделит что куб суммы цифр этого числа равен А*А\nВведите число А: ";

	int userNumberA;
	cin >> userNumberA;

	int sum = getSumDigits(userNumberA);

	if (userNumberA * userNumberA == sum * sum * sum) {
		cout << "Куб суммы цифр числа. " << userNumberA << " РАВНО A*A" << endl;
	}
	else {
		cout << "Куб суммы цифр числа. " << userNumberA << " НЕРАВНО A*A" << endl;
	}
	return 0;
}
