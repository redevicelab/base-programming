// Написать имитацию кассового аппарата для магазина, торгующего новогодними товарами. Кассир должен:
//     a.	 выбрать товар из списка, 
//     b.	ввести его количество, 
//     c.	затем выбрать следующий товар. 
// По завершению ввода программа должна вывести на экран общую сумму покупки и вычислить сумму НДС равный 12%.
// Предусмотреть наличие скидки. 
// В списке товаров должно быть не меньше 4х товаров, должна отображаться их цена. 
// Предусмотреть обработку неправильно вводимых данных (номер вне списка товаров).
// Реализовать возможность обслуживания нескольких клиентов подряд, 
// т.е. после вывода итоговых данных одного покупателя предложить повторить операцию. 
// Программа должна подсчитывать общую выручку магазина, т.е. складывать сумму покупок всех покупателей.
// По завершении смены, программа должна выдать отчёт за смену, включающий, общую сумму всех покупок за смену, сумму НДС.

#include <iostream>

using namespace std;

const int LIST = 5;
const int SHIFT = 1;
const int DISCOUNT = 10;
const int MIN_FOR_DISCOUNT = 500;
const int MAX_VALUE = 9999;
const int MIN_INPUT_VALUE = 0;
const float VAT_RATE = 0.12;

int getSum(int userQty, int userList, int *price) {
	return userQty * price[userList - SHIFT];
}

void warehouseHandling(int *listQty, int userList, int userQty) {
	listQty[userList - SHIFT] -= userQty;
}

int getPayment(int purchase, int vat, int discount) {
	return purchase + vat - discount;
}

void printList(string *listProduct, int *listQty, int *price, int totalPurchase) {
	cout << "\tСписок товаров\n";
	cout << "---------------------------------------------\n";
	cout << "№ |" << "Наименование\t|" << "Цена\t|" << "Кол-во" << endl;
	for (int i = 0; i < LIST; i++) {
		cout << "---------------------------------------------\n";
		cout << i+SHIFT << ". "<<listProduct[i] << " \t| " << price[i] << " \t| "<< listQty[i] <<"\n";
	}
	cout << "ИТОГО: " << totalPurchase << endl;
}

void checkingInput(int userValue, int start, int finish) {
	while (userValue < start || userValue > finish) {
		cout << "Повторите ввод" << endl;
		cin >> userValue;
	}
}

int checkingProduct(int* listQty, int userList, int userQty) {
	while (true) {
		if (listQty[userList - SHIFT] < userQty) {
			cout << "Данного количество товара нет в наличии \n"
				"Повторите ввод количества: ";
			cin >> userQty;
		}
		else if (listQty[userList - SHIFT] < 0) {
			return 0;
			break;
		}
		else {
			return userQty;
			break;
		}
	}
}

int giveDiscount(int totalPurchase){
	if (totalPurchase >= MIN_FOR_DISCOUNT) {
		return totalPurchase / DISCOUNT;
	}
	else return 0;
}

int getVAT(int totalSum) {
	return totalSum * VAT_RATE;
}

void printResultPurchase(int totalPurchase, int discount, int totalPayment, int vat) {
	cout << "Общая сумма составила: " << totalPurchase << endl;
	cout << "Cкидка cоставляет " << discount << endl;
	cout << "Cумма НДС: " << vat << endl;
	cout << "Итого к оплате с учетом скидки и НДС " << totalPayment << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int userList;
	int userQty;
	string listProduct[LIST] = { "Хлеб","Молоко","Шоколад","Вода","Соки" };
	int listQty[LIST] = {150,100,500,500,400};
	int price[LIST] = {50,80,100,10,120};
	int totalPurchase;
	int totalPayment;
	bool runContinue;
	int vat = 0;
	int discount = 0;
	int proceeds = 0;
	cout << "Учебная программа \n реализация псевдокасовой системы.\n От пользователя теребуется вводить значение и ВНИМАТЕЛЬНО смотреть,\n что отвечает и запршивает программа\n\n\n";
	while (true) {
		totalPurchase = 0;
		totalPayment = 0;
		printList(listProduct, listQty, price, totalPurchase);
		cout << "Введите номер товара из списка: ";
		cin >> userList;
		checkingInput(userList, MIN_INPUT_VALUE, LIST);
		if (userList == 0) {
			system("cls");
			continue;
		}
		do {						
			userQty = 0;
			cout << "Введите количество покупаемого товара: ";
			cin >> userQty;
			checkingInput(userQty, MIN_INPUT_VALUE, MAX_VALUE);
			userQty = checkingProduct(listQty, userList, userQty);
			totalPurchase += getSum(userQty, userList, price);
			warehouseHandling(listQty, userList, userQty);
			cout << "ВВЕДИТЕ 0 ДЛЯ ЗАВЕРШЕНИЯ ОБСЛУЖИВАНИЯ ПОКУПАТЕЛЯ\n\tИЛИ\nВВЕДИТЕ СЛЕДУЮЩИЙ ТОВАР ИЗ СПИСКА: ";
			cin >> userList;
			checkingInput(userList, MIN_INPUT_VALUE, LIST);
			system("cls");
			printList(listProduct, listQty, price, totalPurchase);
		} while (userList > MIN_INPUT_VALUE);
		discount = giveDiscount(totalPurchase);
		vat = getVAT(totalPurchase);
		totalPayment += getPayment(totalPurchase,vat,discount);
		proceeds += totalPayment;
		printResultPurchase(totalPurchase, discount, totalPayment, vat);
		cout << "ВНИМАНИЕ ЕСЛИ ХОТИТЕ ПРОДОЛЖИТЬ ВВЕДИТЕ 1, ЕСЛИ ХОТЕТЕ ЗАВЕРШИТЬ СМЕНУ ВВЕДИТЕ 0\n";
		cin >> runContinue;

		checkingInput(runContinue, false, true);
		if (runContinue) {
			system("cls");
		}
		else break;
	}
	cout << "--------------------------------------------------\n";
	cout << "Итоги за смену\n";
	cout << "--------------------------------------------------\n";
	cout << "Итого выручка составила: " << proceeds << endl;
	system("pause");
}
