/* 
Написать программу определяющую наибольшее из трёх чисел с помощью указателей.
Задание примитивное, поэтому сделайте красиво и аккуратно!
 */
#include <iostream>

using namespace std;

void findGreatest(int* pfirstVal, int* psecondVal, int* pthirdVal, int* pgreatestVal) {
	(*pfirstVal > * psecondVal) ? *pgreatestVal = *pfirstVal : *pgreatestVal = *psecondVal;
	if (*pgreatestVal < *pthirdVal) *pgreatestVal = *pthirdVal;
}

int main() {
	setlocale(LC_ALL, "ru");
	int firstVal;
	int secondVal;
	int thirdVal;
	int greatestVal;
	cout << "Программа принимает от пользователя 3 числа, и находит какое число больше и выводит его на экран.\nВведите первое число:\t";
	cin >> firstVal;
	cout << "Введите второе число:\t";
	cin >> secondVal;
	cout << "Введите третье число:\t";
	cin >> thirdVal;
	findGreatest(&firstVal, &secondVal, &thirdVal, &greatestVal);
	cout << "Наибольшее число: " << greatestVal << endl;
	return 0;
}