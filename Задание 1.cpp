#include <iostream> // Для работы с вводом/выводом (cout)
#include <cmath>    // Для математических функций (cbrt, sin, cos, abs)

using namespace std;

int main() {
    // Заданные константы
    double x = 2.0;
    double y = 0.7;
    double z = -1.0;

    // Вычисление переменной 'a'
    // a = cbrt(x * y * z + abs(z * sin(y)))
    double a_числитель = x * y * z + abs(z * sin(y)); // Теперь можно использовать abs и sin без std::
    double a = cbrt(a_числитель); // Теперь можно использовать cbrt без std::

    // Вычисление переменной 'b'
    // b = y * cos(x * z * sin(y)) + 3
    double b_аргумент = x * z * sin(y); // Теперь можно использовать sin без std::
    double b = y * cos(b_аргумент) + 3; // Теперь можно использовать cos без std::

    // Вывод результатов на экран
    cout << "Исходные данные:" << endl; // Теперь можно использовать cout и endl без std::
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    cout << endl; // Пустая строка для лучшей читаемости
    cout << "Результаты вычислений:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0; // Возвращаем 0, что означает успешное завершение программы
}
