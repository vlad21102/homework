#include "../header/Point.h"

Point::Point(const double xCoordinate, const double yCoordinate, const double zCoordinate)
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
