#include <iostream>
#include <ctime>

using namespace std;

const int START_RANGE_ARR = 10;
const int FINISH_RANGE_ARR = 30;
const int START_VAL = 15;
const int FINISH_VAL = 30;

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

int* getNewArr(int arrSize) {
	int* newArr = new int[arrSize];
	if (newArr) {
		return newArr;
	}
	else
	{
		return NULL;
	}
}

void pushBack(int*& arr, int& size, int value) {
	int shift = 1;
	int* newArr = getNewArr(size + shift);
	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	newArr[size] = value;
	size++;
	delete[]arr;
	arr = newArr;
}

void fillArr(int* arr, int arrSize) {
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = getRand(START_VAL, FINISH_VAL);
	}
}

void fillArr(int* arrA, int* arrB, int*& arrC, int sizeA, int sizeB, int& sizeC)
{

	for (int i = 0; i < sizeA; i++)
	{
		bool firstRepeat = false;
		bool secondRepeat = false;
		for (int j = 0; j < sizeB; j++)
		{
			if (arrA[i] == arrB[j])
			{
				firstRepeat = true;
			}
			for (int k = 0; k < sizeC; k++)
			{
				if (arrA[i] == arrC[k])
				{
					secondRepeat = true;
				}

			}

		}
		if (!firstRepeat && !secondRepeat)
		{
			pushBack(arrC, sizeC, arrA[i]);
		}
	}
}




void printArr(int* arr, int arrSize) {
	cout << "\nArray: ";
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << "\n";
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	cout << "Приветную тебя дорогой пользователь. Это программа, делает вот что:\n"
		"Случайным образом создает динамический массивы и также случайным образом заполняет массивы в количестве 2 шт.\n"
		"Потом это необыкновенная программа создает третий динамический массив и тоже его заполняет,\n"
		"но только вот каким хитрым способом.Программа сравнивает есть ли не одинаковые числа в первом массиве \n"
		"в сравнеии со вторым массивом,и если есть оно то это число добавляется в третий массив, но без повторений.\n"
		"И так вот он РЕЗУЛЬТАТ :\n";

	int M = getRand(START_RANGE_ARR, FINISH_RANGE_ARR);
	int N = getRand(START_RANGE_ARR, FINISH_RANGE_ARR);
	int K = 0;
	int* A = getNewArr(M);
	int* B = getNewArr(N);
	int* C = getNewArr(K);
	fillArr(A, M);
	fillArr(B, N);
	printArr(A, M);
	printArr(B, N);
	fillArr(A, B, C, M, N, K);
	printArr(C, K);
	delete[]A;
	delete[]B;
	delete[]C;
	return 0;
}
