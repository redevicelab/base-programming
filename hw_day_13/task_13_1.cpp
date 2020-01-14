// 1.	Необходимо создать массив вещественных чисел, размером  10 элементов, затем
// a.	заполнить массив случайными значениями в диапазоне от -10 до +20, с одним знаком после запятой;
// b.	вывести на экран значения элементов массива;
// c.	отсортировать массив с использованием метода сортировки выбором;
// d.	вывести на экран отсортированный массив;
// e.	получить от пользователя число в диапазоне от -10 до +20, с одним знаком после запятой4;
// f.	найти в массиве индекс введённого пользователем числа, если оно есть в массиве, если нет, сообщить об этом пользователю.
// Поиск осуществлять методом бинарного поиска. 



#include <iostream>
#include <ctime>

using namespace std;

const int ARR_SIZE = 10;
const int START_VAL = -10;
const int FINAL_VAL = 20;
const int PRECISION = 1;

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



void printArr(float* arr) {
	for (int i = 0; i < ARR_SIZE; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void fillArr(float* arr) {
	for (int i = 0; i < ARR_SIZE; i++) {
		arr[i] = getRand(START_VAL, FINAL_VAL, PRECISION);
	}
}

void selectionSort(float* arr) {
	int minElement;
	for (int i = 0; i < ARR_SIZE; i++)
	{
		minElement = i;
		for (int j = i; j < ARR_SIZE; j++)
		{
			if (arr[j] < arr[minElement]) {
				minElement = j;
			}
		}
		if (i != minElement) {
			arr[i] = arr[minElement] + arr[i];
			arr[minElement] = arr[i] - arr[minElement];
			arr[i] = arr[i] - arr[minElement];
		}
	}
}


void binatySearch(float* arr, float desiredValue) {
	const int SHIFT = 1;
	const int MIDDLE = 2;
	int midIndex = ARR_SIZE / MIDDLE;
	int lowIndex = 0;
	int highIndex = ARR_SIZE;

	while (arr[midIndex] != desiredValue && lowIndex <= highIndex) {
		if (desiredValue > arr[midIndex]) {
			lowIndex = midIndex + SHIFT;
		}
		else highIndex = midIndex - SHIFT;

		midIndex = (lowIndex + highIndex) / MIDDLE;
	}
	if (lowIndex > highIndex) {
		cout << "Искомое значение не найдено :(\n";
	}
	else cout << "Индекс искомого значение равен: " << midIndex << endl;
}

int main() {
	setlocale(LC_ALL, "ru");
	float userVal;
	float arr[ARR_SIZE];
	cout << "Программа генерирует массив размером " << ARR_SIZE << " и заполняет его значениями от " << START_VAL << " до " << FINAL_VAL << " с " << PRECISION << " знаком(ми) после запятой.\n";
	srand(time(NULL));
	fillArr(arr);
	cout << "\nВывод массива: \n\n";
	printArr(arr);
	selectionSort(arr);
	cout << "\nВывод массива cортированого: \n\n";
	printArr(arr);
	cout << "\nВведите число для поиска по массиву, индекса с этим числом: ";
	cin >> userVal;
	binatySearch(arr, userVal);
	return 0;
}