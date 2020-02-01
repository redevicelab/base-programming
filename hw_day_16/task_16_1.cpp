// Даны два массива : а[m] и b[n](m и n, т.е.размерности массива генерируются случайно,
// в диапазоне от 10 до 30).Оба массива заполняются случайными, целыми числами в диапазоне
// от 5 до 20. Необходимо создать третий массив, минимально необходимого размера, в котором
// нужно собрать, без повторений, общие значения(общие – это такие значения, которые есть
// в обоих массивах) элементов двух массивов.

#include <iostream>
#include <ctime>

using namespace std;

const int START_RANGE_ARR = 10;
const int FINISH_RANGE_ARR = 30;
const int START_VAL = 5;
const int FINISH_VAL = 20;

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

int* getNewArr(int arrSize)
{
	int* newArr = new int[arrSize];
	if (newArr)
	{
		return newArr;
	}
	else
	{
		return NULL;
	}
}

void pushBack(int*& arr, int& size, int value)
{
	int shift = 1;
	int* newArr = getNewArr(size + shift);
	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	newArr[size] = value;
	size++;
	delete[] arr;
	arr = newArr;
}

void fillArr(int* arr, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = getRand(START_VAL, FINISH_VAL);
	}
}

void fillArr(int* arrA, int* arrB, int*& arrC, int sizeA, int sizeB, int& sizeC)
{

	for (int i = 0; i < sizeA; i++)
	{
		int flag = 0;
		for (int j = 0; j < sizeB; j++)
		{
			if (arrA[i] == arrB[j])
			{
				for (int k = 0; k < sizeC; k++)
				{
					if (arrA[i] == arrC[k])
					{
						flag = 1;
					}
				}
				if (flag == 0)
				{
					pushBack(arrC, sizeC, arrA[i]);
				}
			}
		}
	}
}

void printArr(int* arr, int arrSize)
{
	cout << "\nArray: ";
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << "\n";
}

int main()
{
	srand(time(NULL));
	int m = getRand(START_RANGE_ARR, FINISH_RANGE_ARR);
	int n = getRand(START_RANGE_ARR, FINISH_RANGE_ARR);
	int k = 0;
	int* a = getNewArr(m);
	int* b = getNewArr(n);
	int* c = getNewArr(k);
	fillArr(a, m);
	fillArr(b, n);
	printArr(a, m);
	printArr(b, n);
	fillArr(a, b, c, m, n, k);
	printArr(c, k);
	delete[] a;
	delete[] b;
	delete[] c;
	return 0;
}

//int K = 0;
//for (int i = 0; i < size; i++)
//{
//	int flag = 0;
//	for (int j = 0; j < size; j++)
//	{
//		if (a[i] == b[j]) {
//			for (int k = 0; k < size; k++)
//			{
//				if (a[i] == c[k]) {
//					flag = 1;
//				}
//			}
//			if (flag == 0) {
//				c[K] = a[i];
//				K++;
//			}
//		}
//
//	}
//
//}


//for (int i = 0; i < size; i++)
//{
//	int flag = 0;
//	for (int j = 0; j < size; j++)
//	{
//		if (a[i] == b[j]) {
//			for (int k = 0; k < sizeC; k++)
//			{
//				if (a[i] == c[k]) {
//					flag = 1;
//				}
//			}
//			if (flag == 0) {
//				pushBack(c, sizeC, a[i]);
//			}
//		}
//
//	}
//
//}
