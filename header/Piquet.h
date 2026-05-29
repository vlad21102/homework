#pragma once

#include <iosfwd>
#include <string>

/**
* @brief Класс пикета
*/
class Piquet
{
private:
    int number;
    double shift;
    double length;

public:
    /**
    * @brief Создаёт пикет
    * @param piquetNumber - номер пикета
    * @param piquetShift - смещение от начала пикета
    * @param piquetLength - длина пикета
    */
    Piquet(int piquetNumber = 0, double piquetShift = 0.0, double piquetLength = 100.0);

    /**
    * @brief Возвращает номер пикета
    * @return номер пикета
    */
    int GetNumber() const;

    /**
    * @brief Возвращает смещение пикета
    * @return смещение пикета
    */
    double GetShift() const;

    /**
    * @brief Возвращает длину пикета
    * @return длина пикета
    */
    double GetLength() const;

    /**
    * @brief Проверяет, является ли пикет стандартным
    * @return true, если пикет стандартный
    */
    bool IsStandard() const;

    /**
    * @brief Возвращает координату пикета
    * @return координата пикета
    */
    double GetCoordinate() const;

    /**
    * @brief Возвращает строковое представление пикета
    * @return строковое представление пикета
    */
    std::string ToString() const;

    /**
    * @brief Оператор равенства
    * @param other - другой пикет
    * @return true, если пикеты равны
    */
    bool operator == (const Piquet& other) const;

    /**
    * @brief Оператор неравенства
    * @param other - другой пикет
    * @return true, если пикеты не равны
    */
    bool operator != (const Piquet& other) const;

    /**
    * @brief Оператор меньше
    * @param other - другой пикет
    * @return true, если текущий пикет меньше другого
    */
    bool operator < (const Piquet& other) const;

    /**
    * @brief Оператор больше
    * @param other - другой пикет
    * @return true, если текущий пикет больше другого
    */
    bool operator > (const Piquet& other) const;

    /**
    * @brief Оператор меньше или равно
    * @param other - другой пикет
    * @return true, если текущий пикет меньше или равен другому
    */
    bool operator <= (const Piquet& other) const;

    /**
    * @brief Оператор больше или равно
    * @param other - другой пикет
    * @return true, если текущий пикет больше или равен другому
    */
    bool operator >= (const Piquet& other) const;

    /**
    * @brief Оператор вывода пикета
    * @param out - выходной поток
    * @param piquet - пикет
    * @return выходной поток
    */
    friend std::ostream& operator << (std::ostream& out, const Piquet& piquet);

    /**
    * @brief Оператор ввода пикета
    * @param in - входной поток
    * @param piquet - пикет
    * @return входной поток
    */
    friend std::istream& operator >> (std::istream& in, Piquet& piquet);
};
