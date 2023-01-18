#include <iostream>
#include <math.h>

using namespace std;

// long double длинное число(256 бит) с плавающей точкой
long double fun1(double x) {
	return (1 + x*x) / (2 - sqrt(1 + pow(x, 4)));
}

long double fun2(double x) {
	return (1 + fabs(x)) / (pow(1 + x + pow(x, 3), 1 / 3));
}

void f2min() {
    float a[4]; // Статический(память освобождать ненужно) массив на 4 элемента

    // Читаем массив в цикле
    // size_t - длинное беззнаковое число(не может быть отрицательным)
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }

    // Обычная сортировка пузырьком(bubble sort)
    // https://en.wikipedia.org/wiki/Bubble_sort
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 3; k++) {
            if (a[k] > a[k + 1]) {
                float t = a[k];
                a[k] = a[k + 1];
                a[k + 1] = t;
            }
        }
    }

    // Поскольку массив теперь отсортированный можно просто взять первые 2
    // элемента или последние не помню
    cout << a[0] << endl << a[1] << endl; // endl - конец строки
}

int main() {
	cout << fun1(81) << endl << fun2(15) << endl; // Вызов функции с 1 аргументом и вывод его в консоль

	f2min(); // Вызов функции без аргументов

	return 0;
}