// Написать приложение. Пользователь вводит с клавиатуры сумму в тенге и курс доллара.
// Приложение должно посчитать, сколько ЦЕЛЫХ долларов сможет купить пользователь на заданную сумму
// и сколько тенге он получит в качестве сдачи (центы не выдаются!). 

#include <iostream>

using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	int	currencyTenge;
	int currencyDollar;
	float exchangeRate;
	int change;
	cout << "Узнайте сколько можно получить целых долларов и сдачу при обмене Тенге\n"
			"Расчет производится по сумме в Тенге и курсу обмена Доллара\n"
			"-----------------------------------------------------------------\n\n"
			"Введите Сумму в Тенге: ";
	cin >> currencyTenge;
	cout << "Введите курс Доллара: ";
	cin >> exchangeRate;
	currencyDollar = currencyTenge / exchangeRate;
	change = currencyTenge - (currencyDollar * exchangeRate);
	cout << "\n\nНа указаную сумму в тенге можно купить: " << currencyDollar << "$\n";
	cout << "Сдача составит: " << change << " тг\n\n";
}
