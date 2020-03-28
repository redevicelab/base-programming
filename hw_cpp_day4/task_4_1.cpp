// Используя функции, написать программу с нижеследующей функциональностью. 
// Пользователь вводит цены 10-ти плиток шоколада, 5 литров сока. 
// Программа должна вычислять стоимость: 
//     a.	одной покупки из 3-х плиток шоколада и 21,5 литра сока; 
//     b.	4-х покупок, каждая из 6-ти плиток шоколада и 2-х литров соков.

#include <iostream>

using namespace std;

int const BASE_CHOCOLADE = 10;
int const BASE_JUICE = 5;
int const THREE_CHOCOLADE = 3;
float const TWENTY_ONE_POINT_FIVE_JUICE = 21.5;
int const SEX_CHOCOLADE = 6;
int const TWO_JUICE = 2;
int const ONE_BUY = 1;
int const FOUR_BUY = 4;

float countingPriсeOneProduct(float totalPrice, float product) {
	return totalPrice / product;
}

float countingTotalCost(float priceChoco, float priceJuice , float quantityChoco , float quantityJuice, int quantityBuy) 
{
	return (((countingPriсeOneProduct(priceChoco, BASE_CHOCOLADE) * quantityChoco) + 
				(countingPriсeOneProduct(priceJuice, BASE_JUICE) * quantityJuice))* quantityBuy);
}

int main()
{
	int totalPriceChoco, totalPriceJuice;
	setlocale(LC_ALL, "ru");
    cout << "Учебная программа\n"
		"Пользователь вводит цены 10 - ти плиток шоколада, 5 литров сока.\n"
		"Программа вычисляет стоимость:\n"
		"1. Стоимость одной покупки из 3-х плиток шоколада и 21,5 литров сока.\n"
		"2. Стоисомть четырех покупок из 6-ти плиток шоколада и 2-х литров сока\n"
		"-----------------------------------------------------------------------\n\n"
		"Введите стоимость 10-ти плиток шоколада: ";
	cin >> totalPriceChoco;
	cout << "Введите стоимость 5-ти литров сока: ";
	cin >> totalPriceJuice;
	cout << "\nСтоимость одной покупки из 3 - х плиток шоколада и 21,5 литров сока составляет: " << countingTotalCost(totalPriceChoco,totalPriceJuice,THREE_CHOCOLADE,TWENTY_ONE_POINT_FIVE_JUICE,ONE_BUY) << endl;
	cout << "Стоисомть четырех покупок из 6-ти плиток шоколада и 2-х литров сока составляет: " << countingTotalCost(totalPriceChoco,totalPriceJuice,SEX_CHOCOLADE,TWO_JUICE,FOUR_BUY)<< endl;
}
