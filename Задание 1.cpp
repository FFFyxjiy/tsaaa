#include <iostream>
#include <cmath>

using namespace std;

// Исходные значения для вычислений
const double VALUE_X = 2.0;
const double VALUE_Y = 0.7;
const double VALUE_Z = -1.0;

double calculate_a(double x, double y, double z) {
    double numerator = x * y * z + abs(z * sin(y));
    return cbrt(numerator);
}

double calculate_b(double x, double y, double z) {
    double cos_argument = x * z * sin(y);
    return y * cos(cos_argument) + 3; 
}

int main() {
    double a = calculate_a(VALUE_X, VALUE_Y, VALUE_Z);
    double b = calculate_b(VALUE_X, VALUE_Y, VALUE_Z);

    cout << "Исходные данные:" << endl;
    cout << "x = " << VALUE_X << endl;
    cout << "y = " << VALUE_Y << endl;
    cout << "z = " << VALUE_Z << endl;
    cout << endl;
    cout << "Результаты вычислений:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}

