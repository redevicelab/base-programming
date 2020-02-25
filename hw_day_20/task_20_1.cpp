// Создать программу, принимающую от пользователя два значения, определяющих количество строк и столбцов двумерного массива.
// Создать динамический двумерный массив вещественных чисел заданных размеров.
// Заполнить созданный массив числами от -10 до +20, с одним знаком после запятой.
// Вывести на экран значения элементов массива.

#include <iostream>
#include <ctime>

using namespace std;

const int VAL_START = -10;
const int VAL_FINAL = 20;
const int PRECISION = 1;

float getRand(float startValue, float finalValue, int precision = 0)
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

float** getNewArr(int rows, int cols)
{
	float** newArr = new float* [rows];
	for (int i = 0; i < rows; i++)
	{
		newArr[i] = new float[cols];
	}
	if (newArr)
	{
		return newArr;
	}
	else
	{
		return NULL;
	}
}

void deleteArr(float** &arr, int rows, int cols) {

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void fillArr(float** &arr, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = getRand(VAL_START, VAL_FINAL, PRECISION);
		}
	}
}

void printArr(float** &arr, int rows, int cols) {
	cout << "\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n\n";
	}
	cout << "\n";
}

void printWellcome() {
	cout << "Программа от пользователя принимает два целочисленых числа,\n"
		"Первое число это кол-во строк массива\n"
		"Второе число это кол-во столбцов массива\n"
		"После ввода программа выведит массив слечайно заполнеными числами,\n"
		"от " << VAL_START << " до " << VAL_FINAL << " c " << PRECISION << " знаком(ми) после запятой\n"
		"Удачи.....\n\n";
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int userRows;
	int userCols;
	printWellcome();
	cout << "Введите поличество строк ";
	cin >> userRows;
	cout << "введите количество столбцов ";
	cin >> userCols;
	float** array = getNewArr(userRows, userCols);
	fillArr(array, userRows, userCols);
	printArr(array, userRows, userCols);
	deleteArr(array, userRows, userCols);
	return 0;
}

