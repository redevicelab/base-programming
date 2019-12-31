// Написать программу, заполняющую массив из 4-х элементов, случайными целыми значениями от -10 до +10. 
// Вывести содержимое массива на экран. Подсчитать сумму всех чисел в массиве и среднее арифметическое, вывести их на экран. 
// Затем сравнить каждое число массива со средним арифметическим и если оно меньше среднего арифметического, 
// заменить это число на ноль.

#include <iostream>
#include <ctime>

using namespace std;

const int START_VALUE = -10;
const int FINISH_VALUE = 10;
const int PRECISION = 0;
const int ARRAY_SIZE = 4;
const int REPLACEABLE_VALUE = 0;

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

float findAverage(float arraySum) {
	return arraySum / ARRAY_SIZE;
}

int findSum(int array[]) {
	int sum = 0;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		sum += array[i];
	}
	return sum;
}

void fillArray(int arr[]) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		arr[i] = getRand(START_VALUE,FINISH_VALUE,PRECISION);
	}
}

void replaceValueArray(int arr[], float average) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (arr[i] < average) {
			arr[i] = REPLACEABLE_VALUE;
		}
	}
}

void printArray(int arr[]) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		const int UPPER_BOUND_SHIFT = 1;;
		cout << i+UPPER_BOUND_SHIFT <<"-е занчение массива: " << arr[i] << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int arrayTask[ARRAY_SIZE];
	int sum;
	float average;
	cout << "Программа заполняющую массив из " << ARRAY_SIZE << "-х(-ти) элементов\n"
		"случайными целыми значениями от " << START_VALUE << " до +" << FINISH_VALUE <<"\n\n";
	fillArray(arrayTask);
	printArray(arrayTask);
	sum = findSum(arrayTask);
	cout << "\nСумма всех значение массива равно: " << sum << endl;
	average = findAverage(sum);
	cout << "\nСреднее арефметическое всех значений массива равно: " << average << endl;
	replaceValueArray(arrayTask, average);
	cout << "\nВывод массива с изменеными значениями если оно меньше среднего арифметического, заменяется это число на ноль. \n";
	printArray(arrayTask);
	return 0;
}