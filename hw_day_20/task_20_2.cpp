// Создать программу, принимающую от пользователя три значения, определяющих количество страниц,
// строк и столбцов трёхмерного массива. Создать динамический трёхмерный массив вещественных чисел заданных размеров.
// Заполнить созданный массив числами от -5 до +6, с двумя знаками после запятой. Вывести на экран значения элементов массива.

#include <iostream>
#include <ctime>

using namespace std;

const int VAL_START = -5;
const int VAL_FINAL = 6;
const int PRECISION = 2;

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

float*** getNewArr(int list, int rows, int cols)
{
	float*** newArr = new float** [list];
	for (int i = 0; i < list; i++)
	{
		newArr[i] = new float*[rows];
		
	}
	for (int i = 0; i < list; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			newArr[i][j] = new float[cols];
		}
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

void deleteArr(float*** &arr, int list, int rows) {//////

	for (int i = 0; i < list; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			delete[] arr[i][j];
		}
	}

	for (int i = 0; i < list; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void fillArr(float*** &arr, int list, int rows, int cols) {
	for (int i = 0; i < list; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			for (int k = 0; k < cols; k++)
			{
				arr[i][j][k] = getRand(VAL_START, VAL_FINAL, PRECISION);
			}
		}
	}
}

void printArr(float*** &arr, int list, int rows, int cols) {
	cout << "\n";
	for (int i = 0; i < list; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			for (int k = 0; k < cols; k++)
			{
				cout << arr[i][j][k] << "\t";
			}
			cout << "\n\n";
		}
		cout << "---------------------------------------------------------------------------\n\n";
	}
	cout << "\n";
}

void printWellcome() {
	cout << "Программа от пользователя принимает три целочисленых числа,\n"
		"Первое число это кол-во страниц\n"
		"Второе число это кол-во строк массива\n"
		"Третье число это кол-во столбцов массива\n"
		"После ввода программа выведит массив трехмерный случайно заполнеными числами,\n"
		"от " << VAL_START << " до " << VAL_FINAL << " c " << PRECISION << " знаком(ми) после запятой\n"
		"Удачи.....\n\n";
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int userRows;
	int userCols;
	int userList;
	printWellcome();
	cout << "Введите количество страниц ";
	cin >> userList;
	cout << "Введите поличество строк ";
	cin >> userRows;
	cout << "введите количество столбцов ";
	cin >> userCols;
	float*** array = getNewArr(userList,userRows, userCols);
	fillArr(array, userList, userRows, userCols);
	printArr(array, userList, userRows, userCols);
	deleteArr(array, userList, userRows);
	return 0;
}
