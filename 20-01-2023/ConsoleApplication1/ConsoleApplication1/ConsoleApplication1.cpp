#include <iostream>
#include <math.h>
#include <windows.h>

// .editorconfig нужен что бы vs сохраняла файл в utf-8 кодировке и на гите его можно было нормально прочитать

// a *= 5 аналогично a = a * 5
// a += 5 аналогично a = a + 5
// a /= 5 аналогично a = a / 5
// ...
// Операторы сокращённой арифметики думаю ты уже знаком с ними по питону

// Размеры массивов для удобства
// define означает что эти значения просто подставятся на этапе перпроцессинга тот же этап компиляции что и include
// Можно считать просто констанатми
#define SIZE_A 8
#define SIZE_B 10
#define SIZE_C 12

// Выносим чтение массива в функцию т.к. много где понадобится а код одинаковый
// Поскольку массив сам является указателем можно принимать просто указатель вместо именно массива
void ReadArray(int* A, size_t size) {
	for (size_t i = 0; i < size; i++) { // Проходимся по массиву
		std::cin >> A[i];				// Читаем i-тый элемент
	}
}

// 1. Сумма отрицательных элементов массива
void t1(int *A, size_t size) {
    // Принимаем массив для работы в функцию с его размером т.к. массив является указателем а у него нету размера далее аналогично
	int sum = 0;			// Переменная в которую суммируем
	for (size_t i = 0; i < size; i++) {	// Проходимся по массиву циклом
		if (A[i] < 0) {						// Если меньше нуля то
			sum += A[i];					// Суммируем
		}
	}

	std::cout << sum << std::endl; // Выводим результат
}

// 2. Сумму элементов массива с нечетными номерами.
void t2(int* A, size_t size) {

	int sum = 0;
	for (size_t i = 0; i < size; i++) {	// Проходимся по массиву циклом
		if (i % 2 != 0) {						// Если i-индекс не чётный(% - остаток от деления)
			sum += A[i];					// Суммируем
		}
	}

	std::cout << sum << std::endl; // Выводим результат
}

// З. Произведение элементов массива с четными номерами.
void t3(int* A, size_t size) {

	int sum = 1;
	for (size_t i = 0; i < size; i++) {	// Проходимся по массиву циклом
		if (i % 2 == 0) {						// Если i-индекс не чётный(% - остаток от деления)
			sum *= A[i];					// Умножаем
		}
	}

	std::cout << sum << std::endl; // Выводим результат
}

// 4. Дан одномерный массив А. Найти сумму положительных элементов и их количество.
void t4(int* A, size_t size) {
	int sum = 0;
	int count = 0;

	for (size_t i = 0; i < size; i++) {	// Проходимся по массиву циклом
		if (A[i] > 0) {						// Если больше нуля то
			sum += A[i];					// Суммируем
			count++;						// Увеличиваем счётчик на единицу
		}
	}

	std::cout << sum << ' ' << count << std::endl; // Выводим результат
}

// 5. В массиве, состоящем из положительных и отрицательных чисел, определить,
// сколько элементов превосходят по модулю максимальный элемент.
void t5(int* A, size_t size) {
	int count = 0;
	int max = 0;
    // Поиск максимального значения
	for (size_t i = 0; i < size; i++) {	// Проходимся по массиву циклом
		if (A[i] > max) {					// Если элемент больше текущего максимального
			max = A[i];						// Заменяем
		}
	}

    // Подсчёт элементов по модулю больше чем max
    for (size_t i = 0; i < size; i++) {
        if (abs(A[i]) > max) {
            count++;
        }
    }

	std::cout << count << std::endl;	// Выводим результат
}

// 6. Задать массив для работы с числами.Заполнить массив 10 - ми числами с консоли -
// После запуска задачи на решение выполнить обработку массива, увеличив четные
// числав двараза, результат отобразить в консоли, при этом исходные данные должны
// быть видны -
void t6(int* B, size_t size) {

    for (size_t i = 0; i < size; i++) {
        std::cout << B[i] << '\t';
    }
    std::cout << std::endl;

    for (size_t i = 0; i < size; i++) {
        if (i % 2 == 0) {
            B[i] *= 2;
        }
        std::cout << B[i] << '\t'; // Сразу выводим элементы, после применения изменений, через таб что бы не писать 2 цикл и вывод не сьехал при умножении
    }

    std::cout << std::endl;
}

// 7. В массиве определить индексы элементов: значение которых не меньше заданного
// минимума и не больше заданного максимума -
void t7(int* A, size_t size) {
    int min, max;

    std::cout << "Введите макcимальное и минимальное число: ";
    std::cin >> min >> max;

    for (size_t i = 0; i < size; i++) {
        if (A[i] > min && A[i] < max) {
            std::cout << i << ' '; // Сразу выводим через пробел индекс что бы нигде их не хранить
        }
    }
    std::cout << std::endl; // Перевод на новую строку
}

// 8. В массиве А из 12 (N)элементов определить количество элементов : значения
// которых больше среднего арифметического всех элементов.Число N и значения
// элементов массива задаются вводом.
void t8(int* C, size_t size) {
    int srar = 0;
    int count = 0;

    // Сумма элементов
    for (size_t i = 0; i < size; i++) {
        srar += C[i];
    }
    srar /= size; // Делённая на количество

    // Подсчёт элементов больше среднего арифметического
    for (size_t i = 0; i < size; i++) {
        if (C[i] > srar) {
            count++;
        }
    }

    std::cout << count << std::endl;
}

int main()
{
    // Что бы можно было выводить сообщения на русском и не только
    // Работает только под виндой
    SetConsoleOutputCP(CP_UTF8);

    // Статические массивы(осовбождать память не нужно)
    int A[SIZE_A]{ 1,2,3,-9,5,6,-7,8 }; // после препроцессинга -> int A[8]; далее аналогично
    int B[SIZE_B]{ 1,2,-3,4,5,6,7,-8,9,0 };
    int C[SIZE_C]{ 1,-2,3,4,-5,6,7,8,9,0,-1,-2 };

    // Читаем один раз сразу все массивы можно раскомментировать для ввода значений
    // std::cout << "Введите A массив размером 8: ";
    // ReadArray(A, SIZE_A);
    // std::cout << "Введите B массив размером 10: ";
    // ReadArray(B, SIZE_B);
    // std::cout << "Введите C массив размером 12: ";
    // ReadArray(C, SIZE_C);

    // Выполняем задания на заданных массивах
    std::cout << "t1() - ";
    t1(A, SIZE_A);
    std::cout << "t2() - ";
    t2(A, SIZE_A);
    std::cout << "t3() - ";
    t3(A, SIZE_A);
    std::cout << "t4() - ";
    t4(A, SIZE_A);
    std::cout << "t5() - ";
    t5(A, SIZE_A);
    std::cout << "t6()" << std::endl;
    t6(B, SIZE_B);
    std::cout << "t7() - ";
    t7(A, SIZE_A);
    std::cout << "t8() - ";
    t8(C, SIZE_C);
}
