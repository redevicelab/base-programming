#include <iostream>
#include <math.h>
using namespace std;

enum Menu
{
    EQUATION = 1 ,
    CLEAR,
    EXIT
};

enum EquationType {
    LINEAR = 1,
    QUADRATIC,
    BACK
};

int linearEquation(int a, int b)
{
    return -b / a;
}

double linearEquation(double a, double b)
{
    return -b / a;
}

void quadraticEquation(double a, double b, double c) {
    double firstRoot, secondRoot, d;
    d = (b * b) - (4 * a * c);
    if (d > 0)
    {
        firstRoot = ((-b) + sqrt(d)) / (2 * a);
        secondRoot = ((-b) - sqrt(d)) / (2 * a);
        cout << "Ответ: Первый корень = " << firstRoot << "\n";
        cout << "Ответ: Второй корень = " << secondRoot << "\n";
    }
    else if (d < 0)
    {
        cout << "НЕТ РЕШЕНИЯ\n";
    }
    else if (d == 0)
    {
        firstRoot = ((-b) + sqrt(d)) / (2 * a);
        cout << "Ответ: Единственый корень = " << firstRoot << "\n";
    }
}

void printMenu() {

    cout << "Программа для нахождения корней линейного и квадратного уравнений.\n"
        "Следуйте инструкция\n"
        "1 - Выберите для нахождения корней ураванения\n"
        "2 - Очистить консоль\n"
        "3 - Выход из программы\n\n"
    "Введите пункт меню: ";
}

void mainMenu() {

    while (true) {
        printMenu();
        int userMenu;
        double a, b, c;
        cin >> userMenu;
        switch (Menu(userMenu))
        {
        case EQUATION:
            cout << "1 - Линейное уравнение\n"
                "2 - Квадратное урованение\n"
                "3 - Выйти в главное меню\n"
                "Введите пункт меню: " ;
            cin >> userMenu;
            switch (EquationType(userMenu))
            {
            case LINEAR:
                cout << " Введите первый коэффициент :";
                cin >> a;
                cout << " Введите второй коэффициент :";
                cin >> b;
                cout << endl;
                cout << " Корень линейного уравнения равен :" << linearEquation(a, b);
                cout << endl;
                system("pause");
                system("cls");
                break;
            case QUADRATIC:
                cout << " Введите первый коэффициент :";
                cin >> a;
                cout << endl;
                cout << "Введите второй коэффициент :";
                cin >> b;
                cout << endl;
                cout << " Введите третий коэффициент :";
                cin >> c;
                cout << endl;
                quadraticEquation(a, b, c);
                cout << endl;
                system("pause");
                system("cls");
                break;
            case BACK:
                system("cls");
                break;
            }
            break;
        case CLEAR:
            system("cls");
            break;
        case EXIT:
            exit(0);
            break;
        default:
            system("cls");
            break;
        }

    }
}

int main(){
    setlocale(LC_ALL, "ru");
    mainMenu();
    return 0;
}