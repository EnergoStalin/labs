#include <iostream>
#include "tasks.hpp"

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