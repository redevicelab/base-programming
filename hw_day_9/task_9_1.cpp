// Пользователь вводит число, сохранить это число в переменной. 
// Определить количество цифр в числе, введённом пользователем, 
// посчитать сумму и среднее арифметическое цифр, в ведённом пользователем числе. 
// Определить количество нулей в этом числе. Оформить красивый интерфейс. 
// (маленькая подсказка: для определения количества цифр в числе, необходимо использовать целочисленное деление, в цикле).
#include <iostream>

using namespace std;

const int DECIMAL_NOTATION = 10;
const int SEARCH_NUMBER = 0;

int getSum(int userNumber, int sum) {
	return sum += userNumber % DECIMAL_NOTATION;

}

float getAverage(float sum, float quantatyNumber) {
	return sum / quantatyNumber;
}


int findNumber(int userNumber, int counter) {
	int verifiableNumber = userNumber % DECIMAL_NOTATION;
	if (verifiableNumber == SEARCH_NUMBER) {
		counter++;
	}
	return counter;
}

void printResults(int userNumber) {
	int counterDigit = 0;
	int counterSearch = 0;
	int sum = 0;
	float average;
	while (userNumber < 0 || userNumber > 0) {
		sum = getSum(userNumber, sum);
		counterSearch = findNumber(userNumber, counterSearch);
		userNumber /= DECIMAL_NOTATION;
		counterDigit++;
	}
	average = getAverage(sum, counterDigit);
	cout << "Сумма цифр:\t\t" << sum << endl;
	cout << "Количество цифр:\t" << counterDigit << endl;
	cout << "Среднее арифмитическое:\t" << average << endl;
	cout << "Количество нулей:\t" << counterSearch << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int userNumber;
	cout << "Пользователь вводит любое число!\n"
		"Прогрмма подсчитает сумму, кол-во цифр, среднее арефметическое, и количество нулей в числе \n\n"
		"Введите число: ";
	cin >> userNumber;
	printResults(userNumber);
}
