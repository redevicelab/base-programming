// Подсчитать количество целых чисел в диапазоне от 100 до 999 у которых все цифры разные
#include<iostream>

using namespace std;

const int BASE_HUNDREDS = 100;
const int BASE_TENS = 10;

int main() {
	setlocale(LC_ALL, "ru");
	int result = 0;
	int firstNum, secondNum, thirdNum;
	int startValue = 100;
	int finalValue = 999;
	cout << "Учебная программа которая выводить количество целых чисел в диапазоне от 100 до 999 все цифры разные\n\n";
	while (startValue <= finalValue)
		{
			firstNum = finalValue / BASE_HUNDREDS;
			secondNum = (finalValue % BASE_HUNDREDS) / BASE_TENS;
			thirdNum = finalValue % BASE_TENS;
			if (firstNum != secondNum && secondNum != thirdNum && thirdNum != firstNum) {
				result++;
			}
			finalValue--;
		}
	cout << "Результат: " << result << endl;

	system("pause");
	return 0;
}