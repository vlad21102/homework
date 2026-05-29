#include "../header/SpeedRestriction.h"

#include <clocale>
#include <iostream>

/**
* @brief Точка входа в программу
* @return Если программа выполнена корректно - 0, иначе 1
*/
int main()
{
    setlocale(LC_ALL, "Russian");

    const Piquet firstStart(12, 28.37, 100.0);
    const Piquet firstFinish(14, 10.0, 100.0);

    const Piquet secondStart(20, 0.0, 95.0);
    const Piquet secondFinish(21, 50.0, 95.0);

    const SpeedRestriction firstRestriction(firstStart, firstFinish, 40.0);
    const SpeedRestriction secondRestriction(secondStart, secondFinish, 60.0);

    std::cout << firstRestriction << std::endl;
    std::cout << secondRestriction << std::endl;

    std::cout << "Введите начало, конец и скорость ограничения" << std::endl;
    std::cout << "Формат пикета: номер смещение длина" << std::endl;
    std::cout << "Пример: 12 28.37 100 14 10 100 40" << std::endl;

    const SpeedRestriction userRestriction = SpeedRestriction::Read(std::cin);

    std::cout << userRestriction << std::endl;

    return 0;
}
