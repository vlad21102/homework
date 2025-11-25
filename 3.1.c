#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<float.h>

/**
* @brief Рассчитывает значение функции в точке
* @param x - точка
* @return Рассчитанное значение
*/
const double function(const double x);

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double defValue();

/**
* @brief Проверяет значения на условие
* @param end - значение конца промежутка
* @param start - значение начала промежутка
*/
void checkEndStart(const double start, const double end);

/**
* @brief Проверяет значение на условие
* @param step - значение шага
*/
void checkStep(const double step);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
  system("chcp 1251");

  printf("Введите начальное значение: ");
  double start = defValue();
  printf("Введите конечное значение: ");
  double end = defValue();
  checkEndStart(start, end);

  printf("Введите шаг: ");
  double step = defValue();
  checkStep(step);

  printf("%-10s %s\n", "x", "f(x)");
  for (double x = start; x < end + DBL_EPSILON; x += step)
  {
    printf_s("%-10.2lf%.4lf\n", x, function(x));
  }

  return 0;
}

const double function(const double x)
{
  return 3 * x - 14 + exp(x) - exp(-x);
}

double defValue()
{
  double value = 0;
  if (!scanf_s("%lf", &value))
  {
    fprintf(stderr, "Error\n");
    exit(1);
  }
  return value;
}

void checkEndStart(const double start, const double end)
{
  if (!(start < end))
  {
    fprintf(stderr, "Error\n");
    exit(1);
  }
}

void checkStep(const double step)
{
  if (step <= DBL_EPSILON)
  {
    fprintf(stderr, "Error\n");
    exit(1);
  }
}
