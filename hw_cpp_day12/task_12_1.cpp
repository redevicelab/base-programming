//Составить программу, используя оператор switch, которая выводит на экран такое меню
//"Запуск программ: \n"
//	"1 - Блокнот \n"
//	"2 - Офис Ворд \n"
//	"3 - Браузер Мазила \n"
//	"Вернуться в начало - 9 \n"
//	"Выход - 0 \n"
//Пользователь выбирает соотв.пункт и происходит запуск приложения.
//Подсказка
//включите а программу заголовочный файл
//#include <Windows.h>
//и используйте следующую команду
//WinExec("C:\\Program Files (x86)\\Microsoft Office\\Office12\\WINWORD.EXE", 1);
//где в кавычках указан путь к приложению.


#include <iostream>
#include <Windows.h>

using namespace std;

const int EXEC_CODE = 31;

void printMenu() {
	cout << "Выберите пункт меню введя только число, если ввести несколько чисел разделяя пробелами,\nто пункты меню будут выбраны по очереди.\nЗапуск программ:\n \t1. Блокнот\n\t2. Microsoft Word\n\t3. Google Chrome\n\t9. Вернутся в начало\n\t0. Выход\n\n";
}

void printExecMsg(int execMsg) {
	if (execMsg >= EXEC_CODE) {
		cout << "\rПрограмма запушена с кодом: " << execMsg << endl;
	}
	else cout << "\rИсполняющий файл не найден или программа запустилась с ошибкой. код: "<< execMsg << endl;
}

int inputUserMenuItem() {
	int userMenuItem;
	bool errorFlag = false;
	while (true) {
		if (errorFlag == false) {
			cout << "Введите пункт меню:";
		}else cout << "Некорректное значение, введите число: ";
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

void selectMenu(int menuItem) {
	switch (menuItem)
	{
	case 1:
		printExecMsg(WinExec("C:\\Windows\\system32\\notepad.exe", 1));
		break;
	case 2:
		printExecMsg(WinExec("C:\\Program Files (x86)\\Microsoft Office\\root\\Office16\\WINWORD.EXE", 1));
		break;
	case 3:
		printExecMsg(WinExec("C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe", 1));
		break;
	case 9:
		system("cls");
		printMenu();
		break;
	case 0:
		exit(0);
		break;

	default:
		cout << "Введен не сушествующий пункт меню\n ";
		system("pause");
		system("cls");
		printMenu();
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	printMenu();
	while (1) {
		selectMenu(inputUserMenuItem());
	}
	return 0;
}
