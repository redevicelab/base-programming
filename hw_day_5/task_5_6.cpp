// Написать программу для отбора кандидатов в корпус морской пехоты. Допускаются только совершеннолетние граждане 
// (т.е. старше 18-ти лет), имеющие мужской пол, ростом выше 180 см, с индексом массы тела (ИМТ) в пределах от 20 до 30. 
// ИМТ рассчитывается по формуле:
// I=m/h^2
// m- масса тела в кг
// h- рост в метрах.
// При создании программы, по максимуму использовать функции.
#include <iostream>

using namespace std;

const int NUMBER_CONVERT_TO_METER = 100;
const int POINT_MALE_MENU = 1;
const int POINT_FEMALE_MUNU = 2;
const int MIN_AGE = 18;
const int MIN_HEIGHT = 180;
const int MIN_BODY_MASS_INDEX = 20;
const int MAX_BODY_MASS_INDEX = 30;

void errorMessage() {
	cout << "Не сответсвует критериям отбора: ";
}

int findBodyMassIndex(float height, float weight) {
	height = height / NUMBER_CONVERT_TO_METER;
	return weight / (height *= height);
}

bool checkSex(int sex) {
	if (sex == POINT_MALE_MENU) {
		cout << "Мужской пол\n";
		return true;
	}
	else if (sex == POINT_FEMALE_MUNU) {
		cout << "Женский пол ";
		errorMessage();
		cout << endl;
		return false;
	}
	else {
		cout << "Ошибка выбора меню\n";
		return false;
	}
}

bool checkAge(int age) {
	if (age >= MIN_AGE) {
		return true;
	}
	else {
		errorMessage();
		cout << "Кандидату менее " << MIN_AGE << " лет\n";
		return false;
	}
}

bool checkHeight(float height) {
	if (height >= MIN_HEIGHT) {
		return true;
	}
	else {
		errorMessage();
		cout << "Рост кандидата менее " << MIN_HEIGHT << "см.\n";
		return false;
	}
}

bool checkBodyMassIndex(int bodyMassIndex) {
	if (bodyMassIndex >= MIN_BODY_MASS_INDEX && MAX_BODY_MASS_INDEX >= bodyMassIndex) {
		cout << "Индекс массы тела равен: " << bodyMassIndex << " что в пределах нормы от " << MIN_BODY_MASS_INDEX << " до " << MAX_BODY_MASS_INDEX << "\n";
		return true;
		}
	else {
		errorMessage();
		cout << "Индекс массы тела равен: " << bodyMassIndex << " что в не соответвует индексам от " << MIN_BODY_MASS_INDEX << " до " << MAX_BODY_MASS_INDEX << "\n";
		return false;
	}
}

void resultCandidate(bool result) {
	if (result == true) {
		cout << "ИТОГ: Кандидат годен\n";
	}
	else cout << "ИТОГ: Кандидат не годен\n";
}



int main()
{
	setlocale(LC_ALL, "ru");
	int age;
	float weight;
	float height;
	int sex;
	float bodyMassIndex;
	bool result;
	cout << "Учебная программа\n"
		"Программа для отбора кандита в морскую пехоту\n\n";
		
	cout << "Из меню выберете пол введя номер пункта \n"
		"1 - Пол Мужской\n"
		"2 - Пол Женский\n";
	cin >> sex;
	result = checkSex(sex);
	cout <<	"Введите возраст кандидата полных лет: ";
	cin >> age;
	result = result & checkAge(age);
	cout << "Введите рост кандидата в сантиметрах: ";
	cin >> height;
	result = result & checkHeight(height);
	cout << "Введите вес кандидата в килограмах: ";
	cin >> weight;
	bodyMassIndex = findBodyMassIndex(height, weight);
	result = result & checkBodyMassIndex(bodyMassIndex);
	resultCandidate(result);
	return 0;
}
