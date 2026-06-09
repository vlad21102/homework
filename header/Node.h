#pragma once

/**
* @brief Класс элемента списка
*/
class Node
{
private:
	int value;
	Node* next;

public:
	/**
	* @brief Создаёт элемент списка
	* @param nodeValue - значение элемента
	*/
	Node(const int nodeValue);

	/**
	* @brief Возвращает значение элемента
	* @return значение элемента
	*/
	int GetValue() const;

	/**
	* @brief Изменяет значение элемента
	* @param newValue - новое значение
	*/
	void SetValue(const int newValue);

	/**
	* @brief Возвращает указатель на следующий элемент
	* @return указатель на следующий элемент
	*/
	Node* GetNext() const;

	/**
	* @brief Изменяет указатель на следующий элемент
	* @param nextNode - новый следующий элемент
	*/
	void SetNext(const Node* nextNode);
};
