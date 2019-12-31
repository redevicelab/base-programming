// Написать программу для отбора кандидатов в корпус морской пехоты. Допускаются только совершеннолетние граждане 
// (т.е. старше 18-ти лет), имеющие мужской пол, ростом выше 180 см, с индексом массы тела (ИМТ) в пределах от 20 до 30. 
// ИМТ рассчитывается по формуле:
// I=m/h^2
// m- масса тела в кг
// h- рост в метрах.
// При создании программы, по максимуму использовать функции.

/*Более короткое решение задачи*/
#include <iostream>

using namespace std;

const int NUMBER_CONVERT_TO_METER = 100;
const int POINT_MALE_MENU = 1;
const int POINT_FEMALE_MUNU = 2;
const int MIN_AGE = 18;
const int MIN_HEIGHT = 180;
const int MIN_BODY_MASS_INDEX = 20;
const int MAX_BODY_MASS_INDEX = 30;

void sendErrorMessageMenu() {
	cout << "ВНИМАНИЕ ОШИБОЧНО ВЫБРАН НЕ СУШЕСТВУЮЩИЙ ПУНКТ МЕНЮ\n\n"
		"\t\t\\ПОПРОБУЙТЕ СНОВА\\\n";
}

int findBodyMassIndex(float height, float weight) {
	height = height / NUMBER_CONVERT_TO_METER;
	return weight / (height *= height);
}

void checkCandidate(int sex, int age, float weight, float height, float BodyMassIndex) {
	if (sex == POINT_MALE_MENU) {
		if (age >= MIN_AGE) {
			if (height >= MIN_HEIGHT) {
				if ((BodyMassIndex >= MIN_BODY_MASS_INDEX) && (MAX_BODY_MASS_INDEX >= BodyMassIndex)) {
					cout << "Кандидат годен\n\n";
				}
				else cout << "Кандидат не годен ИМТ не соответвует норме от " << MIN_BODY_MASS_INDEX << " до " << MAX_BODY_MASS_INDEX << "\n\n";
			}
			else cout << "Кандидат не годен рост ниже " << MIN_HEIGHT << "см.\n\n";
		}
		else cout << "Кандидат не годен возраст не сответвует " << MIN_AGE << " годам и выше\n\n";
	}
	else if (sex == POINT_FEMALE_MUNU) {
		cout << "Кандидат жеского пола, не подходит критериям отбора\n\n";
	}
	else sendErrorMessageMenu();
}

int main()
{
	setlocale(LC_ALL, "ru");
	int age;
	float weight;
	float height;
	int sex;
	float bodyMassIndex;
	cout << "Учебная программа\n"
		"Программа для отбора кандита в морскую пехоту\n\n";
		
	cout << "Из меню выберете пол введя номер пункта \n"
		"1 - Пол Мужской\n"
		"2 - Пол Женский\n";
	cin >> sex;
	cout <<	"Введите возраст кандидата полных лет: ";
	cin >> age;
	cout << "Введите рост кандидата в сантиметрах: ";
	cin >> height;
	cout << "Введите вес кандидата в килограмах: ";
	cin >> weight;
	bodyMassIndex = findBodyMassIndex(height, weight);
	checkCandidate(sex, age, weight, height, bodyMassIndex);
	return 0;
}
