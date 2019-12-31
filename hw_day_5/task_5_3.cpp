// Написать программу, которая принимает 4 числа в массив и затем сравнивает, что больше, 
// сумма первых двух чисел, или сумма двух последних чисел. 
// Обе суммы, обязательно, выводить на экран перед сравнением;

#include <iostream>

using namespace std;

const int SIZE_ARRAY = 4;


int main()
{
	setlocale(LC_ALL, "ru");
	int iterator = 0;
	int userArray[SIZE_ARRAY];
	cout << "Учебная программа\n"
			"Принимает 4 числа в массив и затем сравнивает, что больше, сумма первых двух чисел, или сумма двух последних чисел.\n\n"
			"Введите первое число: ";
	cin >> userArray[iterator];
	cout << "Введите второе число: ";
	cin >> userArray[++iterator];
	cout << "Введите третье число: ";
	cin >> userArray[++iterator];
	cout << "Введите четвертое число: ";
	cin >> userArray[++iterator];
	cout << "\nСумма первых двух чисел = " << userArray[0] + userArray[1] << endl;
	cout << "Сумма поледних двух чисел = " << userArray[2] + userArray[3] << endl;
	if (userArray[0] + userArray[1] > userArray[2] + userArray[3]) {
		cout << "\nCумма первых двух чисел больше\n";
	}
	else if (userArray[0] + userArray[1] == userArray[2] + userArray[3]) {
		cout << "\nCуммы первых и последних двух чисел равны\n";
	}
	else cout << "\nСумма последних двух чисел больше\n";
	return 0;
}
