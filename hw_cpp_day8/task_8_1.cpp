// Написать программу, которая будет проверять знание таблицы умножения. Программа должна иметь следующую функциональность:
// Для теста, программа последовательно генерирует задание на умножение (случайные числа от 2 до 9) и ждёт ответа пользователя. 
// После ввода пользователем варианта ответа, программа не выводит результат сразу (верно, или неверно), 
// а задает следующее задание, всего 5 заданий. 
// После ввода ответа на 5-е задание, программа выводит пользователю таблицу, содержащую:
//     a.	заданный пример, 
//     b.	правильный ответ, 
//     c.	ответ пользователя, 
// Ниже таблицы даётся статистика теста: сколько было правильных и сколько не правильных ответов и оценку по 5-ти бальной шкале;
// Распределить всю программу по функциям, учитывайте правило: одна функция – одно дело.

#include <iostream>
#include <ctime>

using namespace std;

const int QUANTATY_TESTS = 5;
const int RANGE = 8;
const int FACTOR = 2;
const float FIVE_POINTS = 1;
const float FOUR_POINTS = 0.8;
const float THREE_POINTS = 0.6;
const float TWO_POINTS = 0.4;
const float ONE_POINTS = 0;

void printWelcome() {
	cout << "\tПрограмма тестирования на знание таблицы умножения.\n\n"
			"И так поехали.....\n\n";
}

void generateTests(int *multiplicand, int *multiplier, int *genAnswer, int *userAnswer) {
	for (int i = 0; i < QUANTATY_TESTS; i++)
	{
		multiplicand[i] = rand() % RANGE + FACTOR;
		multiplier[i] = rand() % RANGE + FACTOR;
		genAnswer[i] = multiplicand[i] * multiplier[i];
		cout << "Сколько будет: " <<multiplicand[i] << " * " << multiplier[i] << " = ";
		cin >> userAnswer[i];
	}
}

int findResult(int* genAnswer, int* userAnswer, int result) {
	for (int i = 0; i < QUANTATY_TESTS; i++)
	{
		if (genAnswer[i] == userAnswer[i]) {
			result++;
		}
	}
	return result;
}

void printResult(int result) {
	cout << "Количество правильных ответов:\t " << result << endl;
	cout << "Количество непрвельных ответов:\t " << QUANTATY_TESTS - result << endl;
}

void printRating(float result) {
	float rating = result / QUANTATY_TESTS;
	int point = 0;
	if (rating == FIVE_POINTS) {
		point = 5;
	}
	else if (rating < FIVE_POINTS && rating >= FOUR_POINTS) {
		point = 4;
	}
	else if (rating < FOUR_POINTS && rating >= THREE_POINTS) {
		point = 3;
	}
	else if (rating < THREE_POINTS && rating >= TWO_POINTS) {
		point = 2;
	}
	else if (rating < TWO_POINTS && rating >= ONE_POINTS) {
		point = 1;
	}
	cout << "\nОбщая оценка за тест: " << point << endl;
}

void printTable(int *arr,int *arr2, int *arr3, int *arr4) {
	cout << "\n\t-----------------------------------------------------------------";
	cout << "\n\t|Задание\t|" << "Правильный ответ\t|" << "Ответ пользователя\t|";
	cout << "\n\t-----------------------------------------------------------------\n";
	for (int i = 0; i < QUANTATY_TESTS; i++)
	{
		cout << "\t|"<<arr[i] << " x " << arr2[i] << "\t\t|" << arr3[i] << "\t\t\t|" << arr4[i] << "\t\t\t|" << endl;
	}
	cout << "\t-----------------------------------------------------------------\n\n";
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int userAnswer[QUANTATY_TESTS];
	int genAnswer[QUANTATY_TESTS];
	int multiplicand[QUANTATY_TESTS];
	int multiplier[QUANTATY_TESTS];
	int result = 0;
	float rating;
	printWelcome();
	generateTests(multiplicand, multiplier, genAnswer, userAnswer);
	result = findResult(genAnswer, userAnswer, result);
	printTable(multiplicand, multiplier, genAnswer, userAnswer);
	printResult(result);
	printRating(result);
	return 0;
}
