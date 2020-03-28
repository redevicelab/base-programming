// Написать программу, которая принимает, от пользователя, 
// в массив два числа, а затем меняет местами в массиве эти два числа, 
// т.е. число лежащее в нулевой ячейке переносится в первую ячейку, 
// а число лежащее в первой ячейке переносится в нулевую.

#include <iostream>

using namespace std;

const int SIZE_ARRAY = 2;

int main()
{
	setlocale(LC_ALL, "ru");
	int iterator = 0;
	int buffer;
	int userArray[SIZE_ARRAY];
	cout << "Учебная программа\n"
		"Пользователь вводит в массив два числа, программа меняет местами в массиве эти два числа.\n\n"
		"Введите число для ячейки с индексом 0: ";
	cin >> userArray[iterator];
	cout << "Введите число для ячейки с индексом 1: ";
	cin >> userArray[++iterator];
	buffer = userArray[0];
	userArray[0] = userArray[1];
	userArray[1] = buffer;
	cout << "\nВывод содержимого ячейки с индексом 0: " << userArray[0]<< endl;
	cout << "Вывод содержимого ячейки с индексом 1: " << userArray[1]<< endl;
	return 0;
}
