#include <iostream>
#include <ctime>

using namespace std;

const int ROW = 5;
const int COL = 5;
const int RANGE = 51;
const int SHIFT = 1;
const int FACTOR_FOR_FILL_ARRAY = 2;
const int FOR_EVENTY_CHECKING = 2;

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int firstArr[ROW][COL * FACTOR_FOR_FILL_ARRAY];
	int secondArr[ROW][COL];
	int counterColumn = 0;

	cout << "Вывод первного массива: \n";
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL * FACTOR_FOR_FILL_ARRAY; j++)
		{
			firstArr[i][j] = rand() % RANGE;
			cout << firstArr[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < ROW; i++)
	{
		counterColumn = 0;
		for (int j = 0; j < COL * FACTOR_FOR_FILL_ARRAY; j++)
		{
			if (j % FOR_EVENTY_CHECKING == 0) {
				secondArr[i][counterColumn] = firstArr[i][j + SHIFT] + firstArr[i][j];
				counterColumn++;
			}
		}
	}


	cout << "Вывод второго массива: \n";
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
			cout << secondArr[i][j] << "\t";
		cout << endl;
	}
}
