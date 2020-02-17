#include <iostream>
#include <string.h>

using namespace std;

const int STR_SIZE = 50;
const int SHIFT = 1;

enum MainMenu
{
	CLEARSCREEN,
	CREATECAR,
	SHOWALLCARS,
	SHOWCARNUMBER,
	SEARCHCARPARAM
};

enum SearchMenu {
	LENGHT = 1,
	CLEARANCE,
	ENGINEPOWER,
	WHEELDIAMETER,
	COLOR,
	GEARBOX
};

enum Gearbox { AUTOMATIC = 'a', MANUAL = 'm' };

struct Car
{
	float lenght;
	float clearance;
	float enginePower;
	int wheelDiameter;
	char color[STR_SIZE];
	Gearbox gearbox;
};

Car createCar() {
	Car temp;
	char tempGearbox;
	cout << "Для создание записи информации об автомобиле введите последовательно указаные пункты" << endl;
	cout << "Введите длину автомобиля ";
	cin >> temp.lenght;
	cout << "Введите клиренс автомобиля ";
	cin >> temp.clearance;
	cout << "Введите мошность автомобиля в КВт ";
	cin >> temp.enginePower;
	cout << "Введите диаметр колес ";
	cin >> temp.wheelDiameter;
	cout << "Введите цвет ";
	cin >> temp.color;
	do
	{
		cout << "Введите тип коробки передачь путем в ввода\n"
			"m - Механческая КПП\n"
			"а - Автоматическая КПП\n";
		cin >> tempGearbox;
	} while (!(tempGearbox == 'm' || tempGearbox == 'a'));
	temp.gearbox = Gearbox(tempGearbox);
	cout << endl;
	return temp;
}

void showCar(Car* a, int i) {
	cout << "\t\tАвтомобиль №_" << i + SHIFT << endl;
	cout << "=================================" << endl;
	cout << "Длина Автомобиля\t" << a[i].lenght << endl;
	cout << "Клиренс:\t\t" << a[i].clearance << endl;
	cout << "Мошность двигателя\t" << a[i].enginePower << endl;
	cout << "Диаметр колес\t\t" << a[i].wheelDiameter << endl;
	cout << "Цвет\t\t\t" << a[i].color << endl;
	cout << "Тип КПП\t\t\t";
	if (a[i].gearbox == 'a' ? cout << "Автоматическая" << endl : cout << "Механическая" << endl);
	cout << endl;
}


void searchCarParam(Car*& arr, int& sizeArr) {
	system("cls");
	char userPoint[STR_SIZE];
	int pointMenu;
	char tempSearch[STR_SIZE];
	bool flag = false;
	cout << "Поиск автомобилей по параметрам " << endl;
	cout << "1 - Длина Автомобиля" << endl;
	cout << "2 - Клиренс" << endl;
	cout << "3 - Мошность двигателя" << endl;
	cout << "4 - Диаметр колес" << endl;
	cout << "5 - Цвет" << endl;
	cout << "6 - Тип КПП" << endl;
	cout << "выберите пункт меню введя цифру с клавиатуры: ";
	cin >> userPoint;
	pointMenu = atoi(userPoint);
	cout << "Введите искомое значение: ";
	switch (SearchMenu(pointMenu))
	{
	case LENGHT:
		cin >> tempSearch;
		for (int i = 0; i < sizeArr; i++)
		{
			if (atof(tempSearch) == (arr[i].lenght)) {
				showCar(arr, i);
				flag = true;
			}
		}
		break;
	case CLEARANCE:
		cin >> tempSearch;
		for (int i = 0; i < sizeArr; i++)
		{
			if (atof(tempSearch) == arr[i].clearance) {
				showCar(arr, i);
				flag = true;
			}
		}
		break;
	case ENGINEPOWER:
		cin >> tempSearch;
		for (int i = 0; i < sizeArr; i++)
		{
			if (atof(tempSearch) == arr[i].enginePower) {
				showCar(arr, i);
				flag = true;
			}
		}
		break;
	case WHEELDIAMETER:
		cin >> tempSearch;
		for (int i = 0; i < sizeArr; i++)
		{
			if (atoi(tempSearch) == arr[i].wheelDiameter) {
				showCar(arr, i);
				flag = true;
			}
		}
		break;
	case COLOR:
		cin >> tempSearch;
		for (int i = 0; i < sizeArr; i++)
		{

			if (!(strcmp(arr[i].color, tempSearch))){
				showCar(arr, i);
				flag = true;
			}
		}
		break;
	case GEARBOX:
		char tempGearbox;
		do
		{
			system("cls");
			cout << "Введите для поиска тип коробки передач\n"
				"m - Механческая КПП\n"
				"а - Автоматическая КПП\n";
			cin >> tempGearbox;
		} while (!(tempGearbox == 'm' || tempGearbox == 'a'));
		for (int i = 0; i < sizeArr; i++)
		{
			if (Gearbox(tempGearbox) == arr[i].gearbox) {
				showCar(arr, i);
				flag = true;
			}
		}
		break;
	default:
		break;
	}
	if (!flag) {
		cout << "По данным параметрам не обнаружено автомобилей";
	}
}

Car* getNewArr(int arrSize)
{
	Car* newArr = new Car[arrSize];
	if (newArr)
	{
		return newArr;
	}
	else
	{
		return NULL;
	}
}

void pushBack(Car*& arr, int& size, Car value) {
	int shift = 1;
	Car* newArr = getNewArr(size + shift);
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
	cout << "1 - Создать запись автомобиля\n"
		"2 - Просмотр все автомобилей\n"
		"3 - Просмотр автомоибиля по номеру записи\n"
		"4 - Поиск автомобилей по тех характеристекам\n"
		"0 - Очистить консоль\n";
	cout << "Введите пункт меню: ";
}

void mainMenu(Car*& arr, int& size) {
	char userPoint[STR_SIZE];
	int pointMenu;
	cin >> userPoint;
	pointMenu = atoi(userPoint);
	switch (MainMenu(pointMenu))
	{
	case CREATECAR: {
		system("cls");
		pushBack(arr, size, createCar());
		cout << "Отлично запись сохранена\n";
		system("pause");
		system("cls");
		printMenu();
		break;
	}
	case SHOWALLCARS: {
		for (int i = 0; i < size; i++)
		{
			showCar(arr, i);
		}
		system("pause");
		system("cls");
		printMenu();
		break;
	case SHOWCARNUMBER: {
		int carNum;
		cout << "Введите номер автомобиля для отображения его характеристик" << endl;
		cin >> carNum;
		showCar(arr, carNum - SHIFT);
		system("pause");
		system("cls");
		printMenu();
		break;
	}
	case SEARCHCARPARAM: {
		searchCarParam(arr, size);
		system("pause");
		system("cls");
		printMenu();
		break;
	}
	case CLEARSCREEN: {
		system("cls");
		printMenu();
		break;
	}
	default:
		system("cls");
		cout << "Программа для внесения, просмотра и поиска технических характреристик автомобиля\nПросто следуйте пунктам и меню и инструкциям\n"
			"-------------------------------------------------------------------------------------\n\n";
		printMenu();
		break;
	}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int size = 0;
	Car* car = getNewArr(size);
	cout << "Программа для внесения, просмотра и поиска технических характреристик автомобиля\nПросто следуйте пунктам и меню и инструкциям\n"
		"-------------------------------------------------------------------------------------\n\n";
	printMenu();
	while (true)
	{
		mainMenu(car, size);
	}
	delete[]car;
}
