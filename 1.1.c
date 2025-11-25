#include<stdio.h>

#include<math.h>

/
* @brief рассчёт значения функции A
* @param x - значение параметра x
* @param y - значение параметра y
* @param z - значение параметра z
* @return рассчитанное значение
*/
double defA(const double x, const double y, const double z);

/
* @brief рассчёт значения функции B
* @param x - значение параметра x
* @param y - значение параметра y
* @param z - значение параметра z
* @return рассчитанное значение
*/
double defB(const double x, const double y, const double z);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
  const double x = 1.4;
  const double y = 3.1;
  const double z = 0.5;

  printf("A = %.5f\nB = %.5f", defA(x, y, z), defB(x, y, z));

  return 0;
}

double defA(const double x, const double y, const double z)
{
  return (pow(x, 2) * (x + 1)) / (y - ((sin(x + z)) * (sin(x + z))));
}

double defB(const double x, const double y, const double z)
{
  return sqrt(x * y / z) + cos((x + y) * (x + y)) * cos((x + y) * (x + y));
