#include <iostream>

using namespace std;

/**
* @brief Считывает значение с клавиатуры с проверкой ввода
* @return Введённое значение
*/
double getValue();

/**
 * @brief Функция для проверки, что введено положительное число
 * @param value Проверяемое значение
 * @return true, если значение положительное, иначе false
 */
bool checkPositive(int value);

/**
 * @brief Функция для перевода байтов в мегабайты и гигабайты
 * @param bytes Объем информации в байтах
 */
void convertBytes(const int bytes);

int main() {
    setlocale(LC_ALL, "rus");
    cout << "Введите положительное число!" << endl;
    int bytes = getValue();
    while (!checkPositive(bytes)) {
        cout << "Введите положительное число!" << endl;
        bytes = getValue();
    }

    convertBytes(bytes);

    return 0;
}

double getValue()
{
    
    double value;
    cin >> value;
    if (cin.fail())
    {
        cout << "Неправильное значение" << endl;
        abort();
    }
    return value;
}
bool checkPositive(const int value) {
    if (value > 0) {
        return true;
    }
    else {
        return false;
    }
}

void convertBytes(const int bytes) 
{
    double megabytes = bytes / 1024.0 / 1024.0;
    double gigabytes = bytes / 1024.0 / 1024.0 / 1024.0;

    cout << "Объем информации в мегабайтах: " << megabytes << " МБ" << endl;
    cout << "Объем информации в гигабайтах: " << gigabytes << " ГБ" << endl;
}
