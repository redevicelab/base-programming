// 1.	Написать программу, которая примет от пользователя строку, длиною не более 100 символов, 
//затем, примет от пользователя один символ. Программа должна предложить меню:
// a.	Принять строку от пользователя;
// b.	Принять символ от пользователя;
// c.	Вывести на экран принятую от пользователя строку;
// d.	Вывести на экран принятый от пользователя символ;
// e.	Вывести на экран индекс первого вхождения введённого символа в строку 
//(если введённый символ имеется в строке, если отсутствует – сообщить об этом);
// f.	Индекс последнего вхождения символа в строку (если введённый символ 
//имеется в строке, если отсутствует – сообщить об этом);;
// g.	Показать длину введённой строки;
// h.	Завершить программу;
// Программа должна работать в бесконечном цикле, до тех, по, пока пользователь не выберет пункт «Завершить программу»
// Внимание! При работе со строками в цикле, Вы можете столкнуться с тем, 
//что ввод данных «пролетает», для решения этой проблемы, используйте дополнительные функции cin.clear() и cin.ignore();



#include <iostream>
#include <string.h>
#include <stdio.h>
#include <Windows.h>

using namespace std;

enum Menu { A = 'a', B = 'b', C = 'c', D = 'd', E = 'e', F = 'f', G = 'g', H = 'h' };

const int STRING_LENGHT = 100;

void printMenu() {
	cout << "Меню программы:\n"
		"a.Принять строку от пользователя;\n"
		"b.Принять символ от пользователя;\n"
		"c.Вывести на экран принятую от пользователя строку;\n"
		"d.Вывести на экран принятый от пользователя символ;\n"
		"e.Вывести на экран индекс первого вхождения введённого символа в строку\n"
		"f.Индекс последнего вхождения символа в строку\n"
		"g.Показать длину введённой строки; \n"
		"h.Завершить программу; \n";

}

char inputUserMenuItem() {
	char userMenuItem;
	bool errorFlag = false;
	while (true) {
		if (errorFlag == false) {
			cout << "Введите пункт меню:";
		}
		else cout << "Некорректное значение, введите символ: ";
		cin >> userMenuItem;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail(), '\n');
			errorFlag = true;
		}
		else {
			errorFlag = false;
			return userMenuItem;
		}
	}
}

void chooseMenu(char* string, char& uchar) {
	char choice;
	choice = inputUserMenuItem();
	char* firstEntry;
	char* lastEntry;
	switch ((Menu)tolower(choice))
	{
	case A:
		cout << "Введите строку: ";
		cin >> string;
		break;
	case B:
		cout << "Введите символ: ";
		cin >> uchar;
		break;
	case C:
		cout << "Вывод введеной строки: ";
		cout << string << endl;
		break;
	case D:
		cout << "Вывод введеного символа: ";
		cout << uchar << endl;
		break;
	case E:
		firstEntry = strchr(string, uchar);
		if (firstEntry != NULL) {
			cout << "Вывод индекса первого вхождения символа: ";
			cout << firstEntry - string << endl;
		}
		else cout << "Нет этого символа \"" << uchar << "\" в строке\n";
		break;
	case F:
		lastEntry = strrchr(string, uchar);
		if (lastEntry != NULL) {
			cout << "Вывод индекса последенго вхождения символа: ";
			cout << lastEntry - string << endl;
		}
		else cout << "Нет этого символа \"" << uchar << "\" в строке\n";
		break;
	case G:
		cout << "Длина строки равна: " << strlen(string) << " символ(aм)\n";
		break;
	case H:
		exit(0);
		break;
	default:
		system("cls");
		printMenu();
		break;
	}
	cin.clear();
	cin.ignore();

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Используй программу следуя инструкциям: \n\n";
	char userString[STRING_LENGHT] = "\0";
	char userChar = ' ';
	printMenu();
	while (true) {

		chooseMenu(userString, userChar);
	}
}
