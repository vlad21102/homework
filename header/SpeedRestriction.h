#pragma once

#include "Piquet.h"
#include "Restriction.h"

#include <iosfwd>
#include <string>

/**
* @brief Класс ограничения скорости на линии метрополитена
*/
class SpeedRestriction : public Restriction
{
private:
    Piquet start;
    Piquet finish;
    double speedLimit;

public:
    /**
    * @brief Создаёт ограничение скорости
    * @param startPiquet - начало действия предупреждения
    * @param finishPiquet - конец действия предупреждения
    * @param speed - ограничение скорости
    */
    SpeedRestriction(const Piquet& startPiquet, const Piquet& finishPiquet, double speed);

    /**
    * @brief Возвращает начало действия предупреждения
    * @return начало действия предупреждения
    */
    Piquet GetStart() const;

    /**
    * @brief Возвращает конец действия предупреждения
    * @return конец действия предупреждения
    */
    Piquet GetFinish() const;

    /**
    * @brief Возвращает ограничение скорости
    * @return ограничение скорости
    */
    double GetSpeedLimit() const;

    /**
    * @brief Возвращает строковое представление ограничения скорости
    * @return строковое представление ограничения скорости
    */
    std::string ToString() const override;

    /**
    * @brief Возвращает строковое представление ограничения скорости
    * @param restriction - ограничение скорости
    * @return строковое представление ограничения скорости
    */
    static std::string ToString(const SpeedRestriction& restriction);

    /**
    * @brief Считывает ограничение скорости из входного потока
    * @param in - входной поток
    * @return ограничение скорости
    */
    static SpeedRestriction Read(std::istream& in);

    /**
    * @brief Оператор равенства
    * @param other - другое ограничение скорости
    * @return true, если ограничения равны
    */
    bool operator == (const SpeedRestriction& other) const;

    /**
    * @brief Оператор неравенства
    * @param other - другое ограничение скорости
    * @return true, если ограничения не равны
    */
    bool operator != (const SpeedRestriction& other) const;

    /**
    * @brief Оператор вывода ограничения скорости
    * @param out - выходной поток
    * @param restriction - ограничение скорости
    * @return выходной поток
    */
    friend std::ostream& operator << (std::ostream& out, const SpeedRestriction& restriction);

    /**
    * @brief Оператор ввода ограничения скорости
    * @param in - входной поток
    * @param restriction - ограничение скорости
    * @return входной поток
    */
    friend std::istream& operator >> (std::istream& in, SpeedRestriction& restriction);
};
