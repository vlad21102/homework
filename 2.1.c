#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
* @brief Считывает значение введённое с клавиатуры, с проверкой ввода
* @return Возвращает считанное значение
*/
double getValue(void);

/**
* @brief Вычисляет периметр треугольника по 3 заданным точкам
* @param Ax - координаты точки A по оси x
* @param Ay - координаты точки A по оси y
* @param Bx - координаты точки B по оси x
* @param By - координаты точки B по оси y
* @param Сx - координаты точки С по оси x
* @param Сy - координаты точки С по оси y
* @return Периметр треугольника
*/
const double getP(const double Ax, const double Ay, const double Bx, const double By, const double Cx, const double Cy);

/**
* @brief Вычисляет площадь треугольника по 3 заданным точкам
* @param Ax - координаты точки A по оси x
* @param Ay - координаты точки A по оси y
* @param Bx - координаты точки B по оси x
* @param By - координаты точки B по оси y
* @param Сx - координаты точки С по оси x
* @param Сy - координаты точки С по оси y
* @return Площадь треугольника
*/
const double getS(const double Ax, const double Ay, const double Bx, const double By, const double Cx, const double Cy);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа выполнена корректно, иначе 1
*/
int main(void)
{
  system("chcp 1251");

  printf("Введите координаты точки A в формате(x; y):\n");
  double Ax = getValue();
  double Ay = getValue();

  printf("Введите координаты точки B в формате(x; y):\n");
  double Bx = getValue();
  double By = getValue();

  printf("Введите координаты точки C в формате(x; y):\n");
  double Cx = getValue();
  double Cy = getValue();
  
  printf("Периметр = %.2lf\nПлощадь = %.2lf\n", getP(Ax,Ay,Bx,By,Cx,Cy), getS(Ax, Ay, Bx, By, Cx, Cy));

  return 0;
}

double getValue(void)
{
  double value = 0;
  if (!scanf_s("%lf", &value))
  {
    fprintf(stderr, "Error, ошибка чтения");
    exit(1);
  }

  return value;
}

const double getS(const double Ax, const double Ay, const double Bx, const double By, const double Cx, const double Cy)
{
  double ABx = Bx - Ax;
  double ABy = By - Ay;

  double ACx = Cx - Ax;
  double ACy = Cy - Ay;

  return 1.0 / 2 * fabs(ABx * ACy - ABy * ACx);
}

const double getP(const double Ax, const double Ay, const double Bx, const double By, const double Cx, const double Cy)
{
  double lenAB = sqrt(pow(Bx - Ax, 2) + pow(By - Ay, 2));
  double lenBC = sqrt(pow(Cx - Bx, 2) + pow(Cy - By, 2));
  double lenAC = sqrt(pow(Cx - Ax, 2) + pow(Cy - Ay, 2));
  return lenAB + lenBC + lenAC;
}
