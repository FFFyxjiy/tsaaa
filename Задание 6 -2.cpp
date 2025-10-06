#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

enum SELECT
{
    RANDOM = 0,
    MANUALLY = 1
};

void checkN(const int n);

size_t getSize();

int getNumber();

void printArray(const int* arr, const int n);

void fillArrayRandom(int* arr, const int n, const int min, const int max);

void checkRange(const int min, const int max);

int sumOfElementsBelow10(const int* arr, const int n);

void printIndexesLargerThanNext(const int* arr, const int n);

void multiplyOddMultiplesOf3ByIndex(int* arr, const int n);

void fillArray( int* arr, const int n, const int min, const int max);

int* copyArray(const int* sourceArr, const int n);

int main()
{

    setlocale(LC_ALL, "Russian");
    size_t n = getSize();
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
        delete[] arr;
        return -1;
        break;
    }

    cout << "Элементы массива:" << endl;
    printArray(arr, n);

    cout << "Сумма элементов, значения которых по модулю меньше 10: " << sumOfElementsBelow10(arr, n) << endl;

    cout << "Индексы тех элементов, значения которых больше значения последующего элемента: ";
    printIndexesLargerThanNext(arr, n);
    cout << endl;

    int* modifiedArr = copyArray(arr, n);

    multiplyOddMultiplesOf3ByIndex(modifiedArr, n); 

    cout << "Измененный массив: ";
    printArray(modifiedArr, n); 
    cout << endl; 
    
    delete[] arr; 
    delete[] modifiedArr; 

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

void printArray(const int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " "; 
    }
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

int* copyArray(const int* sourceArr, const int n)
{
    if (n <= 0) {
        return nullptr;
    }
    
    int* destArr = new int[n]; 
    
    for (size_t i = 0; i < n; ++i) {
        destArr[i] = sourceArr[i];
    }
    
    return destArr;
}
