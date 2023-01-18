#include <iostream>
#include <math.h>

using namespace std;

// long double ������� �����(256 ���) � ��������� ������
long double fun1(double x) {
	return (1 + x*x) / (2 - sqrt(1 + pow(x, 4)));
}

long double fun2(double x) {
	return (1 + fabs(x)) / (pow(1 + x + pow(x, 3), 1 / 3));
}

void f2min() {
    float a[4]; // �����������(������ ����������� �������) ������ �� 4 ��������

    // ������ ������ � �����
    // size_t - ������� ����������� �����(�� ����� ���� �������������)
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }

    // ������� ���������� ���������(bubble sort)
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

    // ��������� ������ ������ ��������������� ����� ������ ����� ������ 2
    // �������� ��� ��������� �� �����
    cout << a[0] << endl << a[1] << endl; // endl - ����� ������
}

int main() {
	cout << fun1(81) << endl << fun2(15) << endl; // ����� ������� � 1 ���������� � ����� ��� � �������

	f2min(); // ����� ������� ��� ����������

	return 0;
}