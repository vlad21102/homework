#pragma once

#include <string>

/**
* @brief Абстрактный базовый класс ограничения
*/
class Restriction
{
public:
    /**
    * @brief Виртуальный деструктор
    */
    virtual ~Restriction() = default;

    /**
    * @brief Возвращает строковое представление ограничения
    * @return строковое представление ограничения
    */
    virtual std::string ToString() const = 0;
};
