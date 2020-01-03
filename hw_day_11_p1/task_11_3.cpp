// Напишите программу, в которой объявляется массив размером 5х10 и массив размером 5х5. 
// Первый массив заполняется случайными числами, в диапазоне от 0 до 50. 
// Второй массив заполняется по следующему принципу: 
// первый элемент второго массива равен сумме первого и второго элемента первого массива, 
// второй элемент второго массива равен сумму третьего и четвертого элемента первого массива и тд.


#include <iostream>
#include <ctime>

using namespace std;

const int ROW = 5;
const int COL = 5;
const int RANGE = 51;
const int SHIFT = 1;
const int FACTOR_FOR_FILL_ARRAY = 2;
const int FOR_ODDITY_CHECKING = 2;

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int firstArr[ROW][COL * FACTOR_FOR_FILL_ARRAY];
	int secondArr[ROW][COL];

	cout << "Вывод первного массива: \n";
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL * FACTOR_FOR_FILL_ARRAY; j++)
		{
			firstArr[i][j] = rand() % RANGE;
			cout << firstArr[i][j] << "\t";
			if (j % FOR_ODDITY_CHECKING != 0) {
				secondArr[i][j / FACTOR_FOR_FILL_ARRAY] = firstArr[i][j - SHIFT] + firstArr[i][j];
			}
		}
		cout << endl;
	}

	cout << "Вывод второго массива: \n";
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
			cout << secondArr[i][j] << "\t";
		cout << endl;
	}
}