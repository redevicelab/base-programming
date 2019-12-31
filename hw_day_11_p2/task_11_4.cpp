// Пользователь вводит любое целое число. Необходимо из этого целого числа удалить все цифры 3 и 6 и вывести обратно на экран; 

#include <iostream>

using namespace std;

const int BASE_TENS = 10;
const int FIRST_DEL_DIGIT = 3;
const int SECOND_DEL_DIGIT = 6;

int main()
{
	setlocale(LC_ALL, "ru");
	int userNumber;
	int outputNumber = 0;

	cout << "Пользователь вводит любое целое число.\nНеобходимо из этого целого числа удалить\nвсе цифры " << FIRST_DEL_DIGIT << " и " << SECOND_DEL_DIGIT << "\nВведите число: ";
	cin >> userNumber;

	while (userNumber > 0)
	{
		if (userNumber % BASE_TENS != FIRST_DEL_DIGIT &&
			userNumber % BASE_TENS != SECOND_DEL_DIGIT)
		{
			outputNumber *= BASE_TENS;
			outputNumber += userNumber % BASE_TENS;
		}
		userNumber /= BASE_TENS;
	}

	cout << "Полученное число: ";

	while (outputNumber > 0)
	{
		cout << outputNumber % BASE_TENS;
		outputNumber /= BASE_TENS;
	}
	cout << endl;
	return 0;
}