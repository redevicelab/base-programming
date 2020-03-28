// С новым годом! Создать программу, которая выведет на экран треугольник из звёздочек, следующего вида «Ёлочки»:
//         *
//        ***
//       *****
//      *******
//     *********


#include <iostream>

using namespace std;
const int SHIFT = 2;

int main()
{
	setlocale(LC_ALL, "ru");
	int userValue;
	cout << "Приветствую пользователь это не простая программа, а НОВОГОДНЯЯ. \nВведите число и программа нарисует ЕЛОЧКУ такой высоты, которую вы зададите\nИ так Ваше число: ";
	cin >> userValue;
	for (int i = 0; i < userValue; i++)
	{
		for (int j = 0; j < userValue - i; j++)
			cout << ' ';
		for (int j = userValue - SHIFT * i; j <= userValue; j++)
			cout << '*';
		cout << endl;
	}
	cout << "С НОВЫМ ГОДОМ!!!\n\n";
	system("pause");
	return 0;
}
