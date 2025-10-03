#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <vector> // Используем vector для упрощения копирования

using namespace std;

/**
 * @brief оператор выбора способа заполнения массива
 * @param RANDOM = 0 автоматическое заполнение
 * @param MANUALLY =1 ручное заполнение
 */
enum SELECT
{
    RANDOM = 0,
    MANUALLY = 1
};

/**
 * @brief проверяет размер массива
 * @param n - размер массива
 */
void checkN(const int n);

/**
 * @brief считывает размер массива
 * @return размер массива в беззнаковом типе данных
 */
size_t getSize();

/**
 * @brief считывает значение типа int
 * @return считанное значение целочисленное
 */
int getNumber();

/**
 * @brief вывод массива на экран
 * @param arr - массив
 * @param n - размер массива
 */
void printArray(const int* arr, const int n);

/**
 * @brief заполнение массива автоматически случайными числами в заданном диапазоне
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArrayRandom(int* arr, const int n, const int min, const int max);

/**
 * @brief проверяет диапазон
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void checkRange(const int min, const int max);

/**
 * @brief суммирует все элементы массива, значения которых по модулю меньше 10.
 * @param arr Указатель на массив целых чисел.
 * @param n Количество элементов в массиве.
 * @return Сумма элементов массива, значения которых по модулю меньше 10.
 */
int sumOfElementsBelow10(const int* arr, const int n);

/**
 * @brief Функция выводит индексы тех элементов, значения которых больше значения последующего элемента.
 * @param arr  массив
 * @param n Количество элементов в массиве
 */
void printIndexesLargerThanNext(const int* arr, const int n);

/**
* @brief Проходит по всем элементам массива. Проверяет, является ли текущий элемент нечетным и кратным 3. Если условие выполняется, умножает значение элемента на значение элемента с индексом 2.
* @param arr  Указатель на массив целых чисел
* @param n  Количество элементов в массиве
*/
void multiplyOddMultiplesOf3ByIndex(int* arr, const int n);

/**
 * @brief заполнение массива вручную
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArray( int* arr, const int n, const int min, const int max);

/**
* @brief точка входа в программу
* @return 0 - если программма выполнена корректно, иначе -1
*/
int main()
{

    setlocale(LC_ALL, "Russian");
    int n = getSize();
    int* arr = new int[n];

    cout << "Введите минимальное и максимальное значение диапазона: ";
    int minValue = getNumber();
    int maxValue = getNumber();
    checkRange(minValue, maxValue);

    cout << "Введите выбор для заполнения массива: " << endl
        << RANDOM << " Для случайного заполнения" << endl
        << MANUALLY << " Для ручного заполнения" << endl;

    int choice = getNumber();

    switch ((enum SELECT)choice)
    {
    case RANDOM:
        fillArrayRandom(arr, n, minValue, maxValue);
        break;
    case MANUALLY:
        fillArray(arr, n, minValue, maxValue);
        break;
    default:
        cout << "Ваш выбор неверен" << endl;
        return -1;
        break;
    }

    cout << "Элементы массива:" << endl;
    printArray(arr, n);

    // Вызов функций
    cout << "Сумма элементов, значения которых по модулю меньше 10: " << sumOfElementsBelow10(arr, n) << endl;

    cout << "Индексы тех элементов, значения которых больше значения последующего элемента: ";
    printIndexesLargerThanNext(arr, n);
    cout << endl;
// Создаем копию массива перед модификацией, если исходный массив нужен для дальнейшего использования.
    // Если исходный массив после этой точки не нужен, то модификация на месте допустима.
    std::vector<int> modifiedArr(arr, arr + n); // Копирование в vector для демонстрации
    // Если придерживаться сырых указателей, нужно было бы вручную выделить память и скопировать:
    // int* modifiedArr = new int[n];
    // for (size_t i = 0; i < n; ++i) {
    //     modifiedArr[i] = arr[i];
    // }

    multiplyOddMultiplesOf3ByIndex(modifiedArr.data(), n); // Передаем указатель на скопированные данные

    cout << "Измененный массив: ";
    // Вместо дублирующего кода для вывода массива, вызываем существующую функцию printArray
    printArray(modifiedArr.data(), n); // Передаем указатель на данные измененного вектора
    cout << endl; // Добавляем перевод строки после вывода, как было в исходном коде

    delete[] arr; // Не забываем удалить исходный массив

    return 0;
}

void checkN(const int n)
{
    if (n <= 0)
    {
        cout << "Неправильный размер массива" << endl;
        abort();
    }
}

size_t getSize()
{
    cout << "Введите размер массива: ";
    int n;
    cin >> n;
    checkN(n);
    return (size_t)n;
}

int getNumber()
{
    int number;
    cin >> number;
    if (cin.fail())
    {
        cout << "Неправильный ввод данных";
        abort();
    }
    return number;
}

// Изменена функция printArray, чтобы она выводила элементы в одну строку через пробел
// и добавляла перевод строки в конце, если это требуется для данного вывода
void printArray(const int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // Вывод элемента и пробела
    }
    // Здесь не нужно добавлять cout << endl;, так как оно будет добавлено в main после вызова
    // для измененного массива. Если требуется перевод строки после каждого вывода массива,
    // тогда можно добавить его здесь.
}


void fillArrayRandom(int* arr, const int n, const int min, const int max)
{
    srand(time(0));
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void checkRange(const int min, const int max)
{
    if (min > max)
    {
        cout << "Введен неправильный диапазон" << endl;
        abort();
    }
}

int sumOfElementsBelow10(const int* arr, const int n)
{
    int sum = 0;
    for (size_t i = 0; i < n; i++) {
        if (abs(arr[i]) < 10) {
            sum += arr[i];
        }
    }
    return sum;
}

void printIndexesLargerThanNext(const int* arr, const int n)
{
    for (size_t i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            cout << i << " ";
        }
    }
}

void multiplyOddMultiplesOf3ByIndex(int* arr, const int n)
{
    if (n < 3) {
        cout << "Ошибка: Размер массива меньше 3. Невозможно использовать arr[2] для умножения." << endl;
        return;
    }

    int valueOfArr2 = arr[2];

    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0 && arr[i] % 3 == 0)
        {
            arr[i] *= valueOfArr2;
        }
    }
}

void fillArray( int* arr, const int n, const int min, const int max)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "Введите значение для arr[" << i << "]: ";
        arr[i] = getNumber();
        if (arr[i] < min || arr[i] > max)
        {
            cout << "Значение вне диапазона. Повторите ввод." << endl;
            i--;
        }
    }
}
