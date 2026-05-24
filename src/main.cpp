#include "../header/Cylinder.h"
#include "../header/Point.h"

#include <cstdlib>
#include <iostream>

int main()
{
    system("chcp 1251");
    system("cls");

    double centerX;
    double centerY;
    double centerZ;
    double radius;
    double height;

    std::cout << "Введите координаты центра цилиндра: ";
    std::cin >> centerX >> centerY >> centerZ;

    std::cout << "Введите радиус и высоту цилиндра: ";
    std::cin >> radius >> height;

    const Point center(centerX, centerY, centerZ);
    const Cylinder cylinder(center, radius, height);

    std::cout << "Объём цилиндра: " << cylinder.GetVolume() << std::endl;

    double pointX;
    double pointY;
    double pointZ;

    std::cout << "Введите координаты точки: ";
    std::cin >> pointX >> pointY >> pointZ;

    const Point point(pointX, pointY, pointZ);

    if (cylinder.IsPointInside(point))
    {
        std::cout << "Точка лежит внутри цилиндра" << std::endl;
    }
    else
    {
        std::cout << "Точка не лежит внутри цилиндра" << std::endl;
    }

    return 0;
}
