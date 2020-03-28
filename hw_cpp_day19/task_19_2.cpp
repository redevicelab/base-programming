#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

const int STR_SIZE = 256;
const int SHIFT = 1;

enum Bathroom {
	SEPARETED,
	COMBINED
};

enum Decoration {
	WITHOUT_REPAIR,
	ORDINARY,
	LUXE
};

enum Menu {
	EXIT,
	ADD_NEW_APART,
	LIST_APART,
	SEARCH_APART_AREA,
	SEARCH_APART_CITY,
	SORT_APART_PRICE,
	CLEAR = 9,
};

struct Apartment
{
	char city[STR_SIZE];
	char area[STR_SIZE];
	float totalArea;
	float effectiveArea;
	float kitchenArea;
	Bathroom bathroom;
	int floor;
	int numberOfStoreys;
	Decoration decoration;
	double price;
};

Apartment addApartment() {
	Apartment temp;
	char tempBathroom;
	char tempDecoration;
	cout << "Для создание записи информации об квартире введите последовательно указаные пункты" << endl;
	cout << "Город ";
	gets_s(temp.city,STR_SIZE);
	cout << "Район ";
	gets_s(temp.area,STR_SIZE);
	cout << "Общая площадь ";
	cin >> temp.totalArea;
	cout << "Жилая площадь ";
	cin >> temp.effectiveArea;
	cout << "Площадь кухни ";
	cin >> temp.kitchenArea;
	do
	{
		cout << "Выбирите тип санузла\n"
			"s - раздельный санузел \n"
			"c - совмещеный санузел \n";
		cin >> tempBathroom;
	} while (!(tempBathroom == 's' || tempBathroom == 'c'));
	temp.bathroom = Bathroom(tempBathroom);
	cout << "Этаж ";
	cin >> temp.floor;
	cout << "Этажность ";
	cin >> temp.numberOfStoreys;
	do
	{
		cout << "Выбирите тип ремонта\n"
			"w - без ремонта \n"
			"o - косметический ремонт \n"
			"l - люкс \n";
		cin >> tempDecoration;
	} while (!(tempDecoration == 'w' || tempDecoration == 'o' || tempDecoration == 'l'));
	temp.bathroom = Bathroom(tempDecoration);
	cout << "Введите стоимость квартиры " << endl;
	cin >> temp.price;
	cout << endl;
	return temp;
}

void showApartment(Apartment* a, int i) {
	cout << "\t\tКвартира №_" << i + SHIFT << endl;
	cout << "=================================" << endl;
	cout << "Город\t\t\t" << a[i].city << endl;
	cout << "Район\t\t\t" << a[i].area << endl;
	cout << "Общая площадь\t\t" << a[i].totalArea << endl;
	cout << "Жилая площадь\t\t" << a[i].effectiveArea << endl;
	cout << "Площадь кухни\t\t" << a[i].kitchenArea << endl;
	cout << "Санузел\t\t\t";
	if (a[i].bathroom == 'a' ? cout << "Раздельный" << endl : cout << "Совмещеный" << endl);
	cout << "Этаж\t\t\t" << a[i].floor << endl;
	cout << "Этажность\t\t" << a[i].numberOfStoreys << endl;
	switch (Decoration(a[i].decoration))
	{
	case WITHOUT_REPAIR:
		cout << "Без ремонта \n";
		break;
	case ORDINARY:
		cout << "Косметический ремонт\n";
		break;
	case LUXE:
		cout << "Люкс\n";
		break;
	default:
		break;
	}
	cout << "Стоимость квартиры\t" << a[i].price << endl;
	cout << endl;
}


void searchRange(Apartment*& arr, int& sizeArr) {
	cout << "Введите диапазон поиска квартыры по площади\n";
	float userFirstVal , userSecondVal;
	bool flag = false;
	cout << "Введите значение от ";
	cin >> userFirstVal;
	cout << "Введите значение до ";
	cin >> userSecondVal;
	for (int i = 0; i < sizeArr; i++)
	{
		if (userFirstVal <= arr[i].totalArea && userSecondVal >= arr[i].totalArea) {
			showApartment(arr, i);
			flag = true;
		}
	}
	if (!flag) {
		cout << "По данным параметрам не обнаружено квартиры\n\n";
	}
}

void searchApart(Apartment*& arr, int& sizeArr) {
	cout << "Введите город для поиска квартыры\n";
	bool flag = false;
	char tempSearch[STR_SIZE];
	cin >> tempSearch;
	for (int i = 0; i < sizeArr; i++)
	{

		if (!(strcmp(arr[i].city, tempSearch))) {
			showApartment(arr, i);
			flag = true;
		}
	}
	if (!flag) {
		cout << "По данным параметрам не обнаружено квартиры\n\n";
	}
}

void sortApart(Apartment*& arr, int& sizeArr) {
	int minElement;
	Apartment temp;
	for (int i = 0; i < sizeArr; i++)
	{
		minElement = i;
		for (int j = i; j < sizeArr; j++)
		{
			if (arr[j].price < arr[minElement].price) {
				minElement = j;
				temp = arr[minElement];
				arr[minElement] = arr[i];
				arr[i] = temp;
			}
		}
	}
	for (int i = 0; i < sizeArr; i++)
	{
		showApartment(arr, i);
	}
}

Apartment* getNewArr(int arrSize)
{
	Apartment* newArr = new Apartment[arrSize];
	if (newArr)
	{
		return newArr;
	}
	else
	{
		return NULL;
	}
}

void pushBack(Apartment*& arr, int& size, Apartment value) {
	int shift = 1;
	Apartment* newArr = getNewArr(size + shift);
	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	newArr[size] = value;
	size++;
	delete[]arr;
	arr = newArr;
}

void printMenu() {
	cout << "1 - Добавить квартиру\n"
		"2 - Список квартир\n"
		"3 - Поиск квартиры по площади\n"
		"4 - Поиск кавартиры по городу\n"
		"5 - сортировка квартир по цене\n"
		"9 - Очистить консоль\n"
		"0 - Выход из программы\n";
	cout << "Введите пункт меню: ";
}

void mainMenu(Apartment*& arr, int& size) {
	char userPoint[STR_SIZE];
	int pointMenu;
	cin >> userPoint;
	pointMenu = atoi(userPoint);
	cin.clear();
	cin.ignore();
	switch (Menu(pointMenu))
	{

	case ADD_NEW_APART:
		system("cls");
		pushBack(arr, size, addApartment());
		cout << "Отлично запись сохранена\n";
		system("pause");
		system("cls");
		printMenu();
		break;
	case LIST_APART:
		for (int i = 0; i < size; i++)
		{
			showApartment(arr, i);
		}
		system("pause");
		system("cls");
		printMenu();
		break;
	case SEARCH_APART_AREA:
		searchRange(arr, size);
		system("pause");
		system("cls");
		printMenu();
		break;
	case SEARCH_APART_CITY:
		searchApart(arr, size);
		system("pause");
		system("cls");
		printMenu();
		break;
	case SORT_APART_PRICE:
		sortApart(arr, size);
		system("pause");
		system("cls");
		printMenu();
		break;
	case CLEAR:
		system("cls");
		printMenu();
		break;
	case EXIT:
		exit(0);
		break;
	default:
		system("cls");
		cout << "Программа для внесения, просмотра и поиска квартир\nПросто следуйте пунктам и меню и инструкциям\n"
			"-------------------------------------------------------------------------------------\n\n";
		printMenu();
		break;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size = 0;
	Apartment* apart = getNewArr(size);
	cout << "Программа для внесения, просмотра и поиска квартир\nПросто следуйте пунктам и меню и инструкциям\n"
		"-------------------------------------------------------------------------------------\n\n";
	printMenu();
	while (true)
	{
		mainMenu(apart, size);
	}
	delete[]apart;
	return 0;
}