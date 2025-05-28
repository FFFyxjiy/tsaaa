#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
*@brief Считывает значиния с клавиатуры с проверкой ввода
*@return возвращает значение, если оно правильное , иначе завершает программу
*/
double getValue();

/**
*@brief  Функция для вычисления значения функции y = 0.1 * x * x - x * log(x)
*@return a
*/
double calculateFunction(const double x);

/**
*@brief  Функция для проверки, что шаг положительный
*@param step шаг с которым идёт постороение графика
*@return step
*/
double getPositiveStep();

/**
 *@brief  запрашивает у пользователя ввод положительного значения x,
 * и продолжает запрашивать значение до тех пор, пока не будет введено положительное число.
 * @return Возвращает введенное положительное значение x.
 */
double getPositiveX();

/**
*@brief  Функция для проверки, что значение x является ООФ
*@param x значение x
*@return true, если x является ООФ, иначе false
*/
bool OOF(double x);

/**
*@brief  точка хода в программу
*@return 0
*/
int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите начальное значение x: ";
    double startX = getPositiveX();

    cout << "Введите конечное значение x: ";
    double endX = getPositiveX();

    if (startX > endX)
    {
        cout << "Ошибка: xstart должно быть меньше, чем xend" << endl;
        return 1;
    }

    cout << "Введите шаг: ";
    double step = getPositiveStep();

    cout << "x | y" << endl;
    cout << "--------" << endl;

    for (double x = startX; x < endX + step; x += step)
    {
        if (OOF(x))
        {
            double y = calculateFunction(x);
            cout << x << " | " << y << endl;
        }
    }

    return 0;
}

double getValue()
{
    double value;
    cin >> value;
    if (cin.fail())
    {
        cout << "Некорректное значение" << endl;
        abort();
    }
    return value;
}


double calculateFunction(const double x)
{
    double a = 0.1 * x * x - x * log(x);
    return a;
}

double getPositiveStep()
{
    double step;
    do {
        step = getValue();
        if (step <= 0)
        {
            cout << "Ошибка. Шаг должен быть положительным. Повторите ввод." << endl;
        }
    } while (step <= 0);
    return step;
}

double getPositiveX()
{
    double x;
    do {
        cout << "Введите положительное значение x: ";
        x = getValue();
        if (x <= 0)
        {
            cout << "Ошибка. X должно быть положительным. Повторите ввод." << endl;
        }
    } while (x <= 0);
    return x;
}

bool OOF(double x)
{
    return x > 0;
}