#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;
const int START_FILTER_YEAR = 1940;
const int FINISH_FILTER_YEAR = 2020;

enum Menu {
	EXIT,
	ADDSTUD,
	ADDGROUP,
};

class Student
{
	enum Sex
	{
		Male =1,
		Female
	};

	string name;
	string midName;
	string surname;
	int yearBirth;
	Sex sex;


public:
	Student();
	~Student();

	void setName() {
		getline(cin, name);
	}
	void setMidName() {
		getline(cin, midName);
	}
	void setSurname() {
		getline(cin, surname);
	}
	void setYearBirth(int value) {
		if (value >= START_FILTER_YEAR && value <= FINISH_FILTER_YEAR) yearBirth = value;
		else value = NULL;
	}
	
	void setSex(int value) {
		if (value == Male || value == Female) sex = Sex(value);
		else int(sex) = NULL;
	}

	void printAll() {
		cout << "Имя " <<name << endl;
		cout << "Отчество "<<midName << endl;
		cout << "Фамилия "<<surname << endl;
		cout << "Год рождения "<<yearBirth << endl;
		cout << "Пол ";
		sex == Male ? cout << "Мужской" << endl : cout << "Женский" << endl;
	}

private:

};

Student::Student()
{
	name = "NULL";
	midName = "NULL";
	surname = "NULL";
	yearBirth = NULL;
	sex = Male;
}

Student::~Student()
{
}

class Group
{
	int sizeGroup;
	Student* listStudent;
	string groupName;
	
public:
	Group()
	{	
		sizeGroup = 0;
		groupName = "New Name Group";
		listStudent = getNewArr(sizeGroup);
	}
	~Group()
	{
		delete[] listStudent;
	}

	void renameGroup() {
		getline(cin, groupName);
	}

	string getInfoGroup() {
		return groupName;
	}

	void printListStudents() {
		int shift = 1;
		cout << "Группа: " << groupName << endl;
		for (int i = 0; i < sizeGroup; i++)
		{
			cout << "Номер студунта №" << i+shift << endl;
			cout << "----------------------------------" << endl;
			listStudent[i].printAll();
		}
	}

	void addStudent(Student value) {
		int shift = 1;
		Student* newArr = getNewArr(sizeGroup + shift);
		for (int i = 0; i < sizeGroup; i++)
		{
			newArr[i] = listStudent[i];
		}
		newArr[sizeGroup] = value;
		sizeGroup++;
		delete[]listStudent;
		listStudent = newArr;
	}


	Student* getNewArr(int arrSize)
	{
		Student* newArr = new Student[arrSize];
		if (newArr)
		{
			return newArr;
		}
		else
		{
			return NULL;
		}
	}


	void getInfo() {
		listStudent[0].printAll();
	}
};


class Faculty {

	Group* listGroup;
	string nameFaculty;
	string nameDean;
	string surnameDean;
	string midNameDean;
	int sizeFaculty;
public:

	Faculty() {
		sizeFaculty = 0;
		nameFaculty = "New Name Faculty";
		listGroup = new Group[sizeFaculty];
		nameDean = "NULL";
		midNameDean = "NULL";
		surnameDean = "NULL";
	}

	~Faculty() {
		delete[]listGroup;
	}

	void renameGroup() {
		getline(cin, nameFaculty);

	}
	
	void addGroup(Group value) {
		int shift = 1;
		Group* newArr = getNewArr (sizeFaculty + shift);
		for (int i = 0; i < sizeFaculty; i++)
		{
			newArr[i] = listGroup[i];
		}
		newArr[sizeFaculty] = value;
		sizeFaculty++;
		delete[]listGroup;
		listGroup = newArr;
	}


	Group* getNewArr(int arrSize)
	{
		Group* newArr = new Group[arrSize];
		if (newArr)
		{
			return newArr;
		}
		else
		{
			return NULL;
		}
	}
};

void printMenu() {
	cout << "Добро пожаловать!!!" << endl;
	cout << "Пункт меню\n"
		"1. Добить нового студента\n"
		"2. Добвить нового студента в группу\n"
		"Введите любую цифру что бы вывести на экран списко студентов группы\n"
		"Ввод : ";
}

void loop() {
	Faculty newFac;
	Group newGroup;
	Student newStudent;
	string userMenu;
	printMenu();
	while (true)
	{
		getline(cin,userMenu);
		switch (Menu(stoi(userMenu)))
		{
		case EXIT:
			break;
		case ADDSTUD:
			cout << "Введите имя ";
			newStudent.setName();
			cout << "Введите фамилию ";
			newStudent.setSurname();
			break;
		case ADDGROUP:
			newGroup.addStudent(newStudent);
			break;
		default:
			newGroup.printListStudents();
			system("pause");
			system("cls");
			printMenu();
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

