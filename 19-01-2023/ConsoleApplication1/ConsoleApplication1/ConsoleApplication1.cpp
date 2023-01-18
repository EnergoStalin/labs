#include <iostream>
#include <math.h>

// long double длинное число(64 бита) с плавающей точкой
long double f1(double x) {
	return (1 + pow(x, 2)) / (2 - sqrt(1 + pow(x, 4)));
}

long double f2(double x) {
	return (1 + fabs(x)) / (pow(1 + x + pow(x, 3), 1 / 3));
}

void t1() {
    double x[4]; // Статический(память освобождать ненужно) массив на 4 элемента

    // Читаем массив в цикле
    // size_t - длинное беззнаковое число(не может быть отрицательным)
    for (size_t i = 0; i < 4; i++) {
        std::cin >> x[i];
    }

    // Обычная сортировка пузырьком(bubble sort)
    // https://en.wikipedia.org/wiki/Bubble_sort
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 3; j++) {
            if (x[j] > x[j + 1]) {
                double t = x[j];
                x[j] = x[j + 1];
                x[j + 1] = t;
            }
        }
    }

    // Поскольку массив теперь отсортированный можно просто взять первые 2
    // элемента или последние не помню
    std::cout << x[0] << std::endl; // endl - конец строки
    std::cout << x[1] << std::endl;
}

int main() {
	std::cout << f1(81) << std::endl; // Вызов функции с 1 аргументом и вывод его в консоль
	std::cout << f2(15) << std::endl; // Аналогично

	t1(); // Вызов функции без аргументов

	return 0;
}