// Написать программу, которая принимает три числа в массив и затем выводит на экран эти первое и последнее введённые числа;

#include <iostream>

using namespace std;

const int SIZE_ARRAY = 3;

int main()
{
	setlocale(LC_ALL, "ru");
	int iterator = 0;
	int array[SIZE_ARRAY];
	cout << "Учебная программа\n"
		"принимает три числа в массив и затем выводит на экран эти первое и последнее введённые числа\n\n"
		"Введите первое число: ";
	cin >> array[iterator];
	cout << "Введите второе число: ";
	cin >> array[++iterator];
	cout << "Введите третье число: ";
	cin >> array[++iterator];
	iterator = 0;
	cout << "\nПервое число - " << array[iterator] <<endl;
	++iterator;
	cout << "Последние число - " << array[++iterator] << endl;
	return 0;
}
