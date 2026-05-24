#pragma once

/**
 * @brief Класс точки в пространстве
 */
class Point
{
private:
    double x;
    double y;
    double z;

public:
    /**
     * @brief Создаёт точку
     * @param xCoordinate - координата x
     * @param yCoordinate - координата y
     * @param zCoordinate - координата z
     */
    Point(double xCoordinate, double yCoordinate, double zCoordinate);

    /**
     * @brief Возвращает координату x
     * @return координата x
     */
    double GetX() const;

    /**
     * @brief Возвращает координату y
     * @return координата y
     */
    double GetY() const;

    /**
     * @brief Возвращает координату z
     * @return координата z
     */
    double GetZ() const;
};
