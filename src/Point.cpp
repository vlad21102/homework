#include "../header/Point.h"

Point::Point(double xCoordinate, double yCoordinate, double zCoordinate)
    : x(xCoordinate), y(yCoordinate), z(zCoordinate)
{
}

double Point::GetX() const
{
    return x;
}

double Point::GetY() const
{
    return y;
}

double Point::GetZ() const
{
    return z;
}
