#include "../header/Piquet.h"

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

bool AreDoublesEqual(double first, double second)
{
    return std::fabs(first - second) <= std::numeric_limits<double>::epsilon();
}

std::string FormatDouble(double value)
{
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << value;

    std::string text = stream.str();

    for (char& symbol : text)
    {
        if (symbol == '.')
        {
            symbol = ',';
        }
    }

    return text;
}

Piquet::Piquet(int piquetNumber, double piquetShift, double piquetLength)
    : number(piquetNumber), shift(piquetShift), length(piquetLength)
{
    if (shift < 0.0)
    {
        std::cerr << "Смещение пикета должно быть неотрицательным" << std::endl;
        exit(1);
    }

    if (length <= 0.0)
    {
        std::cerr << "Длина пикета должна быть положительной" << std::endl;
        exit(1);
    }

    if (shift > length)
    {
        std::cerr << "Смещение пикета не может быть больше длины пикета" << std::endl;
        exit(1);
    }
}

int Piquet::GetNumber() const
{
    return number;
}

double Piquet::GetShift() const
{
    return shift;
}

double Piquet::GetLength() const
{
    return length;
}

bool Piquet::IsStandard() const
{
    return AreDoublesEqual(length, 100.0);
}

double Piquet::GetCoordinate() const
{
    if (number >= 0)
    {
        return number * length + shift;
    }

    return number * length - shift;
}

std::string Piquet::ToString() const
{
    std::ostringstream stream;
    stream << "ПК ";

    if (number < 0)
    {
        stream << "0" << std::abs(number);
    }
    else
    {
        stream << number;
    }

    stream << "+" << FormatDouble(shift);
    return stream.str();
}

bool Piquet::operator == (const Piquet& other) const
{
    return number == other.number &&
        AreDoublesEqual(shift, other.shift) &&
        AreDoublesEqual(length, other.length);
}

bool Piquet::operator != (const Piquet& other) const
{
    return !(*this == other);
}

bool Piquet::operator < (const Piquet& other) const
{
    return GetCoordinate() < other.GetCoordinate();
}

bool Piquet::operator > (const Piquet& other) const
{
    return other < *this;
}

bool Piquet::operator <= (const Piquet& other) const
{
    return !(*this > other);
}

bool Piquet::operator >= (const Piquet& other) const
{
    return !(*this < other);
}

std::ostream& operator << (std::ostream& out, const Piquet& piquet)
{
    out << piquet.ToString();
    return out;
}

std::istream& operator >> (std::istream& in, Piquet& piquet)
{
    int number;
    double shift;
    double length;

    in >> number >> shift >> length;

    if (!in)
    {
        std::cerr << "Ошибка ввода пикета" << std::endl;
        exit(1);
    }

    piquet = Piquet(number, shift, length);
    return in;
}
