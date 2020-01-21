/* 
Используя указатель на массив целых чисел, изменить порядок следования элементов массива на противоположный.
Изменить сам массив, а не просто вывести значения массива в обратном порядке.
Для продвижения по массиву, использовать в программе только арифметику указателей, а также оператор разыменования.
 */


#include <iostream>

const int ARR_SIZE = 10;
const int RANGE = 10;
const int SHIFT = 1;
const int HALF_ARRAY = 2;

using namespace std;

void fillArr(int* pArr) {
	for (int i = 0; i < ARR_SIZE; i++)
	{
		*(pArr + i) = rand() % RANGE;
	}
}

void printArr(int* pArr) {
	for (int i = 0; i < ARR_SIZE; i++)
	{
		cout << *(pArr + i) << "\t";
	}
	cout << endl;
}

void mySwap(int* firstVal, int *secondval) {
	*firstVal = *firstVal + *secondval;
	*secondval = *firstVal - *secondval;
	*firstVal = *firstVal - *secondval;
}

void swapArr(int* pArr) {
	for (int i = 0; i < ARR_SIZE / HALF_ARRAY; i++)
		mySwap((pArr + i), pArr+(ARR_SIZE - i - SHIFT));
}

int main() {
	setlocale(LC_ALL, "ru");
	int arr[ARR_SIZE];
	cout << "Программа создает массив 10 элементов, затем используя указатели изменяет\nпорядок следования элементов на противоположный.\n\n";
	fillArr(arr);
	cout << "Вывод массива:\t\t\t";
	printArr(arr);
	cout << endl;
	swapArr(arr);
	cout << "Вывод массива с измененым\nпорядком следования элементов:\t";
	printArr(&arr[0]);
	return 0;
}