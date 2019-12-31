// Написать приложение, игру, «Лотерея: 2 из 3-х». 
// Программа принимает от пользователя три числа в диапазоне от 0 до 2 (включительно). 
// Затем программа сравнивает каждое введённое, пользователем, число со случайно сгенерированным от 0 до 2 (включительно) числом. 
// Для каждого сравнения генерируется новое случайное число. 
// Если два из введённых пользователем числа совпадают со случайным – пользователь выиграл.

#include <iostream>
#include <ctime>

using namespace std;

const int COINCIDENCE_VALUE = 2;
const int GENERATE_VALUE = 3;
const int ARRAY_SIZE = 3;

int compareUserValue(int userValues[]) {
	const int UPPER_BOUND_VALUE = 1;
	int generateNumber;
	int comparisonResult = 0;
	int iterator = 0;
	int plusOne = 1;

	generateNumber = rand() % GENERATE_VALUE;
	if (userValues[iterator] == generateNumber) {
		comparisonResult += plusOne;
		cout << "СОВПАДЕНИЕ   - ";
	}
	else cout << "НЕСОВПАДЕНИЕ - ";
	cout << iterator+UPPER_BOUND_VALUE << "-е значение пользователя " << userValues[iterator] << " и Случайное значение " << generateNumber << endl;

	generateNumber = rand() % GENERATE_VALUE;
	if (userValues[++iterator] == generateNumber) {
		comparisonResult += plusOne;
		cout << "СОВПАДЕНИЕ   - ";
	}
	else cout << "НЕСОВПАДЕНИЕ - ";
	cout << iterator + UPPER_BOUND_VALUE << "-е значение пользователя " << userValues[iterator] << " и Случайное значение " << generateNumber << endl;

	generateNumber = rand() % GENERATE_VALUE;
	if (userValues[++iterator] == generateNumber) {
		comparisonResult += plusOne;
		cout << "СОВПАДЕНИЕ   - ";
	}
	else cout << "НЕСОВПАДЕНИЕ - ";
	cout << iterator + UPPER_BOUND_VALUE << "-е значение пользователя " << userValues[iterator] << " и Случайное значение " << generateNumber << endl;
	return comparisonResult;
}

void findResult(int comparisonResult) {
	if (comparisonResult == COINCIDENCE_VALUE || comparisonResult == GENERATE_VALUE) {
		cout << "\nВЫ ВЫЙГРАЛИ\n";
	}
	else cout << "\nВЫ ПРОИГРАЛИ\n";
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int userValues[ARRAY_SIZE];
	int iterator = 0;
	int compareResult = 0;
	cout << "Лотерея: 2 из 3 - х\n"
		"Введите три часла от 0 до 2 включительно\n"
		"Если совпадут хотя бы два числа вы выйграли\n\n";
	cin >> userValues[iterator];
	cin >> userValues[++iterator];
	cin >> userValues[++iterator];
	compareResult = compareUserValue(userValues);
	findResult(compareResult);
}