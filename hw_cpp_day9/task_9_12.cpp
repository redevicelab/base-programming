/* Более коротка запись данной задачи  */
#include <iostream>

using namespace std;

const int DECIMAL_NOTATION = 10;
const int SEARCH_NUMBER = 0;

int main()
{
	setlocale(LC_ALL, "ru");
	int userNumber;
	float average;
	int verifiableNumber;
	int sum = 0;
	int counterDigit = 0;
	int counterSearch = 0;
    	cout << "Пользователь вводит любое число!\n"
"Прогрмма подсчитает сумму, кол-во цифр, среднее арефметическое, и количество нулей в числе \n\n"
		"Введите число: ";
	cin >> userNumber;
	while (userNumber < 0 || userNumber > 0) {
		verifiableNumber = userNumber % DECIMAL_NOTATION;
		sum += verifiableNumber;
		if (verifiableNumber == SEARCH_NUMBER) {
			counterSearch++;
		}
		userNumber /= DECIMAL_NOTATION;
		counterDigit++;
	}
	average = (float)sum / (float)counterDigit;
	cout << "Сумма цифр:\t\t" << sum << endl;
	cout << "Количество цифр:\t" << counterDigit << endl;
	cout << "Среднее арифмитическое:\t" << average << endl;
	cout << "Количество нулей:\t" << counterSearch << endl;
}
