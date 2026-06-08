#include "../header/Cylinder.h"

#include <cstdlib>
#include <iostream>
#include <numbers>

Cylinder::Cylinder(const Point& centerPoint, const double cylinderRadius, const double cylinderHeight)
    : center(centerPoint), radius(cylinderRadius), height(cylinderHeight)
{
    if (radius <= 0)
    {
        std::cout << "Ошибка: радиус должен быть положительным" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    if (height <= 0)
    {
        std::cout << "Ошибка: высота должна быть положительной" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

double Cylinder::GetVolume() const
{
    return std::numbers::pi * radius * radius * height;
}

bool Cylinder::IsPointInside(const Point& point) const
{
    const double deltaX = point.GetX() - center.GetX();
    const double deltaY = point.GetY() - center.GetY();

    const double distanceToAxisSquared = deltaX * deltaX + deltaY * deltaY;
    const double radiusSquared = radius * radius;

    const bool isInsideBase = distanceToAxisSquared <= radiusSquared;

    const bool isInsideHeight =
        point.GetZ() >= center.GetZ() &&
        point.GetZ() <= center.GetZ() + height;

    return isInsideBase && isInsideHeight;
}
