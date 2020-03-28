#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

const int SHIFT_FOR_TERMINATOR = 1;

enum PointMenu
{
	FILL_LIST = 1,
	PRINT_LIST,
	ADD_NEW_ITEM,
	DELETE_ITEM,
	EDIT_SUBJECT,
	EXIT
};

enum SubMenu {
	EDIT_NAME_TEACHER =1,
	EDIT_NAME_SUBJECT,
	CHANGE_NUM_LIST,
	BACK,
};


class Subject
{

	char* nameTeacher;
	char* nameSubject;

public:
	Subject()
	{
		nameTeacher = NULL;
		nameSubject = NULL;
	}

	Subject& operator=(Subject obj) {
		this->nameTeacher = obj.nameTeacher;
		this->nameSubject = obj.nameSubject;
		return *this;
	}

	~Subject()
	{
		delete[]this->nameTeacher;
		delete[]this->nameSubject;
	}

	void SetNameTeacher(const char* name)
	{
		int nameLenght = strlen(name) + SHIFT_FOR_TERMINATOR;
		if (this->nameTeacher)
		{
			delete[] this->nameTeacher;
		}
		this->nameTeacher = new char[nameLenght];
		strcpy_s(this->nameTeacher, nameLenght, name);
	}

	void EnterNameTeacher()
	{
		const int MAX_NAME_LENGHT = 1000;
		char teacherName[MAX_NAME_LENGHT];
		cout << "Введите ФИО Преподователя:";
		gets_s(teacherName, MAX_NAME_LENGHT);
		SetNameTeacher(teacherName);
	}

	char* GetNameTeacher()
	{
		if (!this->nameTeacher)
		{
			char nullMessage[] = "ФИО Преподавателя ещё не задано!";
			int nameLenght = strlen(nullMessage) + SHIFT_FOR_TERMINATOR;
			this->nameTeacher = new char[nameLenght];
			strcpy_s(this->nameTeacher, nameLenght, nullMessage);
		}
		return this->nameTeacher;
	}

	void PrintNameTeacher()
	{
		cout << this->GetNameTeacher() << endl;
	}

	void SetNameSubject(const char* name)
	{
		int nameLenght = strlen(name) + SHIFT_FOR_TERMINATOR;
		if (this->nameSubject)
		{
			delete[] this->nameSubject;
		}
		this->nameSubject = new char[nameLenght];
		strcpy_s(this->nameSubject, nameLenght, name);
	}

	void EnterNameSubject()
	{
		const int MAX_NAME_LENGHT = 1000;
		char subjectName[MAX_NAME_LENGHT];
		cout << "Введите Название предмета: ";
		gets_s(subjectName, MAX_NAME_LENGHT);
		SetNameSubject(subjectName);
	}

	char* GetNameSubject()
	{
		if (!this->nameSubject)
		{
			char nullMessage[] = "Название ещё не задано!";
			int nameLenght = strlen(nullMessage) + SHIFT_FOR_TERMINATOR;
			this->nameSubject = new char[nameLenght];
			strcpy_s(this->nameSubject, nameLenght, nullMessage);
		}
		return this->nameSubject;
	}

	void PrintNameSubject()
	{
		cout << this->GetNameSubject() << endl;
	}
};

class ListSubject
{
	int listSize = 0;
	Subject* list;
public:

	ListSubject(int listSize)
	{
		list = new Subject[listSize];
		this->listSize = listSize;
	}



	void FillList()
	{
		cin.clear();
		cin.ignore();
		for (int i = 0; i < listSize; i++)
		{
			list[i].EnterNameTeacher();
			list[i].EnterNameSubject();
			cout << "____________________________________________" << endl;
		}
	}

	void PrintSubject(int index)
	{
		if (index >= 0 && index < listSize)
		{
			cout << "ФИО преподователя: \t| ";
			list[index].PrintNameTeacher();
			cout << "Название предмета: \t| ";
			list[index].PrintNameSubject();
		}
		else {
			cout << "Вы ввели не корректное значение Номера из списка предметов" << endl;
		}
	}

	void PrintList()
	{
		int shift = 1;
		cout << "Список Предметов\n";
		cout << "_____________________________________________________" << endl;
		for (int i = 0; i < listSize; i++)
		{
			cout << "№ предмета: " << i + shift << endl;
			PrintSubject(i);
			cout << "_____________________________________________________" << endl << endl;
		}
		cout << endl << "=================================================" << endl;
	}

	void AddNewSubject(int newQtySubject)
	{
		cin.clear();
		cin.ignore();
		Subject* list = new Subject[this->listSize + newQtySubject];
		for (int i = 0; i < this->listSize; i++)
		{
			list[i] = this->list[i];
		}
		for (int i = this->listSize; i < this->listSize + newQtySubject; i++) {
			list[i].EnterNameTeacher();
			list[i].EnterNameSubject();
		}
		delete[] this->list;
		this->listSize += newQtySubject;
		this->list = list;
	}

	void DeleteSubject(int indexDel)
	{
		int shift = 1;
		this->listSize--;
		Subject* list = new Subject[this->listSize];

		for (int i = indexDel - shift; i < this->listSize; i++)
		{
			list[i] = this->list[i + shift];
		}
		delete[] this->list;
		this->list = list;
	}
	
	void editNameTeacher(int index) {
		cin.clear();
		cin.ignore();
		int shift = 1;
		this->list[index-shift].EnterNameTeacher();
	}

	void editNameSubject(int index) {
		cin.clear();
		cin.ignore();
		int shift = 1;
		this->list[index-shift].EnterNameSubject();
	}

};



class Menu
{
	const short int COUNT_MENU_POINT = 6;
	short int userChoice = 1;
public:
	void ShowMenu()
	{
		cout << endl;
		cout << "Меню программы" << endl;
		cout << "=============================================" << endl;
		cout << "1.  Заполнить список предметов;" << endl;
		cout << "2.  Вывести на экран список предметов;" << endl;
		cout << "3.  Добавление новых предметов;" << endl;
		cout << "4.  Удаление предметов;" << endl;
		cout << "5.  Редактирование" << endl;
		cout << "6.  Выход;" << endl;
		cout << "=============================================" << endl;
	}

	void ShowSubMenu() {
		cout << endl;
		cout << "Меню редактирования" << endl;
		cout << "=============================================" << endl;
		cout << "1.  Изменить ФИО преподователя;" << endl;
		cout << "2.  Изменить название предмета;" << endl;
		cout << "3.  Изменить номер списка;" << endl;
		cout << "4.  Вернуться назад;" << endl;
		cout << "=============================================" << endl;
	}

	short int SetUserChoice(short int userChoice)
	{
		if (userChoice > 0 && userChoice <= COUNT_MENU_POINT)
		{
			this->userChoice = userChoice;
			return userChoice;
		}
		return 0;
	}
	void EnterUserChoice()
	{
		int userChoice;
		while (true)
		{
			cout << "Введите пункт меню: ";
			cin >> userChoice;
			if (SetUserChoice(userChoice)) break;
			cout << endl << "Вы ввели не корректный номер пункта меню." << endl;
			cout << "Допустимое значение должно быть в диапазоне от 1 до 4, пожалуйста, повторите ввод." << endl << endl;
		} ;
	}
	short int GetUserChoice()
	{
		return userChoice;
	}

	void waitAndClear() {
		system("pause");
		system("cls");
	}
};

void loop() {
	bool exitFlag;
	Menu menu;
	int defaultListQty = 2;
	int newQtySubject;
	int indexList;
	ListSubject list(defaultListQty);
	while (true) {
		exitFlag = true;
		menu.ShowMenu();
		menu.EnterUserChoice();
		switch (menu.GetUserChoice())
		{
		case FILL_LIST:
			list.FillList();
			menu.waitAndClear();
			break;
		case PRINT_LIST:
			list.PrintList();
			menu.waitAndClear();
			break;
		case ADD_NEW_ITEM:
			cout << "Введите количество новых предметов: ";
			cin >> newQtySubject;
			list.AddNewSubject(newQtySubject);
			menu.waitAndClear();
			break;
		case DELETE_ITEM:
			cout << "Введите номер удаляемого предмета: ";
			cin >> indexList;
			cout << "Внимание!!!\nДля удаление нажмите \"y\"\n"
				"Для отмены удалениея нажмите \"n\"\n" ;
			if (!_kbhit()) {
				switch (_getch())
				{
				case 'y':
					list.DeleteSubject(indexList);
					cout << "Элемент списка удален :(\n";
					menu.waitAndClear();
					break;
				case 'n':
					cout << "Удаление отменено:)\n";
					menu.waitAndClear();
					break;
				default:
					break;
				}
			}
			break;
		case EDIT_SUBJECT:
			cout << "Введите номер из списка предметов: ";
			cin >> indexList;
			while (exitFlag) {
				menu.waitAndClear();
				menu.ShowSubMenu();
				menu.EnterUserChoice();
				switch (menu.GetUserChoice())
				{
				case EDIT_NAME_TEACHER:
					list.editNameTeacher(indexList);
					break;
				case EDIT_NAME_SUBJECT:
					list.editNameSubject(indexList);
					break;
				case CHANGE_NUM_LIST:
					cout << "Введите номер из списка предметов: ";
					cin >> indexList;
				case BACK:
					cout << "Возврат в главное меню\n";
					exitFlag = false;
					menu.waitAndClear();
					break;
				default:
					break;
				}
			}
			break;
		case EXIT:
			exit(0);
			break;
		}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	loop();
	return 0;
}
