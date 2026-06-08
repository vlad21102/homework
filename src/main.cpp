#include "../header/Cylinder.h"
#include "../header/Point.h"

#include <cstdlib>
#include <iostream>

/**
 * @brief Считывает вещественное число с клавиатуры
 * @param text сообщение для пользователя
 * @return введённое значение
 */
double getValue(const std::string text);

/**
 * @brief Точка входа в программу
 * @return Если программа выполнена коректно - 0, иначе - 1
 */
int main()
{
    system("chcp 1251");
    system("cls");

    const double centerX =
        getValue("Введите координату X центра цилиндра: ");
    const double centerY =
        getValue("Введите координату Y центра цилиндра: ");
    const double centerZ =
        getValue("Введите координату Z центра цилиндра: ");

    const double radius =
        getValue("Введите радиус цилиндра: ");
    const double height =
        getValue("Введите высоту цилиндра: ");

    const Point center(centerX, centerY, centerZ);
    const Cylinder cylinder(center, radius, height);

    std::cout << "Объём цилиндра: "
              << cylinder.GetVolume()
              << std::endl;

    const double pointX =
        getValue("Введите координату X точки: ");
    const double pointY =
        getValue("Введите координату Y точки: ");
    const double pointZ =
        getValue("Введите координату Z точки: ");

    const Point point(pointX, pointY, pointZ);

    if (cylinder.IsPointInside(point))
    {
        std::cout << "Точка лежит внутри цилиндра"
                  << std::endl;
    }
    else
    {
        std::cout << "Точка не лежит внутри цилиндра"
                  << std::endl;
    }

    return 0;
}

double getValue(const std::string text)
{
    double value;

    std::cout << prompt << std::endl;
    std::cin >> value;
    if (cin.fail())
    {
        std::cout << "Ошибка ввода" << std::endl;
        exit(1);
    }

    return value;
}
