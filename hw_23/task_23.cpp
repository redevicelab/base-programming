#include <iostream>
#include <string.h>
#include <Windows.h>

#pragma warning(disable : 4996)

using namespace std;

const int MAXLEN = 128;
const int MINLEN = 10;
const int SHIFT = 1;

enum Menu {
	
	ADDITEM = 1,
	EDITITEM,
	DELETEITEM,
	DELETEALL,
	PRINTLIST,
	CLEAR,
	EXIT,
};

class Drug
{
	int size;
	char* name;

public:
	Drug() {
		size = 0;
		name = new char[size];
	}

	Drug(const char* name) {
		size = strlen(name) + 1;
		this->name = new char[size];
		strcpy(this->name, name);
	}

	Drug(const Drug& obj) {
		size = obj.size + 1;
		name = new char[size];
		strcpy(name, obj.name);
	}

	Drug& operator=(const Drug& obj) {
		size = obj.size + 1;
		name = new char[size];
		strcpy(name, obj.name);
		return *this;
	}

	~Drug() {
		delete[]name;
	}

	void setName(const char* name)
	{
		size = strlen(name) + 1;
		this->name = new char[size];
		strcpy(this->name, name);
	}

	void editName(const char* name) {
		delete[]this->name;
		size = strlen(name) + 1;
		this->name = new char[size];
		strcpy(this->name, name);
	}

	void getName() {
		cout << name << endl;
	}

};


Drug* addItem(Drug* list, int& listSize, const char* string) {
	int shift = 1;
	Drug* newArr = new Drug[listSize + shift];
	for (int i = 0; i < listSize; i++)
	{
		newArr[i] = list[i];
	}
	newArr[listSize].setName(string);
	listSize++;
	delete[]list;
	list = newArr;
	return list;
}

Drug* popItem(Drug* list, int& listSize)
{
	listSize--;
	Drug* newArr = new Drug[listSize];
	for (int i = 0; i < listSize; i++)
	{
		newArr[i] = list[i];
	}
	delete[]list;
	list = newArr;
	return list;
}

Drug* flush(int& listSize) {
	listSize = 0;
	Drug* newArr = new Drug[listSize];
	if (newArr)
	{
		return newArr;
	}
	else
	{
		return NULL;
	}
}


void printList(Drug* list, int& listSize)
{
	int shift = 1;
	cout << "Список препоратов\n"
		"======================================\n";
	for (int i = 0; i < listSize; i++)
	{
		cout << "Лекасртвеный препарат №" << i + shift << "\n\n";
		list[i].getName();
		cout << "===\n\n";
	}
}

void printMenu() {
	cout << "Добро пожаловать!!!\n"
		"Данная программа умеет создавать\n"
		"Список лекарственных препаратов\n"
		"Удалять и редактировать\n"
		"И все это делается динамически\n"
		"Следуйте пунктам меню все будет ок\n\n"
		"==============================================================================================\n"
		"\t1.Добавить новый элемент\n"
		"\t2.Редактировать элемент укажите номер в списке элемента и введите новое название\n"
		"\t3.Удалить элемент\n"
		"\t4.Очистить весь список\n"
		"\t5.Вывести на экран весь список\n"
		"\t6.Очистить экран.\n"
		"\t7.Выход\n"
		"==============================================================================================\n\n"
		"Введите пункт меню: ";
}

void waitClear() {
	system("pause");
	system("cls");
	printMenu();
}

void loop()
{
	int size = 0;
	Drug* list;
	char name[MAXLEN];
	char pos[MINLEN];
	char userMenu[MINLEN];
	list = new Drug[size];
	printMenu();
	while (true)
	{
		gets_s(userMenu, 10);
		switch (Menu(atoi(userMenu)))
		{
		case EXIT:
			exit(0);
			break;
		case ADDITEM:
			cout << "Введите название препарата: ";
			gets_s(name, MAXLEN);
			list = addItem(list, size, name);
			cout << "Добавлен новый элемент\n";
			waitClear();
			break;
		case EDITITEM:
			cout << "Введите номер препарата из списка: ";
			gets_s(pos, MINLEN);
			if (atoi(pos) <= size)
			{
				cout << "Введите новое название препарата: ";
				gets_s(name, MAXLEN);
				list[atoi(pos) - SHIFT].editName(name);
				cout << "Новое название назначено препарату №" << pos << endl;
			}
			waitClear();
			break;
		case DELETEITEM:
			if (!(size <= 0)) {
				list = popItem(list, size);
				cout << "Элемент удален\n";
			}
			else cout << "Ошибка нет элементов для удаления\n";
			waitClear();
			break;
		case DELETEALL:
			list = flush(size);
			cout << "Список очишен\n";
			waitClear();
			break;
		case PRINTLIST:
			system("cls");
			printList(list, size);
			waitClear();
			break;
		case CLEAR:
			system("cls");
			printMenu();
		default:
			system("cls");
			printMenu();
			break;
		}
	}
	delete[]list;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	loop();
	return 0;
}
