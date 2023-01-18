#include <math.h>
#include "tasks.hpp"

// long double длинное число(64 бита) с плавающей точкой
long double f1(double x) {
  return (1 + pow(x, 2)) / (2 - sqrt(1 + pow(x, 4)));
}

long double f2(double x) {
  return (1 + fabs(x)) / (pow(1 + x + pow(x, 3), 1 / 3));
}