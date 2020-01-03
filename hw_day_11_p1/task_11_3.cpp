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

int main()
{	
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int firstArr[ROW][COL * 2];
	int secondArr[ROW][COL];

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL * 2; j++)
		{
			firstArr[i][j] = rand()%50;
			cout << firstArr[i][j] << "\t";
			if (j % 2 != 0) {
				secondArr[i][j / 2] = firstArr[i][j - 1] + firstArr[i][j];
			}
		}
		cout << endl;
	}

	cout << "\nВторой массив\n";
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
			cout << secondArr[i][j] << "\t";
		cout << endl;
	}
}