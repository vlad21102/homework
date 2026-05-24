#pragma once

#include "Point.h"

/**
 * @brief Класс цилиндра
 */
class Cylinder
{
private:
    Point center;
    double radius;
    double height;

public:
    /**
     * @brief Создаёт цилиндр
     * @param centerPoint - центр нижнего основания цилиндра
     * @param cylinderRadius - радиус основания цилиндра
     * @param cylinderHeight - высота цилиндра
     */
    Cylinder(const Point& centerPoint, double cylinderRadius, double cylinderHeight);

    /**
     * @brief Возвращает объём цилиндра
     * @return объём цилиндра
     */
    double GetVolume() const;

    /**
     * @brief Проверяет принадлежность точки цилиндру
     * @param point - проверяемая точка
     * @return true если точка лежит внутри цилиндра или на его границе
     */
    bool IsPointInside(const Point& point) const;
};
