// 1.	Программа, случайным образом, генерирует размер прибыли фирмы за месяц, в диапазоне от 10000 до 20000. Заполнить массив прибыли за 1 год. Вывести информацию о помесячной прибыли на экран.
// 2.	Дополнение к заданию 1.  Необходимо определить месяц, в котором прибыль была максимальна и месяц, в котором прибыль была минимальна.
// 3.	Дополнение к заданию 2. Программа позволяет пользователю ввести интересующий его период, статистика с какого по какой месяц его интересует, далее программа выводит информацию за интересующий пользователя период.

#include <iostream>
#include <ctime>

using namespace std;

const int MINIMAL_PROFIT = 10000;
const int MAXIMAL_PROFIT = 20000;
const int MONTHS_YEAR = 12;
const int PRECISION = 0;


float getRand(float startValue, float finalValue, int precision)
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

int shiftUp(int value) {
	const int BOUND_SHIFT = 1;
	return value += BOUND_SHIFT;
}

int shiftDown(int value) {
	const int BOUND_SHIFT = 1;
	return value -= BOUND_SHIFT;
}

void fillEveryMonthProfit(int array[]) {
	for (int i = 0; i < MONTHS_YEAR; i++) {
		array[i] = getRand(MINIMAL_PROFIT, MAXIMAL_PROFIT, PRECISION);
	}
}

void printEveryMonthProfit(int array[]) {
	const int ALIGN_TABLE = 9;
	cout << "Доход компании за год по месячно\n\n";
	for (int i = 0; i < MONTHS_YEAR; i++) {
		if (i >= ALIGN_TABLE) {
			cout << shiftUp(i) << "-й меc|";
		}
		else cout << shiftUp(i) << "-й меc |";
	}
	cout << endl;
	for (int i = 0; i < MONTHS_YEAR; i++) {
		
		cout << array[i] << "   |";
	}
	cout << endl << endl;
}

void printRangeMonthProfit(int array[], int startMouth = 1, int endMouth=12) {
	const int ALIGN_TABLE = 9;
	cout << "\nДоход компании за периуд с "<< startMouth <<"-го по "<< endMouth <<"-й месяц\n";
	for (int i = shiftDown(startMouth); i <= shiftDown(endMouth); i++) {
		if (i >= ALIGN_TABLE) {
			cout << shiftUp(i) << "-й меc|";
		}
		else cout << shiftUp(i) << "-й меc |";
	}
	cout << endl;
	for (int i = shiftDown(startMouth); i <= shiftDown(endMouth); i++) {

		cout << array[i] << "   |";
	}
	cout << endl << endl;
}

int findMaximumProfitMonth(int array[]) {
	int maximumProfit = 0;
	for (int i = 0; i < MONTHS_YEAR; i++) {
		if (maximumProfit < array[i]) {
			maximumProfit = array[i];
		}
	}
	return maximumProfit;
}

int findMinimumProfitMonth(int array[]) {
	int minimumProfit;
	minimumProfit = findMaximumProfitMonth(array);
	for (int i = 0; i < MONTHS_YEAR; i++) {
		if (minimumProfit > array[i]) {
			minimumProfit = array[i];
		}
	}
	return minimumProfit;
}

int findMonth(int array[], int profit) {
	int mouth;
	for (int i = 0; i < MONTHS_YEAR; i++) {
		if (array[i] == profit) {
			mouth = i;
		}
	}
	return shiftUp(mouth);
}

int checkInputUserValue() {
	int userValue;
	const int minimalWrongValue = 0;
	const int maximalWrongValue = 13;
	cin >> userValue;
	for (; userValue < minimalWrongValue || userValue > maximalWrongValue;) {
		cout << "Ошибка, пропробуйте снова, введите число от 1 до 12\n";
		cin >> userValue;
	}
	return userValue;
}

void userFindStatistic(int array[]) {
	int userStartPeriod;
	int userEndPeriod;
	cout << "Что бы узнать статистику за периуд введите начало периуда: ";
	userStartPeriod = checkInputUserValue();
	cout << "Что бы узнать статистику за периуд введите конец периуда: ";
	userEndPeriod = checkInputUserValue();
	printRangeMonthProfit(array, userStartPeriod, userEndPeriod);
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int annualIncome[MONTHS_YEAR];
	int maximumProfit, minimumProfit, maximumMouth, minimumMouth;
	cout << "Программа случайнна генерирует доход фирмы за год по месяцаи и позволяет вывождить простую статитстику\n\n";
	fillEveryMonthProfit(annualIncome);
	printEveryMonthProfit(annualIncome);
	maximumProfit = findMaximumProfitMonth(annualIncome);
	minimumProfit = findMinimumProfitMonth(annualIncome);
	maximumMouth = findMonth(annualIncome, maximumProfit);
	minimumMouth = findMonth(annualIncome, minimumProfit);
	cout << "Максимальный доход за "<< maximumMouth << "-й месяц и составил: " << maximumProfit << endl;
	cout << "Минимальный доход за " << minimumMouth << "-й месяц и составил: " << minimumProfit << endl;
	cout << endl;
	userFindStatistic(annualIncome);
}
