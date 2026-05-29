#include "../header/SpeedRestriction.h"

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

SpeedRestriction::SpeedRestriction(const Piquet& startPiquet, const Piquet& finishPiquet, double speed)
    : start(startPiquet), finish(finishPiquet), speedLimit(speed)
{
    if (finish < start)
    {
        std::cerr << "Конец ограничения не может быть раньше начала" << std::endl;
        exit(1);
    }

    if (speed <= 0.0 || speed > 80.0)
    {
        std::cerr << "Ограничение скорости должно быть больше 0 и не больше 80 км/ч" << std::endl;
        exit(1);
    }
}

Piquet SpeedRestriction::GetStart() const
{
    return start;
}

Piquet SpeedRestriction::GetFinish() const
{
    return finish;
}

double SpeedRestriction::GetSpeedLimit() const
{
    return speedLimit;
}

std::string SpeedRestriction::ToString() const
{
    std::ostringstream stream;
    stream << "Ограничение скорости: от " << start
        << " до " << finish
        << ", скорость " << std::fixed << std::setprecision(2)
        << speedLimit << " км/ч";

    return stream.str();
}

std::string SpeedRestriction::ToString(const SpeedRestriction& restriction)
{
    return restriction.ToString();
}

SpeedRestriction SpeedRestriction::Read(std::istream& in)
{
    Piquet start;
    Piquet finish;
    double speed;

    in >> start >> finish >> speed;

    if (!in)
    {
        std::cerr << "Ошибка ввода ограничения скорости" << std::endl;
        exit(1);
    }

    return SpeedRestriction(start, finish, speed);
}

bool SpeedRestriction::operator == (const SpeedRestriction& other) const
{
    return start == other.start &&
        finish == other.finish &&
        std::fabs(speedLimit - other.speedLimit) <= std::numeric_limits<double>::epsilon();
}

bool SpeedRestriction::operator != (const SpeedRestriction& other) const
{
    return !(*this == other);
}

std::ostream& operator << (std::ostream& out, const SpeedRestriction& restriction)
{
    out << restriction.ToString();
    return out;
}

std::istream& operator >> (std::istream& in, SpeedRestriction& restriction)
{
    restriction = SpeedRestriction::Read(in);
    return in;
}
