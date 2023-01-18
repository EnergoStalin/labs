#include <iostream>
#include <math.h>

// long double ������� �����(64 ����) � ��������� ������
long double f1(double x) {
	return (1 + pow(x, 2)) / (2 - sqrt(1 + pow(x, 4)));
}

long double f2(double x) {
	return (1 + fabs(x)) / (pow(1 + x + pow(x, 3), 1 / 3));
}

void t1() {
    double x[4]; // �����������(������ ����������� �������) ������ �� 4 ��������

    // ������ ������ � �����
    // size_t - ������� ����������� �����(�� ����� ���� �������������)
    for (size_t i = 0; i < 4; i++) {
        std::cin >> x[i];
    }

    // ������� ���������� ���������(bubble sort)
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

    // ��������� ������ ������ ��������������� ����� ������ ����� ������ 2
    // �������� ��� ��������� �� �����
    std::cout << x[0] << std::endl; // endl - ����� ������
    std::cout << x[1] << std::endl;
}

int main() {
	std::cout << f1(81) << std::endl; // ����� ������� � 1 ���������� � ����� ��� � �������
	std::cout << f2(15) << std::endl; // ����������

	t1(); // ����� ������� ��� ����������

	return 0;
}