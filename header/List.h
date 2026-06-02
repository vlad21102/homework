#pragma once
#include "Node.h"
#include <initializer_list>
#include <iosfwd>
#include <string>

/**
* @brief Класс линейного односвязного списка
*/
class List
{
private:
	Node* head;
	size_t size;

	/**
	* @brief Копирует элементы списка
	* @param other - копируемый список
	*/
	void Copy(const List& other);

public:
	/**
	* @brief Создаёт пустой список
	*/
	List();

	/**
	* @brief Создаёт список из набора значений
	* @param values - набор значений
	*/
	List(std::initializer_list<int> values);

	/**
	* @brief Создаёт копию списка
	* @param other - копируемый список
	*/
	List(const List& other);

	/**
	* @brief Переносит список
	* @param other - переносимый список
	*/
	List(List&& other) noexcept;

	/**
	* @brief Удаляет список
	*/
	~List();

	/**
	* @brief Оператор копирующего присваивания
	* @param other - копируемый список
	* @return текущий список
	*/
	List& operator = (const List& other);

	/**
	* @brief Оператор перемещающего присваивания
	* @param other - переносимый список
	* @return текущий список
	*/
	List& operator = (List&& other) noexcept;

	/**
	* @brief Оператор добавления элемента в конец списка
	* @param value - добавляемое значение
	* @return текущий список
	*/
	List& operator << (int value);

	/**
	* @brief Оператор извлечения первого элемента списка
	* @param value - значение первого элемента
	* @return текущий список
	*/
	List& operator >> (int& value);

	/**
	* @brief Добавляет элемент в начало списка
	* @param value - добавляемое значение
	*/
	void PushFront(int value);

	/**
	* @brief Добавляет элемент в конец списка
	* @param value - добавляемое значение
	*/
	void PushBack(int value);

	/**
	* @brief Добавляет элемент по индексу
	* @param index - индекс элемента
	* @param value - добавляемое значение
	*/
	void Insert(size_t index, int value);

	/**
	* @brief Удаляет элемент по значению
	* @param value - удаляемое значение
	* @return true, если элемент удалён
	*/
	bool Remove(int value);

	/**
	* @brief Удаляет первый элемент списка
	* @return значение первого элемента
	*/
	int PopFront();

	/**
	* @brief Проверяет наличие элемента в списке
	* @param value - искомое значение
	* @return true, если элемент найден
	*/
	bool Contains(int value) const;

	/**
	* @brief Изменяет значение элемента
	* @param oldValue - старое значение
	* @param newValue - новое значение
	* @return true, если элемент изменён
	*/
	bool Change(int oldValue, int newValue);

	/**
	* @brief Возвращает значение элемента
	* @param index - индекс элемента
	* @return значение элемента
	*/
	int GetValue(size_t index) const;

	/**
	* @brief Возвращает количество элементов списка
	* @return количество элементов списка
	*/
	size_t GetSize() const;

	/**
	* @brief Проверяет список на пустоту
	* @return true, если список пуст
	*/
	bool IsEmpty() const;

	/**
	* @brief Очищает список
	*/
	void Clear();

	/**
	* @brief Возвращает строковое представление списка
	* @return строковое представление списка
	*/
	std::string ToString() const;

	/**
	* @brief Оператор вывода списка
	* @param out - выходной поток
	* @param list - список
	* @return выходной поток
	*/
	friend std::ostream& operator << (std::ostream& out, const List& list);
};
