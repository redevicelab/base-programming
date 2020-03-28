// В двухмерном массиве целых чисел, заполненном случайным образом целыми числами в диапазоне от – 900 до +900,
// посчитать сумму элементов:
//     1) в каждой строке
//     2) в каждом столбце
//     3) всех элементов по всем строкам и всем столбцам. 
// Оформить вывод информации следующим образом:
// 3   5   6   7   |   21
// 12  1   1   1   |   15
// 0   7   12  1   |   20
// ------------------------
// 15  13  19  9   |   56 


#include <iostream>
#include <ctime>

using namespace std;

const int ROW = 4;
const int COL = 4;
const int START_VALUE = -900;
const int FINAL_VALUE = 900;
const int PRECISION = 0;
const int NUMBER_OF_CHARACTERS_PER_TAB = 8;

float getRand(float startValue, float finalValue, int precision)
{
	float randomNumber;
	const int NUMBER_SYSTEM = 10;
	const int UPPER_BOUND_SHIFT = 1;
	int precisionFactor = pow(NUMBER_SYSTEM, precision);
	finalValue += UPPER_BOUND_SHIFT;
	int numbersAmount = (finalValue - startValue) *
		precisionFactor;
	randomNumber = rand() % numbersAmount + startValue *
		precisionFactor;
	randomNumber /= precisionFactor;
	return randomNumber;
}

void fillArr(int arr[][COL]) {

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++) {
			arr[i][j] = getRand(START_VALUE,FINAL_VALUE,PRECISION);
		}
	}
}

void printHorizontalLine() {
	for (int i = 0; i < COL * NUMBER_OF_CHARACTERS_PER_TAB + NUMBER_OF_CHARACTERS_PER_TAB; i++)
	{
		cout << "-";
	}
	cout << "\n";
}

void printFormatingRow(int value) {
	if (value >= 0) {
		cout << "|  " << value;
	}
	else cout << "| " << value;
}

void printFormatingCol(int value) {
	if (value >= 0) {
		cout << " " << value << "\t";
	}
	else cout << value << "\t";
}

void printTableArr(int arr[][COL]) {
	cout << endl;
	int sumRow;
	int sumCol;
	int total = 0;
	for (int i = 0; i < ROW; i++)
	{
		sumRow = 0;
		for (int j = 0; j < COL; j++) {
			if (arr[i][j] >= 0) {
				cout << " " <<arr[i][j] << "\t";
			}else cout << arr[i][j] << "\t";
			sumRow += arr[i][j];
		}
		total += sumRow;
		printFormatingRow(sumRow);
		cout << endl;
	}

	printHorizontalLine();

	for (int i = 0; i < COL; i++)
	{
		sumCol = 0;
		for (int j = 0; j < ROW; j++) {
			sumCol += arr[j][i];
		}
		printFormatingCol(sumCol);
	}
	printFormatingRow(total);
}

int main() {
	setlocale(LC_ALL, "ru");
	cout << "Программа выводит двумерный массив заполенный случайными числами в виде таблицы\nа так же сумму всех чисел по строкам и стобцам и общию сумму\n";
	srand(time(NULL));
	int arr[ROW][COL];
	fillArr(arr);
	printTableArr(arr);
	return 0;
}
