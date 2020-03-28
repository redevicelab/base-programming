#include <iostream>
#include <Windows.h>


using namespace std;

class Array {
    int size;
    int* arr;

    void create(int size) {
        if (size < 1) {
            size = 1;
        }
        this->size = size;
        this->arr = new int[size];
    }

public:
    Array() {
        create(1);
    }

    Array(int size) {
        create(size);
    }

    Array(const Array& obj)
    {
        create(obj.size);
        for (int i = 0; i < this->size; i++)
        {
            this->arr[i] = obj.arr[i];
        }

    }
    ~Array()
    {
        delete[]arr;
    }

    Array& clear()
    {
        create(1);
        return *this;
    }

    Array& init(int size)
    {
        create(size);
        return *this;
    }

    int GetSize() {
        return this->size;
    }

    int& operator[](int i) {
        int shift = 1;
        if (i < 0) {
            i = 0;
        }
        else if (i >= this->size) {
            i = this->size - shift;
        }
        return this->arr[i];
    }

    Array operator++()
    {
        int shift = 1;
        this->size++;
        int* temp = new int[this->size];
        for (int i = 0; i < this->size - shift; i++)
        {
            temp[i + shift] = this->arr[i];
        }
        delete[]arr;
        arr = temp;
        return *this;
    }

    Array operator++(int k)
    {
        int shift = 1;
        this->size++;
        int* temp = new int[this->size];
        for (int i = 0; i < this->size - shift; i++)
        {
            temp[i] = this->arr[i];
        }
        delete[]arr;
        arr = temp;
        return *this;
    }

    Array operator--()
    {
        if (size <= 0) {
            delete[]arr;
            create(1);
            return *this;
        }
        else {
            int shift = 1;
            this->size--;
            int* temp = new int[this->size];
            for (int i = 0; i < this->size; i++)
            {
                temp[i] = this->arr[i + shift];
            }
            delete[]arr;
            arr = temp;
            return *this;
        }
    }

    Array operator--(int k)
    {
        if (size <= 0) {
            delete[]arr;
            create(1);
            return *this;
        }
        else {
            this->size--;
            int* temp = new int[this->size];
            for (int i = 0; i < this->size; i++)
            {
                temp[i] = this->arr[i];
            }
            delete[]arr;
            arr = temp;
            return *this;
        }
    }

    void operator=(Array obj) {
        this->size = obj.size;
        delete[]this->arr;
        this->arr = new int[this->size];
        for (int i = 0; i < this->size; i++)
        {
            this->arr[i] = obj.arr[i];
        }
    }

    Array operator+(Array obj) {
        int tempSize = this->size + obj.size;
        Array temp(tempSize);
        for (int i = 0; i < this->size; i++)
        {
            temp.arr[i] = this->arr[i];
        }
        for (int i = 0; i < obj.size; i++)
        {
            temp.arr[i + this->size] = obj.arr[i];
        }
        return temp;
    }

    Array operator-(Array obj) {
        int tempSize = this->size - obj.size;
        if (tempSize < 0) {
            Array temp(0);
            return temp;
        }
        else {
            Array temp(tempSize);
            for (int i = 0; i < tempSize; i++)
            {
                temp.arr[i] = this->arr[i];
            }
            return temp;
        }
    }

    static float getRand(float startValue, float finalValue, int precision = 0)
    {
        float randomNumber;
        const int NUMBER_SYSTEM = 10;
        const int UPPER_BOUND_SHIFT = 1;
        int precisionFactor = pow(NUMBER_SYSTEM, precision);
        finalValue += UPPER_BOUND_SHIFT;
        int numbersAmount = (finalValue - startValue) *
            precisionFactor;
        randomNumber = rand() % numbersAmount + startValue *
            precisionFactor;
        randomNumber /= precisionFactor;
        return randomNumber;
    }

    void fillArrRand(float start, float final, int precision = 0) {
        for (int i = 0; i < this->size; i++)
        {
            this->arr[i] = getRand(start, final, precision);
        }
    }

    void PrintArr() {
        if (size == 0) {
            cout << "NULL";
        }
        else {
            for (int i = 0; i < this->size; i++)
            {
                cout << arr[i] << "\t";
            }
        }
        cout << endl;
    }
};

class Menu
{
    const short int COUNT_MENU_POINT = 15;
    short int userChoice = 1;
public:

    void ShowWellcom()
    {
        cout << "==========================================================================";
        cout << endl << endl;
        cout << "\tКраткое описание\n"
            "Это программа для тестирования работы класса Динамического массива.\n"
            "Данная программа создает 3 объекта динамического массива\n"
            "Программа предлагает заполнить вывести сложить или вычестить массивы\n"
            "Программа предлагает добавление в конец или в начало элемента массива либо\n"
            "удаление элементов массива в начале или в конце\n"
            "Так же можно внести значения каждому элементу массива отдельно\n";
        cout << "==========================================================================";
        cout << endl << endl;
    }

    void ShowMenu()
    {
        cout << endl;
        cout << "Меню программы" << endl;
        cout << "=============================================" << endl;
        cout << "1.  Ввод размеров массивов;" << endl;
        cout << "2.  Заполнить массивы случайными числами;" << endl;
        cout << "3.  Вывести массив;" << endl;
        cout << "4.  Вывести все массивы;" << endl;
        cout << "5.  Присвоение значение одного массива другому;" << endl;
        cout << "6.  формирование массива, являющегося объединением количества элементов двух массивов;" << endl;
        cout << "7.  формирование массива, содержащего количество элементов разности двух массивов;" << endl;
        cout << "8.  Добавление элемента в начало массива;" << endl;
        cout << "9.  Добавление элемента в конец массива;" << endl;
        cout << "10.  Удаление элемента с начало массива;" << endl;
        cout << "11.  Удаление элемента с конца массива;" << endl;
        cout << "12.  Ввести значение определеному элементу массива;" << endl;
        cout << "13.  Вывести значение определенного элемента массива;" << endl;
        cout << "14.  Очистить экран;" << endl;
        cout << "15.  Выход;" << endl;
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
            cout << "Допустимое значение должно быть в диапазоне от 1 до " << COUNT_MENU_POINT << ", пожалуйста, повторите ввод." << endl << endl;
        };
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

void inputIndex(int& index, int check) {
    while (true) {
        cout << "Введите номер массива: ";
        cin >> index;
        if (index > check || index < 1) {
            cout << "Введено не верное значение повторите\n";
        }
        else break;
    }
}

enum MenuPoint {
    INPUT_CAP_ARR = 1,
    FILL_ARR,
    PRINT_ARR,
    PRINT_ALL_ARR,
    ASSIGNMENT,
    ADDITION,
    SUBTRACTION,
    PREFIX_INC,
    POSTFIX_INC,
    PREFIX_DECR,
    POSTFIX_DECR,
    INPUT_VAL_ARR,
    PRINT_VAL_ARR,
    CLEAR_SCREEN,
    EXIT
};

void loop() {
    Menu menu;
    int const QTY_ARR = 3;
    Array arr[QTY_ARR];
    int shift = 1;
    int index;
    int userVal;
    int numberArray;
    int size = 0;
    int userValStart;
    int userValFinal;
    int firstIndex, secondIndex, thirdIndex;
    menu.ShowWellcom();
    menu.waitAndClear();
    menu.ShowMenu();
    while (true) {
        menu.EnterUserChoice();
        switch (menu.GetUserChoice())
        {
        case INPUT_CAP_ARR:
            cout << "----------" << endl;
            for (int i = 0; i < QTY_ARR; i++)
            {
                cout << "Введите размер массива № " << i + shift << ": ";
                cin >> size;
                arr[i].init(size);
            }
            cout << "----------" << endl;
            break;
        case FILL_ARR:
            cout << "----------" << endl;
            for (int i = 0; i < QTY_ARR; i++)
            {
                cout << "Заполняется массив № " << i + shift << endl;
                cout << "Введите начало диапазона случайных чисел: ";
                cin >> userValStart;
                cout << "Введите конец диапазона случайных чисел: ";
                cin >> userValFinal;
                arr[i].fillArrRand(userValStart, userValFinal);
                cout << "Результат :\n";
                arr[i].PrintArr();
            }
            cout << "----------" << endl;
            break;
        case PRINT_ARR:
            cout << "----------" << endl;
            inputIndex(numberArray, QTY_ARR);
            cout << "Массива № " << numberArray << ": ";
            arr[numberArray - shift].PrintArr();
            cout << "----------" << endl;
            break;
        case PRINT_ALL_ARR:
            cout << "----------" << endl;
            for (int i = 0; i < QTY_ARR; i++)
            {
                cout << "Массива № " << i + shift << ": ";
                arr[i].PrintArr();
            }
            cout << "----------" << endl;
            break;
        case ASSIGNMENT:
            cout << "----------" << endl;
            cout << "Введите номер массива для присвоения значения: ";
            cin >> firstIndex;
            cout << "Введите номер массива присваемого: ";
            cin >> secondIndex;
            cout << "----------" << endl;
            cout << "Массива № " << firstIndex << ": ";
            arr[firstIndex - shift].PrintArr();
            cout << "Массива № " << secondIndex << ": ";
            arr[secondIndex - shift].PrintArr();
            arr[firstIndex - shift] = arr[secondIndex - shift];
            cout << "Результат :\n";
            cout << "Массива № " << firstIndex << ": ";
            arr[firstIndex - shift].PrintArr();
            cout << "----------" << endl;
            break;
            break;
        case ADDITION:
            cout << "----------" << endl;
            cout << "Введите номер массива для формирования: ";
            cin >> thirdIndex;
            cout << "Введите первый массив: ";
            cin >> firstIndex;
            cout << "Введите второй массив: ";
            cin >> secondIndex;
            cout << "----------" << endl;
            cout << "Массива № " << firstIndex << ": ";
            arr[firstIndex - shift].PrintArr();
            cout << " + \n";
            cout << "Массива № " << secondIndex << ": ";
            arr[secondIndex - shift].PrintArr();
            arr[thirdIndex - shift] = arr[firstIndex - shift] + arr[secondIndex - shift];
            cout << "Результат :\n";
            cout << "Массива № " << thirdIndex << ": ";
            arr[thirdIndex - shift].PrintArr();
            cout << "----------" << endl;
            break;
        case SUBTRACTION:
            cout << "----------" << endl;
            cout << "Введите номер массива для формирования: ";
            cin >> thirdIndex;
            cout << "Введите первый массив: ";
            cin >> firstIndex;
            cout << "Введите второй массив: ";
            cin >> secondIndex;
            cout << "----------" << endl;
            cout << "Массива № " << firstIndex << ": ";
            arr[firstIndex - shift].PrintArr();
            cout << " - \n";
            cout << "Массива № " << secondIndex << ": ";
            arr[secondIndex - shift].PrintArr();
            arr[thirdIndex - shift] = arr[firstIndex - shift] - arr[secondIndex - shift];
            cout << "Результат :\n";
            cout << "Массива № " << thirdIndex << ": ";
            arr[thirdIndex - shift].PrintArr();
            cout << "----------" << endl;
            break;
        case PREFIX_INC:
            cout << "----------" << endl;
            inputIndex(numberArray, QTY_ARR);
            ++arr[numberArray - shift];
            cout << "Результат :\n";
            arr[numberArray - shift].PrintArr();
            cout << "----------" << endl;
            break;
        case POSTFIX_INC:
            inputIndex(numberArray, QTY_ARR);
            arr[numberArray - shift]++;
            cout << "Результат :\n";
            arr[numberArray - shift].PrintArr();
            cout << "----------" << endl;
            break;
        case PREFIX_DECR:
            cout << "----------" << endl;
            inputIndex(numberArray, QTY_ARR);
            --arr[numberArray - shift];
            cout << "Результат :\n";
            arr[numberArray - shift].PrintArr();
            cout << "----------" << endl;
            break;
        case POSTFIX_DECR:
            cout << "----------" << endl;
            inputIndex(numberArray, QTY_ARR);
            arr[numberArray - shift]--;
            cout << "Результат :\n";
            arr[numberArray - shift].PrintArr();
            cout << "----------" << endl;
            break;
        case INPUT_VAL_ARR:
            cout << "----------" << endl;
            inputIndex(numberArray, QTY_ARR);
            cout << "Введите номер элемента массива : ";
            cin >> index;
            cout << "Введите значение для сохранения в массив : ";
            cin >> userVal;
            arr[numberArray - shift][index - shift] = userVal;
            cout << "Результат :\n";
            arr[numberArray - shift].PrintArr();
            cout << "----------" << endl;
            break;
        case PRINT_VAL_ARR:
            cout << "----------" << endl;
            inputIndex(numberArray, QTY_ARR);
            cout << "Введите номер элемента массива : ";
            cin >> index;
            cout << "Значение ячейки массива: " << arr[numberArray - shift][index - shift] << endl;
            cout << "----------" << endl;
            break;
        case CLEAR_SCREEN:
            menu.waitAndClear();
            menu.ShowMenu();
            break;
        case EXIT:
            exit(0);
            break;
        default:
            break;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    loop();
    return 0;
}
